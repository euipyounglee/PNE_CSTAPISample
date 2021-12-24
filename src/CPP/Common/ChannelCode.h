/** 
 *@file		ChannelCode.h
 *@brief	PSSeverAPI ä���ڵ� ���� �����Դϴ�.											
 *@author	PNE Solution (Kang se-jun)
 *@date		2019-03-22
 */


//���� CTSMonPro������ Database���� �����ϴ� ����̳�, APIȭ�ϸ� define ����Ʈ��.
/** @defgroup ChannelCode Channel Code
 *  @ingroup define
 *  @brief 
 * ������� ä���� ä���ڵ� �Դϴ�.\n
 *  @details
 * ������� ��翡 ���� ������ �ʴ� �ڵ嵵 �ֽ��ϴ�.\n
 * ������� ������ ���� �� API ������ ���ǵ��� ���� �ڵ嵵 ������⿡�� ������ �� �ֽ��ϴ�.\n
 *  @{
 */
#define CTS_CHANNELCODE_000					0	/*!< ���� (Normal)	\n ���� Cell( Code 20 ~ 79) \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> ���� </TD><TD> OK </TD><TD></TD><TD></TD></TR></TABLE> */
#define CTS_CHANNELCODE_001					1	/*!< NonCell  \n 												
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> NonCell </TD><TD> NonCell </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_002					2	/*!< ��� ���� (Equipment error)	
												*���� ������ �Ǹ�Ȱ� (Code 100 ~ 129)  \n
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> ������ </TD><TD> Machin Error </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_003					3	/*!< �ҷ� Cell (Bad Cell) \n �ҷ� Cell (Code 160 ~ 255)  \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> �ҷ� Cell </TD><TD> Error Cell </TD><TD></TD><TD></TD></TR></TABLE>*/												
#define CTS_CHANNELCODE_004					4	/*!< Cell Check ���� (Cell check error) \n Cell Check���� ������ �߻��� Cell ( Coe 130~ 159)  \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> Cell Check ���� </TD><TD> Cell Check Error </TD><TD></TD><TD></TD></TR></TABLE>*/												
#define CTS_CHANNELCODE_020					20	/*!< Step �ð� ����	(Step time end) \n ���� ������ �ð� ���ǿ� ���� �����  \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> Step �ð� ���� </TD><TD> Step Time End </TD><TD></TD><TD></TD></TR></TABLE>*/												
#define CTS_CHANNELCODE_021					21	/*!< ���� ���� ���� (Max volt End) \n ���� ������ ���� ���ǿ� ���� �����  \n
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> ���� ���� ���� </TD><TD> Max volt End </TD><TD></TD><TD></TD></TR></TABLE>*/												
#define CTS_CHANNELCODE_022					22	/*!< ���� ���� (Current end) \n ���� ������ ���� ���ǿ� ���� �����  \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> ���� ���� </TD><TD> Current End </TD><TD></TD><TD></TD></TR></TABLE>*/												
#define CTS_CHANNELCODE_023					23	/*!< �뷮 ���� (Capacity end) \n ���� ������ �뷮 ���ǿ� ���� �����  \n
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> �뷮 ���� </TD><TD> Capaticy End </TD><TD></TD><TD></TD></TR></TABLE>*/												
#define CTS_CHANNELCODE_024					24	/*!< OCV ���� (OCV end) \n ���� ������ OCV ������ �����  \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> OCV ���� </TD><TD> OCV End </TD><TD></TD><TD></TD></TR></TABLE>*/												
#define CTS_CHANNELCODE_025					25	/*!< �Ϸ� Step (Step complete) \n ���� ������ ������ Step�� �����  \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> �Ϸ� Step </TD><TD> Complete Step </TD><TD></TD><TD></TD></TR></TABLE>*/												
#define CTS_CHANNELCODE_026					26	/*!< ����� ���� (User stop) \n ����ڿ� ���� ������  \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> ����� ���� </TD><TD> Stop </TD><TD></TD><TD></TD></TR></TABLE>*/												
#define CTS_CHANNELCODE_027					27	/*!< �۾� ���� ���� (Test stop end) \n ����ڳ� Fault ���ǿ� ���� ��ø���  \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> �۾����� ���� </TD><TD> Pause </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_028					28	/*!< CHECK Step ���� (Check step end) \n Cell Check ������ ����� \n
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> Check step ���� </TD><TD> Check Step End </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_029					29	/*!< ���� Step ����	(Next step end) \n ����ڿ� ���� ���� Step���� �����ϱ� ���� �����  \n 
												<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> ���� Step ���� </TD><TD> Next Step End </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_030					30	/*!< ���Ǵ��� Step ����	(Impedance step end) \n ���� ������ ���Ǵ��� ������ �����  \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> ���Ǵ��� Step ���� </TD><TD> Impedence Step End </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_031					31	/*!< CYCLE Step ���� (Cycle Step End) \n ���� ������ CYCLE Step ����  \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> CYCLE Step ���� </TD><TD> Cycle Step End </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_032					32	/*!< LOOP Step ���� (Loop step end) \n ���� ������ LOOP Step ����  \n
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> LOOP Step ���� </TD><TD> Loop Step End </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_033					33	/*!< Delta Voltage ����	(Delta voltage end) \n ���� ������ Delta Voltage ���ǿ� ���� �����  \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> Delta Voltage ���� </TD><TD> Delta Voltage End </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_034					34	/*!< Ah ���� ���� \n ���� ������ Ah ���� ���ǿ� ���� �����  \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> Ah ���� ����</TD><TD> Ah Rate End </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_035					35	/*!< Reserved1 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> Reserved1 </TD><TD> Reserved1 </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_036					36	/*!< ���� ���� (Watt end) \n ���� ������ ���� ���ǿ� ���� �����  \n
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> ���� ���� </TD><TD> Power End </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_037					37	/*!< ���·� ���� (WattHour end) \n ���� ������ ���·� ���ǿ� ���� �����  \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> ���·� ���� </TD><TD> Wattage End </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_038					38	/*!< ���� ��ȭ ���� (Delta current end) \n ���� ������ ���� ��ȭ ���ǿ� ���� �����  \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> ������ȭ ���� </TD><TD> Current change End </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_039					39	/*!< �ܺ� �µ� ���� ���� (External temperature upper limit end) \n �ܺε����� ������ �µ����� ���ǿ� ���� �����  \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> �ܺ� �µ����� ���� </TD><TD> Upper Aux Temp Limit End </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_040					40	/*!< �ܺ� �µ� ���� ���� (External temperature lower limit end) \n �ܺε����� ������ �µ����� ���ǿ� ���� �����  \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> �ܺ� �µ����� ���� </TD><TD> Lower Aux Temp Limit End </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_041					41	/*!< �ܺ� ���� ���� ���� (External voltage upper limit end) \n �ܺε����� ������ ���л��� ���ǿ� ���� �����  \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> �ܺ� ���л��� ���� </TD><TD> Upper Aux Voltage Limit End </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_042					42	/*!< �ܺ� ���� ���� ���� (External voltage lower limit end) \n �ܺε����� ������ �������� ���ǿ� ���� �����  \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> �ܺ� �������� ���� </TD><TD> Lower Aux Voltage Limit End </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_043					43	/*!< CAN ���� ���� (CAN upper limit end) \n CAN������ ������ ���� ���ǿ� ���� �����  \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> CAN ���� ���� </TD><TD> CAN Upper CAN Limit End </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_044					44	/*!< CAN ���� ���� (CAN lower limit end) \n CAN������ ������ ���� ���ǿ� ���� �����  \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> CAN ���� ���� </TD><TD> Lower CAN Limit End </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_045					45	/*!< ���� ���� ���� (Voltage lower limit end) \n ���� ������ �������� ���ǿ� ���� �����  \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> ���� ���� ���� </TD><TD> Lower Voltage Limit End </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_046					46	/*!< CV �ð� ���� (CV time end) \n ���� ������ CV�ð� ���ǿ� ���� �����  \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> CV �ð� ���� </TD><TD> CV Time End </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_047					47	/*!< Goto Step ����	(Goto step end) \n ����ڿ� ���� Goto Step�ϱ� ���� ����� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> Goto Step ���� </TD><TD> Goto Step End </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_048					48	/*!< CAN ���� ���� �б� (CAN voltage upper branch) \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> CAN ���� ���� �б� </TD><TD> Upper CAN Voltage Limit Section </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_049					49	/*!< CAN ���� ���� �б�	(CAN voltage lower branch) \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> CAN ���� ���� �б� </TD><TD> Lower CAN Voltage Limit Section </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_050					50	/*!< CAN �µ� ���� �б�	(CAN temperature upper branch) \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> CAN �µ� ���� �б� </TD><TD> Upper CAN Temp Limit Section </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_051					51	/*!< CAN �µ� ���� �б�	(CAN temperature lower branch) \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> CAN �µ� ���� �б� </TD><TD> Lower CAN Temp Limit Section </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_052					52	/*!< CAN ���� �б� (CAN setting branch) \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> CAN ���� �б� </TD><TD> CAN Setting Section </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_053					53	/*!< �ܺ� ���� ���� �б� (External voltage upper limit branch) \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> �ܺ� ���� ���� �б� </TD><TD> Upper Aux Voltage Limit Section </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_054					54	/*!< �ܺ� ���� ���� �б� (External voltage lower limit branch) \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> �ܺ� ���� ���� �б� </TD><TD> Lower Aux Voltage Limit Section </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_055					55	/*!< �ܺ� �µ� ���� �б� (External temperature upper limit branch) \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> �ܺ� �µ� ���� �б� </TD><TD> Upper Aux Temp Limit Section </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_056					56	/*!< �ܺ� �µ� ���� �б� (External temperature lower limit branch) \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> �ܺ� �µ� ���� �б� </TD><TD> Lower Auz Temp Limit Section \n (DB���� Auz�� ��Ÿ)</TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_057					57	/*!< ���·� ���� ���� (WattHour ratio end) \n
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> ���·� ���� ���� </TD><TD> Wattage Rate End </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_058					58	/*!< �ջ� �뷮 ����	(Total capacity end) \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> �ջ� �뷮 ���� </TD><TD> Accumulated Capacity End </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_059					59	/*!< �ջ� �Ŀ� ����	 (Total power end) \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> �ջ� �Ŀ� ���� </TD><TD> Accumulated Power End </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_060					60	/*!< �ջ� �ð� ����	 (Total time end) \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> �ջ� �ð� ���� </TD><TD> Accumulated Time End </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_061					61	/*!< DAQ ���� ���� (DAQ condition terminate ) \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> DAQ ���� ���� </TD><TD> DAQ Condition End </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_062					62	/*!< CAN ���� ���� (CAN condition terminate ) \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> CAN ���� ���� </TD><TD> CAN Condition End </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_066					66	/*!< ����ð� �б� (Reservation time quarter) \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> ����ð� �б� </TD><TD> Reservation Time Quarter </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_080					80	/*!< ���� ����(�ð�)	(Test end(Time)) \n ���� ������ �ð��� ���� ���� ���� ���� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> ��������(�ð�) </TD><TD> Process End(Time) </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_081					81	/*!< ���� ����(����)	(Test end(Voltage)) \n ���� ������ ���п� ���� ���� ���� ���� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> ��������(����) </TD><TD> Process End(Voltage) </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_082					82	/*!< ���� ����(����)	(Test end(Current)) \n ���� ������ ������ ���� ���� ���� ���� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> ��������(����) </TD><TD> Process End(Current) </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_083					83	/*!< ���� ����(�뷮)	(Test end(Capacity)) \n ���� ������ �뷮�� ���� ���� ���� ���� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> ��������(�뷮) </TD><TD> Process End(Capacity) </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_084					84	/*!< ���� ����(����)	(Test end(Watt)) \n ���� ������ ���¿� ���� ���� ���� ���� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> ��������(����) </TD><TD> Process End(Power) </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_085					85	/*!< ���� ����(���·�) (Test end(WattHour)) \n ���� ������ ���·��� ���� ���� ���� ���� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> ��������(���·�) </TD><TD> Process End(Wattage) </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_087					87	/*!< è������ ��� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> è������ ��� </TD><TD> Standby Chamber Interlock </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_089					89	/*!< ������ ���� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> ������ ���� </TD><TD> Change Schedule </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_100					100	/*!< ���� �̻�(���) (Voltage error(Warning)) \n �������� ���� ��ɰ� ���� ������ 1% ���� ���, ������ ���� ��� (��, ���� 5000mV : 50mV) \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> ���� �̻�(���) </TD><TD> Voltage Error(Warning) </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_101					101	/*!< ���� �̻�(���) (Current error(Warning)) \n �������� ���� ��ɰ� ���� ������ 2% ���� ���, ������ ���� ��� (��, ���� 5000mA : 100mA) \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> ���� �̻�(���) </TD><TD> Current Error(Warning) </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_102					102	/*!< ȸ�� ����(���) (Circuit overheating error(Warning)) \n ���� �µ� �̻� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> ȸ�� ����(���) </TD><TD> Circuit Overheat(Warning) </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_103					103	/*!< ���� ���� �̻� (Control power error) \n ���� �������� �̻� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> �������� �̻� </TD><TD> Control Power Error </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_104					104	/*!< ���� ����(Switch) (Force quit(Switch)) \n ��� Run�� Power Switch�� ����� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> ��������(Switch) </TD><TD> Forced termination(Switch) </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_105					105	/*!< ���� ����, UPS �Է� ���� �̻� (Power outage detection, UPS input power abnormality) \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> ���� ���� </TD><TD> Power Failure Detect </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_106					106	/*!< UPS BATTERY �̻� (UPS battery error) \n UPS Battery �̻� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> UPS BATTERY �̻� </TD><TD> UPS BATTERY Error </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_107					107	/*!< EMG(MAIN)	\n Main Emergency Switch ������ \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> EMG (MAIN) </TD><TD> EMG (MAIN) </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_108					108	/*!< EMG(SUB)	\n Sub Emergency Switch ������ \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> EMG (SUB) </TD><TD> EMG (SUB) </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_109					109	/*!< Network �̻� (Network error) \n Network ��� �̻� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> Network �̻� </TD><TD> Network Error </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_110					110	/*!< ���� CPU �̻� (CPU error) \n CPU Watchdog �̻� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> ����CPU �̻� </TD><TD> Control CPU Error </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_111					111	/*!< ���� ����(�͹̳�1) (Force quit(Terminal1)) \n ��� Run�� Terminal���� Halt�� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> ��������(�͹̳�1) </TD><TD> Forced termination(Terminal1) </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_112					112	/*!< ���� ����(�͹̳�2) (Force quit(Terminal2)) \n ��� Run�� Terminal���� Quit�� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> ��������(�͹̳�2) </TD><TD> Forced termination(Terminal2) </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_113					113	/*!< ADC �̻� (ADC error) \n Analog to Digital Converter �̻� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> ADC �̻� </TD><TD> ADC Error </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_114					114	/*!< ä�� ���� �̻� (Channel power error) \n ä�� ������� ���� �̻� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> ä������ �̻� </TD><TD> Channel Power Error </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_115					115	/*!< ä�� ���� ���� Over (Channel control voltage over) \n �������� OV \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> ä����������Over </TD><TD> Channel Control Voltage Over </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_116					116	/*!< ä�� ���� ���� Over (Channel control current over) \n �������� OC \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> ä����������Over </TD><TD> Channel Control Current Over </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_117					117	/*!< DCOV	\n Inverter Output Over Voltage \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> DCOV </TD><TD> DCOV </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_118					118	/*!< ä�� �Է� FUSE �̻� (Channel input FUSE error) \n DC/DC Input Fuse �̻� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> ä���Է� FUSE �̻� </TD><TD> Channel Input Fuse Error </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_119					119	/*!< ä�� ��� FUSE �̻� (Channel output FUSE error) \n ��� Fuse �̻� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> ä����� FUSE �̻� </TD><TD> Channel Output Fuse Error </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_120					120	/*!< ��� Reactor ���� (Output reactor overheating) \n
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> ��� Reactor ���� </TD><TD> Output Reactor Overheat </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_121					121	/*!< Main ���б� ���� (Main transformers overheating) \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> Main ���б� ���� </TD><TD> Main Transforme Overheat </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_122					122	/*!< Main Reactor ���� (Main reactor overheating) \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> Main Reactor ���� </TD><TD> Main Reactor Overheat </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_124					124	/*!< range fault \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> range fault </TD><TD> range fault </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_125					125	/*!< �ι���OC \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> �ι���OC </TD><TD> Inverter OC </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_126					126	/*!< �ι���ETC \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> �ι���ETC </TD><TD> Inverter ETC </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_130					130	/*!< �˻� ������ (Test voltage over) \n Cell Check���� OCV�� ���ǰ� ���� Ŭ �� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> �˻� ������ </TD><TD> Cell Check_Over Voltage </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_131					131	/*!< �˻� ���� �̴� (Test voltage under) \n Cell Check���� OCV�� ���ǰ� ���� ���� �� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> �˻� ���й̴� </TD><TD> Cell Check_Under Voltage </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_132					132	/*!< �˻� ���� ���� (Test voltage upper limit) \n Cell Check���� ���� �ΰ� �� ������ ���ǰ� ���� Ŭ �� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> �˻� ���л��� </TD><TD> Cell Check_Upper Voltage Limit </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_133					133	/*!< �˻� ���� ���� (Test voltage lower limit) \n Cell Check���� ���� �ΰ� �� ������ ���ǰ� ���� ���� �� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> �˻� �������� </TD><TD> Cell Check_Lower Voltage Limit </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_134					134	/*!< �˻� ���� ���� (Test current upper limit) \n Cell Check���� ���� �ΰ� �� ������ ���ǰ� ���� Ŭ �� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> �˻� �������� </TD><TD> Cell Check_Upper Voltage Limit \n(DB�󿡵� Voltage�� �߸� ���) </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_135					135	/*!< �˻� ���� ���� (Test current lower limit) \n Cell Check���� ���� �ΰ� �� ������ ���ǰ� ���� ���� �� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> �˻� �������� </TD><TD> Cell Check_Lower Voltage Limit \n(DB�󿡵� Voltage�� �߸� ���) </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_136					136	/*!< ���˺ҷ�1 (Poor contact1) \n Cell Check���� CC ������ 3mA ���Ϸ� �带 �� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> ���˺ҷ�1 </TD><TD> Cell Check_Contact Error1 </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_137					137	/*!< ���˺ҷ�2 (Poor contact2) \n Cell Check���� ������ �带 �� ������ 10mV �̻� ������ �� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> ���˺ҷ�2 </TD><TD> Cell Check_Contact Error2 </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_138					138	/*!< ���˺ҷ�3 (Poor contact3) \n Cell Check���� CC ������ 5mA �̻� ������ �� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> ���˺ҷ�3 </TD><TD> Cell Check_Contact Error3 </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_139					139	/*!< BadCell1	\n Cell Check���� ������ OCV���� 10mV �̻� ����ϰ�, ������ 3mA ���Ϸ� �带 �� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> BadCell1 </TD><TD> Cell Check_Bad Cell1 </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_140					140	/*!< BadCell2	\n Cell Check���� ������ ���� ����ġ�� +,-10mV �̳��� �ְ�, ������ 3mA ���Ϸ� �带 �� \n
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> BadCell2 </TD><TD> Cell Check_Bad Cell2 </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_141					141	/*!< BadCell3	\n Cell Check���� ������ 2mA ���Ϸ� �带 �� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> BadCell3 </TD><TD> Cell Check_Bad Cell3 </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_142					142	/*!< Short	\n Cell Check���� OCV�� ���� ������ ������ ���� ���ǰ� �̻� ���� �ʾ��� �� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> Short </TD><TD> Cell Check_Short </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_143					143	/*!< ��ġ ����(����) (Position error(None)) \n �Է���ġ ������ �ִµ� Check ��� ���� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> ��ġ����(����) </TD><TD> Location Error(None) </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_144					144	/*!< ��ġ ����(����) (Position error(Exist)) \n �Է���ġ ������ ���µ� Check ��� ���� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> ��ġ����(����) </TD><TD> Location Error(Exist) </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_160					160	/*!< ���� ���� (Voltage upper limit) \n ������� ������ ���ǰ� ���� Ŭ �� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> ���� ���� </TD><TD> Upper Voltage Limit </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_161					161	/*!< ���� ���� (Voltage lower limit) \n ������� ������ ���ǰ� ���� ���� �� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> ���� ���� </TD><TD> Lower Voltage Limit </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_162					162	/*!< ���� ��ȭ ���� (Voltage change upper limit) \n ������� ���� �ð��� ��ȭ�ϴ� ������ ���ǰ� ���� Ŭ �� 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> ���к�ȭ���� </TD><TD> Upper Voltage Change Limit </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_163					163	/*!< ���� ��ȭ ���� (Voltage change lower limit) \n ������� ���� �ð��� ��ȭ�ϴ� ������ ���ǰ� ���� ���� �� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> ���к�ȭ���� </TD><TD> Lower Voltage Change Limit </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_164					164	/*!< ���� �� ����1 (Voltage compare upper limit1) \n ������� ���� �ð�1������ ������ ����1�� ���� Ŭ �� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> ���к񱳻���1 </TD><TD> Upper Voltage Compare Limit1 </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_165					165	/*!< ���� �� ����1 (Voltage compare lower limit1) \n ������� ���� �ð�1������ ������ ����1�� ���� ���� �� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> ���к�����1 </TD><TD> Lower Voltage Compare Limit1 </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_166					166	/*!< OCV ���� (OCV upper limit) \n OCV ������ ���ǰ� ���� Ŭ �� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> OCV���� </TD><TD> Upper OCV Limit </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_167					167	/*!< OCV ���� (OCV lower limit) \n OCV ������ ���ǰ� ���� ���� �� \n 
												<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> OCV���� </TD><TD> Lower OCV Limit </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_168					168	/*!< ���� ���� (Current upper limit) \n ������� ������ ���ǰ� ���� Ŭ �� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> �������� </TD><TD> Upper Current Limit </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_169					169	/*!< ���� ���� (Current lower limit) \n ������� ������ ���ǰ� ���� ���� �� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> �������� </TD><TD> Lower Current Limit </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_170					170	/*!< ���� ��ȭ ���� (Current change upper limit) \n ������� ���� �ð��� ��ȭ�ϴ� ������ ���ǰ� ���� Ŭ �� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> ������ȭ���� </TD><TD> Upper Voltage Change Limit </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_171					171	/*!< ���� ��ȭ ���� (Current change lower limit) \n ������� ���� �ð��� ��ȭ�ϴ� ������ ���ǰ� ���� ���� �� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> ������ȭ���� </TD><TD> Lower Voltage Change Limit </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_172					172	/*!< ���� �� ���� (Current compare upper limit) \n ������� ���� �ð������� ������ ���ǰ� ���� Ŭ �� \n
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> �����񱳻��� </TD><TD> Upper Current Compare Limit </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_173					173	/*!< ���� �� ���� (Current compare lower limit) \n ������� ���� �ð������� ������ ���ǰ� ���� ���� �� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> ���������� </TD><TD> Lower Current Compare Limit </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_174					174	/*!< �뷮 ���� (Watt upper limit) \n ������� �뷮�� ���ǰ� ���� Ŭ �� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> �뷮���� </TD><TD> Upper Capacity Limit </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_175					175	/*!< �뷮 ���� (Watt lower limit) \n ����� ����� �뷮�� ���ǰ� ���� ���� �� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> �뷮���� </TD><TD> Lower Capacity Limit </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_176					176	/*!< �뷮 ��ȭ ���� (Watt change upper limit) \n ������� ���� �ð��� ��ȭ�ϴ� �뷮�� ���ǰ� ���� Ŭ �� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> �뷮��ȭ���� </TD><TD> Upper Capacity Change Limit </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_177					177	/*!< �뷮 ��ȭ ���� (Watt change lower limit) \n ������� ���� �ð��� ��ȭ�ϴ� �뷮�� ���ǰ� ���� ���� �� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> �뷮��ȭ���� </TD><TD> Lower Capacity Change Limit </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_178					178	/*!< �뷮 �� ���� (Watt compare upper limit) \n ������� ���� �ð������� �뷮�� ���ǰ� ���� Ŭ �� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> �뷮�񱳻��� </TD><TD> Upper Current Compare Limit \n (DB�󿡵� Current�� �߸� ���)</TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_179					179	/*!< �뷮 �� ���� (Watt compare lower limit) \n ������� ���� �ð������� �뷮�� ���ǰ� ���� ���� �� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> �뷮������ </TD><TD> Lower Current Compare Limit \n (DB�󿡵� Current�� �߸� ���)</TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_180					180	/*!< ���Ǵ��� ���� (Impedance upper limit) \n ���Ǵ��� ������ ���Ǵ����� ���ǰ� ���� Ŭ �� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> ���Ǵ������� </TD><TD> Upper Impedence Limit </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_181					181	/*!< ���Ǵ��� ���� (Impedance lower limit) \n ���Ǵ��� ������ ���Ǵ����� ���ǰ� ���� ���� �� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> ���Ǵ������� </TD><TD> Lower Impedence Limit </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_182					182	/*!< �ð� �ʰ� (Time over) \n �ش� Step ���� �ð��� ���ǰ� ���� Ŭ �� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> �ð��ʰ� </TD><TD> Timeout </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_183					183	/*!< �ð� �̴� (Time out) \n �ش� Step�� ����� ���� �ð��� ���ǰ� ���� ���� �� \n
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> �ð��̴� </TD><TD> Time Shortage </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_184					184	/*!< ����� �Ϸ� (User end) \n ������� �۾��Ϸ� ���� �� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> ����ڿϷ� </TD><TD> User Command Complete </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_185					185	/*!< ����� �۾� ���� ���� (User test stop end) \n������� �۾����� �����̳� �ܺ� Error�� ���� �۾����� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> �۾��������� </TD><TD> Operating Stop </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_186					186	/*!< ����� ���� Step ���� (User next step end) \n������� ����Step ���ɽ� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> ����Step���� </TD><TD> Next Step End </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_187					187	/*!< ���� �� ����2 (Voltage change upper limit2) \n������� ���� �ð�2������ ������ ����2�� ���� Ŭ �� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> ���к񱳻���2 </TD><TD> Upper Voltage Compare Limit2 </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_188					188	/*!< ���� �� ����2 (Voltage change lower limit2) \n������� ���� �ð�2������ ������ ����2�� ���� ���� �� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> ���к�����2 </TD><TD> Lower Voltage Compare Limit2 </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_189					189	/*!< ���� �� ����3 (Voltage change upper limit3) \n������� ���� �ð�3������ ������ ����3�� ���� Ŭ �� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> ���к񱳻���3 </TD><TD> Upper Voltage Compare Limit3 </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_190					190	/*!< ���� �� ����3 (Voltage change lower limit3) \n������� ���� �ð�3������ ������ ����3�� ���� ���� �� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> ���к�����3 </TD><TD> Lower Voltage Compare Limit3 </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_191					191	/*!< CC �ð� �̻� (CC time error) \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> CC�ð� �̻� </TD><TD> CC Time Error </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_192					192	/*!< �۾� �ҷ� (Poor operation) \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> �۾��ҷ� </TD><TD> Process Failure </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_193					193	/*!< ���� �� ����2 (Current change upper limit2) \n������� ���� �ð�2������ ������ ����2�� ���� Ŭ �� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> �����񱳻���2 </TD><TD> Upper Current Compare Limit2 </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_194					194	/*!< ���� �� ����2 (Current change lower limit2) \n������� ���� �ð�2������ ������ ����2�� ���� ���� �� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> ����������2 </TD><TD> Lower Current Compare Limit2 </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_195					195	/*!< ���� �� ����3 (Current change upper limit3) \n������� ���� �ð�3������ ������ ����3�� ���� Ŭ �� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> �����񱳻���3 </TD><TD> Upper Current Compare Limit3 </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_196					196	/*!< ���� �� ����3 (Current change lower limit3) \n������� ���� �ð�3������ ������ ����3�� ���� ���� �� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> ����������3 </TD><TD> Lower Current Compare Limit3 </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_197					197	/*!< �µ� ���� (Temperature upper limit) \n�µ����� ���� ���� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> �µ����� </TD><TD> Upper Temp Limit </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_198					198	/*!< �µ� ���� (Temperature lower limit) \n�µ����� ���� ���� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> �µ����� </TD><TD> Lower Temp Limit </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_199					199	/*!< �µ� ��ȭ ���� (Temperature change detect) \n�µ���ȭ ���ǿ� ���� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> �µ���ȭ���� </TD><TD> Temp Change Detect </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_200					200	/*!< �ܺ� �µ� ���� (External temperature upper limit)  \n�ܺε����� ������ �µ����� ���� ���� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> �ܺ� �µ����� </TD><TD> Upper Aux Temp Limit </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_201					201	/*!< �ܺ� �µ� ���� (External temperature lower limit)  \n�ܺε����� ������ �µ����� ���� ���� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> �ܺ� �µ����� </TD><TD> Lower Aux Temp Limit </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_202					202	/*!< �ܺ� ���� ���� (External voltage upper limit) \n�ܺε����� ������ ���л��� ���� ���� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> �ܺ� ���л��� </TD><TD> Upper Aux Voltage Limit </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_203					203	/*!< �ܺ� ���� ���� (External voltage lower limit) \n�ܺε����� ������ �������� ���� ���� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> �ܺ� �������� </TD><TD> Lower Aux Voltage Limit </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_204					204	/*!< CAN ���� (CAN upper limit) \n CAN������ ������ ���� ���� ���� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> CAN ���� </TD><TD> Upper CAN Limit </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_205					205	/*!< CAN ���� (CAN lower limit) \n CAN������ ������ ���� ���� ���� \n 
												<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> CAN ���� </TD><TD> Lower CAN Limit </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_206					206	/*!< GROUP CYCLE ���� (Group cycle end) \n GROUP CYCLE ���� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> GROUP CYCLE ���� </TD><TD> GROUP CYCLER End \n (DB�󿡵� CYCLER��� ���)</TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_207					207	/*!< Capacitance ���� (Capacitance upper limit) \n ������� Capacitance�� ���ǰ� ���� Ŭ �� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> Capacitance ���� </TD><TD> Upper Capacitance Limit </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_208					208	/*!< Capacitance ���� (Capacitance lower limit) \n ������� Capacitance�� ���ǰ� ���� ���� �� \n 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> Capacitance ���� </TD><TD> Lower Capacitance Limit </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_209					209	/*!< ���·� ���� (WattHour upper limit) 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> ���·� ���� </TD><TD> Upper Wattage Limit </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_210					210	/*!< ���·� ���� (WattHour lower limit) 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> ���·� ���� </TD><TD> Lower Wattage Limit </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_211					211	/*!< DAQ �������� ���� (DAQ common condition detect) 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> DAQ �������� ���� </TD><TD> DAQ Common Condition Detect </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_212					212	/*!< CAN �������� ���� (CAN common condition detect)
												<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> CAN �������� ���� </TD><TD> CAN Common Condition Detect </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_213					213	/*!< DAQ �������� ���� (DAQ step condition detect)
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> DAQ �������� ���� </TD><TD> DAQ Step Condition Detect </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_214					214	/*!< CAN �������� ���� (CAN step condition detect)
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> CAN �������� ���� </TD><TD> CAN Step Condition Detect </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_215					215	/*!< Watt �������� ���� (Watt common condition detection) \n �������� �� ������������� Watt Upper ��\n
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> Watt �������� ���� </TD><TD> Watt CommonCondition Detect </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_220					220 /*!< è�� �̻� \n è���� ������ ������ ��� \n
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> è�� �̻� </TD><TD> Chamber Error </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_221					221	/*!< CAN ��� �̻� (CAN communication error) \n CAN Receive ������ �ߴµ� 2�ʵ��� �ƹ��� �����͵� �ȵ����� ä�� Pause 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> CAN ��� �̻� </TD><TD> CAN communication Error </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_222					222	/*!< �ܺ� CAN ���� ��ġ �̻� (External CAN connecting device error) 
												<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> �ܺ� CAN ���� ��ġ �̻� </TD><TD> Abnormal Ext CAN connection </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_223					223	/*!< �ܺ� CAN ��ɰ� �̻� (External CAN command value error) \n ��ȿ ��� ������ ��� 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> �ܺ� CAN ��ɰ� �̻� </TD><TD> Abnormal Ext CAN command </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_224					224	/*!< �ܺ� CAN ����� �̻� (External CAN controller error) \n �ܺ� ������� RUN ���� �̻� 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> �ܺ� CAN ����� �̻� </TD><TD> Abnormal Ext CAN controller </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_225					225	/*!< �ܺ� CAN NM�ֱ� �̻� 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> �ܺ� CAN NM�ֱ� �̻� </TD><TD> Error Ext CAN NM period </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_226					226	/*!< 1���� ���� �̻� (1 sections deviation error) 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 1���� ���� �̻� </TD><TD> Detect Cell Dev.Voltage </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_227					227	/*!< BMS �µ� ����(�Ͻ�����) (BMS temperature interlocking (Pause)) \n BMS �µ� �����Ͱ� �������� �µ� ���� Upper �� �Ͻ�����
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> BMS�µ� ����(�Ͻ�����) �̻� </TD><TD> Interlock BMS Temp.(pause) </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_228					228	/*!< BMS �µ� ����(�۾����) (BMS temperature interlocking (continued)) \n BMS �µ� �����Ͱ� �������� �µ� ���� lower �� �۾���� 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> BMS�µ� ����(�۾����) </TD><TD> Interlock BMS Temp.(cotinue) </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_229					229	/*!< ���к�ȭ�̻� (Voltage change error)
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> ���к�ȭ�̻� </TD><TD> Abnormal Voltage Change </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_231					231	/*!< ���������¡Fail (Output precharging fail)
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> ���������¡Fail </TD><TD> Export Pre-Charging Fail </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_232					232	/*!< ������ȭ�̻�
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> ������ȭ�̻� </TD><TD> Abnormal Current Change </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_234					234	/*!< �������� ����(AuxV upper limit) \n (default4.6) \n
												*safetyInfo.lVtgCellHigh �������� cell voltage 4.6 \n
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> �������� ����(default4.6) </TD><TD> AuxVolt Upper Limit(default4.6) </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_235					235	/*!< AuxT ���� �̻� (AuxT deviation error) 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> AuxT ���� �̻� </TD><TD> AuxT Deviation Abnormal </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_236					236	/*!< AuxTh ���� �̻�(AuxTh deviation error)
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> AuxTh ���� �̻� </TD><TD> AuxTh Deviation Abnormal </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_237					237	/*!< AuxT+AuxTh ���� �̻� ���� �̻� \n
												*safetyInfo.lVtgCellLow �������� cell voltage 2.0 \n
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> AuxT+AuxTh ���� �̻� </TD><TD> AuxT+AuxTh Deviation Abnormal </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_238					238	/*!< �ܺ� ���� ��ȭ �̻� (AuxV change error)
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> �ܺ� ���� ��ȭ �̻� </TD><TD> Ext Volt Change Abnormal </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_239					239	/*!< �������� ���� (AuxV lower limit) 
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> �������� ����(default2.0) </TD><TD> AuxVolt Lower Limit(default2.0) </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_240					240	/*!< 2���� ���� �̻� (2 sections deviation error) \n
												*�������� �� �� �������� �⺻ ���� �̻� \n
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 2���� ���� �̻� </TD><TD> 2 Section Deviation Abnormal </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_241					241	/*!< 3���� ���� �̻� (3 sections deviation error) \n
												*�������� �� �� 3���� �������� �̻� �� \n
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 3���� ���� �̻� </TD><TD> 3 Section Deviation Abnormal </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_242					242	/*!< Step ���� ���� (Step voltage deviation) \n
												*�������� �� Step �������� �̻� \n
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> Step ���� ���� </TD><TD> Step Volt Deviation </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_243					243	/*!< CHAMBER EMG
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> CHAMBER EMG </TD><TD> CHAMBER EMG </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_244					244	/*!< CHAMBER DOOR OPEN
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> CHAMBER DOOR OPEN </TD><TD> CHAMBER DOOR OPEN </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_245					245	/*!< CHAMBER ETC ERROR
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> CHAMBER ETC ERROR </TD><TD> CHAMBER ETC ERROR </TD><TD></TD><TD></TD></TR></TABLE>*/

#define CTS_CHANNELCODE_246					246	/*!< �ܺε����� ���� ����
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> ����� �� ���� ���¿��� �ܺε����� ���� ���� ���� </TD><TD> No Translated </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_247					247	/*!< �ܺε����� ���� ����
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> ����� �� ���� ���¿��� �ܺε����� ���� ���� ���� </TD><TD> No Translated </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_248					248	/*!< VENT ���� ����
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> UI ȭ���� VENT OPEN ��ư�� ���� VENT�� ���� ���� </TD><TD> No Translated </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_249					249	/*!< �ܺ� ��������
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> �ܺε����� ������ �������� ���� ���� </TD><TD> No Translated </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_250					250	/*!< �ܺ� ��������
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> �ܺε����� ������ �������� ���� ���� </TD><TD> No Translated </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_68					68	/*!< �ܺ� �������� ����
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> �ܺε����� ������ �������� ���ǿ� ���� ����� </TD><TD> No Translated </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_69					69	/*!< �ܺ� �������� ����
												*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> �ܺε����� ������ �������� ���ǿ� ���� ����� </TD><TD> No Translated </TD><TD></TD><TD></TD></TR></TABLE>*/


/** @} */ //Channel Code ���� ��