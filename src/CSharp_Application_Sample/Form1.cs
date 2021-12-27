/* 
 file		Form1.cs
 brief	    C Sharp 에서 ctsAPI와의 통신 예제 										
 author	    PNE Solution (Kang se-jun)
 date		2019-03-22
*/

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Runtime.InteropServices;   //Dll을 사용할때 추가합니다.


namespace CSharp_Application_Sample
{
    //EMG CODE 구조체 생성 API의 CTS_EMG_DATA 구조체 참고.
    [StructLayout(LayoutKind.Sequential)]
    public struct CTS_EMG_DATA
    {
        [MarshalAs(UnmanagedType.I2, SizeConst = 1)]//길이 2
        public Int16 Code;		    	     /**< EMG 코드 */

        [MarshalAs(UnmanagedType.I2, SizeConst = 1)]//길이 2
        public Int16 Value;		    	     /**< EMG 값 */

        [MarshalAs(UnmanagedType.I4, SizeConst = 1)]//길이 4
        public int reserved;   		     /**< 예비 공간 */

        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 128)]//길이128
        public byte[] szName;           /**< EMG 이름 */
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct DEBUG_TEST
    {
        [MarshalAs(UnmanagedType.I4, SizeConst = 1)]
        public int nTest;
        [MarshalAs(UnmanagedType.R4, SizeConst = 1)]
        public float fTest;
    }


    //ksj 20200728 : CTS_MD_SYSTEM_DATA 구조체 선언
    [StructLayout(LayoutKind.Sequential)]
    public struct CTS_MD_SYSTEM_DATA
    {
        [MarshalAs(UnmanagedType.U4, SizeConst = 1)]//길이 4
        public UInt32 nModuleID;	   	     /**< 모듈 ID */

        [MarshalAs(UnmanagedType.U4, SizeConst = 1)]//길이 4
        public UInt32 nSystemType;

        [MarshalAs(UnmanagedType.U4, SizeConst = 1)]//길이 4
        public UInt32 nProtocolVersion;

        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 128)]//길이128
        public byte[] szModelName;

        [MarshalAs(UnmanagedType.U4, SizeConst = 1)]//길이 4
        public UInt32 nOSVersion;

        [MarshalAs(UnmanagedType.U2, SizeConst = 1)]//길이 2
        public UInt16 wVoltageRange;

        [MarshalAs(UnmanagedType.U2, SizeConst = 1)]//길이 2
        public UInt16 wCurrentRange;

        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 20)]//길이 4 * 5 = 20
        public UInt32[] nVoltageSpec;

        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 20)]//길이 4 * 5 = 20
        public UInt32[] nCurrentSpec;

        [MarshalAs(UnmanagedType.U1, SizeConst = 1)]//길이 1
        public byte byCanCommType;

        [MarshalAs(UnmanagedType.U1, SizeConst = 1)]//길이 1
        public byte byTypeData;

        [MarshalAs(UnmanagedType.U2, SizeConst = 1)]//길이 2
        public UInt16 wInstalledBoard;

        [MarshalAs(UnmanagedType.U2, SizeConst = 1)]//길이 2
        public UInt16 wChannelPerBoard;

        [MarshalAs(UnmanagedType.U4, SizeConst = 1)]//길이 4
        public UInt32 nInstalledChCount;

        [MarshalAs(UnmanagedType.U4, SizeConst = 1)]//길이 4
        public UInt32 nTotalJigNo;

        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 64)]//길이 4 * 16 = 64
        public UInt32[] awBdinJig;

        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 16)]//길이 4 * 4 = 16
        public UInt32[] reserved;

    }



enum PS_STEP
{
    PS_STEP_NONE = 0, //Idle
        PS_STEP_CHARGE,  //충전
        PS_STEP_DISCHARGE,//방전
        PS_STEP_REST,//휴지
        PS_STEP_OCV, //OCV
        PS_STEP_IMPEDANCE,//임피던스
        PS_STEP_END,//완료
        PS_STEP_ADV_CYCLE,//작업중
        PS_STEP_LOOP,//작업중
        PS_STEP_PATTERN//Pattern

    }



