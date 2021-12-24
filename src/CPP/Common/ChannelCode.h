/** 
 *@file		ChannelCode.h
 *@brief	PSSeverAPI 채널코드 정의 파일입니다.											
 *@author	PNE Solution (Kang se-jun)
 *@date		2019-03-22
 */


//기존 CTSMonPro에서는 Database에서 관리하던 목록이나, API화하며 define 리스트업.
/** @defgroup ChannelCode Channel Code
 *  @ingroup define
 *  @brief 
 * 충방전기 채널의 채널코드 입니다.\n
 *  @details
 * 충방전기 사양에 따라 사용되지 않는 코드도 있습니다.\n
 * 충방전기 버전에 따라 본 API 버전에 정의되지 않은 코드도 충방전기에서 보내올 수 있습니다.\n
 *  @{
 */
#define CTS_CHANNELCODE_000					0	/*!< 정상 (Normal)	\n 정상 Cell( Code 20 ~ 79) \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 정상 </TD><TD> OK </TD><TD></TD><TD></TD></TR></TABLE> */
#define CTS_CHANNELCODE_001					1	/*!< NonCell  \n 												
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> NonCell </TD><TD> NonCell </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_002					2	/*!< 장비 오류 (Equipment error)	
												*장비상에 오류로 판명된것 (Code 100 ~ 129)  \n
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 장비오류 </TD><TD> Machin Error </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_003					3	/*!< 불량 Cell (Bad Cell) \n 불량 Cell (Code 160 ~ 255)  \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 불량 Cell </TD><TD> Error Cell </TD><TD></TD><TD></TD></TR></TABLE>*/												
#define CTS_CHANNELCODE_004					4	/*!< Cell Check 오류 (Cell check error) \n Cell Check에서 오류가 발생한 Cell ( Coe 130~ 159)  \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> Cell Check 오류 </TD><TD> Cell Check Error </TD><TD></TD><TD></TD></TR></TABLE>*/												
#define CTS_CHANNELCODE_020					20	/*!< Step 시간 종료	(Step time end) \n 시험 조건의 시간 조건에 의해 종료됨  \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> Step 시간 종료 </TD><TD> Step Time End </TD><TD></TD><TD></TD></TR></TABLE>*/												
#define CTS_CHANNELCODE_021					21	/*!< 전압 상한 종료 (Max volt End) \n 시험 조건의 전압 조건에 의해 종료됨  \n
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 전압 상한 종료 </TD><TD> Max volt End </TD><TD></TD><TD></TD></TR></TABLE>*/												
#define CTS_CHANNELCODE_022					22	/*!< 전류 종료 (Current end) \n 시험 조건의 전류 조건에 의해 종료됨  \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 전류 종료 </TD><TD> Current End </TD><TD></TD><TD></TD></TR></TABLE>*/												
#define CTS_CHANNELCODE_023					23	/*!< 용량 종료 (Capacity end) \n 시험 조건의 용량 조건에 의해 종료됨  \n
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 용량 종료 </TD><TD> Capaticy End </TD><TD></TD><TD></TD></TR></TABLE>*/												
#define CTS_CHANNELCODE_024					24	/*!< OCV 종료 (OCV end) \n 시험 조건의 OCV 측정이 종료됨  \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> OCV 종료 </TD><TD> OCV End </TD><TD></TD><TD></TD></TR></TABLE>*/												
#define CTS_CHANNELCODE_025					25	/*!< 완료 Step (Step complete) \n 시험 조건의 마지막 Step이 종료됨  \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 완료 Step </TD><TD> Complete Step </TD><TD></TD><TD></TD></TR></TABLE>*/												
#define CTS_CHANNELCODE_026					26	/*!< 사용자 종료 (User stop) \n 사용자에 의해 중지됨  \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 사용자 종료 </TD><TD> Stop </TD><TD></TD><TD></TD></TR></TABLE>*/												
#define CTS_CHANNELCODE_027					27	/*!< 작업 멈춤 종료 (Test stop end) \n 사용자나 Fault 조건에 의해 잠시멈춤  \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 작업멈춤 종료 </TD><TD> Pause </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_028					28	/*!< CHECK Step 종료 (Check step end) \n Cell Check 과정이 종료됨 \n
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> Check step 종료 </TD><TD> Check Step End </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_029					29	/*!< 다음 Step 종료	(Next step end) \n 사용자에 의해 다음 Step으로 진행하기 위해 종료됨  \n 
												<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 다음 Step 종료 </TD><TD> Next Step End </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_030					30	/*!< 임피던스 Step 종료	(Impedance step end) \n 시험 조건의 임피던스 측정이 종료됨  \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 임피던스 Step 종료 </TD><TD> Impedence Step End </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_031					31	/*!< CYCLE Step 종료 (Cycle Step End) \n 시험 조건의 CYCLE Step 종료  \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> CYCLE Step 종료 </TD><TD> Cycle Step End </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_032					32	/*!< LOOP Step 종료 (Loop step end) \n 시험 조건의 LOOP Step 종료  \n
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> LOOP Step 종료 </TD><TD> Loop Step End </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_033					33	/*!< Delta Voltage 종료	(Delta voltage end) \n 시험 조건의 Delta Voltage 조건에 의해 종료됨  \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> Delta Voltage 종료 </TD><TD> Delta Voltage End </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_034					34	/*!< Ah 비율 종료 \n 시험 조건의 Ah 비율 조건에 의해 종료됨  \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> Ah 비율 종료</TD><TD> Ah Rate End </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_035					35	/*!< Reserved1 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> Reserved1 </TD><TD> Reserved1 </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_036					36	/*!< 전력 종료 (Watt end) \n 시험 조건의 전력 조건에 의해 종료됨  \n
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 전력 종료 </TD><TD> Power End </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_037					37	/*!< 전력량 종료 (WattHour end) \n 시험 조건의 전력량 조건에 의해 종료됨  \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 전력량 종료 </TD><TD> Wattage End </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_038					38	/*!< 전류 변화 종료 (Delta current end) \n 시험 조건의 전류 변화 조건에 의해 종료됨  \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 전류변화 종료 </TD><TD> Current change End </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_039					39	/*!< 외부 온도 상한 종료 (External temperature upper limit end) \n 외부데이터 설정의 온도상한 조건에 의해 종료됨  \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 외부 온도상한 종료 </TD><TD> Upper Aux Temp Limit End </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_040					40	/*!< 외부 온도 하한 종료 (External temperature lower limit end) \n 외부데이터 설정의 온도하한 조건에 의해 종료됨  \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 외부 온도하한 종료 </TD><TD> Lower Aux Temp Limit End </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_041					41	/*!< 외부 전압 상한 종료 (External voltage upper limit end) \n 외부데이터 설정의 전압상한 조건에 의해 종료됨  \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 외부 전압상한 종료 </TD><TD> Upper Aux Voltage Limit End </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_042					42	/*!< 외부 전압 하한 종료 (External voltage lower limit end) \n 외부데이터 설정의 전압하한 조건에 의해 종료됨  \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 외부 전압하한 종료 </TD><TD> Lower Aux Voltage Limit End </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_043					43	/*!< CAN 상한 종료 (CAN upper limit end) \n CAN데이터 설정의 상한 조건에 의해 종료됨  \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> CAN 상한 종료 </TD><TD> CAN Upper CAN Limit End </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_044					44	/*!< CAN 하한 종료 (CAN lower limit end) \n CAN데이터 설정의 하한 조건에 의해 종료됨  \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> CAN 하한 종료 </TD><TD> Lower CAN Limit End </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_045					45	/*!< 전압 하한 종료 (Voltage lower limit end) \n 시험 조건의 전압하한 조건에 의해 종료됨  \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 전압 하한 종료 </TD><TD> Lower Voltage Limit End </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_046					46	/*!< CV 시간 종료 (CV time end) \n 시험 조건의 CV시간 조건에 의해 종료됨  \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> CV 시간 종료 </TD><TD> CV Time End </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_047					47	/*!< Goto Step 종료	(Goto step end) \n 사용자에 의해 Goto Step하기 위해 종료됨 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> Goto Step 종료 </TD><TD> Goto Step End </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_048					48	/*!< CAN 전압 상한 분기 (CAN voltage upper branch) \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> CAN 전압 상한 분기 </TD><TD> Upper CAN Voltage Limit Section </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_049					49	/*!< CAN 전압 하한 분기	(CAN voltage lower branch) \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> CAN 전압 하한 분기 </TD><TD> Lower CAN Voltage Limit Section </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_050					50	/*!< CAN 온도 상한 분기	(CAN temperature upper branch) \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> CAN 온도 상한 분기 </TD><TD> Upper CAN Temp Limit Section </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_051					51	/*!< CAN 온도 하한 분기	(CAN temperature lower branch) \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> CAN 온도 하한 분기 </TD><TD> Lower CAN Temp Limit Section </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_052					52	/*!< CAN 설정 분기 (CAN setting branch) \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> CAN 설정 분기 </TD><TD> CAN Setting Section </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_053					53	/*!< 외부 전압 상한 분기 (External voltage upper limit branch) \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 외부 전압 상한 분기 </TD><TD> Upper Aux Voltage Limit Section </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_054					54	/*!< 외부 전압 하한 분기 (External voltage lower limit branch) \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 외부 전압 하한 분기 </TD><TD> Lower Aux Voltage Limit Section </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_055					55	/*!< 외부 온도 상한 분기 (External temperature upper limit branch) \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 외부 온도 상한 분기 </TD><TD> Upper Aux Temp Limit Section </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_056					56	/*!< 외부 온도 하한 분기 (External temperature lower limit branch) \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 외부 온도 하한 분기 </TD><TD> Lower Auz Temp Limit Section \n (DB에도 Auz로 오타)</TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_057					57	/*!< 전력량 비율 종료 (WattHour ratio end) \n
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 전력량 비율 종료 </TD><TD> Wattage Rate End </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_058					58	/*!< 합산 용량 종료	(Total capacity end) \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 합산 용량 종료 </TD><TD> Accumulated Capacity End </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_059					59	/*!< 합산 파워 종료	 (Total power end) \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 합산 파워 종료 </TD><TD> Accumulated Power End </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_060					60	/*!< 합산 시간 종료	 (Total time end) \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 합산 시간 종료 </TD><TD> Accumulated Time End </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_061					61	/*!< DAQ 조건 종료 (DAQ condition terminate ) \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> DAQ 조건 종료 </TD><TD> DAQ Condition End </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_062					62	/*!< CAN 조건 종료 (CAN condition terminate ) \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> CAN 조건 종료 </TD><TD> CAN Condition End </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_066					66	/*!< 예약시간 분기 (Reservation time quarter) \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 예약시간 분기 </TD><TD> Reservation Time Quarter </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_080					80	/*!< 공정 종료(시간)	(Test end(Time)) \n 시험 조건의 시간에 의한 공정 완전 종료 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 공정종료(시간) </TD><TD> Process End(Time) </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_081					81	/*!< 공정 종료(전압)	(Test end(Voltage)) \n 시험 조건의 전압에 의한 공정 완전 종료 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 공정종료(전압) </TD><TD> Process End(Voltage) </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_082					82	/*!< 공정 종료(전류)	(Test end(Current)) \n 시험 조건의 전류에 의한 공정 완전 종료 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 공정종료(전류) </TD><TD> Process End(Current) </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_083					83	/*!< 공정 종료(용량)	(Test end(Capacity)) \n 시험 조건의 용량에 의한 공정 완전 종료 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 공정종료(용량) </TD><TD> Process End(Capacity) </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_084					84	/*!< 공정 종료(전력)	(Test end(Watt)) \n 시험 조건의 전력에 의한 공정 완전 종료 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 공정종료(전력) </TD><TD> Process End(Power) </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_085					85	/*!< 공정 종료(전력량) (Test end(WattHour)) \n 시험 조건의 전력량에 의한 공정 완전 종료 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 공정종료(전력량) </TD><TD> Process End(Wattage) </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_087					87	/*!< 챔버연동 대기 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 챔버연동 대기 </TD><TD> Standby Chamber Interlock </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_089					89	/*!< 스케쥴 변경 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 스케쥴 변경 </TD><TD> Change Schedule </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_100					100	/*!< 전압 이상(경고) (Voltage error(Warning)) \n 측정값이 전압 명령값 보다 정격의 1% 높을 경우, 방전은 낮을 경우 (예, 정격 5000mV : 50mV) \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 전압 이상(경고) </TD><TD> Voltage Error(Warning) </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_101					101	/*!< 전류 이상(경고) (Current error(Warning)) \n 측정값이 전류 명령값 보다 정격의 2% 높을 경우, 방전은 낮을 경우 (예, 정격 5000mA : 100mA) \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 전류 이상(경고) </TD><TD> Current Error(Warning) </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_102					102	/*!< 회로 과열(경고) (Circuit overheating error(Warning)) \n 내부 온도 이상 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 회로 과열(경고) </TD><TD> Circuit Overheat(Warning) </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_103					103	/*!< 제어 전원 이상 (Control power error) \n 내부 제어전원 이상 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 제어전원 이상 </TD><TD> Control Power Error </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_104					104	/*!< 강제 종료(Switch) (Force quit(Switch)) \n 장비 Run중 Power Switch로 종료됨 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 강제종료(Switch) </TD><TD> Forced termination(Switch) </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_105					105	/*!< 정전 감지, UPS 입력 전원 이상 (Power outage detection, UPS input power abnormality) \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 정전 감지 </TD><TD> Power Failure Detect </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_106					106	/*!< UPS BATTERY 이상 (UPS battery error) \n UPS Battery 이상 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> UPS BATTERY 이상 </TD><TD> UPS BATTERY Error </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_107					107	/*!< EMG(MAIN)	\n Main Emergency Switch 눌려짐 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> EMG (MAIN) </TD><TD> EMG (MAIN) </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_108					108	/*!< EMG(SUB)	\n Sub Emergency Switch 눌려짐 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> EMG (SUB) </TD><TD> EMG (SUB) </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_109					109	/*!< Network 이상 (Network error) \n Network 통신 이상 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> Network 이상 </TD><TD> Network Error </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_110					110	/*!< 제어 CPU 이상 (CPU error) \n CPU Watchdog 이상 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 제어CPU 이상 </TD><TD> Control CPU Error </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_111					111	/*!< 강제 종료(터미널1) (Force quit(Terminal1)) \n 장비 Run중 Terminal에서 Halt됨 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 강제종료(터미널1) </TD><TD> Forced termination(Terminal1) </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_112					112	/*!< 강제 종료(터미널2) (Force quit(Terminal2)) \n 장비 Run중 Terminal에서 Quit됨 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 강제종료(터미널2) </TD><TD> Forced termination(Terminal2) </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_113					113	/*!< ADC 이상 (ADC error) \n Analog to Digital Converter 이상 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> ADC 이상 </TD><TD> ADC Error </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_114					114	/*!< 채널 전원 이상 (Channel power error) \n 채널 충방전용 전원 이상 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 채널전원 이상 </TD><TD> Channel Power Error </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_115					115	/*!< 채널 제어 전압 Over (Channel control voltage over) \n 제어전원 OV \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 채널제어전압Over </TD><TD> Channel Control Voltage Over </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_116					116	/*!< 채널 제어 전류 Over (Channel control current over) \n 제어전원 OC \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 채널제어전류Over </TD><TD> Channel Control Current Over </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_117					117	/*!< DCOV	\n Inverter Output Over Voltage \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> DCOV </TD><TD> DCOV </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_118					118	/*!< 채널 입력 FUSE 이상 (Channel input FUSE error) \n DC/DC Input Fuse 이상 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 채널입력 FUSE 이상 </TD><TD> Channel Input Fuse Error </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_119					119	/*!< 채널 출력 FUSE 이상 (Channel output FUSE error) \n 출력 Fuse 이상 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 채널출력 FUSE 이상 </TD><TD> Channel Output Fuse Error </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_120					120	/*!< 출력 Reactor 과열 (Output reactor overheating) \n
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 출력 Reactor 과열 </TD><TD> Output Reactor Overheat </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_121					121	/*!< Main 변압기 과열 (Main transformers overheating) \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> Main 변압기 과열 </TD><TD> Main Transforme Overheat </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_122					122	/*!< Main Reactor 과열 (Main reactor overheating) \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> Main Reactor 과열 </TD><TD> Main Reactor Overheat </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_124					124	/*!< range fault \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> range fault </TD><TD> range fault </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_125					125	/*!< 인버터OC \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 인버터OC </TD><TD> Inverter OC </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_126					126	/*!< 인버터ETC \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 인버터ETC </TD><TD> Inverter ETC </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_130					130	/*!< 검사 과전압 (Test voltage over) \n Cell Check에서 OCV가 조건값 보다 클 때 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 검사 과전압 </TD><TD> Cell Check_Over Voltage </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_131					131	/*!< 검사 전압 미달 (Test voltage under) \n Cell Check에서 OCV가 조건값 보다 작을 때 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 검사 전압미달 </TD><TD> Cell Check_Under Voltage </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_132					132	/*!< 검사 전압 상한 (Test voltage upper limit) \n Cell Check에서 전류 인가 중 전압이 조건값 보다 클 때 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 검사 전압상한 </TD><TD> Cell Check_Upper Voltage Limit </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_133					133	/*!< 검사 전압 하한 (Test voltage lower limit) \n Cell Check에서 전류 인가 중 전압이 조건값 보다 작을 때 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 검사 전압하한 </TD><TD> Cell Check_Lower Voltage Limit </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_134					134	/*!< 검사 전류 상한 (Test current upper limit) \n Cell Check에서 전류 인가 중 전류이 조건값 보다 클 때 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 검사 전류상한 </TD><TD> Cell Check_Upper Voltage Limit \n(DB상에도 Voltage로 잘못 등록) </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_135					135	/*!< 검사 전류 하한 (Test current lower limit) \n Cell Check에서 전류 인가 중 전류이 조건값 보다 작을 때 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 검사 전류하한 </TD><TD> Cell Check_Lower Voltage Limit \n(DB상에도 Voltage로 잘못 등록) </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_136					136	/*!< 접촉불량1 (Poor contact1) \n Cell Check에서 CC 전류가 3mA 이하로 흐를 때 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 접촉불량1 </TD><TD> Cell Check_Contact Error1 </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_137					137	/*!< 접촉불량2 (Poor contact2) \n Cell Check에서 전류가 흐를 때 전압이 10mV 이상 낮아질 때 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 접촉불량2 </TD><TD> Cell Check_Contact Error2 </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_138					138	/*!< 접촉불량3 (Poor contact3) \n Cell Check에서 CC 전류가 5mA 이상 낮아질 때 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 접촉불량3 </TD><TD> Cell Check_Contact Error3 </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_139					139	/*!< BadCell1	\n Cell Check에서 전압이 OCV보다 10mV 이상 상승하고, 전류가 3mA 이하로 흐를 때 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> BadCell1 </TD><TD> Cell Check_Bad Cell1 </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_140					140	/*!< BadCell2	\n Cell Check에서 전압이 전압 지령치의 +,-10mV 이내에 있고, 전류가 3mA 이하로 흐를 때 \n
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> BadCell2 </TD><TD> Cell Check_Bad Cell2 </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_141					141	/*!< BadCell3	\n Cell Check에서 전류가 2mA 이하로 흐를 때 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> BadCell3 </TD><TD> Cell Check_Bad Cell3 </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_142					142	/*!< Short	\n Cell Check에서 OCV와 전류 종료전 전압의 차가 조건값 이상 나지 않았을 때 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> Short </TD><TD> Cell Check_Short </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_143					143	/*!< 위치 오류(없음) (Position error(None)) \n 입력위치 정보에 있는데 Check 결과 없음 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 위치오류(없음) </TD><TD> Location Error(None) </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_144					144	/*!< 위치 오류(있음) (Position error(Exist)) \n 입력위치 정보에 없는데 Check 결과 있음 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 위치오류(있음) </TD><TD> Location Error(Exist) </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_160					160	/*!< 전압 상한 (Voltage upper limit) \n 충방전시 전압이 조건값 보다 클 때 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 전압 상한 </TD><TD> Upper Voltage Limit </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_161					161	/*!< 전압 하한 (Voltage lower limit) \n 충방전시 전압이 조건값 보다 작을 때 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 전압 하한 </TD><TD> Lower Voltage Limit </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_162					162	/*!< 전압 변화 상한 (Voltage change upper limit) \n 충방전시 조건 시간당 변화하는 전압이 조건값 보다 클 때 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 전압변화상한 </TD><TD> Upper Voltage Change Limit </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_163					163	/*!< 전압 변화 하한 (Voltage change lower limit) \n 충방전시 조건 시간당 변화하는 전압이 조건값 보다 작을 때 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 전압변화하한 </TD><TD> Lower Voltage Change Limit </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_164					164	/*!< 전압 비교 상한1 (Voltage compare upper limit1) \n 충방전시 조건 시간1에서의 전압이 조건1값 보다 클 때 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 전압비교상한1 </TD><TD> Upper Voltage Compare Limit1 </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_165					165	/*!< 전압 비교 하한1 (Voltage compare lower limit1) \n 충방전시 조건 시간1에서의 전압이 조건1값 보다 작을 때 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 전압비교하한1 </TD><TD> Lower Voltage Compare Limit1 </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_166					166	/*!< OCV 상한 (OCV upper limit) \n OCV 측정시 조건값 보다 클 때 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> OCV상한 </TD><TD> Upper OCV Limit </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_167					167	/*!< OCV 하한 (OCV lower limit) \n OCV 측정시 조건값 보다 작을 때 \n 
												<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> OCV하한 </TD><TD> Lower OCV Limit </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_168					168	/*!< 전류 상한 (Current upper limit) \n 충방전시 전류가 조건값 보다 클 때 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 전류상한 </TD><TD> Upper Current Limit </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_169					169	/*!< 전류 하한 (Current lower limit) \n 충방전시 전류가 조건값 보다 작을 때 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 전류하한 </TD><TD> Lower Current Limit </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_170					170	/*!< 전류 변화 상한 (Current change upper limit) \n 충방전시 조건 시간당 변화하는 전류가 조건값 보다 클 때 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 전류변화상한 </TD><TD> Upper Voltage Change Limit </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_171					171	/*!< 전류 변화 하한 (Current change lower limit) \n 충방전시 조건 시간당 변화하는 전류가 조건값 보다 작을 때 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 전류변화하한 </TD><TD> Lower Voltage Change Limit </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_172					172	/*!< 전류 비교 상한 (Current compare upper limit) \n 충방전시 조건 시간에서의 전류가 조건값 보다 클 때 \n
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 전류비교상한 </TD><TD> Upper Current Compare Limit </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_173					173	/*!< 전류 비교 하한 (Current compare lower limit) \n 충방전시 조건 시간에서의 전류가 조건값 보다 작을 때 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 전류비교하한 </TD><TD> Lower Current Compare Limit </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_174					174	/*!< 용량 상한 (Watt upper limit) \n 충방전시 용량이 조건값 보다 클 때 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 용량상한 </TD><TD> Upper Capacity Limit </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_175					175	/*!< 용량 하한 (Watt lower limit) \n 충방전 종료시 용량이 조건값 보다 작을 때 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 용량하한 </TD><TD> Lower Capacity Limit </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_176					176	/*!< 용량 변화 상한 (Watt change upper limit) \n 충방전시 조건 시간당 변화하는 용량이 조건값 보다 클 때 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 용량변화상한 </TD><TD> Upper Capacity Change Limit </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_177					177	/*!< 용량 변화 하한 (Watt change lower limit) \n 충방전시 조건 시간당 변화하는 용량이 조건값 보다 작을 때 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 용량변화하한 </TD><TD> Lower Capacity Change Limit </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_178					178	/*!< 용량 비교 상한 (Watt compare upper limit) \n 충방전시 조건 시간에서의 용량이 조건값 보다 클 때 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 용량비교상한 </TD><TD> Upper Current Compare Limit \n (DB상에도 Current로 잘못 등록)</TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_179					179	/*!< 용량 비교 하한 (Watt compare lower limit) \n 충방전시 조건 시간에서의 용량이 조건값 보다 작을 때 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 용량비교하한 </TD><TD> Lower Current Compare Limit \n (DB상에도 Current로 잘못 등록)</TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_180					180	/*!< 임피던스 상한 (Impedance upper limit) \n 임피던스 측정시 임피던스가 조건값 보다 클 때 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 임피던스상한 </TD><TD> Upper Impedence Limit </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_181					181	/*!< 임피던스 하한 (Impedance lower limit) \n 임피던스 측정시 임피던스가 조건값 보다 작을 때 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 임피던스하한 </TD><TD> Lower Impedence Limit </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_182					182	/*!< 시간 초과 (Time over) \n 해당 Step 수행 시간이 조건값 보다 클 때 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 시간초과 </TD><TD> Timeout </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_183					183	/*!< 시간 미달 (Time out) \n 해당 Step의 종료시 수행 시간이 조건값 보다 작을 때 \n
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 시간미달 </TD><TD> Time Shortage </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_184					184	/*!< 사용자 완료 (User end) \n 사용자의 작업완료 지령 시 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 사용자완료 </TD><TD> User Command Complete </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_185					185	/*!< 사용자 작업 멈춤 종료 (User test stop end) \n사용자의 작업멈춤 지령이나 외부 Error에 의해 작업멈춤 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 작업멈춤종료 </TD><TD> Operating Stop </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_186					186	/*!< 사용자 다음 Step 종료 (User next step end) \n사용자의 다음Step 지령시 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 다음Step종료 </TD><TD> Next Step End </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_187					187	/*!< 전압 비교 상한2 (Voltage change upper limit2) \n충방전시 조건 시간2에서의 전압이 조건2값 보다 클 때 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 전압비교상한2 </TD><TD> Upper Voltage Compare Limit2 </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_188					188	/*!< 전압 비교 하한2 (Voltage change lower limit2) \n충방전시 조건 시간2에서의 전압이 조건2값 보다 작을 때 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 전압비교하한2 </TD><TD> Lower Voltage Compare Limit2 </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_189					189	/*!< 전압 비교 상한3 (Voltage change upper limit3) \n충방전시 조건 시간3에서의 전압이 조건3값 보다 클 때 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 전압비교상한3 </TD><TD> Upper Voltage Compare Limit3 </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_190					190	/*!< 전압 비교 하한3 (Voltage change lower limit3) \n충방전시 조건 시간3에서의 전압이 조건3값 보다 작을 때 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 전압비교하한3 </TD><TD> Lower Voltage Compare Limit3 </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_191					191	/*!< CC 시간 이상 (CC time error) \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> CC시간 이상 </TD><TD> CC Time Error </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_192					192	/*!< 작업 불량 (Poor operation) \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 작업불량 </TD><TD> Process Failure </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_193					193	/*!< 전류 비교 상한2 (Current change upper limit2) \n충방전시 조건 시간2에서의 전류가 조건2값 보다 클 때 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 전류비교상한2 </TD><TD> Upper Current Compare Limit2 </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_194					194	/*!< 전류 비교 하한2 (Current change lower limit2) \n충방전시 조건 시간2에서의 전류가 조건2값 보다 작을 때 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 전류비교하한2 </TD><TD> Lower Current Compare Limit2 </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_195					195	/*!< 전류 비교 상한3 (Current change upper limit3) \n충방전시 조건 시간3에서의 전류가 조건3값 보다 클 때 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 전류비교상한3 </TD><TD> Upper Current Compare Limit3 </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_196					196	/*!< 전류 비교 하한3 (Current change lower limit3) \n충방전시 조건 시간3에서의 전류가 조건3값 보다 작을 때 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 전류비교하한3 </TD><TD> Lower Current Compare Limit3 </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_197					197	/*!< 온도 상한 (Temperature upper limit) \n온도상한 조건 감지 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 온도상한 </TD><TD> Upper Temp Limit </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_198					198	/*!< 온도 하한 (Temperature lower limit) \n온도하한 조건 감지 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 온도하한 </TD><TD> Lower Temp Limit </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_199					199	/*!< 온도 변화 감지 (Temperature change detect) \n온도변화 조건에 감지 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 온도변화감지 </TD><TD> Temp Change Detect </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_200					200	/*!< 외부 온도 상한 (External temperature upper limit)  \n외부데이터 설정의 온도상한 조건 감지 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 외부 온도상한 </TD><TD> Upper Aux Temp Limit </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_201					201	/*!< 외부 온도 하한 (External temperature lower limit)  \n외부데이터 설정의 온도하한 조건 감지 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 외부 온도하한 </TD><TD> Lower Aux Temp Limit </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_202					202	/*!< 외부 전압 상한 (External voltage upper limit) \n외부데이터 설정의 전압상한 조건 감지 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 외부 전압상한 </TD><TD> Upper Aux Voltage Limit </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_203					203	/*!< 외부 전압 하한 (External voltage lower limit) \n외부데이터 설정의 전압하한 조건 감지 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 외부 전압하한 </TD><TD> Lower Aux Voltage Limit </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_204					204	/*!< CAN 상한 (CAN upper limit) \n CAN데이터 설정의 상한 조건 감지 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> CAN 상한 </TD><TD> Upper CAN Limit </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_205					205	/*!< CAN 하한 (CAN lower limit) \n CAN데이터 설정의 하한 조건 감지 \n 
												<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> CAN 하한 </TD><TD> Lower CAN Limit </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_206					206	/*!< GROUP CYCLE 종료 (Group cycle end) \n GROUP CYCLE 종료 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> GROUP CYCLE 종료 </TD><TD> GROUP CYCLER End \n (DB상에도 CYCLER라고 등록)</TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_207					207	/*!< Capacitance 상한 (Capacitance upper limit) \n 충방전시 Capacitance가 조건값 보다 클 때 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> Capacitance 상한 </TD><TD> Upper Capacitance Limit </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_208					208	/*!< Capacitance 하한 (Capacitance lower limit) \n 충방전시 Capacitance가 조건값 보다 작을 때 \n 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> Capacitance 하한 </TD><TD> Lower Capacitance Limit </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_209					209	/*!< 전력량 상한 (WattHour upper limit) 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 전력량 상한 </TD><TD> Upper Wattage Limit </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_210					210	/*!< 전력량 하한 (WattHour lower limit) 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 전력량 하한 </TD><TD> Lower Wattage Limit </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_211					211	/*!< DAQ 공통조건 감지 (DAQ common condition detect) 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> DAQ 공통조건 감지 </TD><TD> DAQ Common Condition Detect </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_212					212	/*!< CAN 공통조건 감지 (CAN common condition detect)
												<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> CAN 공통조건 감지 </TD><TD> CAN Common Condition Detect </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_213					213	/*!< DAQ 스탭조건 감지 (DAQ step condition detect)
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> DAQ 스탭조건 감지 </TD><TD> DAQ Step Condition Detect </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_214					214	/*!< CAN 스탭조건 감지 (CAN step condition detect)
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> CAN 스탭조건 감지 </TD><TD> CAN Step Condition Detect </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_215					215	/*!< Watt 공통조건 감지 (Watt common condition detection) \n 시험조건 중 공통안전조건의 Watt Upper 시\n
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> Watt 공통조건 감지 </TD><TD> Watt CommonCondition Detect </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_220					220 /*!< 챔버 이상 \n 챔버에 문제가 생겼을 경우 \n
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 챔버 이상 </TD><TD> Chamber Error </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_221					221	/*!< CAN 통신 이상 (CAN communication error) \n CAN Receive 설정을 했는데 2초동안 아무런 데이터도 안들어오면 채널 Pause 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> CAN 통신 이상 </TD><TD> CAN communication Error </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_222					222	/*!< 외부 CAN 연결 장치 이상 (External CAN connecting device error) 
												<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 외부 CAN 연결 장치 이상 </TD><TD> Abnormal Ext CAN connection </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_223					223	/*!< 외부 CAN 명령값 이상 (External CAN command value error) \n 유효 명령 범위를 벗어남 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 외부 CAN 명령값 이상 </TD><TD> Abnormal Ext CAN command </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_224					224	/*!< 외부 CAN 제어기 이상 (External CAN controller error) \n 외부 제어기의 RUN 상태 이상 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 외부 CAN 제어기 이상 </TD><TD> Abnormal Ext CAN controller </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_225					225	/*!< 외부 CAN NM주기 이상 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 외부 CAN NM주기 이상 </TD><TD> Error Ext CAN NM period </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_226					226	/*!< 1구간 편차 이상 (1 sections deviation error) 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 1구간 편차 이상 </TD><TD> Detect Cell Dev.Voltage </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_227					227	/*!< BMS 온도 연동(일시정지) (BMS temperature interlocking (Pause)) \n BMS 온도 데이터가 시험조건 온도 보다 Upper 시 일시정지
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> BMS온도 연동(일시정지) 이상 </TD><TD> Interlock BMS Temp.(pause) </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_228					228	/*!< BMS 온도 연동(작업계속) (BMS temperature interlocking (continued)) \n BMS 온도 데이터가 시험조건 온도 보다 lower 시 작업계속 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> BMS온도 연동(작업계속) </TD><TD> Interlock BMS Temp.(cotinue) </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_229					229	/*!< 전압변화이상 (Voltage change error)
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 전압변화이상 </TD><TD> Abnormal Voltage Change </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_231					231	/*!< 출력프리차징Fail (Output precharging fail)
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 출력프리차징Fail </TD><TD> Export Pre-Charging Fail </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_232					232	/*!< 전류변화이상
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 전류변화이상 </TD><TD> Abnormal Current Change </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_234					234	/*!< 보조전압 상한(AuxV upper limit) \n (default4.6) \n
												*safetyInfo.lVtgCellHigh 안전조건 cell voltage 4.6 \n
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 보조전압 상한(default4.6) </TD><TD> AuxVolt Upper Limit(default4.6) </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_235					235	/*!< AuxT 편차 이상 (AuxT deviation error) 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> AuxT 편차 이상 </TD><TD> AuxT Deviation Abnormal </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_236					236	/*!< AuxTh 편차 이상(AuxTh deviation error)
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> AuxTh 편차 이상 </TD><TD> AuxTh Deviation Abnormal </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_237					237	/*!< AuxT+AuxTh 편차 이상 편차 이상 \n
												*safetyInfo.lVtgCellLow 안전조건 cell voltage 2.0 \n
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> AuxT+AuxTh 편차 이상 </TD><TD> AuxT+AuxTh Deviation Abnormal </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_238					238	/*!< 외부 전압 변화 이상 (AuxV change error)
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 외부 전압 변화 이상 </TD><TD> Ext Volt Change Abnormal </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_239					239	/*!< 보조전압 하한 (AuxV lower limit) 
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 보조전압 하한(default2.0) </TD><TD> AuxVolt Lower Limit(default2.0) </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_240					240	/*!< 2구간 편차 이상 (2 sections deviation error) \n
												*시험조건 중 셀 편차전압 기본 구간 이상 \n
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 2구간 편차 이상 </TD><TD> 2 Section Deviation Abnormal </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_241					241	/*!< 3구간 편차 이상 (3 sections deviation error) \n
												*시험조건 중 셀 3구간 편차전압 이상 시 \n
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 3구간 편차 이상 </TD><TD> 3 Section Deviation Abnormal </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_242					242	/*!< Step 전압 편차 (Step voltage deviation) \n
												*시험조건 중 Step 전압편차 이상 \n
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> Step 전압 편차 </TD><TD> Step Volt Deviation </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_243					243	/*!< CHAMBER EMG
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> CHAMBER EMG </TD><TD> CHAMBER EMG </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_244					244	/*!< CHAMBER DOOR OPEN
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> CHAMBER DOOR OPEN </TD><TD> CHAMBER DOOR OPEN </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_245					245	/*!< CHAMBER ETC ERROR
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> CHAMBER ETC ERROR </TD><TD> CHAMBER ETC ERROR </TD><TD></TD><TD></TD></TR></TABLE>*/

