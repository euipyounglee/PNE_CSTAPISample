/** 
 *@file		PSServerAPI_Def.h
 *@brief	PSSeverAPI 함수 정의 헤더 파일 입니다.								
			본 라이브러리(PSServerAPI.lib, PSServerAPI.dll) 사용을 위해서는		
 			host app에서 "PSServerAPI_DEF.h" 파일 include 필요합니다.					
 *@author	PNE Solution (Kang se-jun)
 *@date		2019-03-22
 */

#include "define.h" //define
#include "ChannelItem.h" //모니터링 데이터의 채널 아이템 정의
#include "ChannelCode.h" //채널 상태 코드 정의
#include "Emergency.h" //알람 코드 정의
#include "ResponseCode.h" //충방전기 통신 응답 코드 정의
#include "struct.h" //구조체 정의

//#define CTS_API_VER	"1.0.14" //API 버전 정보
//#define CTS_API_VER	"1.0.15" //API 버전 정보 //ksj 20191212

//#define CTS_API_VER	"1.0.17" //API 버전 정보 //ksj 20200312
//#define CTS_API_VER	"1.0.18" //API 버전 정보 //ksj 20200428
#define CTS_API_VER	"1.0.19" //API 버전 정보 //ksj 20200914

///////////////////////////////////////////////////////////////////////////////////////////////////
#define CTS_DLL_API extern "C" __declspec(dllexport)

/** @defgroup ctsAPI ctsAPI Functions (함수)
 *  @brief 
 *  PNE 충방전기와 통신을 위한 ctsAPI 함수를 정의합니다.
 *  @details
 *
 *  @{
 */
/** @} */ //ctsAPI 기본 그룹 정의 끝