[StructLayout(LayoutKind.Sequential)]
    public struct CTS_SIMPLE_TEST_INFO
    {
        [MarshalAs(UnmanagedType.I4, SizeConst = 1)]//길이 4
        public Int32 nStepType;             //   스텝. Charge:1, Discharge:2, Rest:3, OCV:4  

        [MarshalAs(UnmanagedType.I4, SizeConst = 1)]//길이 4
        public Int32 nMode;             //   모드. CCCV:1, CC:2 CV:3 CP:6   



        [MarshalAs(UnmanagedType.I4, SizeConst = 1)]//길이 4
        public Int32 nRefVoltage;             // <  설정 전압 mV   

        [MarshalAs(UnmanagedType.I4, SizeConst = 1)]//길이 4
        public Int32 nRefCurrent;             //   설정 전압 mA   

        [MarshalAs(UnmanagedType.I4, SizeConst = 1)]//길이 4
        public Int32 nRefPower;             //   설정 파워 mW 

        [MarshalAs(UnmanagedType.I4, SizeConst = 1)]//길이 4
        public Int32 nRecordTime;				//  기록 시간 (1/10초) 예) 1초:10 , 20초:200, 0.1초: 1 



        [MarshalAs(UnmanagedType.I4, SizeConst = 1)]//길이 4
        //종료 조건
        public Int32 nCutoffCondTime;            //  종료 시간 (초) 

        [MarshalAs(UnmanagedType.I4, SizeConst = 1)]//길이 4
        public Int32 nCutoffCondVolt;            //  종료 전압 mV 

        [MarshalAs(UnmanagedType.I4, SizeConst = 1)]//길이 4
        public Int32 nCutoffCondCurrent;         //  종료 전류 mA 

        [MarshalAs(UnmanagedType.I4, SizeConst = 1)]//길이 4
        public Int32 nCutoffCondAh;              //  종료 용량 mAh 


        [MarshalAs(UnmanagedType.I4, SizeConst = 1)]//길이 4
        //안전 조건
        public Int32 nSafetyVoltageHigh;         //  전압 상한 mV 

        [MarshalAs(UnmanagedType.I4, SizeConst = 1)]//길이 4
        public Int32 nSafetyVoltageLow;          //  전압 하한 mV 

        [MarshalAs(UnmanagedType.I4, SizeConst = 1)]//길이 4
        public Int32 nSafetyCurrentHigh;         //  전류 상한 mA 

        [MarshalAs(UnmanagedType.I4, SizeConst = 1)]//길이 4
        public Int32 nSafetyCurrentLow;          //  전류 하한 mA 

        [MarshalAs(UnmanagedType.I4, SizeConst = 1)]//길이 4
        public Int32 nSafetyAhHigh;              //  용량 상한 mAh 
            
        [MarshalAs(UnmanagedType.I4, SizeConst = 1)]//길이 4
        public Int32  nSafetyAhLow;               //  용량 하한 mAh 



       // [MarshalAs(UnmanagedType.LPArray, SizeConst = 12)]//길이 4 * 4 = 12
      //  public int[] nReserved;             //  미사용 


        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 12)]//길이 4 * 4 = 16
        public Int32[] reserved;

    }

    public partial class Form1 : Form
    {
#if x64
        private const  string STR_DllNAME = "PSServerAPI64.dll";
#else
        private const  string STR_DllNAME = "PSServerAPI.dll";
#endif
        // private const string DLLNAME = "PSServerAPI.dll";


        // 디버깅용 Test API 정의 ////////////////////////////////////////////////////////////////////////////////
        [DllImport(STR_DllNAME)] //PSServerAPI.DLL 링크
        public static extern IntPtr ctsApiDebugPtrStruct(ref DEBUG_TEST debug1);

        [DllImport(STR_DllNAME)] //PSServerAPI.DLL 링크
        public static extern DEBUG_TEST ctsApiDebugStruct(DEBUG_TEST stEmg); //API 함수 정의

        [DllImport(STR_DllNAME)] //PSServerAPI.DLL 링크
        public static extern int ctsApiDebugInteger(int nA); //API 함수 정의

        [DllImport(STR_DllNAME)] //PSServerAPI.DLL 링크
        public static extern StringBuilder ctsApiDebugString(char[] szString);

        [DllImport(STR_DllNAME)] //PSServerAPI.DLL 링크
        public static extern IntPtr ctsApiDebugPtrStruct2(ref CTS_EMG_DATA debug1);

        // ctsAPI 정의 ////////////////////////////////////////////////////////////////////////////////
        [DllImport(STR_DllNAME)] //PSServerAPI.DLL 링크
        public static extern int ctsServerCreate(int nInstalledModuleNo, IntPtr hWnd);

        [DllImport(STR_DllNAME)] //PSServerAPI.DLL 링크
        public static extern int ctsServerStart();

        [DllImport(STR_DllNAME)] //PSServerAPI.DLL 링크
        public static extern int ctsServerClose();

        // CallBack API 정의
        [DllImport(STR_DllNAME, CallingConvention = CallingConvention.StdCall)] //PSServerAPI.DLL 링크
        public static extern int CallbackConnected(CALLBACK_CONNECTED callback);
        public delegate int CALLBACK_CONNECTED(int nModuleID, ref CTS_MD_SYSTEM_DATA sysinfo); //ksj 20200728 : callback 함수 처리를 위한 대리자 deleagate 선언.



        [DllImport(STR_DllNAME)] //PSServerAPI.DLL 링크
        public static extern int ctsSendSimpleTest(uint nModuleID, int nBitLCh, int nBitHCh , int nStepCount , CTS_SIMPLE_TEST_INFO[] pStepInfo );

        //////////////////////////////////////////////////////////////////////////////////////////////

        [DllImport(STR_DllNAME)] //PSServerAPI.DLL 링크
        public static extern void ctsSetLogPath(string szLogPath);

        public Form1()
        {
            InitializeComponent();

            //ksj 20200728 : Callback delegate 선언
            CALLBACK_CONNECTED CB_Connected = new CALLBACK_CONNECTED(ctsConnected);
            CallbackConnected(CB_Connected);
        }

        //ksj 20200728 : delegate 호출 메소드 선언 (접속 이벤트)
        public int ctsConnected(int nModuleID, ref CTS_MD_SYSTEM_DATA sysinfo)
        {
            string str;
            string strModelName = Encoding.Default.GetString(sysinfo.szModelName);

            str = string.Format("ctsConnected!! {0},{1},{2}",
                                        sysinfo.nModuleID,
                                        sysinfo.nProtocolVersion,
                                        strModelName
                                        );

            BtnctsAPIServerStopState(true);//Stop 버튼 활성화
            BtnSimpleState(true); //서버 연결

            
        //    MessageBox.Show(str,"OK"); // 통신 연결됨---- OK
            Console.Write(str + "\n");

            
            BtnResultState(str); //통신 연결됨----OK

            return 0;
        }

        //ksj 20190411 : DLL 정수 입력 / 정수 리턴 예제
        private void button1_Click_1(object sender, EventArgs e)
        {
            //ksj 20190410 : DLL API 통신 테스트
            int nA = ctsApiDebugInteger(3);  //ksj 20190410 : 입력한 값을 그대로  리턴하는 테스트 API
            int nB = ctsApiDebugInteger(2);

            string str;
            str = string.Format("{0},{1}", nA, nB);

            MessageBox.Show(str);
        }

        //ksj 20190411 : DLL 구조체 포인터 인자  입력/ 구조체 포인터 리턴 예제
        private void button2_Click(object sender, EventArgs e)
        {
            //ksj 20190410 : DLL API 통신 테스트
            DEBUG_TEST stDataIn = new DEBUG_TEST();
            DEBUG_TEST stDataOut = new DEBUG_TEST();


            stDataIn.nTest = 1234;
            stDataIn.fTest = 56.78F;

            var rtnPtr = ctsApiDebugPtrStruct(ref stDataIn);  //입력한 값을 그대로 메세지 박스로 출력하고 리턴하는 테스트 API
            if (rtnPtr != IntPtr.Zero)
                stDataOut = (DEBUG_TEST)Marshal.PtrToStructure(rtnPtr, typeof(DEBUG_TEST));
            
            string str;
            str = string.Format("DATA IN {0},{1}\nDATA OUT {2},{3}", stDataIn.nTest, stDataIn.fTest, stDataOut.nTest, stDataOut.fTest); 
            MessageBox.Show(str);
        }

        //ksj 20190411 : DLL 문자열 입력 / 문자열 리턴 예제
        private void button3_Click(object sender, EventArgs e)
        {
            //문자열 주고 받기 예제
            //String을 char 배열 형식으로 변환한다.
            //Char배열로 바꾼후 넘긴다.

            String _data = "피앤이솔루션 ctsAPI 문자열 테스트";
            char[] _data_char = _data.ToCharArray();
            StringBuilder SB = ctsApiDebugString(_data_char);

            string str;
            str = string.Format("{0}",SB); //API가 되돌려준 문자열을 출력한다.

            MessageBox.Show(str); 
            

        }

        //ksj 20190411 : DLL 구조체 입력 / 구조체 출력 예제
       private void button4_Click(object sender, EventArgs e)
        { 
            //ksj 20190410 : DLL API 통신 테스트
            CTS_EMG_DATA stDataIn = new CTS_EMG_DATA();
            CTS_EMG_DATA stDataOut = new CTS_EMG_DATA();


            stDataIn.Code = 12;
            stDataIn.Value = 34;
            String _data = "pne solution string test 한글 테스트?";
            String _data2 = _data.PadRight(128); //문자열 자리수 구조체 사이즈와 같이 128개 맞춰야 됩니다.
            stDataIn.szName = System.Text.Encoding.Default.GetBytes(_data2); //string -> byte (한글 2byte 영문 1byte ascii 로 변환 필요.)

            var rtnPtr = ctsApiDebugPtrStruct2(ref stDataIn); //입력한 값을 그대로 메세지 박스로 출력하고 리턴하는 테스트 API
            if (rtnPtr != IntPtr.Zero)
                stDataOut = (CTS_EMG_DATA)Marshal.PtrToStructure(rtnPtr, typeof(CTS_EMG_DATA));

            string strNameIn = System.Text.Encoding.Default.GetString(stDataIn.szName); //byte -> string
            string strNameOut = System.Text.Encoding.Default.GetString(stDataOut.szName); //byte -> string
      
            string str;
            str = string.Format("DATA IN {0},{1},{2}\nDATA OUT {3},{4},{5}", stDataIn.Code, stDataIn.Value, strNameIn, stDataOut.Code, stDataOut.Value, strNameOut);
            MessageBox.Show(str);
        }

       //ctsApi 초기화 API 호출
       private void button5_Click(object sender, EventArgs e)
       {
           int rtn = ctsServerCreate(1, this.Handle);

            if(1 == rtn)
            {
                button6.Enabled = true;
            }

           MessageBox.Show(string.Format("rtn : {0}", rtn));
       }

       //서버 listen 시작
       private void button6_Click(object sender, EventArgs e)
       {
           int rtn = ctsServerStart();

           MessageBox.Show(string.Format("rtn : {0}", rtn));
            
           BtnSimpleState(false);
        }

        private void BtnSimpleState(bool bEnable)
        {
        //    invoke.
            if (this.InvokeRequired)
            {
                this.Invoke(new MethodInvoker(delegate ()
                {
                    button8.Enabled = bEnable;// false; //활성화
                }));
            }
            else
            {
                button8.Enabled = bEnable;// false; //활성화
            }
        }


        private void BtnctsAPIServerStopState(bool bEnable)
        {
            //    invoke.
            if (this.InvokeRequired)
            {
                this.Invoke(new MethodInvoker(delegate ()
                {
                    button7.Enabled = bEnable;// false; //활성화
                }));
            }
            else
            {
                button7.Enabled = bEnable;// false; //활성화
            }
        }


        private void BtnResultState(string strmessgae)
        {

            if (this.InvokeRequired)
            {
                this.Invoke(new MethodInvoker(delegate ()
                {
                    //button7.Enabled = bEnable;// false; //활성화
                    listBox1.Items.Add(strmessgae);
                }));
            }
            else
            {
                //button7.Enabled = bEnable;// false; //활성화
                listBox1.Items.Add(strmessgae);
            }
         
        }

        //서버 close
        private void button7_Click(object sender, EventArgs e)
       {
           int rtn = ctsServerClose();

           MessageBox.Show(string.Format("rtn : {0}", rtn));
       }

        void TestStruc()
        {
            //ksj 20190410 : DLL API 통신 테스트
            DEBUG_TEST stDataIn = new DEBUG_TEST();
            DEBUG_TEST stDataOut = new DEBUG_TEST();


            stDataIn.nTest = 1234;
            stDataIn.fTest = 56.78F;

            var rtnPtr = ctsApiDebugPtrStruct(ref stDataIn);  //입력한 값을 그대로 메세지 박스로 출력하고 리턴하는 테스트 API
            if (rtnPtr != IntPtr.Zero)
                stDataOut = (DEBUG_TEST)Marshal.PtrToStructure(rtnPtr, typeof(DEBUG_TEST));

            string str;
            str = string.Format("DATA IN {0},{1}\nDATA OUT {2},{3}", stDataIn.nTest, stDataIn.fTest, stDataOut.nTest, stDataOut.fTest);
            MessageBox.Show(str);

            //listBox1.ControlAdded("aaa");
         //   listBox1.Items.Add(str);


    }

        private void button8_Click(object sender, EventArgs e)
        {
          
            SimepeTest();
            return;

        }



        private int SimepeTest()
        {
            string root = System.Windows.Forms.Application.StartupPath;
#if false
            ctsSetLogPath("C:\\PNE1");
#else
            //실행파일 위치에 생성 시킴
            string LogRoot = root + "\\PNE";
            ctsSetLogPath(LogRoot);
#endif

            int nModuleNum = 1;
            int nStepCount = 6;
            CTS_SIMPLE_TEST_INFO[] SimpleSch = new CTS_SIMPLE_TEST_INFO[nStepCount];

            SimpleSch[0].nStepType = (int)PS_STEP.PS_STEP_OCV;

            //휴지 스텝
            SimpleSch[1].nStepType = (int)PS_STEP.PS_STEP_REST; //REST

            SimpleSch[1].nRecordTime = 10;
            SimpleSch[1].nCutoffCondTime = 3;

            SimpleSch[2].nStepType = (int)PS_STEP.PS_STEP_REST; //REST
            SimpleSch[2].nRecordTime = 1;
            SimpleSch[2].nCutoffCondTime = 3;

            SimpleSch[3].nStepType = (int)PS_STEP.PS_STEP_REST; //REST
            SimpleSch[3].nRecordTime = 101;
            SimpleSch[3].nCutoffCondTime = 3;

            SimpleSch[4].nStepType = (int)PS_STEP.PS_STEP_REST; //REST
            SimpleSch[4].nRecordTime = 1;
            SimpleSch[4].nCutoffCondTime = 3;

            SimpleSch[5].nStepType = (int)PS_STEP.PS_STEP_REST; //REST
            SimpleSch[5].nRecordTime = 205;
            SimpleSch[5].nCutoffCondTime = 3;

            String strOut = "1";
            int errCode;
            errCode = ctsSendSimpleTest((uint)nModuleNum, Int32.Parse(strOut), 0, nStepCount, SimpleSch);

            if (errCode == 1)
            {
                // 정상
                MessageBox.Show(string.Format("code ={0}", errCode.ToString()), "OK");
            }
            else
            {
                MessageBox.Show(string.Format("code ={0}", errCode.ToString()), "Error");

            }


            return errCode;
        }


        private void Form1_Load(object sender, EventArgs e)
        {
#if x64
            this.Text = this.Text + "-x64";
#else
            this.Text = this.Text + "-x86";
#endif

        }
    }
}