#define CTS_CHANNELCODE_246					246	/*!< 외부데이터 고정 상한
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 비공정 및 공정 상태에서 외부데이터 고정 상한 검출 </TD><TD> No Translated </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_247					247	/*!< 외부데이터 고정 하한
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 비공정 및 공정 상태에서 외부데이터 고정 하한 검출 </TD><TD> No Translated </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_248					248	/*!< VENT 수동 오픈
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> UI 화면의 VENT OPEN 버튼을 눌러 VENT를 수동 오픈 </TD><TD> No Translated </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_249					249	/*!< 외부 습도상한
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 외부데이터 설정의 습도상한 조건 감지 </TD><TD> No Translated </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_250					250	/*!< 외부 습도하한
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 외부데이터 설정의 습도하한 조건 감지 </TD><TD> No Translated </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_68					68	/*!< 외부 습도상한 종료
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 외부데이터 설정의 습도상한 조건에 의해 종료됨 </TD><TD> No Translated </TD><TD></TD><TD></TD></TR></TABLE>*/
#define CTS_CHANNELCODE_69					69	/*!< 외부 습도하한 종료
												*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH><TH></TH><TH></TH></TR><TR><TD> PNE \n Message </TD><TD> 외부데이터 설정의 습도상한 조건에 의해 종료됨 </TD><TD> No Translated </TD><TD></TD><TD></TD></TR></TABLE>*/


/** @} */ //Channel Code 정의 끝