//ctsAPI 하위 그룹 정의 시작
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** @defgroup ctsAPI_group1 1. 초기화
 *  @ingroup ctsAPI
 *  @brief 
 *  PNE 충방전기와 통신을 위한 초기화 함수를 정의합니다.
 *  @{
 */

/**
*@brief		충방전기와의 통신을 위한 Server를 생성합니다.
*@details	설정한 충방전기 모듈 수만큼 접속을 허용하고, Host App의 윈도우 핸들을 받아 Host App에 이벤트 보고를 합니다.
*@param		nInstalledModuleNo	[int]\n
			연결하고자 하는 충방전기 모듈 수.
*@param		hWnd				[HWND]\n
			이벤트를 통지 받을 Host App의 윈도우 핸들.
*@return	FALSE(0), TRUE(1)
*/
CTS_DLL_API int ctsServerCreate(int nInstalledModuleNo, HWND hWnd = NULL);

/**
*@brief		서버를 시작합니다. (Listen)
*@details	ctsServerCreate() 서버 생성 후 최초 1회 호출하여 충방전기가 접속할 수 있도록 Listen을 시작합니다.
*@return	FALSE(0), TRUE(1)
*/
CTS_DLL_API int ctsServerStart();

/**
*@brief		서버를 종료합니다.
*@details	충방전기와의 통신을 끊고 서버를 해제 합니다.
*@return	FALSE(0), TRUE(1)
*/
CTS_DLL_API int ctsServerClose();

/**
*@brief		API 내부의 채널 객체를 초기화 합니다. 
*@details	채널 객체에 할당된 값들을 초기화하여 새 시험을 진행 할 수 있는 상태로 준비합니다.
*@param		nModuleID	[int]\n
			충방전기 모듈의 ModuleID(1-base, ex. module이 1일 경우 1 입력, 3일 경우 3 입력)
*@param		nChIndex	[int]\n
			Channel 0-base, ex. 1번 channel 설정시 0입력, 3번 channel 설정일 경우 2 입력\n
			nChIndex는 여러 채널을 선택 할 수 없습니다.
*/
CTS_DLL_API void ctsInitChannel(int nModuleID, int nChIndex);



/** @} */ //ctsAPI_group1 함수 정의 끝


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** @defgroup ctsAPI_group2 2. 시스템 정보 확인 및 설정
 *  @ingroup ctsAPI
 *  @brief 
 *  시스템 정보를 확인하거나 설정하는 ctsAPI 함수를 정의합니다.
 *  @{
 */

/** @} */ // ctsAPI_group2 함수 정의 끝

////////////////////////////////////////////////////////////////////////////
/** @defgroup ctsAPI_group2_AUX 1) AUX 확인 및 설정
 *  @ingroup ctsAPI_group2
 *  @brief 
 *  시스템 정보를 확인하거나 설정하는 ctsAPI 함수를 정의합니다.
 *  @{
 */

/**
*@brief		충방전기로 Aux Data 설정을 전송한다. (2020-01-14 갱신)
*@details	충방전기로 Aux Data 설정을 전송한다.\n
*			******사용을 권장하지 않습니다*****\n
*			기존 API 형식 호환성 유지를 위해 남겨놓았으나, ctsSendAuxData_V2 또는 ctsSendAuxData_V3 사용을 권장합니다.\n
            본 API는 ctsSendAuxData_V2(nModuleID, pAuxData, 1) API로 DataCount를 1로 고정하여 전달하는 역할만 합니다.\n
*@param		nModuleID	[int]\n
			충방전기 모듈의 ModuleID(1-base, ex. module이 1일 경우 1 입력, 3일 경우 3 입력)
*@param		pAuxData	[CTS_MD_AUX_SET_DATA*]\n
			Aux 설정 구조체 주소
*@return	\ref ResponseCode [int] 충방전기 Response Code
*/
CTS_DLL_API int ctsSendAuxData(UINT nModuleID, CTS_MD_AUX_SET_DATA* pAuxData);

/**
*@brief		충방전기로 Aux Data 설정을 전송한다. (2020-01-14 추가)
*@details	충방전기로 Aux Data 설정을 전송한다.\n
*			
*@param		nModuleID	[int]\n
			충방전기 모듈의 ModuleID(1-base, ex. module이 1일 경우 1 입력, 3일 경우 3 입력)
*@param		pAuxData	[CTS_MD_AUX_SET_DATA*]\n
			Aux 설정 구조체, (최대 512개의 구조체 Array 포인터 전달)\n
			\n
			ctsSendAuxData_V2는 입력받은 구조체 배열의 AuxType과 AuxChNo가 일치하는 외부 센서 데이터를 찾아 해당 데이터만 갱신합니다.\n			
			Aux 설정 구조체의 AuxCh과 AuxType을 정확히 지정해야 해당 Aux 찾아 갱신합니다.\n
			\n
			<b>*주의* 본 API를 사용하여 Aux 설정시 다른 Aux API와 달리 CTS_MD_AUX_SET_DATA 값에 대해 예외적으로 동작합니다.</b>\n
			ctsSendAuxData_V2 : 센서 값 (온도/써미스터: 1000 == 1℃, Voltage: uV)\n
			본 함수로 설정시 AuxType(2) 써미스터의 경우, 1000 == 1℃로 동작합니다. (default: 1000000 == 1℃)\n
			본 함수로 설정시 AuxType(2) 써미스터의 경우 AuxChNo가 1-base로 시작됩니다. (default: MaxAuxV+1)\n

			
*@param		nDataCount	[int]\n
			전송할 AuxData 개수 지정.\n
			pAuxData로 전달하는 데이터 Array 개수를 지정.
			정확히 명시 하지 않는 경우 overflow 발생 가능성있습니다.\n

*@return	\ref ResponseCode [int] 충방전기 Response Code
*/
CTS_DLL_API int ctsSendAuxData_V2(UINT nModuleID, CTS_MD_AUX_SET_DATA* pAuxData, int nDataCount = 1);

//너무 많은 함수가 생겨 유지보수를 위해 제거/정리
#if 0
/**
*@brief		충방전기로 Aux Data 설정을 전송한다. (2020-01-14 추가)
*@details	충방전기로 Aux Data 설정을 전송한다.\n
*			
*@param		nModuleID	[int]\n
			충방전기 모듈의 ModuleID(1-base, ex. module이 1일 경우 1 입력, 3일 경우 3 입력)
*@param		pAuxData	[CTS_MD_AUX_SET_DATA*]\n
			Aux 설정 구조체, (최대 512개의 구조체 Array 포인터 전달)\n
			\n
			ctsSendAuxData_V3는 입력받은 구조체 배열의 AuxType과 AuxChNo가 일치하는 외부 센서 데이터를 찾아 해당 데이터만 갱신합니다.\n			
			Aux 설정 구조체의 AuxCh과 AuxType을 정확히 지정해야 해당 Aux 찾아 갱신합니다.\n
			\n
			ctsSendAuxData_V3 : 센서 값 (온도: 1000 == 1℃, Voltage: uV, 온도: 1000000 == 1℃) \n
			본 함수로 설정시 AuxType(2) 써미스터의 경우, 1000000 == 1℃로 동작합니다.\n
			본 함수로 설정시 AuxType(2) 써미스터의 경우 AuxChNo가 MaxAuxVch+1로 시작합니다. (예: AuxV(auxType(1))가 30채널인 경우 AuxTh(auxType(2))는 AuxChNo = 31 부터 시작합니다.)\n
			
*@param		nDataCount	[int]\n
			전송할 AuxData 개수 지정.\n
			pAuxData로 전달하는 데이터 Array 개수를 지정.
			정확히 명시 하지 않는 경우 overflow 발생 가능성있습니다.\n

*@return	\ref ResponseCode [int] 충방전기 Response Code
*/
CTS_DLL_API int ctsSendAuxData_V3(UINT nModuleID, CTS_MD_AUX_SET_DATA* pAuxData, int nDataCount = 1);
#endif

/**
*@brief		충방전기로 Aux Data 설정을 전송한다. (2020-01-14 이전 방식, 기존의 ctsSendAuxData() 함수에 해당)
*@details	충방전기로 Aux Data 설정을 전송한다.\n
*			512개의 전체 Aux 채널 설정 정보를 한번에 전송.
*@param		nModuleID	[int]\n
			충방전기 모듈의 ModuleID(1-base, ex. module이 1일 경우 1 입력, 3일 경우 3 입력)
*@param		pAuxData	[CTS_MD_AUX_SET_DATA*]\n
			Aux 설정 구조체, (512개의 구조체 Array 포인터 전달)
*@return	\ref ResponseCode [int] 충방전기 Response Code
*/
CTS_DLL_API int ctsSendAuxData_Org(UINT nModuleID, CTS_MD_AUX_SET_DATA* pAuxData);




/**
*@brief		충방전기로 Aux Data 설정을 전송한다. (v1016 ~, 2020-04 추가)
*@details	충방전기로 Aux Data 설정을 전송한다.\n
*			512개의 전체 Aux 채널 설정 정보를 한번에 전송.\n
*			ctsSendAuxData_Org의 v1016 버전 함수.
*@param		nModuleID	[int]\n
			충방전기 모듈의 ModuleID(1-base, ex. module이 1일 경우 1 입력, 3일 경우 3 입력)
*@param		pAuxData	[CTS_MD_AUX_SET_DATA_16*]\n
			Aux 설정 구조체, (512개의 구조체 Array 포인터 전달)
*@return	\ref ResponseCode [int] 충방전기 Response Code
*/
CTS_DLL_API int ctsSendAuxData16(UINT nModuleID, CTS_MD_AUX_SET_DATA_16* pAuxData);


/**
*@brief		충방전기로 Aux Data 설정을 전송한다. (v1016 ~ , 2020-04 추가)
*@details	충방전기로 Aux Data 설정을 전송한다.\n
*			
*@param		nModuleID	[int]\n
			충방전기 모듈의 ModuleID(1-base, ex. module이 1일 경우 1 입력, 3일 경우 3 입력)
*@param		pAuxData	[CTS_MD_AUX_SET_DATA_16*]\n
			Aux 설정 구조체, (최대 512개의 구조체 Array 포인터 전달)\n
			\n
			ctsSendAuxData16_V2는 입력받은 구조체 배열의 AuxType과 AuxChNo가 일치하는 외부 센서 데이터를 찾아 해당 데이터만 갱신합니다.\n			
			Aux 설정 구조체의 AuxCh과 AuxType을 정확히 지정해야 해당 Aux 찾아 갱신합니다.\n
			\n
			<b>*주의* 본 API를 사용하여 Aux 설정시 다른 Aux API와 달리 CTS_MD_AUX_SET_DATA_16 값에 대해 예외적으로 동작합니다.</b>\n
			ctsSendAuxData16_V2 : 센서 값 (온도/써미스터: 1000 == 1℃, Voltage: uV)\n
			본 함수로 설정시 AuxType(2) 써미스터의 경우, 1000 == 1℃로 동작합니다. (default: 1000000 == 1℃)\n
			본 함수로 설정시 AuxType(2) 써미스터의 경우 AuxChNo가 1-base로 시작됩니다. (default: MaxAuxV+1)\n
			본 함수로 설정시 AuxType(3) 습도 경우 AuxChNo가 1-base로 시작됩니다. (default: MaxAuxV+MaxAuxTh+1)\n

			
*@param		nDataCount	[int]\n
			전송할 AuxData 개수 지정.\n
			pAuxData로 전달하는 데이터 Array 개수를 지정.
			정확히 명시 하지 않는 경우 overflow 발생 가능성있습니다.\n

*@return	\ref ResponseCode [int] 충방전기 Response Code
*/
CTS_DLL_API int ctsSendAuxData16_V2(UINT nModuleID, CTS_MD_AUX_SET_DATA_16* pAuxData, int nDataCount = 1);


/**
*@brief		충방전기의 모든 Aux를 할당된 채널에서 해제한다.
*@details	충방전기의 모든 Aux를 할당된 채널에서 해제한다.\n
*			API 내부적으로 ctsGetAuxInfoData_V2 호출하여 512개의 전체 Aux 정보를 가져온 뒤,\n
*			각 Aux정보의 chNo 값을 모두 0으로 바꾸어 Master Channel을 미지정상태로 초기화 한다.
*			초기화 한 512개의 데이터를 다시 ctsSendAuxData_Org() 를 호출하여 값을 쓴다.
*           chNo 외의 모든 값은 그대로 유지.
*@param		nModuleID	[int]\n
			충방전기 모듈의 ModuleID(1-base, ex. module이 1일 경우 1 입력, 3일 경우 3 입력)
*@return	\ref ResponseCode [int] 충방전기 Response Code
*/
CTS_DLL_API int ctsReleaseAllAux(UINT nModuleID);


/**
*@brief		Aux 정보 확인

*@details	충방전기 모듈의 Aux 정보를 확인합니다. (V100D~V1015)
*@param		nModuleID	[int]\n
			충방전기 모듈의 ModuleID(1-base, ex. module이 1일 경우 1 입력, 3일 경우 3 입력)
			*@return	요청한 모듈 Aux 정보 구조체 [CTS_MD_AUX_INFO_DATA] \n
			구조체 갯수 1개
*/
CTS_DLL_API CTS_MD_AUX_INFO_DATA* ctsGetAuxInfoData(int nModuleID);

/**
*@brief		Aux 정보 확인

*@details	충방전기 모듈의 Aux 정보를 확인합니다. (V100D~V1015)
*@param		nModuleID	[int]\n
			충방전기 모듈의 ModuleID(1-base, ex. module이 1일 경우 1 입력, 3일 경우 3 입력)
			*@return	요청한 모듈 Aux 정보 구조체 [CTS_MD_AUX_INFO_DATA_V2] \n
			구조체 갯수 1개
*/
CTS_DLL_API CTS_MD_AUX_INFO_DATA_V2* ctsGetAuxInfoData_V2(int nModuleID);

/**
*@brief		Aux 정보 확인
*@details	충방전기 모듈의 Aux 정보를 확인합니다. (V1016~)
*@param		nModuleID	[int]\n
			충방전기 모듈의 ModuleID(1-base, ex. module이 1일 경우 1 입력, 3일 경우 3 입력)
			*@return	요청한 모듈 Aux 정보 구조체 [CTS_MD_AUX_INFO_DATA_16] \n
			구조체 갯수 1개
*/
CTS_DLL_API CTS_MD_AUX_INFO_DATA_16* ctsGetAuxInfoData16(int nModuleID);


/**
*@brief		Aux Data 확인
*@details	충방전기 모듈의 Aux Data를 확인합니다.
*@param		nModuleID	[int]\n
			충방전기 모듈의 ModuleID(1-base, ex. module이 1일 경우 1 입력, 3일 경우 3 입력)
*@param		nChIndex	[int]\n
			충방전기 모듈의 ChannelIndex(1-base, ex. 1번일 경우 1 입력, 3일 경우 3 입력)\n
			nChIndex는 여러 채널을 선택 할 수 없습니다.
*@return	요청한 모듈 Aux Data 구조체 주소 [CTS_AUX_DATA*] \n
			구조체 최대 갯수 512개(첫 번째 인자인 auxChNo가 0일때까지 read)\n
			nChIndex는 여러 채널을 선택 할 수 없습니다.
*/
CTS_DLL_API CTS_AUX_DATA* ctsGetAuxData(int nModuleID, int nChIndex);


/** @} */ // ctsAPI_group2_AUX 함수 정의 끝

////////////////////////////////////////////////////////////////////////////
/** @defgroup ctsAPI_group2_AUX 1) AUX 확인 및 설정
 *  @ingroup ctsAPI_group2
 *  @brief 
 *  시스템 정보를 확인하거나 설정하는 ctsAPI 함수를 정의합니다.
 *  @{
 */



/** @} */ // ctsAPI_group2_AUX 함수 정의 끝
////////////////////////////////////////////////////////////////////////////
/** @defgroup ctsAPI_group2_CAN 2) CAN 확인 및 설정
 *  @ingroup ctsAPI_group2
 *  @brief 
 *  시스템 정보를 확인하거나 설정하는 ctsAPI 함수를 정의합니다.
 *  @{
 */

/**
*@brief		충방전기로 Can Rx Data 설정을 전송한다.
*@details	충방전기로 Can Rx Data 설정을 전송한다.\n
*			
*@param		nModuleID	[int]\n
			충방전기 모듈의 ModuleID(1-base, ex. module이 1일 경우 1 입력, 3일 경우 3 입력)
*@param		nChIndex	[int]\n
			충방전기 모듈의 ChannelIndex(bitflag, ex. 3번 channel 설정일 경우 4(bit : 0000 0100) 입력)\n
			단, nChIndex는 여러 채널을 선택 할 수 없습니다. 한비트 단위로 선택 가능.
*@param		szTxPath	[char*]\n
			Setting 할 Receive csv file full path \n
*@param		nCanClear	[BOOL]\n
			CAN 정보 삭제
*@return	\ref ResponseCode [int] 충방전기 Response Code
*/
CTS_DLL_API int ctsSetRxCANData(UINT nModuleID, int nChIndex, char *szRxPath, BOOL nCanClear);


/**
*@brief		충방전기로 Can 전송 Data 설정을 전송한다.
*@details	충방전기로 Can 전송 Data 설정을 전송한다.\n
*			
*@param		nModuleID	[int]\n
			충방전기 모듈의 ModuleID(1-base, ex. module이 1일 경우 1 입력, 3일 경우 3 입력)
*@param		nChIndex	[int]\n
			충방전기 모듈의 ChannelIndex(bitflag, ex. 3번 channel 설정일 경우 4(bit : 0000 0100) 입력)\n
			단, nChIndex는 여러 채널을 선택 할 수 없습니다. 한비트 단위로 선택 가능.
*@param		szTxPath	[char*]\n
			Setting 할 Transmit csv file full path \n
*@param		nCanClear	[BOOL]\n
			CAN 정보 삭제
*@return	\ref ResponseCode [int] 충방전기 Response Code
*/
CTS_DLL_API int ctsSetTxCANData(UINT nModuleID, int nChIndex, char* szTxPath, BOOL nCanClear);



/**
*@brief		CAN RX 정보 확인
*@details	충방전기 모듈의 CAN RX 정보를 확인합니다.
*@param		nModuleID	[int]\n
			충방전기 모듈의 ModuleID(1-base, ex. module이 1일 경우 1 입력, 3일 경우 3 입력)
*@return	요청한 모듈 CAN RX 정보 구조체 \n
			구조체 최대 갯수 1개
*/
CTS_DLL_API CTS_MD_CAN_RECV_INFO_DATA* ctsGetCanRxInfoData(int nModuleID);

/**
*@brief		CAN TX 정보 확인
*@details	충방전기 모듈의 CAN TX 정보를 확인합니다.
*@param		nModuleID	[int]\n
			충방전기 모듈의 ModuleID(1-base, ex. module이 1일 경우 1 입력, 3일 경우 3 입력)
*@return	요청한 모듈 CAN TX 정보 구조체 주소 \n
			구조체 최대 갯수 1개
*/
CTS_DLL_API CTS_MD_CAN_TRANS_INFO_DATA* ctsGetCanTxInfoData(int nModuleID);


/** @} */ // ctsAPI_group2_CAN 함수 정의 끝

////////////////////////////////////////////////////////////////////////////
/** @defgroup ctsAPI_group2_ETC 3) 시스템 등 기타 설정
 *  @ingroup ctsAPI_group2
 *  @brief 
 *  시스템 정보를 확인하거나 설정하는 ctsAPI 함수를 정의합니다.
 *  @{
 */

/**
*@brief		Log 파일 기록을 위한 경로를 설정합니다.
*@details	Log 기록시 설정된 경로에 파일을 생성합니다.\n
*			경로를 지정하지 않는 경우 Log 파일이 생성되지 않습니다.
*			경로가 존재하지 않는 경우 Log 파일이 생성되지 않습니다.
*/
CTS_DLL_API void ctsSetLogPath(char* szLogPath);


/**
*@brief		충방전기 모듈 정보 확인
*@details	충방전기 모듈의 정보를 확인합니다.
*@param		nModuleID	[int]		충방전기 모듈의 ModuleID(1-base, ex. module이 1일 경우 1 입력, 3일 경우 3 입력)
*@return	요청한 모듈 정보 구조체 주소 [CTS_MD_SYSTEM_DATA*]  \n
			구조체 최대 갯수 1개
*/
CTS_DLL_API CTS_MD_SYSTEM_DATA* ctsGetModuleSysData(int nModuleID);



/**
*@brief		설정된 충방전기 모듈의 수를 확인합니다.
*@details	ctsServerCreate에서 설정한 최대 허용 모듈의 수를 확인합니다.
*@return	설정된 충방전기 모듈 수 [int]
*/
CTS_DLL_API int ctsGetInstalledModuleNum();

/**
*@brief		충방전기 모듈의 IP를 확인합니다.
*@details	접속된 충방전기 모듈의 IP를 확인합니다.
*@return	IP Address [char*]
*/
CTS_DLL_API char* ctsGetIPAddress(int nModuleID);

/**
*@brief		충방전기에 시스템 정보를 전송합니다.
*@details	초기 접속시 충방전기에 시스템 정보를 1회 전송해야합니다.
*@param		nModuleIndex	[int]\n
			dll 내부 sturcture info를 설정하기 위한 충방전기 모듈 ModuleIndex(0-base, module이 1일 경우 0 입력, 3일 경우 2 입력)
*@param		nModuleID		[int]\n
			실제 충방전기 모듈의 ModuleID(1-base, ex. module이 1일 경우 1 입력, 3일 경우 3 입력)
*@param		pSysParam		[void*]\n
			충방전기 모듈에 전송할 시스템 파라미터 구조체 포인터 
*@return	\ref ResponseCode [int] 충방전기 Response Code
*/
CTS_DLL_API int ctsSetSysParam(int nModuleIndex, int nModuleID, CTS_SYSTEM_PARAM* pSysParam);


/**
*@brief		충방전기의 시스템 정보를 확인합니다.
*@details	초기 접속시 설정된 시스템 정보를 확인합니다.
*@param		nModuleID	[int]\n
			충방전기 모듈의 ModuleID(1-base, ex. module이 1일 경우 1 입력, 3일 경우 3 입력)
*@return	시스템 파라미터 구조체 [CTS_SYSTEM_PARAM*] \n
			구조체 최대 갯수 1개
*/
CTS_DLL_API CTS_SYSTEM_PARAM* ctsGetSysParam(int nModuleID);

/**
*@brief		충방전기 Response Code 확인
*@details	충방전기에 명령전송 후 수신된 Response Code를 문자열 메세지로 변환합니다.
*@param		nCode	[int]\n
			SendCommand Response Code
*@return	문자열 메세지
*/
CTS_DLL_API char* ctsCmdFailMsg(int nCode);


/**
*@brief		API 버전 정보 확인
*@details	API 버전 정보를 확인 합니다.
*@return	API 버전 정보 문자열\n
*			ex) ctsAPI v1.0.0 [build: 2019-03-22]
*/
CTS_DLL_API char* ctsGetAPIVer();

/**
*@brief		충방전기 통신 프로토콜 버전 확인
*@details	충방전기 모듈의 통신 프로토콜 버전 확인합니다.
*@param		nModuleID	[int]\n
			충방전기 모듈의 ModuleID(1-base, ex. module이 1일 경우 1 입력, 3일 경우 3 입력)
*@return	요청한 모듈의 충방전기 통신 프로토콜 버전\n
*			ex) 0x100D, 0x100F 등
*/
CTS_DLL_API UINT ctsGetProtocolVer(int nModuleID);

/**
*@brief		통신 Error Code 확인
*@details	통신 Error Code를 문자열 메세지로 변환합니다.\n
			ctsGetLastError()로 Error Code를 얻어올 수 있습니다.
*@param		nErrorCode	[int]\n
			통신 Error Code
*@return	문자열 메세지
*/
CTS_DLL_API char* ctsGetErrorString(int nErrorCode);

/**
*@brief		마지막 통신 Error Code를 확인
*@details	마지막 통신 Error Code를 확인합니다.\n
			ctsGetErrorString()로 문자열 에러 메세지를 얻을 수 있습니다.
*@return	Error Code
*/
CTS_DLL_API int ctsGetLastError();


/**
*@brief		PC 시간 기준으로 설비 시간을 동기화.
*@details	PC 시간 기준으로 설비 시간을 동기화합니다.\n
			가동중인 채널이 있는 경우 동기화 되지 않으며,
			본 명령 호출시 PC 시간 기준으로 설비 시간이 변경되므로, 신중하게 호출해야 합니다.
*@return	Error Code
*/
CTS_DLL_API int ctsSendTimeSyncData(UINT nModuleID);

/** @} */ // ctsAPI_group2_ETC 함수 정의 끝



////////////////////////////////////////////////////////////////////////////
/** @defgroup ctsAPI_group2_LIN 4) LIN 확인 및 설정
 *  @ingroup ctsAPI_group2
 *  @brief 
 *  시스템 정보를 확인하거나 설정하는 ctsAPI 함수를 정의합니다.
 *  @{
 */

/**
*@brief		충방전기로 LIN Data 설정을 전송.
*@details	설정한 충방전기 모듈과 채널의 LIN to CAN 통신 쓰레드를 시작합니다.
*@param		nModuleID	[int]\n
			충방전기 모듈의 ModuleID(1-base, ex. module이 1일 경우 1 입력, 3일 경우 3 입력)
*@param		nChIndex	[int]\n
			충방전기 모듈의 ChannelIndex(1-base, ex. 1번일 경우 1 입력, 3일 경우 3 입력)\n
			nChIndex는 여러 채널을 선택 할 수 없습니다.
*@param		strPathName				[char*]		LIN 설정 file full path.
*			
*@return	\ref ResponseCode [int] 충방전기 Response Code
*/
CTS_DLL_API int ctsSetLINData(UINT nModuleID, int nChIndex, char* strPath);


/**
*@brief		충방전기에 사용가능한 LIN 갯수를 수신
*@details	충방전기에 연결된 LIN의 Channel 갯수를 수신한다.\n
*			
*@return	[int] LIN Channel갯수(0 : 연결된 LIN 없음)
*/
CTS_DLL_API int ctsGetLINInstalled();



/** @} */ // ctsAPI_group2_LIN 함수 정의 끝
////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/** @defgroup ctsAPI_group3 3. 작업 시작 및 스케쥴 전송
 *  @ingroup ctsAPI
 *  @brief 
 *  시험 데이터 확인 및 처리를 위한 ctsAPI 함수를 정의합니다.
 *  @{
 */

/**
*@brief		충방전기에 스케쥴(레시피)를 전송합니다.
*@details	충방전기의 단일 또는 다수개의 채널에 스케쥴(레시피)를 전송합니다.\n
*			bit flag on 채널에 대해서 명령을 수행합니다.
*@param		nModuleID	[UINT]\n
*			명령을 전송할 충방전기의 ModuleID(1-base, ex. module이 1일 경우 1 입력, 3일 경우 3 입력)
*@param		nBitLCh					[int]\n
*			Channel Bit Flag 1~32CH (LSB)\n
			nBitLCh는 여러 채널 선택이 가능합니다.
*@param		nBitHCh					[int]\n
*			Channel Bit Flag 33~64CH (LSB)\n
			nBitHCh는 여러 채널 선택이 가능합니다.
*@param		szSchPath				[char*]\n
*			schedule file full path
*@param		nCANCheckOption			[int]\n
*			Can 체크 모드, 0 : 해제 , 1 : M + S, 2 : Master, 3: Slave
*@param		nChamberOperation		[int]\n
*			0 : 연동 안함, 1 : 연동
*@return	\ref ResponseCode	[int] 충방전기 Response Code
*/
CTS_DLL_API int ctsSendSchedule(UINT nModuleID, int nBitLCh, int nBitHCh = 0, char* szSchPath = NULL, int nCANCheckOption = 0, int nChamberOperation = 0);




/**
*@brief		충방전기에 스케쥴(레시피)를 전송합니다.
*@details	충방전기의 단일 또는 다수개의 채널에 스케쥴(레시피)를 전송합니다.\n
*			bit flag on 채널에 대해서 명령을 수행합니다.
*@param		nModuleID	[UINT]\n
*			명령을 전송할 충방전기의 ModuleID(1-base, ex. module이 1일 경우 1 입력, 3일 경우 3 입력)
*@param		nBitLCh					[int]\n
*			Channel Bit Flag 1~32CH (LSB)\n
			nBitLCh는 여러 채널 선택이 가능합니다.
*@param		nBitHCh					[int]\n
*			Channel Bit Flag 33~64CH (LSB)\n
			nBitHCh는 여러 채널 선택이 가능합니다.
*@param		szSchPath				[char*]\n
*			schedule file full path
*@param		nCANCheckOption			[int]\n
*			Can 체크 모드, 0 : 해제 , 1 : M + S, 2 : Master, 3: Slave
*@param		nChamberOperation		[int]\n
*			0 : 연동 안함, 1 : 연동
*@param		nCycle		[int]\n
*			스케줄을 건너뛰고 중간부터 시작할 사이클 번호를 지정합니다. (스케쥴의 사이클 번호를 정확히 입력해야 합니다.)
*@param		nStep		[int]\n
*			스케줄을 건너뛰고 중간부터 시작할 스텝 번호를 지정합니다. (스케쥴의 스텝 번호를 정확히 입력해야 합니다.)
*@return	\ref ResponseCode	[int] 충방전기 Response Code
*/
CTS_DLL_API int ctsSendSchedule_V2(UINT nModuleID, int nBitLCh, int nBitHCh = 0, char *szSchPath = NULL, int nCANCheckOption = 0, int nChamberOperation = 0, int nCycle = 0, int nStep = 0);
CTS_DLL_API int ctsSendSchedule_Org(UINT nModuleID, int nBitLCh, int nBitHCh = 0, char* szSchPath = NULL, int nCANCheckOption = 0, int nChamberOperation = 0, int nCycle = 0, int nStep = 0);

/**
*@brief		충방전기에 간이 충방전 조건을 전송합니다.
*@details	충방전기의 단일 또는 다수개의 채널에 간이 충방전 조건을 전송합니다.\n
*			간단한 충전 또는 방전 시험을 실행합니다.\n
*			bit flag on 채널에 대해서 명령을 수행합니다.
*@param		nModuleID	[UINT]\n
*			명령을 전송할 충방전기의 ModuleID(1-base, ex. module이 1일 경우 1 입력, 3일 경우 3 입력)
*@param		nBitLCh					[int]\n
*			Channel Bit Flag 1~32CH (LSB)\n
			nBitLCh는 여러 채널 선택이 가능합니다.
*@param		nBitHCh					[int]\n
*			Channel Bit Flag 33~64CH (LSB)\n
			nBitHCh는 여러 채널 선택이 가능합니다.
*@param		nStepCount			[int]\n
*			Max 1~100 개 까지 가능
			전송하고자하는 스텝 조건 개수를 지정합니다.
*@param		pStepInfo*			[CTS_SIMPLE_TEST_INFO]\n
*			전송하고자하는 스텝 정보 구조체 포인터, 배열의 개수는 StepCount에 지정한 개수와 일치해야 합니다.
*			*주의* 스텝 조건을 정확히 입력하지 않는 경우 오작동할 수 있습니다.
*@return	\ref ResponseCode	[int] 충방전기 Response Code
*/
CTS_DLL_API int ctsSendSimpleTest(UINT nModuleID, int nBitLCh, int nBitHCh=0, int nStepCount=0, CTS_SIMPLE_TEST_INFO* pStepInfo = NULL);

/** @} */ //ctsAPI_group3 함수 정의 끝




////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** @defgroup ctsAPI_group4 4. 제어 명령 전송
 *  @ingroup ctsAPI
 *  @brief 
 *  PNE 충방전기 제어를 위한 ctsAPI 함수를 정의합니다.
 *  @{
 */



/**
*@brief		명령 예약 상태 확인
*@details	현재 스텝 종료 후 일시정지 또는 정지 예약이 되어있는지 상태를 확인합니다.
*			\n현재 스텝이 종료된 뒤 예약된 플래그에 따라 일시정지 또는 정지됩니다.
*@param		nModuleID	[int]\n
			충방전기의 ModuleID(1-base, ex. module이 1일 경우 1 입력, 3일 경우 3 입력)
*@param		nChIndex	[int]\n
			충방전기 모듈의 ChannelIndex(0-base, ex. 3번 channel 설정일 경우 2 입력)\n
			nChIndex는 여러 채널을 선택 할 수 없습니다.
*@return	None(0), Stop(1), Pause(2)
*/
CTS_DLL_API int ctsGetReservedCmd(int nModuleID, int nChIndex);


/**
*@brief		충방전기에 작업 일시 정지 명령을 전송합니다.
*@details	충방전기의 단일 또는 다수개의 채널에 일시 정지 명령을 전송합니다.\n
*			bit flag on 채널에 대해서 명령을 수행합니다.
*@param		nModuleID		[UINT]\n
*			명령을 전송할 충방전기의 ModuleID(1-base, ex. module이 1일 경우 1 입력, 3일 경우 3 입력)
*@param		nBitLCh				[int]\n
*			Channel Bit Flag 1~32CH (LSB) \n
			nBitLCh는 여러 채널 선택이 가능합니다.
*@param		nBitHCh				[int]\n
*			Channel Bit Flag 33~64CH (LSB) \n
			nBitHCh는 여러 채널 선택이 가능합니다.
*@param		nCycleNo			[int]\n
*			0이 아닌 값을 지정할 경우 지정한 사이클 이후에 일시정지 시킵니다.
*@param		nStepNo				[int]\n
*			0이 아닌 값을 지정할 경우 지정한 스텝 이후에 일시정지 시킵니다.
*@return	\ref ResponseCode	[int] 충방전기 Response Code
*/
CTS_DLL_API int ctsSendPause(UINT nModuleID,  int nBitLCh, int nBitHCh = 0, int nCycleNo = 0, int nStepNo = 0);

/**
*@brief		충방전기에 예약된 일시정지 명령을 취소합니다.
*@details	충방전기에 예약된 일시정지 명령을 취소합니다.\n
*			bit flag on 채널에 대해서 명령을 수행합니다.
*@param		nModuleID			[UINT]\n
*			명령을 전송할 충방전기의 ModuleID(1-base, ex. module이 1일 경우 1 입력, 3일 경우 3 입력)
*@param		nBitLCh				[int]\n
*			Channel Bit Flag 1~32CH (LSB)\n
			nBitLCh는 여러 채널 선택이 가능합니다.
*@param		nBitHCh				[int]\n
*			Channel Bit Flag 33~64CH (LSB)\n
			nBitHCh는 여러 채널 선택이 가능합니다.
*@return	\ref ResponseCode	[int] 충방전기 Response Code
*/
CTS_DLL_API int ctsSendPauseCancel(UINT nModuleID,  int nBitLCh, int nBitHCh = 0);

/**
*@brief		충방전기에 작업 정지 명령을 전송합니다.
*@details	충방전기의 단일 또는 다수개의 채널에 정지 명령을 전송합니다. (2020-08-20 이전 방식, 기존의 오리지널 ctsSendStop()에 해당)\n 
*			bit flag on 채널에 대해서 명령을 수행합니다.
*@param		nModuleID			[UINT]\n
*			명령을 전송할 충방전기의 ModuleID(1-base, ex. module이 1일 경우 1 입력, 3일 경우 3 입력)
*@param		nBitLCh				[int]\n
*			Channel Bit Flag 1~32CH (LSB)\n
			nBitLCh는 여러 채널 선택이 가능합니다.
*@param		nBitHCh				[int]\n
*			Channel Bit Flag 33~64CH (LSB)\n
			nBitHCh는 여러 채널 선택이 가능합니다.
*@param		nCycleNo			[int]\n
*			0이 아닌 값을 지정할 경우 지정한 사이클 이후에 정지 시킵니다.
*@param		nStepNo				[int]\n
*			0이 아닌 값을 지정할 경우 지정한 스텝 이후에 정지 시킵니다.
*@return	\ref ResponseCode	[int] 충방전기 Response Code
*/
CTS_DLL_API int ctsSendStopImmediate(UINT nModuleID,  int nBitLCh, int nBitHCh = 0, int nCycleNo = 0, int nStepNo = 0);


/**
*@brief		충방전기에 작업 정지 명령을 전송합니다.
*@details	충방전기의 단일 또는 다수개의 채널에 정지 명령을 전송합니다.\n
*			bit flag on 채널에 대해서 명령을 수행합니다.\n
*			안정적인 작업 정지를 위해, 채널에 Pause 명령(ctsSendPause)을 전송하고\n
*			정상적으로 Pause가 된 경우에 Stop을 실시합니다.\n
*@param		nModuleID			[UINT]\n
*			명령을 전송할 충방전기의 ModuleID(1-base, ex. module이 1일 경우 1 입력, 3일 경우 3 입력)
*@param		nBitLCh				[int]\n
*			Channel Bit Flag 1~32CH (LSB)\n
			nBitLCh는 여러 채널 선택이 가능합니다.
*@param		nBitHCh				[int]\n
*			Channel Bit Flag 33~64CH (LSB)\n
			nBitHCh는 여러 채널 선택이 가능합니다.
*@param		nCycleNo			[int]\n
*			0이 아닌 값을 지정할 경우 지정한 사이클 이후에 정지 시킵니다.
*@param		nStepNo				[int]\n
*			0이 아닌 값을 지정할 경우 지정한 스텝 이후에 정지 시킵니다.
*@return	\ref ResponseCode	[int] 충방전기 Response Code
*/
CTS_DLL_API int ctsSendStop(UINT nModuleID,  int nBitLCh, int nBitHCh = 0, int nCycleNo = 0, int nStepNo = 0);

/**
*@brief		충방전기에 예약된 정지 명령을 취소합니다.
*@details	충방전기에 예약된 정지 명령을 취소합니다.\n
*			bit flag on 채널에 대해서 명령을 수행합니다.
*@param		nModuleID			[UINT]\n
*			명령을 전송할 충방전기의 ModuleID(1-base, ex. module이 1일 경우 1 입력, 3일 경우 3 입력)
*@param		nBitLCh				[int]\n
*			Channel Bit Flag 1~32CH (LSB)\n
			nBitLCh는 여러 채널 선택이 가능합니다.
*@param		nBitHCh				[int]\n
*			Channel Bit Flag 33~64CH (LSB)\n
			nBitHCh는 여러 채널 선택이 가능합니다.
*@return	\ref ResponseCode	[int] 충방전기 Response Code
*/
CTS_DLL_API int ctsSendStopCancel(UINT nModuleID,  int nBitLCh, int nBitHCh = 0);

/**
*@brief		충방전기에 작업 작업 계속 명령을 전송합니다.
*@details	충방전기의 단일 또는 다수개의 채널에 작업 계속 명령을 전송합니다.\n
*			bit flag on 채널에 대해서 명령을 수행합니다.
*@param		nModuleID			[UINT]\n
*			명령을 전송할 충방전기의 ModuleID(1-base, ex. module이 1일 경우 1 입력, 3일 경우 3 입력)
*@param		nBitLCh				[int]\n
*			Channel Bit Flag 1~32CH (LSB)\n
			nBitLCh는 여러 채널 선택이 가능합니다.
*@param		nBitHCh				[int]\n
*			Channel Bit Flag 33~64CH (LSB)\n
			nBitHCh는 여러 채널 선택이 가능합니다.
*			0 : 일시 중지시 계속, 1 : Chamber 연동 중지시 계속
*@return	\ref ResponseCode	[int] 충방전기 Response Code
*/
CTS_DLL_API int ctsSendContinue(UINT nModuleID,  int nBitLCh, int nBitHCh = 0, int nContinueOption = 0);



/**
*@brief		충방전기에 작업 다음 스텝 실행 명령을 전송합니다.
*@details	충방전기의 단일 또는 다수개의 채널에 다음 스텝 실행 명령을 전송합니다.\n
*			bit flag on 채널에 대해서 명령을 수행합니다.
*@param		nModuleID			[UINT]\n
*			명령을 전송할 충방전기의 ModuleID(1-base, ex. module이 1일 경우 1 입력, 3일 경우 3 입력)
*@param		nBitLCh				[int]\n
*			Channel Bit Flag 1~32CH (LSB)\n
			nBitLCh는 여러 채널 선택이 가능합니다.
*@param		nBitHCh				[int]\n
*			Channel Bit Flag 33~64CH (LSB)\n
			nBitHCh는 여러 채널 선택이 가능합니다.
*@return	\ref ResponseCode	[int] 충방전기 Response Code
*/
CTS_DLL_API int ctsSendNextStep( UINT nModuleID,  int nBitLCh, int nBitHCh = 0);




/**
*@brief		충방전기에 이동 스텝 명령을 전송합니다.
*@details	충방전기의 단일 또는 다수개의 채널에 특정 스텝으로의 이동 명령을 전송합니다.\n
*			bit flag on 채널에 대해서 명령을 수행합니다.
*@param		nModuleID			[UINT]\n
*			명령을 전송할 충방전기의 ModuleID(1-base, ex. module이 1일 경우 1 입력, 3일 경우 3 입력)
*@param		nBitLCh				[int]\n
*			Channel Bit Flag 1~32CH (LSB)\n
			nBitLCh는 여러 채널 선택이 가능합니다.
*@param		nBitHCh				[int]\n
*			Channel Bit Flag 33~64CH (LSB)\n
			nBitHCh는 여러 채널 선택이 가능합니다.
*@param		nStepNo				[int]\n
*			지정한 스텝으로 이동합니다.
*@return	\ref ResponseCode	[int] 충방전기 Response Code
*/
CTS_DLL_API int ctsSendGotoStep( UINT nModuleID,  int nBitLCh, int nBitHCh = 0, int nStepNo = 0);

/**
*@brief		충방전기에 절연/비절연 분기 명령을 전송합니다. (검사기 전용)
*@details	충방전기의 단일  채널에 충방전기에 절연/비절연 분기 명령을 전송합니다. (검사기 타입 전용)\n
*			예) 1번 모듈 2번 채널 절연 방법\n
			ctsSendIso(1,1,0,0); //절연 (3번째가 0으로 비절연이어도, 4번째 인자가 0이면 절연)\n
			ctsSendIso(1,1,1); //절연 (3번째 인자 1로 절연)\n
			\n
			예) 1번 모듈 2번 채널 비절연 방법\n
			ctsSendIso(1,1,0,1); //비절연 (3번째가 0으로 비절연이며, 4번째가 1로 A분기 비절연)\n
			ctsSendIso(1,1,0); //비절연 (3번째가 0으로 비절연)\n

*@param		nModuleID			[UINT]\n
*			명령을 전송할 충방전기의 ModuleID(1-base, ex. module이 1일 경우 1 입력, 3일 경우 3 입력)
*@param		nChannelIndex	[int]\n
			충방전기 모듈의 ChannelIndex(0-base, ex. Channel이 1일 경우 0 입력, 3일 경우 2 입력) \n
			nChIndex는 여러 채널을 선택 할 수 없습니다.
*@param		bISO				[BYTE]\n
*			0: 비절연 실행,   1: 절연 실행\n
*@param		bDivCh				[BYTE]\n
*			출력 채널(분기 A, B) 정보 1(A),2(B)  (0이면 절연)\n
*			기본 값 : 1 (A분기)\n
*@return	\ref ResponseCode	[int] 충방전기 Response Code
*/
CTS_DLL_API int ctsSendIso(UINT nModuleID, int nChannelIndex, BYTE bISO, BYTE bDivCh = 1);

/**
*@brief		충방전기에 절연/비절연 분기 명령을 전송합니다. (검사기 전용)
*@details	충방전기의 단일 채널에 충방전기에 절연/비절연 명령을 전송합니다. (검사기 타입 전용)\n
*			예) 1번 모듈 2번 채널 절연 방법\n			
			ctsSendIso(1,1,1); //절연 (3번째 인자 1로 절연)\n
			\n
			예) 1번 모듈 2번 채널 비절연 방법\n			
			ctsSendIso(1,1,0); //비절연 (3번째가 0으로 비절연)\n

*@param		nModuleID			[UINT]\n
*			명령을 전송할 충방전기의 ModuleID(1-base, ex. module이 1일 경우 1 입력, 3일 경우 3 입력)
*@param		nChannelIndex	[int]\n
			충방전기 모듈의 ChannelIndex(0-base, ex. Channel이 1일 경우 0 입력, 3일 경우 2 입력) \n
			nChIndex는 여러 채널을 선택 할 수 없습니다.
*@param		bISO				[BYTE]\n
*			0: 비절연 실행,   1: 절연 실행\n
*@return	\ref ResponseCode	[int] 충방전기 Response Code
*/
CTS_DLL_API int ctsSendIsoNormal(UINT nModuleID, int nChannelIndex, BYTE bISO);


/**
*@details	충방전기의 단일 또는 다수개의 채널에 고정 상한 안전 정지 Clear 명령을 보냅니다..\n
*			bit flag on 채널에 대해서 명령을 수행합니다.\n
*			신규(v1015) 고정상한 안전조건에 의해 설비가 일시정지 된 경우 Clear 명령을 내려주어야 재동작 가능합니다.\n
*			고정상한 안전조건이 동작하는 경우 설비 사양에 따라 챔버 Ventilator를 Open 하고 내부 가스를 배출합니다.\n
*			본 API를 호출하는 경우 에러 상태를 초기화하고 챔버 Ventilator를 Close 합니다.
*@param		nModuleID			[UINT]\n
*			명령을 전송할 충방전기의 ModuleID(1-base, ex. module이 1일 경우 1 입력, 3일 경우 3 입력)
*@param		nBitLCh				[int]\n
*			Channel Bit Flag 1~32CH (LSB)\n
			nBitLCh는 여러 채널 선택이 가능합니다.
*@param		nBitHCh				[int]\n
*			Channel Bit Flag 33~64CH (LSB)\n
			nBitHCh는 여러 채널 선택이 가능합니다.
*@param		nFlag				[int]\n
*			0(Default) : Close(Clear),  1: Open\n			
			(v1015에서는 Clear만 동작, V1016은 Close 및 Open 가능)\n
			
*@return	\ref ResponseCode	[int] 충방전기 Response Code
*/
CTS_DLL_API int ctsSendVentClear( UINT nModuleID, int nBitLCh, int nBitHCh = 0, int nFlag = 0);


/**
*@brief		충방전기에 Capacity Bank On/Off 명령을 전송합니다. (v1015~)
*@details	충방전기의 단일 또는 다수개의 채널에 Capacity Bank On/Off 명령을 전송합니다.\n
*			bit flag on 채널에 대해서 명령을 수행합니다.\n
*			CBank 사양 적용된 설비에서만 동작합니다.\n
*			주의!! 배터리 연결을 반드시 해제 후 설정하세요.\n
*@param		nModuleID			[UINT]\n
*			명령을 전송할 충방전기의 ModuleID(1-base, ex. module이 1일 경우 1 입력, 3일 경우 3 입력)
*@param		nBitLCh				[int]\n
*			Channel Bit Flag 1~32CH (LSB)\n
			nBitLCh는 여러 채널 선택이 가능합니다.
*@param		nBitHCh				[int]\n
*			Channel Bit Flag 33~64CH (LSB)\n
			nBitHCh는 여러 채널 선택이 가능합니다.
*@param		nFlag				[int]\n
*			0(Default) : off,  1: On\n						
*@return	\ref ResponseCode	[int] 충방전기 Response Code
*/
CTS_DLL_API int ctsSendCBank( UINT nModuleID, int nBitLCh, int nBitHCh = 0, int nFlag = 0);

/** @} */ //ctsAPI_group4 함수 정의 끝

CTS_DLL_API int ctsSendCommand(UINT nCmd, UINT nModuleID,  int nBitLCh, int nBitHCh = 0, LPVOID lpData = NULL, UINT nSize = 0, UINT nRetryCount = 5);
CTS_DLL_API int ctsSendCommandCh(UINT nCmd, UINT nModuleID, UINT nChannelIndex, LPVOID lpData = NULL, UINT nSize = 0, UINT nRetryCount = 5);


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/** @defgroup ctsAPI_group5 5. 데이터 확인 및 처리
 *  @ingroup ctsAPI
 *  @brief 
 *  시험 데이터 확인 및 처리를 위한 ctsAPI 함수를 정의합니다.
 *  @{
 */

/**
*@brief		현재 충방전기 채널의 모니터링 데이터를 확인합니다.
*@details	선택 채널의 특정 항목의 값을 확인할 수 있습니다.
*@param		nModuleID		[int]\n
			명령을 전송할 충방전기의 ModuleID(1-base, ex. module이 1일 경우 1 입력, 3일 경우 3 입력)
*@param		nChannelIndex	[int]\n
			충방전기 모듈의 ChannelIndex(0-base, ex. Channel이 1일 경우 0 입력, 3일 경우 2 입력) \n
			nChIndex는 여러 채널을 선택 할 수 없습니다.
*@param		nItem			[int]\n
			\ref ChannelItem
*@return	요청한 모니터링 항목의 현재 값 [long], 0인 경우 장비 접속 안 되어 있음
*/
CTS_DLL_API long ctsGetChannelValue(int nModuleID, int nChannelIndex, int nItem);

/**
*@brief		현재 충방전기 채널의 상태 코드를 확인합니다.
*@details	선택 채널의 상태 코드를 확인할 수 있습니다.
*@param		nModuleID	[int]\n
			명령을 전송할 충방전기의 ModuleID(1-base, ex. module이 1일 경우 1 입력, 3일 경우 3 입력)
*@param		nChIndex	[int]\n
			충방전기 모듈의 ChannelIndex(1-Base, ex. 3번 channel 설정일 경우 3 입력) \n
			nChIndex는 여러 채널을 선택 할 수 없습니다.
*@return	\ref define_state_ch [int]	요청한 채널의 상태 코드
*/
CTS_DLL_API int ctsGetChannelState(int nModuleID, int nChIndex);

/**
*@brief		현재 충방전기 채널의 모니터링 데이터를 확인합니다.
*@details	선택 채널의 모든 데이터를 구조체 형식으로 확인합니다.
*@param		nModuleID	[int]\n
			명령을 전송할 충방전기의 ModuleID(1-base, ex. module이 1일 경우 1 입력, 3일 경우 3 입력)
*@param		nChIndex	[int]\n
			충방전기 모듈의 ChannelIndex(1-Base, ex. 3번 channel 설정일 경우 3 입력) \n
			nChIndex는 여러 채널을 선택 할 수 없습니다.
*@return	요청한 채널의 모니터링 데이터의 구조체 메모리 주소 반환 [CTS_VARIABLE_CH_DATA*]  \n
			구조체 최대 갯수 1개
*/
CTS_DLL_API CTS_VARIABLE_CH_DATA* ctsGetRealChData(int nModuleID, int nChIndex);

/**
*@brief		충방전기 모듈의 상태 확인
*@details	충방전기 모듈의 상태 code를 확인합니다.
*@param		ModuleID	[int]\n
			충방전기 모듈의 ModuleID(1-base, ex. module이 1일 경우 1 입력, 3일 경우 3 입력)
*@return	\ref define_state [int]	상태 Code			
*/
CTS_DLL_API int ctsGetModuleState(int ModuleID);

/**
*@brief		메모리 큐 저장 데이터 꺼내기
*@details	API 내부의 데이터 Queue 에서 데이터를 1개 Pop 합니다.\n
*			충방전기로부터 기록조건에 따라 수신한 데이터를 API는 내부 Queue에 저장합니다.\n
*			최대 저장 데이터 Size는 600개이며, 스택에 데이터가 가득 찬 경우 이후 데이터는 버려질 수 있습니다.
*@param		nModuleID	[int]\n
			충방전기 모듈의 ModuleID(1-base, ex. module이 1일 경우 1 입력, 3일 경우 3 입력)
*@param		nChIndex	[int]\n
			충방전기 모듈의 ChannelIndex(1-base, ex. Channel이 1번인 경우 1 입력, 3일 경우 3 입력) \n
			nChIndex는 여러 채널을 선택 할 수 없습니다.
*@param		pSaveChData	[CTS_VARIABLE_CH_DATA*] 	\n데이터를 Pop해서 저장할 구조체의 포인터 입력
*@return	pop 할 data 없으면 FALSE(0), pop 할 data가 있으면 TRUE(1)
*/
CTS_DLL_API int ctsPopSaveData(int nModuleID, int nChIndex, CTS_VARIABLE_CH_DATA* pSaveChData);

/**
*@brief		Stack 에 쌓인 데이터 개수 확인
*@details	기록조건에 의해 충방전기로부터 수신받은 데이터가 쌓인 Queue의 Size를 확인합니다.\n
*			Queue Size를 상시 확인하여, 적절한 시점에 ctsPopSaveData() 를 호출하여 데이터를 Pop 해주어야합니다.
*			Queue의 최대 저장 데이터 Size는 600개이며, 데이터가 가득 찬 경우 이후 데이터는 버려질 수 있습니다.
*			
*@param		nModuleID	[int]\n
			충방전기 모듈의 ModuleID(1-base, ex. module이 1일 경우 1 입력, 3일 경우 3 입력)
*@param		nChIndex	[int]\n
			충방전기 모듈의 ChannelIndex(1-base, ex. Channel이 1번인 경우 1 입력, 3일 경우 3 입력) \n
			nChIndex는 여러 채널을 선택 할 수 없습니다.
*@return	Queue에 보관된 Data Size [int] \n
			잘못된 채널 참조시 0-return;
*/
CTS_DLL_API int ctsGetStackedDataSize(int nModuleID, int nChIndex);

/**
*@brief		특정 스케쥴 파일의 지정 스텝 정보를 확인합니다.
*@details	특정 스케쥴 파일의 지정 스텝 정보(기본 정보)를 확인합니다.\n
*			모든 정보를 포함하지 않으며, 주요 기본 정보들을 포함합니다.\n
*@param		pStepInfo				[CTS_SCH_STEP_INFO*] 	\n데이터를 Pop해서 저장할 구조체의 포인터 입력
*@param		szSchPath				[char*]\n
*			schedule file full path
*@param		nStepIndex				[int]\n
*			확인하고자 하는 스텝 번호를 입력합니다. (0-base, nStepIndex)
*@return	실패(0), 성공(1)
*/
CTS_DLL_API int ctsGetSchStepInfo(CTS_SCH_STEP_INFO* pStepInfo, char* szSchPath, int nStepIndex);

/**
*@brief		특정 스케쥴 파일의 지정 스텝 정보를 확인합니다.
*@details	특정 스케쥴 파일의 지정 스텝 정보를 확인합니다.\n
*
*@param		szSchPath				[char*]\n
*			schedule file full path
*@return	StepCount [int] \n 스케쥴 파일에 기록되어있는 스텝의 수를 리턴합니다.
*/
CTS_DLL_API int ctsGetSchStepCount(char* szSchPath);

/**
*@brief		특정 스케쥴 파일에 포함된 셀밸런싱기 연동에 관련한 정보를 확인합니다.
*@details	특정 스케쥴 파일에 포함된 셀밸런싱기 연동에 관련한 정보를 확인합니다.\n
*			sch 파일에 포함된 셀밸런싱기 정보를 확인합니다.\n
*			CB 연동 스텝 개수만큼 가변적인 메모리 공간을 할당하하여 포인터로 리턴하므로,\n
*			사용이후에는 ctsReleaseSchAllStepCBInfo()를 호출하여 메모리를 해제 해주어야합니다.\n
*			해제하지 않고 반복 호출하는 경우 메모리 누수가 발생할 수 있습니다.\n
*@param		szSchPath				[char*]\n
*			schedule file full path
*@param		pnStepCount				[int*]\n
*			pnStepCount로 리턴하는 CB스텝 구조체의 개수를 전달 합니다. 전달 받을 변수의 주소를 넘겨주어야 합니다.
*@return	요청한 sch 파일에 포함된 CB스텝 수만큼의 CB조건 구조체 포인터 리턴 [CTS_SCH_EXT_CB_INFO*]
*/
CTS_DLL_API CTS_SCH_EXT_CB_INFO* ctsGetSchAllStepCBInfo(char* szSchPath, int* pnStepCount);

/**
*@brief		호출한 셀밸런싱 스텝 정보를 메모리에서 해제합니다.
*@details	호출한 셀밸런싱 스텝 정보를 메모리에서 해제합니다.\n
*			ctsGetSchAllStepCBInfo() 함수는 CB 연동 스텝 개수만큼 가변적인 메모리 공간을 할당하여 리턴하므로,\n
*			사용이후에는 ctsReleaseSchAllStepCBInfo()를 호출하여 메모리를 해제 해주어야합니다.\n
*			해제하지 않고 반복 호출하는 경우 메모리 누수가 발생할 수 있습니다.\n
*@param		pExtCbInfo				[CTS_SCH_EXT_CB_INFO*] 	\n메모리에서 제거할 구조체 포인터 입력.
*@return	실패(0), 성공(1)
*/
CTS_DLL_API int ctsReleaseSchAllStepCBInfo(CTS_SCH_EXT_CB_INFO* pExtCbInfo);

/** @} */ //ctsAPI_group5 함수 정의 끝


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/** @defgroup ctsAPI_group6 6. 병렬 설정 및 정보 확인
 *  @ingroup ctsAPI
 *  @brief 
 *  시험 데이터 확인 및 처리를 위한 ctsAPI 함수를 정의합니다.
 *  @{
 */

/**
*@brief		충방전기에 병렬 설정을 전송합니다.
*@details	충방전기의 다수개의 채널에 병렬 설정을 전송합니다.\n
*			ParallelOption 에 대해서 명령을 수행합니다.
*@param		nModuleID	[UINT]\n
*			명령을 전송할 충방전기의 ModuleID(1-base, ex. module이 1일 경우 1 입력, 3일 경우 3 입력)
*@param		nMaster		[int]\n
*			Channel base, ex. 3번 channel 설정일 경우 3 입력
*@param		nSlave		[int]\n
			충방전기 모듈의 ChannelIndex(0-base, ex. 3번 channel 설정일 경우 4(bit : 0000 0100) 입력)\n
			(nChIndex는 여러 채널을 선택 할 수 있음. \n
			단, 짝수개의 Slave는 설정 불가, ex Master ch:1, Slave ch:2 or ch:2,3,4 로 설정해야 함, Slave ch : 2,3으로 설정 불가)
*@param		nParallelOption		[int]\n
*			0 : 병렬 해제, 1 : 병렬 설정
*@return	\ref ResponseCode [int] 충방전기 Response Code
*/
CTS_DLL_API int ctsSetParallelData(UINT nModuleID, int nMaster, int nSlave, int nParallelOption = 0);

/**
*@brief		병렬 모드 정보 확인
*@details	충방전기 모듈의 병렬 모드 상태를 확인합니다.
*@param		nModuleID	[int]\n
			충방전기 모듈의 ModuleID(1-base, ex. module이 1일 경우 1 입력, 3일 경우 3 입력)
*@return	요청한 모듈 병렬 정보 구조체 \n
			구조체 최대 갯수 8개(첫 번째 인자인 chNoMaster가 0일때까지 read)
*/
CTS_DLL_API CTS_MD_PARALLEL_DATA* ctsGetParallelData(int nModuleID);

/** @} */ //ctsAPI_group6 함수 정의 끝


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/** @defgroup ctsAPI_group7 7. Callback 함수(Notify message)
 *  @ingroup ctsAPI
 *  @brief 
 *  통지 이벤트 관련 callback 함수를 정의합니다.
 *  @{
 */

/**
*@brief		충방전기 접속 이벤트 
*@details	충방전기와의 접속이 되었음을 수신합니다.
*@param		nModuleID	[int]\n
			충방전기 모듈의 ModuleID(1-base, Moudle ID가 1일 경우 1, 3일 경우 3)
*@param		sysInfo		[CTS_MD_SYSTEM_DATA*]\n
			충방전기 시스템 정보 구조체
*@return	null
*/
typedef void(*CALLBACK_CONNECTED)(int nModuleID , CTS_MD_SYSTEM_DATA* sysInfo);
CTS_DLL_API void __stdcall CallbackConnected(CALLBACK_CONNECTED handler);

/**
*@brief		충방전기 접속 종료 이벤트
*@details	충방전기와의 접속이 해제 되었음을 수신합니다.
*@param		nModuleID	[int]\n
			충방전기 모듈의 ModuleID
*@return	null
*/
typedef void(*CALLBACK_CLOSED)(int nModuleID);
CTS_DLL_API void __stdcall CallbackClosed(CALLBACK_CLOSED handler);

/**
*@brief		채널 stack data 이벤트
*@details	Stack에 저장된 data를 꺼내지 않을 경우 저장된 데이터가 삭제 됩니다.
*@param		nModuleID	[int]\n
			충방전기 모듈의 ModuleID(1-base, Moudle ID가 1일 경우 1, 3일 경우 3)
*@param		nChIndex	[int]\n
			충방전기 모듈의 ChannelIndex(1-base, Channel Index가 1번일 경우 1, 3번일 경우 3)
*@return	null 
*/
typedef void(*CALLBACK_STACKNOTIFY)(int nModuleID , int nChIndex);
CTS_DLL_API void __stdcall CallbackStackNotify(CALLBACK_STACKNOTIFY handler);

/**
*@brief		채널 데이터 이벤트
*@details	실시간 채널 데이터를 수신합니다.
*@param		nModIDandChIdex	[unsigned int]\n
			상위 4바이트 : Channel Index (0-base), 하위 4바이트 : Module ID (1-base)\n\n
			예) 모듈1번의 1번채널\n
			  Module ID : 1   (1-Base)\n
			  Channel Index : 0  (0-Base)\n
			  값 : 0x0000 0001  (1)\n\n

			  모듈1번의 2번채널\n
			  Module ID : 1   (1-Base)\n
			  Channel Index : 1  (0-Base)\n
			  값 : 0x0001 0001  (65537)\n\n

			  모듈2번의 2번채널\n
			  Module ID : 2   (1-Base)\n
			  Channel Index : 1  (0-Base)\n
			  값 : 0x0001 0002  (65538)\n\n

			  
*@param		sysInfo			[CTS_VARIABLE_CH_DATA*]\n
			Channel data 구조체
*@return	null 
*/
typedef void(*CALLBACK_CHDATA)(unsigned int nModIDandChIdex , CTS_VARIABLE_CH_DATA* ChData);
CTS_DLL_API void __stdcall CallbackChData(CALLBACK_CHDATA handler);


/**
*@brief		채널 데이터 이벤트
*@details	실시간 채널 데이터를 수신합니다.
*@param		nModIDandChIdex	[unsigned int]\n
			상위 4바이트 : Channel Index (0-base), 하위 4바이트 : Module ID (1-base)\n\n
			예) 모듈1번의 1번채널\n
			  Module ID : 1   (1-Base)\n
			  Channel Index : 0  (0-Base)\n
			  값 : 0x0000 0001  (1)\n\n

			  모듈1번의 2번채널\n
			  Module ID : 1   (1-Base)\n
			  Channel Index : 1  (0-Base)\n
			  값 : 0x0001 0001  (65537)\n\n

			  모듈2번의 2번채널\n
			  Module ID : 2   (1-Base)\n
			  Channel Index : 1  (0-Base)\n
			  값 : 0x0001 0002  (65538)\n\n

*@param		sysInfo			[CTS_VARIABLE_CH_DATA_D*]\n
			Channel data 구조체
*@return	null 
*/
typedef void(*CALLBACK_CHDATA_D)(unsigned int nModIDandChIdex , CTS_VARIABLE_CH_DATA_D* ChData);
CTS_DLL_API void __stdcall CallbackChData_D(CALLBACK_CHDATA_D handler);


/**
*@brief		채널 데이터 이벤트
*@details	실시간 채널 데이터를 수신합니다.
*@param		nModIDandChIdex	[unsigned int]\n
			상위 4바이트 : Channel Index (0-base), 하위 4바이트 : Module ID (1-base)\n\n
			예) 모듈1번의 1번채널\n
			  Module ID : 1   (1-Base)\n
			  Channel Index : 0  (0-Base)\n
			  값 : 0x0000 0001  (1)\n\n

			  모듈1번의 2번채널\n
			  Module ID : 1   (1-Base)\n
			  Channel Index : 1  (0-Base)\n
			  값 : 0x0001 0001  (65537)\n\n

			  모듈2번의 2번채널\n
			  Module ID : 2   (1-Base)\n
			  Channel Index : 1  (0-Base)\n
			  값 : 0x0001 0002  (65538)\n\n

*@param		sysInfo			[CTS_VARIABLE_CH_DATA_F*]\n
			Channel data 구조체
*@return	null 
*/
typedef void(*CALLBACK_CHDATA_F)(unsigned int nModIDandChIdex , CTS_VARIABLE_CH_DATA_F* ChData);
CTS_DLL_API void __stdcall CallbackChData_F(CALLBACK_CHDATA_F handler);

/**
*@brief		테스트 스텝 완료 이벤트
*@details	테스트가 종료된 채널의 스텝 번호 이벤트를 수신합니다.
*@param		nModIDandChIdex	[int]\n
			상위 4바이트 : Channel Index (0-base), 하위 4바이트 : Module ID (1-base)\n\n
			예) 모듈1번의 1번채널\n
			  Module ID : 1   (1-Base)\n
			  Channel Index : 0  (0-Base)\n
			  값 : 0x0000 0001  (1)\n\n

			  모듈1번의 2번채널\n
			  Module ID : 1   (1-Base)\n
			  Channel Index : 1  (0-Base)\n
			  값 : 0x0001 0001  (65537)\n\n

			  모듈2번의 2번채널\n
			  Module ID : 2   (1-Base)\n
			  Channel Index : 1  (0-Base)\n
			  값 : 0x0001 0002  (65538)\n\n

*@param		nStepNum	[int]\n
			테스트가 끝난 step의 번호
*@return	null
*/
typedef void(*CALLBACK_STEPENDDATARECEIVE)(int nModIDandChIdex , int nStepNum);
CTS_DLL_API void __stdcall CallbackStepEndDataReceive(CALLBACK_STEPENDDATARECEIVE handler);

/**
*@brief		테스트 완료 이벤트
*@details	테스트가 종료된 채널의 이벤트를 수신합니다.
*@param		nModuleID	[int]\n
			충방전기 모듈의 ModuleID(1-base, Moudle ID가 1일 경우 1, 3일 경우 3)
*@param		nChIndex	[int]\n
			충방전기 모듈의 ChannelIndex(1-base, Channel Index가 1번일 경우 1, 3번일 경우 3)
*@return	null
*/
typedef void(*CALLBACK_TESTCOMPLETE)(int nModuleID , int nChIndex);
CTS_DLL_API void __stdcall CallbackTestComplete(CALLBACK_TESTCOMPLETE handler);

/**
*@brief		비상 알람 이벤트
*@details	충방전기 비상 알람 이벤트를 수신합니다.
*@param		nModuleID	[int] \n
			충방전기 모듈의 ModuleID(1-base, Moudle ID가 1일 경우 1, 3일 경우 3)
*@param		emgData		[CTS_EMG_DATA*] \n
			충방전기 비상 알람 구조체
*@return	null
*/
typedef void(*CALLBACK_EMERGENCY)(int nModuleID, CTS_EMG_DATA* emgData);
CTS_DLL_API void __stdcall CallbackEmergency(CALLBACK_EMERGENCY handler);


/**
*@brief		채널 pause 이벤트
*@details	장비가 puase state인 경우의 이벤트를 수신합니다.
*@param		nModuleID	[int]\n
			충방전기 모듈의 ModuleID(1-base, Moudle ID가 1일 경우 1, 3일 경우 3)
*@param		nChIndex	[int]\n
			충방전기 모듈의 ChannelIndex(1-base, Channel Index가 1번일 경우 1, 3번일 경우 3)
*@return	null 
*/
typedef void(*CALLBACK_PAUSE)(int nModuleID , int nChIndex);
CTS_DLL_API void __stdcall CallbackPause(CALLBACK_PAUSE handler);


/** @} */ //ctsAPI_group7 함수 정의 끝

//ctsAPI 하위 그룹 정의 끝


////////////////////////////////////////////////////////////////////////
//API 인터페이스 테스트용 DEBUG 디버그 함수 정의 시작
CTS_DLL_API DEBUG_TEST* ctsApiDebugPtrStruct(DEBUG_TEST* pDebug1);
CTS_DLL_API DEBUG_TEST ctsApiDebugStruct(DEBUG_TEST stDebug1);
CTS_DLL_API int ctsApiDebugInteger(int nA);
CTS_DLL_API char* ctsApiDebugString(char* szString);
CTS_DLL_API CTS_EMG_DATA* ctsApiDebugPtrStruct2(CTS_EMG_DATA* pDebug1); //CTS 구조체 테스트
//디버그 함수 정의 끝
////////////////////////////////////////////////////////////////////////