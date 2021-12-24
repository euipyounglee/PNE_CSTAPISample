/** 
 *@file		PSServerAPI_Def.h
 *@brief	PSSeverAPI �Լ� ���� ��� ���� �Դϴ�.								
			�� ���̺귯��(PSServerAPI.lib, PSServerAPI.dll) ����� ���ؼ���		
 			host app���� "PSServerAPI_DEF.h" ���� include �ʿ��մϴ�.					
 *@author	PNE Solution (Kang se-jun)
 *@date		2019-03-22
 */

#include "define.h" //define
#include "ChannelItem.h" //����͸� �������� ä�� ������ ����
#include "ChannelCode.h" //ä�� ���� �ڵ� ����
#include "Emergency.h" //�˶� �ڵ� ����
#include "ResponseCode.h" //������� ��� ���� �ڵ� ����
#include "struct.h" //����ü ����

//#define CTS_API_VER	"1.0.14" //API ���� ����
//#define CTS_API_VER	"1.0.15" //API ���� ���� //ksj 20191212

//#define CTS_API_VER	"1.0.17" //API ���� ���� //ksj 20200312
//#define CTS_API_VER	"1.0.18" //API ���� ���� //ksj 20200428
#define CTS_API_VER	"1.0.19" //API ���� ���� //ksj 20200914

///////////////////////////////////////////////////////////////////////////////////////////////////
#define CTS_DLL_API extern "C" __declspec(dllexport)

/** @defgroup ctsAPI ctsAPI Functions (�Լ�)
 *  @brief 
 *  PNE �������� ����� ���� ctsAPI �Լ��� �����մϴ�.
 *  @details
 *
 *  @{
 */
/** @} */ //ctsAPI �⺻ �׷� ���� ��

//ctsAPI ���� �׷� ���� ����
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** @defgroup ctsAPI_group1 1. �ʱ�ȭ
 *  @ingroup ctsAPI
 *  @brief 
 *  PNE �������� ����� ���� �ʱ�ȭ �Լ��� �����մϴ�.
 *  @{
 */

/**
*@brief		���������� ����� ���� Server�� �����մϴ�.
*@details	������ ������� ��� ����ŭ ������ ����ϰ�, Host App�� ������ �ڵ��� �޾� Host App�� �̺�Ʈ ���� �մϴ�.
*@param		nInstalledModuleNo	[int]\n
			�����ϰ��� �ϴ� ������� ��� ��.
*@param		hWnd				[HWND]\n
			�̺�Ʈ�� ���� ���� Host App�� ������ �ڵ�.
*@return	FALSE(0), TRUE(1)
*/
CTS_DLL_API int ctsServerCreate(int nInstalledModuleNo, HWND hWnd = NULL);

/**
*@brief		������ �����մϴ�. (Listen)
*@details	ctsServerCreate() ���� ���� �� ���� 1ȸ ȣ���Ͽ� ������Ⱑ ������ �� �ֵ��� Listen�� �����մϴ�.
*@return	FALSE(0), TRUE(1)
*/
CTS_DLL_API int ctsServerStart();

/**
*@brief		������ �����մϴ�.
*@details	���������� ����� ���� ������ ���� �մϴ�.
*@return	FALSE(0), TRUE(1)
*/
CTS_DLL_API int ctsServerClose();

/**
*@brief		API ������ ä�� ��ü�� �ʱ�ȭ �մϴ�. 
*@details	ä�� ��ü�� �Ҵ�� ������ �ʱ�ȭ�Ͽ� �� ������ ���� �� �� �ִ� ���·� �غ��մϴ�.
*@param		nModuleID	[int]\n
			������� ����� ModuleID(1-base, ex. module�� 1�� ��� 1 �Է�, 3�� ��� 3 �Է�)
*@param		nChIndex	[int]\n
			Channel 0-base, ex. 1�� channel ������ 0�Է�, 3�� channel ������ ��� 2 �Է�\n
			nChIndex�� ���� ä���� ���� �� �� �����ϴ�.
*/
CTS_DLL_API void ctsInitChannel(int nModuleID, int nChIndex);



/** @} */ //ctsAPI_group1 �Լ� ���� ��


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** @defgroup ctsAPI_group2 2. �ý��� ���� Ȯ�� �� ����
 *  @ingroup ctsAPI
 *  @brief 
 *  �ý��� ������ Ȯ���ϰų� �����ϴ� ctsAPI �Լ��� �����մϴ�.
 *  @{
 */

/** @} */ // ctsAPI_group2 �Լ� ���� ��

////////////////////////////////////////////////////////////////////////////
/** @defgroup ctsAPI_group2_AUX 1) AUX Ȯ�� �� ����
 *  @ingroup ctsAPI_group2
 *  @brief 
 *  �ý��� ������ Ȯ���ϰų� �����ϴ� ctsAPI �Լ��� �����մϴ�.
 *  @{
 */

/**
*@brief		�������� Aux Data ������ �����Ѵ�. (2020-01-14 ����)
*@details	�������� Aux Data ������ �����Ѵ�.\n
*			******����� �������� �ʽ��ϴ�*****\n
*			���� API ���� ȣȯ�� ������ ���� ���ܳ�������, ctsSendAuxData_V2 �Ǵ� ctsSendAuxData_V3 ����� �����մϴ�.\n
            �� API�� ctsSendAuxData_V2(nModuleID, pAuxData, 1) API�� DataCount�� 1�� �����Ͽ� �����ϴ� ���Ҹ� �մϴ�.\n
*@param		nModuleID	[int]\n
			������� ����� ModuleID(1-base, ex. module�� 1�� ��� 1 �Է�, 3�� ��� 3 �Է�)
*@param		pAuxData	[CTS_MD_AUX_SET_DATA*]\n
			Aux ���� ����ü �ּ�
*@return	\ref ResponseCode [int] ������� Response Code
*/
CTS_DLL_API int ctsSendAuxData(UINT nModuleID, CTS_MD_AUX_SET_DATA* pAuxData);

/**
*@brief		�������� Aux Data ������ �����Ѵ�. (2020-01-14 �߰�)
*@details	�������� Aux Data ������ �����Ѵ�.\n
*			
*@param		nModuleID	[int]\n
			������� ����� ModuleID(1-base, ex. module�� 1�� ��� 1 �Է�, 3�� ��� 3 �Է�)
*@param		pAuxData	[CTS_MD_AUX_SET_DATA*]\n
			Aux ���� ����ü, (�ִ� 512���� ����ü Array ������ ����)\n
			\n
			ctsSendAuxData_V2�� �Է¹��� ����ü �迭�� AuxType�� AuxChNo�� ��ġ�ϴ� �ܺ� ���� �����͸� ã�� �ش� �����͸� �����մϴ�.\n			
			Aux ���� ����ü�� AuxCh�� AuxType�� ��Ȯ�� �����ؾ� �ش� Aux ã�� �����մϴ�.\n
			\n
			<b>*����* �� API�� ����Ͽ� Aux ������ �ٸ� Aux API�� �޸� CTS_MD_AUX_SET_DATA ���� ���� ���������� �����մϴ�.</b>\n
			ctsSendAuxData_V2 : ���� �� (�µ�/��̽���: 1000 == 1��, Voltage: uV)\n
			�� �Լ��� ������ AuxType(2) ��̽����� ���, 1000 == 1�ɷ� �����մϴ�. (default: 1000000 == 1��)\n
			�� �Լ��� ������ AuxType(2) ��̽����� ��� AuxChNo�� 1-base�� ���۵˴ϴ�. (default: MaxAuxV+1)\n

			
*@param		nDataCount	[int]\n
			������ AuxData ���� ����.\n
			pAuxData�� �����ϴ� ������ Array ������ ����.
			��Ȯ�� ��� ���� �ʴ� ��� overflow �߻� ���ɼ��ֽ��ϴ�.\n

*@return	\ref ResponseCode [int] ������� Response Code
*/
CTS_DLL_API int ctsSendAuxData_V2(UINT nModuleID, CTS_MD_AUX_SET_DATA* pAuxData, int nDataCount = 1);

//�ʹ� ���� �Լ��� ���� ���������� ���� ����/����
#if 0
/**
*@brief		�������� Aux Data ������ �����Ѵ�. (2020-01-14 �߰�)
*@details	�������� Aux Data ������ �����Ѵ�.\n
*			
*@param		nModuleID	[int]\n
			������� ����� ModuleID(1-base, ex. module�� 1�� ��� 1 �Է�, 3�� ��� 3 �Է�)
*@param		pAuxData	[CTS_MD_AUX_SET_DATA*]\n
			Aux ���� ����ü, (�ִ� 512���� ����ü Array ������ ����)\n
			\n
			ctsSendAuxData_V3�� �Է¹��� ����ü �迭�� AuxType�� AuxChNo�� ��ġ�ϴ� �ܺ� ���� �����͸� ã�� �ش� �����͸� �����մϴ�.\n			
			Aux ���� ����ü�� AuxCh�� AuxType�� ��Ȯ�� �����ؾ� �ش� Aux ã�� �����մϴ�.\n
			\n
			ctsSendAuxData_V3 : ���� �� (�µ�: 1000 == 1��, Voltage: uV, �µ�: 1000000 == 1��) \n
			�� �Լ��� ������ AuxType(2) ��̽����� ���, 1000000 == 1�ɷ� �����մϴ�.\n
			�� �Լ��� ������ AuxType(2) ��̽����� ��� AuxChNo�� MaxAuxVch+1�� �����մϴ�. (��: AuxV(auxType(1))�� 30ä���� ��� AuxTh(auxType(2))�� AuxChNo = 31 ���� �����մϴ�.)\n
			
*@param		nDataCount	[int]\n
			������ AuxData ���� ����.\n
			pAuxData�� �����ϴ� ������ Array ������ ����.
			��Ȯ�� ��� ���� �ʴ� ��� overflow �߻� ���ɼ��ֽ��ϴ�.\n

*@return	\ref ResponseCode [int] ������� Response Code
*/
CTS_DLL_API int ctsSendAuxData_V3(UINT nModuleID, CTS_MD_AUX_SET_DATA* pAuxData, int nDataCount = 1);
#endif

/**
*@brief		�������� Aux Data ������ �����Ѵ�. (2020-01-14 ���� ���, ������ ctsSendAuxData() �Լ��� �ش�)
*@details	�������� Aux Data ������ �����Ѵ�.\n
*			512���� ��ü Aux ä�� ���� ������ �ѹ��� ����.
*@param		nModuleID	[int]\n
			������� ����� ModuleID(1-base, ex. module�� 1�� ��� 1 �Է�, 3�� ��� 3 �Է�)
*@param		pAuxData	[CTS_MD_AUX_SET_DATA*]\n
			Aux ���� ����ü, (512���� ����ü Array ������ ����)
*@return	\ref ResponseCode [int] ������� Response Code
*/
CTS_DLL_API int ctsSendAuxData_Org(UINT nModuleID, CTS_MD_AUX_SET_DATA* pAuxData);




/**
*@brief		�������� Aux Data ������ �����Ѵ�. (v1016 ~, 2020-04 �߰�)
*@details	�������� Aux Data ������ �����Ѵ�.\n
*			512���� ��ü Aux ä�� ���� ������ �ѹ��� ����.\n
*			ctsSendAuxData_Org�� v1016 ���� �Լ�.
*@param		nModuleID	[int]\n
			������� ����� ModuleID(1-base, ex. module�� 1�� ��� 1 �Է�, 3�� ��� 3 �Է�)
*@param		pAuxData	[CTS_MD_AUX_SET_DATA_16*]\n
			Aux ���� ����ü, (512���� ����ü Array ������ ����)
*@return	\ref ResponseCode [int] ������� Response Code
*/
CTS_DLL_API int ctsSendAuxData16(UINT nModuleID, CTS_MD_AUX_SET_DATA_16* pAuxData);


/**
*@brief		�������� Aux Data ������ �����Ѵ�. (v1016 ~ , 2020-04 �߰�)
*@details	�������� Aux Data ������ �����Ѵ�.\n
*			
*@param		nModuleID	[int]\n
			������� ����� ModuleID(1-base, ex. module�� 1�� ��� 1 �Է�, 3�� ��� 3 �Է�)
*@param		pAuxData	[CTS_MD_AUX_SET_DATA_16*]\n
			Aux ���� ����ü, (�ִ� 512���� ����ü Array ������ ����)\n
			\n
			ctsSendAuxData16_V2�� �Է¹��� ����ü �迭�� AuxType�� AuxChNo�� ��ġ�ϴ� �ܺ� ���� �����͸� ã�� �ش� �����͸� �����մϴ�.\n			
			Aux ���� ����ü�� AuxCh�� AuxType�� ��Ȯ�� �����ؾ� �ش� Aux ã�� �����մϴ�.\n
			\n
			<b>*����* �� API�� ����Ͽ� Aux ������ �ٸ� Aux API�� �޸� CTS_MD_AUX_SET_DATA_16 ���� ���� ���������� �����մϴ�.</b>\n
			ctsSendAuxData16_V2 : ���� �� (�µ�/��̽���: 1000 == 1��, Voltage: uV)\n
			�� �Լ��� ������ AuxType(2) ��̽����� ���, 1000 == 1�ɷ� �����մϴ�. (default: 1000000 == 1��)\n
			�� �Լ��� ������ AuxType(2) ��̽����� ��� AuxChNo�� 1-base�� ���۵˴ϴ�. (default: MaxAuxV+1)\n
			�� �Լ��� ������ AuxType(3) ���� ��� AuxChNo�� 1-base�� ���۵˴ϴ�. (default: MaxAuxV+MaxAuxTh+1)\n

			
*@param		nDataCount	[int]\n
			������ AuxData ���� ����.\n
			pAuxData�� �����ϴ� ������ Array ������ ����.
			��Ȯ�� ��� ���� �ʴ� ��� overflow �߻� ���ɼ��ֽ��ϴ�.\n

*@return	\ref ResponseCode [int] ������� Response Code
*/
CTS_DLL_API int ctsSendAuxData16_V2(UINT nModuleID, CTS_MD_AUX_SET_DATA_16* pAuxData, int nDataCount = 1);


/**
*@brief		��������� ��� Aux�� �Ҵ�� ä�ο��� �����Ѵ�.
*@details	��������� ��� Aux�� �Ҵ�� ä�ο��� �����Ѵ�.\n
*			API ���������� ctsGetAuxInfoData_V2 ȣ���Ͽ� 512���� ��ü Aux ������ ������ ��,\n
*			�� Aux������ chNo ���� ��� 0���� �ٲپ� Master Channel�� ���������·� �ʱ�ȭ �Ѵ�.
*			�ʱ�ȭ �� 512���� �����͸� �ٽ� ctsSendAuxData_Org() �� ȣ���Ͽ� ���� ����.
*           chNo ���� ��� ���� �״�� ����.
*@param		nModuleID	[int]\n
			������� ����� ModuleID(1-base, ex. module�� 1�� ��� 1 �Է�, 3�� ��� 3 �Է�)
*@return	\ref ResponseCode [int] ������� Response Code
*/
CTS_DLL_API int ctsReleaseAllAux(UINT nModuleID);


/**
*@brief		Aux ���� Ȯ��

*@details	������� ����� Aux ������ Ȯ���մϴ�. (V100D~V1015)
*@param		nModuleID	[int]\n
			������� ����� ModuleID(1-base, ex. module�� 1�� ��� 1 �Է�, 3�� ��� 3 �Է�)
			*@return	��û�� ��� Aux ���� ����ü [CTS_MD_AUX_INFO_DATA] \n
			����ü ���� 1��
*/
CTS_DLL_API CTS_MD_AUX_INFO_DATA* ctsGetAuxInfoData(int nModuleID);

/**
*@brief		Aux ���� Ȯ��

*@details	������� ����� Aux ������ Ȯ���մϴ�. (V100D~V1015)
*@param		nModuleID	[int]\n
			������� ����� ModuleID(1-base, ex. module�� 1�� ��� 1 �Է�, 3�� ��� 3 �Է�)
			*@return	��û�� ��� Aux ���� ����ü [CTS_MD_AUX_INFO_DATA_V2] \n
			����ü ���� 1��
*/
CTS_DLL_API CTS_MD_AUX_INFO_DATA_V2* ctsGetAuxInfoData_V2(int nModuleID);

/**
*@brief		Aux ���� Ȯ��
*@details	������� ����� Aux ������ Ȯ���մϴ�. (V1016~)
*@param		nModuleID	[int]\n
			������� ����� ModuleID(1-base, ex. module�� 1�� ��� 1 �Է�, 3�� ��� 3 �Է�)
			*@return	��û�� ��� Aux ���� ����ü [CTS_MD_AUX_INFO_DATA_16] \n
			����ü ���� 1��
*/
CTS_DLL_API CTS_MD_AUX_INFO_DATA_16* ctsGetAuxInfoData16(int nModuleID);


/**
*@brief		Aux Data Ȯ��
*@details	������� ����� Aux Data�� Ȯ���մϴ�.
*@param		nModuleID	[int]\n
			������� ����� ModuleID(1-base, ex. module�� 1�� ��� 1 �Է�, 3�� ��� 3 �Է�)
*@param		nChIndex	[int]\n
			������� ����� ChannelIndex(1-base, ex. 1���� ��� 1 �Է�, 3�� ��� 3 �Է�)\n
			nChIndex�� ���� ä���� ���� �� �� �����ϴ�.
*@return	��û�� ��� Aux Data ����ü �ּ� [CTS_AUX_DATA*] \n
			����ü �ִ� ���� 512��(ù ��° ������ auxChNo�� 0�϶����� read)\n
			nChIndex�� ���� ä���� ���� �� �� �����ϴ�.
*/
CTS_DLL_API CTS_AUX_DATA* ctsGetAuxData(int nModuleID, int nChIndex);


/** @} */ // ctsAPI_group2_AUX �Լ� ���� ��

////////////////////////////////////////////////////////////////////////////
/** @defgroup ctsAPI_group2_AUX 1) AUX Ȯ�� �� ����
 *  @ingroup ctsAPI_group2
 *  @brief 
 *  �ý��� ������ Ȯ���ϰų� �����ϴ� ctsAPI �Լ��� �����մϴ�.
 *  @{
 */



/** @} */ // ctsAPI_group2_AUX �Լ� ���� ��
////////////////////////////////////////////////////////////////////////////
/** @defgroup ctsAPI_group2_CAN 2) CAN Ȯ�� �� ����
 *  @ingroup ctsAPI_group2
 *  @brief 
 *  �ý��� ������ Ȯ���ϰų� �����ϴ� ctsAPI �Լ��� �����մϴ�.
 *  @{
 */

/**
*@brief		�������� Can Rx Data ������ �����Ѵ�.
*@details	�������� Can Rx Data ������ �����Ѵ�.\n
*			
*@param		nModuleID	[int]\n
			������� ����� ModuleID(1-base, ex. module�� 1�� ��� 1 �Է�, 3�� ��� 3 �Է�)
*@param		nChIndex	[int]\n
			������� ����� ChannelIndex(bitflag, ex. 3�� channel ������ ��� 4(bit : 0000 0100) �Է�)\n
			��, nChIndex�� ���� ä���� ���� �� �� �����ϴ�. �Ѻ�Ʈ ������ ���� ����.
*@param		szTxPath	[char*]\n
			Setting �� Receive csv file full path \n
*@param		nCanClear	[BOOL]\n
			CAN ���� ����
*@return	\ref ResponseCode [int] ������� Response Code
*/
CTS_DLL_API int ctsSetRxCANData(UINT nModuleID, int nChIndex, char *szRxPath, BOOL nCanClear);


/**
*@brief		�������� Can ���� Data ������ �����Ѵ�.
*@details	�������� Can ���� Data ������ �����Ѵ�.\n
*			
*@param		nModuleID	[int]\n
			������� ����� ModuleID(1-base, ex. module�� 1�� ��� 1 �Է�, 3�� ��� 3 �Է�)
*@param		nChIndex	[int]\n
			������� ����� ChannelIndex(bitflag, ex. 3�� channel ������ ��� 4(bit : 0000 0100) �Է�)\n
			��, nChIndex�� ���� ä���� ���� �� �� �����ϴ�. �Ѻ�Ʈ ������ ���� ����.
*@param		szTxPath	[char*]\n
			Setting �� Transmit csv file full path \n
*@param		nCanClear	[BOOL]\n
			CAN ���� ����
*@return	\ref ResponseCode [int] ������� Response Code
*/
CTS_DLL_API int ctsSetTxCANData(UINT nModuleID, int nChIndex, char* szTxPath, BOOL nCanClear);



/**
*@brief		CAN RX ���� Ȯ��
*@details	������� ����� CAN RX ������ Ȯ���մϴ�.
*@param		nModuleID	[int]\n
			������� ����� ModuleID(1-base, ex. module�� 1�� ��� 1 �Է�, 3�� ��� 3 �Է�)
*@return	��û�� ��� CAN RX ���� ����ü \n
			����ü �ִ� ���� 1��
*/
CTS_DLL_API CTS_MD_CAN_RECV_INFO_DATA* ctsGetCanRxInfoData(int nModuleID);

/**
*@brief		CAN TX ���� Ȯ��
*@details	������� ����� CAN TX ������ Ȯ���մϴ�.
*@param		nModuleID	[int]\n
			������� ����� ModuleID(1-base, ex. module�� 1�� ��� 1 �Է�, 3�� ��� 3 �Է�)
*@return	��û�� ��� CAN TX ���� ����ü �ּ� \n
			����ü �ִ� ���� 1��
*/
CTS_DLL_API CTS_MD_CAN_TRANS_INFO_DATA* ctsGetCanTxInfoData(int nModuleID);


/** @} */ // ctsAPI_group2_CAN �Լ� ���� ��

////////////////////////////////////////////////////////////////////////////
/** @defgroup ctsAPI_group2_ETC 3) �ý��� �� ��Ÿ ����
 *  @ingroup ctsAPI_group2
 *  @brief 
 *  �ý��� ������ Ȯ���ϰų� �����ϴ� ctsAPI �Լ��� �����մϴ�.
 *  @{
 */

/**
*@brief		Log ���� ����� ���� ��θ� �����մϴ�.
*@details	Log ��Ͻ� ������ ��ο� ������ �����մϴ�.\n
*			��θ� �������� �ʴ� ��� Log ������ �������� �ʽ��ϴ�.
*			��ΰ� �������� �ʴ� ��� Log ������ �������� �ʽ��ϴ�.
*/
CTS_DLL_API void ctsSetLogPath(char* szLogPath);


/**
*@brief		������� ��� ���� Ȯ��
*@details	������� ����� ������ Ȯ���մϴ�.
*@param		nModuleID	[int]		������� ����� ModuleID(1-base, ex. module�� 1�� ��� 1 �Է�, 3�� ��� 3 �Է�)
*@return	��û�� ��� ���� ����ü �ּ� [CTS_MD_SYSTEM_DATA*]  \n
			����ü �ִ� ���� 1��
*/
CTS_DLL_API CTS_MD_SYSTEM_DATA* ctsGetModuleSysData(int nModuleID);



/**
*@brief		������ ������� ����� ���� Ȯ���մϴ�.
*@details	ctsServerCreate���� ������ �ִ� ��� ����� ���� Ȯ���մϴ�.
*@return	������ ������� ��� �� [int]
*/
CTS_DLL_API int ctsGetInstalledModuleNum();

/**
*@brief		������� ����� IP�� Ȯ���մϴ�.
*@details	���ӵ� ������� ����� IP�� Ȯ���մϴ�.
*@return	IP Address [char*]
*/
CTS_DLL_API char* ctsGetIPAddress(int nModuleID);

/**
*@brief		������⿡ �ý��� ������ �����մϴ�.
*@details	�ʱ� ���ӽ� ������⿡ �ý��� ������ 1ȸ �����ؾ��մϴ�.
*@param		nModuleIndex	[int]\n
			dll ���� sturcture info�� �����ϱ� ���� ������� ��� ModuleIndex(0-base, module�� 1�� ��� 0 �Է�, 3�� ��� 2 �Է�)
*@param		nModuleID		[int]\n
			���� ������� ����� ModuleID(1-base, ex. module�� 1�� ��� 1 �Է�, 3�� ��� 3 �Է�)
*@param		pSysParam		[void*]\n
			������� ��⿡ ������ �ý��� �Ķ���� ����ü ������ 
*@return	\ref ResponseCode [int] ������� Response Code
*/
CTS_DLL_API int ctsSetSysParam(int nModuleIndex, int nModuleID, CTS_SYSTEM_PARAM* pSysParam);


/**
*@brief		��������� �ý��� ������ Ȯ���մϴ�.
*@details	�ʱ� ���ӽ� ������ �ý��� ������ Ȯ���մϴ�.
*@param		nModuleID	[int]\n
			������� ����� ModuleID(1-base, ex. module�� 1�� ��� 1 �Է�, 3�� ��� 3 �Է�)
*@return	�ý��� �Ķ���� ����ü [CTS_SYSTEM_PARAM*] \n
			����ü �ִ� ���� 1��
*/
CTS_DLL_API CTS_SYSTEM_PARAM* ctsGetSysParam(int nModuleID);

/**
*@brief		������� Response Code Ȯ��
*@details	������⿡ ������� �� ���ŵ� Response Code�� ���ڿ� �޼����� ��ȯ�մϴ�.
*@param		nCode	[int]\n
			SendCommand Response Code
*@return	���ڿ� �޼���
*/
CTS_DLL_API char* ctsCmdFailMsg(int nCode);


/**
*@brief		API ���� ���� Ȯ��
*@details	API ���� ������ Ȯ�� �մϴ�.
*@return	API ���� ���� ���ڿ�\n
*			ex) ctsAPI v1.0.0 [build: 2019-03-22]
*/
CTS_DLL_API char* ctsGetAPIVer();

/**
*@brief		������� ��� �������� ���� Ȯ��
*@details	������� ����� ��� �������� ���� Ȯ���մϴ�.
*@param		nModuleID	[int]\n
			������� ����� ModuleID(1-base, ex. module�� 1�� ��� 1 �Է�, 3�� ��� 3 �Է�)
*@return	��û�� ����� ������� ��� �������� ����\n
*			ex) 0x100D, 0x100F ��
*/
CTS_DLL_API UINT ctsGetProtocolVer(int nModuleID);

/**
*@brief		��� Error Code Ȯ��
*@details	��� Error Code�� ���ڿ� �޼����� ��ȯ�մϴ�.\n
			ctsGetLastError()�� Error Code�� ���� �� �ֽ��ϴ�.
*@param		nErrorCode	[int]\n
			��� Error Code
*@return	���ڿ� �޼���
*/
CTS_DLL_API char* ctsGetErrorString(int nErrorCode);

/**
*@brief		������ ��� Error Code�� Ȯ��
*@details	������ ��� Error Code�� Ȯ���մϴ�.\n
			ctsGetErrorString()�� ���ڿ� ���� �޼����� ���� �� �ֽ��ϴ�.
*@return	Error Code
*/
CTS_DLL_API int ctsGetLastError();


/**
*@brief		PC �ð� �������� ���� �ð��� ����ȭ.
*@details	PC �ð� �������� ���� �ð��� ����ȭ�մϴ�.\n
			�������� ä���� �ִ� ��� ����ȭ ���� ������,
			�� ��� ȣ��� PC �ð� �������� ���� �ð��� ����ǹǷ�, �����ϰ� ȣ���ؾ� �մϴ�.
*@return	Error Code
*/
CTS_DLL_API int ctsSendTimeSyncData(UINT nModuleID);

/** @} */ // ctsAPI_group2_ETC �Լ� ���� ��



////////////////////////////////////////////////////////////////////////////
/** @defgroup ctsAPI_group2_LIN 4) LIN Ȯ�� �� ����
 *  @ingroup ctsAPI_group2
 *  @brief 
 *  �ý��� ������ Ȯ���ϰų� �����ϴ� ctsAPI �Լ��� �����մϴ�.
 *  @{
 */

/**
*@brief		�������� LIN Data ������ ����.
*@details	������ ������� ���� ä���� LIN to CAN ��� �����带 �����մϴ�.
*@param		nModuleID	[int]\n
			������� ����� ModuleID(1-base, ex. module�� 1�� ��� 1 �Է�, 3�� ��� 3 �Է�)
*@param		nChIndex	[int]\n
			������� ����� ChannelIndex(1-base, ex. 1���� ��� 1 �Է�, 3�� ��� 3 �Է�)\n
			nChIndex�� ���� ä���� ���� �� �� �����ϴ�.
*@param		strPathName				[char*]		LIN ���� file full path.
*			
*@return	\ref ResponseCode [int] ������� Response Code
*/
CTS_DLL_API int ctsSetLINData(UINT nModuleID, int nChIndex, char* strPath);


/**
*@brief		������⿡ ��밡���� LIN ������ ����
*@details	������⿡ ����� LIN�� Channel ������ �����Ѵ�.\n
*			
*@return	[int] LIN Channel����(0 : ����� LIN ����)
*/
CTS_DLL_API int ctsGetLINInstalled();



/** @} */ // ctsAPI_group2_LIN �Լ� ���� ��
////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/** @defgroup ctsAPI_group3 3. �۾� ���� �� ������ ����
 *  @ingroup ctsAPI
 *  @brief 
 *  ���� ������ Ȯ�� �� ó���� ���� ctsAPI �Լ��� �����մϴ�.
 *  @{
 */

/**
*@brief		������⿡ ������(������)�� �����մϴ�.
*@details	��������� ���� �Ǵ� �ټ����� ä�ο� ������(������)�� �����մϴ�.\n
*			bit flag on ä�ο� ���ؼ� ����� �����մϴ�.
*@param		nModuleID	[UINT]\n
*			����� ������ ��������� ModuleID(1-base, ex. module�� 1�� ��� 1 �Է�, 3�� ��� 3 �Է�)
*@param		nBitLCh					[int]\n
*			Channel Bit Flag 1~32CH (LSB)\n
			nBitLCh�� ���� ä�� ������ �����մϴ�.
*@param		nBitHCh					[int]\n
*			Channel Bit Flag 33~64CH (LSB)\n
			nBitHCh�� ���� ä�� ������ �����մϴ�.
*@param		szSchPath				[char*]\n
*			schedule file full path
*@param		nCANCheckOption			[int]\n
*			Can üũ ���, 0 : ���� , 1 : M + S, 2 : Master, 3: Slave
*@param		nChamberOperation		[int]\n
*			0 : ���� ����, 1 : ����
*@return	\ref ResponseCode	[int] ������� Response Code
*/
CTS_DLL_API int ctsSendSchedule(UINT nModuleID, int nBitLCh, int nBitHCh = 0, char* szSchPath = NULL, int nCANCheckOption = 0, int nChamberOperation = 0);




/**
*@brief		������⿡ ������(������)�� �����մϴ�.
*@details	��������� ���� �Ǵ� �ټ����� ä�ο� ������(������)�� �����մϴ�.\n
*			bit flag on ä�ο� ���ؼ� ����� �����մϴ�.
*@param		nModuleID	[UINT]\n
*			����� ������ ��������� ModuleID(1-base, ex. module�� 1�� ��� 1 �Է�, 3�� ��� 3 �Է�)
*@param		nBitLCh					[int]\n
*			Channel Bit Flag 1~32CH (LSB)\n
			nBitLCh�� ���� ä�� ������ �����մϴ�.
*@param		nBitHCh					[int]\n
*			Channel Bit Flag 33~64CH (LSB)\n
			nBitHCh�� ���� ä�� ������ �����մϴ�.
*@param		szSchPath				[char*]\n
*			schedule file full path
*@param		nCANCheckOption			[int]\n
*			Can üũ ���, 0 : ���� , 1 : M + S, 2 : Master, 3: Slave
*@param		nChamberOperation		[int]\n
*			0 : ���� ����, 1 : ����
*@param		nCycle		[int]\n
*			�������� �ǳʶٰ� �߰����� ������ ����Ŭ ��ȣ�� �����մϴ�. (�������� ����Ŭ ��ȣ�� ��Ȯ�� �Է��ؾ� �մϴ�.)
*@param		nStep		[int]\n
*			�������� �ǳʶٰ� �߰����� ������ ���� ��ȣ�� �����մϴ�. (�������� ���� ��ȣ�� ��Ȯ�� �Է��ؾ� �մϴ�.)
*@return	\ref ResponseCode	[int] ������� Response Code
*/
CTS_DLL_API int ctsSendSchedule_V2(UINT nModuleID, int nBitLCh, int nBitHCh = 0, char *szSchPath = NULL, int nCANCheckOption = 0, int nChamberOperation = 0, int nCycle = 0, int nStep = 0);
CTS_DLL_API int ctsSendSchedule_Org(UINT nModuleID, int nBitLCh, int nBitHCh = 0, char* szSchPath = NULL, int nCANCheckOption = 0, int nChamberOperation = 0, int nCycle = 0, int nStep = 0);

/**
*@brief		������⿡ ���� ����� ������ �����մϴ�.
*@details	��������� ���� �Ǵ� �ټ����� ä�ο� ���� ����� ������ �����մϴ�.\n
*			������ ���� �Ǵ� ���� ������ �����մϴ�.\n
*			bit flag on ä�ο� ���ؼ� ����� �����մϴ�.
*@param		nModuleID	[UINT]\n
*			����� ������ ��������� ModuleID(1-base, ex. module�� 1�� ��� 1 �Է�, 3�� ��� 3 �Է�)
*@param		nBitLCh					[int]\n
*			Channel Bit Flag 1~32CH (LSB)\n
			nBitLCh�� ���� ä�� ������ �����մϴ�.
*@param		nBitHCh					[int]\n
*			Channel Bit Flag 33~64CH (LSB)\n
			nBitHCh�� ���� ä�� ������ �����մϴ�.
*@param		nStepCount			[int]\n
*			Max 1~100 �� ���� ����
			�����ϰ����ϴ� ���� ���� ������ �����մϴ�.
*@param		pStepInfo*			[CTS_SIMPLE_TEST_INFO]\n
*			�����ϰ����ϴ� ���� ���� ����ü ������, �迭�� ������ StepCount�� ������ ������ ��ġ�ؾ� �մϴ�.
*			*����* ���� ������ ��Ȯ�� �Է����� �ʴ� ��� ���۵��� �� �ֽ��ϴ�.
*@return	\ref ResponseCode	[int] ������� Response Code
*/
CTS_DLL_API int ctsSendSimpleTest(UINT nModuleID, int nBitLCh, int nBitHCh=0, int nStepCount=0, CTS_SIMPLE_TEST_INFO* pStepInfo = NULL);

/** @} */ //ctsAPI_group3 �Լ� ���� ��




////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** @defgroup ctsAPI_group4 4. ���� ��� ����
 *  @ingroup ctsAPI
 *  @brief 
 *  PNE ������� ��� ���� ctsAPI �Լ��� �����մϴ�.
 *  @{
 */



/**
*@brief		��� ���� ���� Ȯ��
*@details	���� ���� ���� �� �Ͻ����� �Ǵ� ���� ������ �Ǿ��ִ��� ���¸� Ȯ���մϴ�.
*			\n���� ������ ����� �� ����� �÷��׿� ���� �Ͻ����� �Ǵ� �����˴ϴ�.
*@param		nModuleID	[int]\n
			��������� ModuleID(1-base, ex. module�� 1�� ��� 1 �Է�, 3�� ��� 3 �Է�)
*@param		nChIndex	[int]\n
			������� ����� ChannelIndex(0-base, ex. 3�� channel ������ ��� 2 �Է�)\n
			nChIndex�� ���� ä���� ���� �� �� �����ϴ�.
*@return	None(0), Stop(1), Pause(2)
*/
CTS_DLL_API int ctsGetReservedCmd(int nModuleID, int nChIndex);


/**
*@brief		������⿡ �۾� �Ͻ� ���� ����� �����մϴ�.
*@details	��������� ���� �Ǵ� �ټ����� ä�ο� �Ͻ� ���� ����� �����մϴ�.\n
*			bit flag on ä�ο� ���ؼ� ����� �����մϴ�.
*@param		nModuleID		[UINT]\n
*			����� ������ ��������� ModuleID(1-base, ex. module�� 1�� ��� 1 �Է�, 3�� ��� 3 �Է�)
*@param		nBitLCh				[int]\n
*			Channel Bit Flag 1~32CH (LSB) \n
			nBitLCh�� ���� ä�� ������ �����մϴ�.
*@param		nBitHCh				[int]\n
*			Channel Bit Flag 33~64CH (LSB) \n
			nBitHCh�� ���� ä�� ������ �����մϴ�.
*@param		nCycleNo			[int]\n
*			0�� �ƴ� ���� ������ ��� ������ ����Ŭ ���Ŀ� �Ͻ����� ��ŵ�ϴ�.
*@param		nStepNo				[int]\n
*			0�� �ƴ� ���� ������ ��� ������ ���� ���Ŀ� �Ͻ����� ��ŵ�ϴ�.
*@return	\ref ResponseCode	[int] ������� Response Code
*/
CTS_DLL_API int ctsSendPause(UINT nModuleID,  int nBitLCh, int nBitHCh = 0, int nCycleNo = 0, int nStepNo = 0);

/**
*@brief		������⿡ ����� �Ͻ����� ����� ����մϴ�.
*@details	������⿡ ����� �Ͻ����� ����� ����մϴ�.\n
*			bit flag on ä�ο� ���ؼ� ����� �����մϴ�.
*@param		nModuleID			[UINT]\n
*			����� ������ ��������� ModuleID(1-base, ex. module�� 1�� ��� 1 �Է�, 3�� ��� 3 �Է�)
*@param		nBitLCh				[int]\n
*			Channel Bit Flag 1~32CH (LSB)\n
			nBitLCh�� ���� ä�� ������ �����մϴ�.
*@param		nBitHCh				[int]\n
*			Channel Bit Flag 33~64CH (LSB)\n
			nBitHCh�� ���� ä�� ������ �����մϴ�.
*@return	\ref ResponseCode	[int] ������� Response Code
*/
CTS_DLL_API int ctsSendPauseCancel(UINT nModuleID,  int nBitLCh, int nBitHCh = 0);

/**
*@brief		������⿡ �۾� ���� ����� �����մϴ�.
*@details	��������� ���� �Ǵ� �ټ����� ä�ο� ���� ����� �����մϴ�. (2020-08-20 ���� ���, ������ �������� ctsSendStop()�� �ش�)\n 
*			bit flag on ä�ο� ���ؼ� ����� �����մϴ�.
*@param		nModuleID			[UINT]\n
*			����� ������ ��������� ModuleID(1-base, ex. module�� 1�� ��� 1 �Է�, 3�� ��� 3 �Է�)
*@param		nBitLCh				[int]\n
*			Channel Bit Flag 1~32CH (LSB)\n
			nBitLCh�� ���� ä�� ������ �����մϴ�.
*@param		nBitHCh				[int]\n
*			Channel Bit Flag 33~64CH (LSB)\n
			nBitHCh�� ���� ä�� ������ �����մϴ�.
*@param		nCycleNo			[int]\n
*			0�� �ƴ� ���� ������ ��� ������ ����Ŭ ���Ŀ� ���� ��ŵ�ϴ�.
*@param		nStepNo				[int]\n
*			0�� �ƴ� ���� ������ ��� ������ ���� ���Ŀ� ���� ��ŵ�ϴ�.
*@return	\ref ResponseCode	[int] ������� Response Code
*/
CTS_DLL_API int ctsSendStopImmediate(UINT nModuleID,  int nBitLCh, int nBitHCh = 0, int nCycleNo = 0, int nStepNo = 0);


/**
*@brief		������⿡ �۾� ���� ����� �����մϴ�.
*@details	��������� ���� �Ǵ� �ټ����� ä�ο� ���� ����� �����մϴ�.\n
*			bit flag on ä�ο� ���ؼ� ����� �����մϴ�.\n
*			�������� �۾� ������ ����, ä�ο� Pause ���(ctsSendPause)�� �����ϰ�\n
*			���������� Pause�� �� ��쿡 Stop�� �ǽ��մϴ�.\n
*@param		nModuleID			[UINT]\n
*			����� ������ ��������� ModuleID(1-base, ex. module�� 1�� ��� 1 �Է�, 3�� ��� 3 �Է�)
*@param		nBitLCh				[int]\n
*			Channel Bit Flag 1~32CH (LSB)\n
			nBitLCh�� ���� ä�� ������ �����մϴ�.
*@param		nBitHCh				[int]\n
*			Channel Bit Flag 33~64CH (LSB)\n
			nBitHCh�� ���� ä�� ������ �����մϴ�.
*@param		nCycleNo			[int]\n
*			0�� �ƴ� ���� ������ ��� ������ ����Ŭ ���Ŀ� ���� ��ŵ�ϴ�.
*@param		nStepNo				[int]\n
*			0�� �ƴ� ���� ������ ��� ������ ���� ���Ŀ� ���� ��ŵ�ϴ�.
*@return	\ref ResponseCode	[int] ������� Response Code
*/
CTS_DLL_API int ctsSendStop(UINT nModuleID,  int nBitLCh, int nBitHCh = 0, int nCycleNo = 0, int nStepNo = 0);

/**
*@brief		������⿡ ����� ���� ����� ����մϴ�.
*@details	������⿡ ����� ���� ����� ����մϴ�.\n
*			bit flag on ä�ο� ���ؼ� ����� �����մϴ�.
*@param		nModuleID			[UINT]\n
*			����� ������ ��������� ModuleID(1-base, ex. module�� 1�� ��� 1 �Է�, 3�� ��� 3 �Է�)
*@param		nBitLCh				[int]\n
*			Channel Bit Flag 1~32CH (LSB)\n
			nBitLCh�� ���� ä�� ������ �����մϴ�.
*@param		nBitHCh				[int]\n
*			Channel Bit Flag 33~64CH (LSB)\n
			nBitHCh�� ���� ä�� ������ �����մϴ�.
*@return	\ref ResponseCode	[int] ������� Response Code
*/
CTS_DLL_API int ctsSendStopCancel(UINT nModuleID,  int nBitLCh, int nBitHCh = 0);

/**
*@brief		������⿡ �۾� �۾� ��� ����� �����մϴ�.
*@details	��������� ���� �Ǵ� �ټ����� ä�ο� �۾� ��� ����� �����մϴ�.\n
*			bit flag on ä�ο� ���ؼ� ����� �����մϴ�.
*@param		nModuleID			[UINT]\n
*			����� ������ ��������� ModuleID(1-base, ex. module�� 1�� ��� 1 �Է�, 3�� ��� 3 �Է�)
*@param		nBitLCh				[int]\n
*			Channel Bit Flag 1~32CH (LSB)\n
			nBitLCh�� ���� ä�� ������ �����մϴ�.
*@param		nBitHCh				[int]\n
*			Channel Bit Flag 33~64CH (LSB)\n
			nBitHCh�� ���� ä�� ������ �����մϴ�.
*			0 : �Ͻ� ������ ���, 1 : Chamber ���� ������ ���
*@return	\ref ResponseCode	[int] ������� Response Code
*/
CTS_DLL_API int ctsSendContinue(UINT nModuleID,  int nBitLCh, int nBitHCh = 0, int nContinueOption = 0);



/**
*@brief		������⿡ �۾� ���� ���� ���� ����� �����մϴ�.
*@details	��������� ���� �Ǵ� �ټ����� ä�ο� ���� ���� ���� ����� �����մϴ�.\n
*			bit flag on ä�ο� ���ؼ� ����� �����մϴ�.
*@param		nModuleID			[UINT]\n
*			����� ������ ��������� ModuleID(1-base, ex. module�� 1�� ��� 1 �Է�, 3�� ��� 3 �Է�)
*@param		nBitLCh				[int]\n
*			Channel Bit Flag 1~32CH (LSB)\n
			nBitLCh�� ���� ä�� ������ �����մϴ�.
*@param		nBitHCh				[int]\n
*			Channel Bit Flag 33~64CH (LSB)\n
			nBitHCh�� ���� ä�� ������ �����մϴ�.
*@return	\ref ResponseCode	[int] ������� Response Code
*/
CTS_DLL_API int ctsSendNextStep( UINT nModuleID,  int nBitLCh, int nBitHCh = 0);




/**
*@brief		������⿡ �̵� ���� ����� �����մϴ�.
*@details	��������� ���� �Ǵ� �ټ����� ä�ο� Ư�� ���������� �̵� ����� �����մϴ�.\n
*			bit flag on ä�ο� ���ؼ� ����� �����մϴ�.
*@param		nModuleID			[UINT]\n
*			����� ������ ��������� ModuleID(1-base, ex. module�� 1�� ��� 1 �Է�, 3�� ��� 3 �Է�)
*@param		nBitLCh				[int]\n
*			Channel Bit Flag 1~32CH (LSB)\n
			nBitLCh�� ���� ä�� ������ �����մϴ�.
*@param		nBitHCh				[int]\n
*			Channel Bit Flag 33~64CH (LSB)\n
			nBitHCh�� ���� ä�� ������ �����մϴ�.
*@param		nStepNo				[int]\n
*			������ �������� �̵��մϴ�.
*@return	\ref ResponseCode	[int] ������� Response Code
*/
CTS_DLL_API int ctsSendGotoStep( UINT nModuleID,  int nBitLCh, int nBitHCh = 0, int nStepNo = 0);

/**
*@brief		������⿡ ����/������ �б� ����� �����մϴ�. (�˻�� ����)
*@details	��������� ����  ä�ο� ������⿡ ����/������ �б� ����� �����մϴ�. (�˻�� Ÿ�� ����)\n
*			��) 1�� ��� 2�� ä�� ���� ���\n
			ctsSendIso(1,1,0,0); //���� (3��°�� 0���� �������̾, 4��° ���ڰ� 0�̸� ����)\n
			ctsSendIso(1,1,1); //���� (3��° ���� 1�� ����)\n
			\n
			��) 1�� ��� 2�� ä�� ������ ���\n
			ctsSendIso(1,1,0,1); //������ (3��°�� 0���� �������̸�, 4��°�� 1�� A�б� ������)\n
			ctsSendIso(1,1,0); //������ (3��°�� 0���� ������)\n

*@param		nModuleID			[UINT]\n
*			����� ������ ��������� ModuleID(1-base, ex. module�� 1�� ��� 1 �Է�, 3�� ��� 3 �Է�)
*@param		nChannelIndex	[int]\n
			������� ����� ChannelIndex(0-base, ex. Channel�� 1�� ��� 0 �Է�, 3�� ��� 2 �Է�) \n
			nChIndex�� ���� ä���� ���� �� �� �����ϴ�.
*@param		bISO				[BYTE]\n
*			0: ������ ����,   1: ���� ����\n
*@param		bDivCh				[BYTE]\n
*			��� ä��(�б� A, B) ���� 1(A),2(B)  (0�̸� ����)\n
*			�⺻ �� : 1 (A�б�)\n
*@return	\ref ResponseCode	[int] ������� Response Code
*/
CTS_DLL_API int ctsSendIso(UINT nModuleID, int nChannelIndex, BYTE bISO, BYTE bDivCh = 1);

/**
*@brief		������⿡ ����/������ �б� ����� �����մϴ�. (�˻�� ����)
*@details	��������� ���� ä�ο� ������⿡ ����/������ ����� �����մϴ�. (�˻�� Ÿ�� ����)\n
*			��) 1�� ��� 2�� ä�� ���� ���\n			
			ctsSendIso(1,1,1); //���� (3��° ���� 1�� ����)\n
			\n
			��) 1�� ��� 2�� ä�� ������ ���\n			
			ctsSendIso(1,1,0); //������ (3��°�� 0���� ������)\n

*@param		nModuleID			[UINT]\n
*			����� ������ ��������� ModuleID(1-base, ex. module�� 1�� ��� 1 �Է�, 3�� ��� 3 �Է�)
*@param		nChannelIndex	[int]\n
			������� ����� ChannelIndex(0-base, ex. Channel�� 1�� ��� 0 �Է�, 3�� ��� 2 �Է�) \n
			nChIndex�� ���� ä���� ���� �� �� �����ϴ�.
*@param		bISO				[BYTE]\n
*			0: ������ ����,   1: ���� ����\n
*@return	\ref ResponseCode	[int] ������� Response Code
*/
CTS_DLL_API int ctsSendIsoNormal(UINT nModuleID, int nChannelIndex, BYTE bISO);


/**
*@details	��������� ���� �Ǵ� �ټ����� ä�ο� ���� ���� ���� ���� Clear ����� �����ϴ�..\n
*			bit flag on ä�ο� ���ؼ� ����� �����մϴ�.\n
*			�ű�(v1015) �������� �������ǿ� ���� ���� �Ͻ����� �� ��� Clear ����� �����־�� �絿�� �����մϴ�.\n
*			�������� ���������� �����ϴ� ��� ���� ��翡 ���� è�� Ventilator�� Open �ϰ� ���� ������ �����մϴ�.\n
*			�� API�� ȣ���ϴ� ��� ���� ���¸� �ʱ�ȭ�ϰ� è�� Ventilator�� Close �մϴ�.
*@param		nModuleID			[UINT]\n
*			����� ������ ��������� ModuleID(1-base, ex. module�� 1�� ��� 1 �Է�, 3�� ��� 3 �Է�)
*@param		nBitLCh				[int]\n
*			Channel Bit Flag 1~32CH (LSB)\n
			nBitLCh�� ���� ä�� ������ �����մϴ�.
*@param		nBitHCh				[int]\n
*			Channel Bit Flag 33~64CH (LSB)\n
			nBitHCh�� ���� ä�� ������ �����մϴ�.
*@param		nFlag				[int]\n
*			0(Default) : Close(Clear),  1: Open\n			
			(v1015������ Clear�� ����, V1016�� Close �� Open ����)\n
			
*@return	\ref ResponseCode	[int] ������� Response Code
*/
CTS_DLL_API int ctsSendVentClear( UINT nModuleID, int nBitLCh, int nBitHCh = 0, int nFlag = 0);


/**
*@brief		������⿡ Capacity Bank On/Off ����� �����մϴ�. (v1015~)
*@details	��������� ���� �Ǵ� �ټ����� ä�ο� Capacity Bank On/Off ����� �����մϴ�.\n
*			bit flag on ä�ο� ���ؼ� ����� �����մϴ�.\n
*			CBank ��� ����� ���񿡼��� �����մϴ�.\n
*			����!! ���͸� ������ �ݵ�� ���� �� �����ϼ���.\n
*@param		nModuleID			[UINT]\n
*			����� ������ ��������� ModuleID(1-base, ex. module�� 1�� ��� 1 �Է�, 3�� ��� 3 �Է�)
*@param		nBitLCh				[int]\n
*			Channel Bit Flag 1~32CH (LSB)\n
			nBitLCh�� ���� ä�� ������ �����մϴ�.
*@param		nBitHCh				[int]\n
*			Channel Bit Flag 33~64CH (LSB)\n
			nBitHCh�� ���� ä�� ������ �����մϴ�.
*@param		nFlag				[int]\n
*			0(Default) : off,  1: On\n						
*@return	\ref ResponseCode	[int] ������� Response Code
*/
CTS_DLL_API int ctsSendCBank( UINT nModuleID, int nBitLCh, int nBitHCh = 0, int nFlag = 0);

/** @} */ //ctsAPI_group4 �Լ� ���� ��

CTS_DLL_API int ctsSendCommand(UINT nCmd, UINT nModuleID,  int nBitLCh, int nBitHCh = 0, LPVOID lpData = NULL, UINT nSize = 0, UINT nRetryCount = 5);
CTS_DLL_API int ctsSendCommandCh(UINT nCmd, UINT nModuleID, UINT nChannelIndex, LPVOID lpData = NULL, UINT nSize = 0, UINT nRetryCount = 5);


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/** @defgroup ctsAPI_group5 5. ������ Ȯ�� �� ó��
 *  @ingroup ctsAPI
 *  @brief 
 *  ���� ������ Ȯ�� �� ó���� ���� ctsAPI �Լ��� �����մϴ�.
 *  @{
 */

/**
*@brief		���� ������� ä���� ����͸� �����͸� Ȯ���մϴ�.
*@details	���� ä���� Ư�� �׸��� ���� Ȯ���� �� �ֽ��ϴ�.
*@param		nModuleID		[int]\n
			����� ������ ��������� ModuleID(1-base, ex. module�� 1�� ��� 1 �Է�, 3�� ��� 3 �Է�)
*@param		nChannelIndex	[int]\n
			������� ����� ChannelIndex(0-base, ex. Channel�� 1�� ��� 0 �Է�, 3�� ��� 2 �Է�) \n
			nChIndex�� ���� ä���� ���� �� �� �����ϴ�.
*@param		nItem			[int]\n
			\ref ChannelItem
*@return	��û�� ����͸� �׸��� ���� �� [long], 0�� ��� ��� ���� �� �Ǿ� ����
*/
CTS_DLL_API long ctsGetChannelValue(int nModuleID, int nChannelIndex, int nItem);

/**
*@brief		���� ������� ä���� ���� �ڵ带 Ȯ���մϴ�.
*@details	���� ä���� ���� �ڵ带 Ȯ���� �� �ֽ��ϴ�.
*@param		nModuleID	[int]\n
			����� ������ ��������� ModuleID(1-base, ex. module�� 1�� ��� 1 �Է�, 3�� ��� 3 �Է�)
*@param		nChIndex	[int]\n
			������� ����� ChannelIndex(1-Base, ex. 3�� channel ������ ��� 3 �Է�) \n
			nChIndex�� ���� ä���� ���� �� �� �����ϴ�.
*@return	\ref define_state_ch [int]	��û�� ä���� ���� �ڵ�
*/
CTS_DLL_API int ctsGetChannelState(int nModuleID, int nChIndex);

/**
*@brief		���� ������� ä���� ����͸� �����͸� Ȯ���մϴ�.
*@details	���� ä���� ��� �����͸� ����ü �������� Ȯ���մϴ�.
*@param		nModuleID	[int]\n
			����� ������ ��������� ModuleID(1-base, ex. module�� 1�� ��� 1 �Է�, 3�� ��� 3 �Է�)
*@param		nChIndex	[int]\n
			������� ����� ChannelIndex(1-Base, ex. 3�� channel ������ ��� 3 �Է�) \n
			nChIndex�� ���� ä���� ���� �� �� �����ϴ�.
*@return	��û�� ä���� ����͸� �������� ����ü �޸� �ּ� ��ȯ [CTS_VARIABLE_CH_DATA*]  \n
			����ü �ִ� ���� 1��
*/
CTS_DLL_API CTS_VARIABLE_CH_DATA* ctsGetRealChData(int nModuleID, int nChIndex);

/**
*@brief		������� ����� ���� Ȯ��
*@details	������� ����� ���� code�� Ȯ���մϴ�.
*@param		ModuleID	[int]\n
			������� ����� ModuleID(1-base, ex. module�� 1�� ��� 1 �Է�, 3�� ��� 3 �Է�)
*@return	\ref define_state [int]	���� Code			
*/
CTS_DLL_API int ctsGetModuleState(int ModuleID);

/**
*@brief		�޸� ť ���� ������ ������
*@details	API ������ ������ Queue ���� �����͸� 1�� Pop �մϴ�.\n
*			�������κ��� ������ǿ� ���� ������ �����͸� API�� ���� Queue�� �����մϴ�.\n
*			�ִ� ���� ������ Size�� 600���̸�, ���ÿ� �����Ͱ� ���� �� ��� ���� �����ʹ� ������ �� �ֽ��ϴ�.
*@param		nModuleID	[int]\n
			������� ����� ModuleID(1-base, ex. module�� 1�� ��� 1 �Է�, 3�� ��� 3 �Է�)
*@param		nChIndex	[int]\n
			������� ����� ChannelIndex(1-base, ex. Channel�� 1���� ��� 1 �Է�, 3�� ��� 3 �Է�) \n
			nChIndex�� ���� ä���� ���� �� �� �����ϴ�.
*@param		pSaveChData	[CTS_VARIABLE_CH_DATA*] 	\n�����͸� Pop�ؼ� ������ ����ü�� ������ �Է�
*@return	pop �� data ������ FALSE(0), pop �� data�� ������ TRUE(1)
*/
CTS_DLL_API int ctsPopSaveData(int nModuleID, int nChIndex, CTS_VARIABLE_CH_DATA* pSaveChData);

/**
*@brief		Stack �� ���� ������ ���� Ȯ��
*@details	������ǿ� ���� �������κ��� ���Ź��� �����Ͱ� ���� Queue�� Size�� Ȯ���մϴ�.\n
*			Queue Size�� ��� Ȯ���Ͽ�, ������ ������ ctsPopSaveData() �� ȣ���Ͽ� �����͸� Pop ���־���մϴ�.
*			Queue�� �ִ� ���� ������ Size�� 600���̸�, �����Ͱ� ���� �� ��� ���� �����ʹ� ������ �� �ֽ��ϴ�.
*			
*@param		nModuleID	[int]\n
			������� ����� ModuleID(1-base, ex. module�� 1�� ��� 1 �Է�, 3�� ��� 3 �Է�)
*@param		nChIndex	[int]\n
			������� ����� ChannelIndex(1-base, ex. Channel�� 1���� ��� 1 �Է�, 3�� ��� 3 �Է�) \n
			nChIndex�� ���� ä���� ���� �� �� �����ϴ�.
*@return	Queue�� ������ Data Size [int] \n
			�߸��� ä�� ������ 0-return;
*/
CTS_DLL_API int ctsGetStackedDataSize(int nModuleID, int nChIndex);

/**
*@brief		Ư�� ������ ������ ���� ���� ������ Ȯ���մϴ�.
*@details	Ư�� ������ ������ ���� ���� ����(�⺻ ����)�� Ȯ���մϴ�.\n
*			��� ������ �������� ������, �ֿ� �⺻ �������� �����մϴ�.\n
*@param		pStepInfo				[CTS_SCH_STEP_INFO*] 	\n�����͸� Pop�ؼ� ������ ����ü�� ������ �Է�
*@param		szSchPath				[char*]\n
*			schedule file full path
*@param		nStepIndex				[int]\n
*			Ȯ���ϰ��� �ϴ� ���� ��ȣ�� �Է��մϴ�. (0-base, nStepIndex)
*@return	����(0), ����(1)
*/
CTS_DLL_API int ctsGetSchStepInfo(CTS_SCH_STEP_INFO* pStepInfo, char* szSchPath, int nStepIndex);

/**
*@brief		Ư�� ������ ������ ���� ���� ������ Ȯ���մϴ�.
*@details	Ư�� ������ ������ ���� ���� ������ Ȯ���մϴ�.\n
*
*@param		szSchPath				[char*]\n
*			schedule file full path
*@return	StepCount [int] \n ������ ���Ͽ� ��ϵǾ��ִ� ������ ���� �����մϴ�.
*/
CTS_DLL_API int ctsGetSchStepCount(char* szSchPath);

/**
*@brief		Ư�� ������ ���Ͽ� ���Ե� ���뷱�̱� ������ ������ ������ Ȯ���մϴ�.
*@details	Ư�� ������ ���Ͽ� ���Ե� ���뷱�̱� ������ ������ ������ Ȯ���մϴ�.\n
*			sch ���Ͽ� ���Ե� ���뷱�̱� ������ Ȯ���մϴ�.\n
*			CB ���� ���� ������ŭ �������� �޸� ������ �Ҵ����Ͽ� �����ͷ� �����ϹǷ�,\n
*			������Ŀ��� ctsReleaseSchAllStepCBInfo()�� ȣ���Ͽ� �޸𸮸� ���� ���־���մϴ�.\n
*			�������� �ʰ� �ݺ� ȣ���ϴ� ��� �޸� ������ �߻��� �� �ֽ��ϴ�.\n
*@param		szSchPath				[char*]\n
*			schedule file full path
*@param		pnStepCount				[int*]\n
*			pnStepCount�� �����ϴ� CB���� ����ü�� ������ ���� �մϴ�. ���� ���� ������ �ּҸ� �Ѱ��־�� �մϴ�.
*@return	��û�� sch ���Ͽ� ���Ե� CB���� ����ŭ�� CB���� ����ü ������ ���� [CTS_SCH_EXT_CB_INFO*]
*/
CTS_DLL_API CTS_SCH_EXT_CB_INFO* ctsGetSchAllStepCBInfo(char* szSchPath, int* pnStepCount);

/**
*@brief		ȣ���� ���뷱�� ���� ������ �޸𸮿��� �����մϴ�.
*@details	ȣ���� ���뷱�� ���� ������ �޸𸮿��� �����մϴ�.\n
*			ctsGetSchAllStepCBInfo() �Լ��� CB ���� ���� ������ŭ �������� �޸� ������ �Ҵ��Ͽ� �����ϹǷ�,\n
*			������Ŀ��� ctsReleaseSchAllStepCBInfo()�� ȣ���Ͽ� �޸𸮸� ���� ���־���մϴ�.\n
*			�������� �ʰ� �ݺ� ȣ���ϴ� ��� �޸� ������ �߻��� �� �ֽ��ϴ�.\n
*@param		pExtCbInfo				[CTS_SCH_EXT_CB_INFO*] 	\n�޸𸮿��� ������ ����ü ������ �Է�.
*@return	����(0), ����(1)
*/
CTS_DLL_API int ctsReleaseSchAllStepCBInfo(CTS_SCH_EXT_CB_INFO* pExtCbInfo);

/** @} */ //ctsAPI_group5 �Լ� ���� ��


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/** @defgroup ctsAPI_group6 6. ���� ���� �� ���� Ȯ��
 *  @ingroup ctsAPI
 *  @brief 
 *  ���� ������ Ȯ�� �� ó���� ���� ctsAPI �Լ��� �����մϴ�.
 *  @{
 */

/**
*@brief		������⿡ ���� ������ �����մϴ�.
*@details	��������� �ټ����� ä�ο� ���� ������ �����մϴ�.\n
*			ParallelOption �� ���ؼ� ����� �����մϴ�.
*@param		nModuleID	[UINT]\n
*			����� ������ ��������� ModuleID(1-base, ex. module�� 1�� ��� 1 �Է�, 3�� ��� 3 �Է�)
*@param		nMaster		[int]\n
*			Channel base, ex. 3�� channel ������ ��� 3 �Է�
*@param		nSlave		[int]\n
			������� ����� ChannelIndex(0-base, ex. 3�� channel ������ ��� 4(bit : 0000 0100) �Է�)\n
			(nChIndex�� ���� ä���� ���� �� �� ����. \n
			��, ¦������ Slave�� ���� �Ұ�, ex Master ch:1, Slave ch:2 or ch:2,3,4 �� �����ؾ� ��, Slave ch : 2,3���� ���� �Ұ�)
*@param		nParallelOption		[int]\n
*			0 : ���� ����, 1 : ���� ����
*@return	\ref ResponseCode [int] ������� Response Code
*/
CTS_DLL_API int ctsSetParallelData(UINT nModuleID, int nMaster, int nSlave, int nParallelOption = 0);

/**
*@brief		���� ��� ���� Ȯ��
*@details	������� ����� ���� ��� ���¸� Ȯ���մϴ�.
*@param		nModuleID	[int]\n
			������� ����� ModuleID(1-base, ex. module�� 1�� ��� 1 �Է�, 3�� ��� 3 �Է�)
*@return	��û�� ��� ���� ���� ����ü \n
			����ü �ִ� ���� 8��(ù ��° ������ chNoMaster�� 0�϶����� read)
*/
CTS_DLL_API CTS_MD_PARALLEL_DATA* ctsGetParallelData(int nModuleID);

/** @} */ //ctsAPI_group6 �Լ� ���� ��


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/** @defgroup ctsAPI_group7 7. Callback �Լ�(Notify message)
 *  @ingroup ctsAPI
 *  @brief 
 *  ���� �̺�Ʈ ���� callback �Լ��� �����մϴ�.
 *  @{
 */

/**
*@brief		������� ���� �̺�Ʈ 
*@details	���������� ������ �Ǿ����� �����մϴ�.
*@param		nModuleID	[int]\n
			������� ����� ModuleID(1-base, Moudle ID�� 1�� ��� 1, 3�� ��� 3)
*@param		sysInfo		[CTS_MD_SYSTEM_DATA*]\n
			������� �ý��� ���� ����ü
*@return	null
*/
typedef void(*CALLBACK_CONNECTED)(int nModuleID , CTS_MD_SYSTEM_DATA* sysInfo);
CTS_DLL_API void __stdcall CallbackConnected(CALLBACK_CONNECTED handler);

/**
*@brief		������� ���� ���� �̺�Ʈ
*@details	���������� ������ ���� �Ǿ����� �����մϴ�.
*@param		nModuleID	[int]\n
			������� ����� ModuleID
*@return	null
*/
typedef void(*CALLBACK_CLOSED)(int nModuleID);
CTS_DLL_API void __stdcall CallbackClosed(CALLBACK_CLOSED handler);

/**
*@brief		ä�� stack data �̺�Ʈ
*@details	Stack�� ����� data�� ������ ���� ��� ����� �����Ͱ� ���� �˴ϴ�.
*@param		nModuleID	[int]\n
			������� ����� ModuleID(1-base, Moudle ID�� 1�� ��� 1, 3�� ��� 3)
*@param		nChIndex	[int]\n
			������� ����� ChannelIndex(1-base, Channel Index�� 1���� ��� 1, 3���� ��� 3)
*@return	null 
*/
typedef void(*CALLBACK_STACKNOTIFY)(int nModuleID , int nChIndex);
CTS_DLL_API void __stdcall CallbackStackNotify(CALLBACK_STACKNOTIFY handler);

/**
*@brief		ä�� ������ �̺�Ʈ
*@details	�ǽð� ä�� �����͸� �����մϴ�.
*@param		nModIDandChIdex	[unsigned int]\n
			���� 4����Ʈ : Channel Index (0-base), ���� 4����Ʈ : Module ID (1-base)\n\n
			��) ���1���� 1��ä��\n
			  Module ID : 1   (1-Base)\n
			  Channel Index : 0  (0-Base)\n
			  �� : 0x0000 0001  (1)\n\n

			  ���1���� 2��ä��\n
			  Module ID : 1   (1-Base)\n
			  Channel Index : 1  (0-Base)\n
			  �� : 0x0001 0001  (65537)\n\n

			  ���2���� 2��ä��\n
			  Module ID : 2   (1-Base)\n
			  Channel Index : 1  (0-Base)\n
			  �� : 0x0001 0002  (65538)\n\n

			  
*@param		sysInfo			[CTS_VARIABLE_CH_DATA*]\n
			Channel data ����ü
*@return	null 
*/
typedef void(*CALLBACK_CHDATA)(unsigned int nModIDandChIdex , CTS_VARIABLE_CH_DATA* ChData);
CTS_DLL_API void __stdcall CallbackChData(CALLBACK_CHDATA handler);


/**
*@brief		ä�� ������ �̺�Ʈ
*@details	�ǽð� ä�� �����͸� �����մϴ�.
*@param		nModIDandChIdex	[unsigned int]\n
			���� 4����Ʈ : Channel Index (0-base), ���� 4����Ʈ : Module ID (1-base)\n\n
			��) ���1���� 1��ä��\n
			  Module ID : 1   (1-Base)\n
			  Channel Index : 0  (0-Base)\n
			  �� : 0x0000 0001  (1)\n\n

			  ���1���� 2��ä��\n
			  Module ID : 1   (1-Base)\n
			  Channel Index : 1  (0-Base)\n
			  �� : 0x0001 0001  (65537)\n\n

			  ���2���� 2��ä��\n
			  Module ID : 2   (1-Base)\n
			  Channel Index : 1  (0-Base)\n
			  �� : 0x0001 0002  (65538)\n\n

*@param		sysInfo			[CTS_VARIABLE_CH_DATA_D*]\n
			Channel data ����ü
*@return	null 
*/
typedef void(*CALLBACK_CHDATA_D)(unsigned int nModIDandChIdex , CTS_VARIABLE_CH_DATA_D* ChData);
CTS_DLL_API void __stdcall CallbackChData_D(CALLBACK_CHDATA_D handler);


/**
*@brief		ä�� ������ �̺�Ʈ
*@details	�ǽð� ä�� �����͸� �����մϴ�.
*@param		nModIDandChIdex	[unsigned int]\n
			���� 4����Ʈ : Channel Index (0-base), ���� 4����Ʈ : Module ID (1-base)\n\n
			��) ���1���� 1��ä��\n
			  Module ID : 1   (1-Base)\n
			  Channel Index : 0  (0-Base)\n
			  �� : 0x0000 0001  (1)\n\n

			  ���1���� 2��ä��\n
			  Module ID : 1   (1-Base)\n
			  Channel Index : 1  (0-Base)\n
			  �� : 0x0001 0001  (65537)\n\n

			  ���2���� 2��ä��\n
			  Module ID : 2   (1-Base)\n
			  Channel Index : 1  (0-Base)\n
			  �� : 0x0001 0002  (65538)\n\n

*@param		sysInfo			[CTS_VARIABLE_CH_DATA_F*]\n
			Channel data ����ü
*@return	null 
*/
typedef void(*CALLBACK_CHDATA_F)(unsigned int nModIDandChIdex , CTS_VARIABLE_CH_DATA_F* ChData);
CTS_DLL_API void __stdcall CallbackChData_F(CALLBACK_CHDATA_F handler);

/**
*@brief		�׽�Ʈ ���� �Ϸ� �̺�Ʈ
*@details	�׽�Ʈ�� ����� ä���� ���� ��ȣ �̺�Ʈ�� �����մϴ�.
*@param		nModIDandChIdex	[int]\n
			���� 4����Ʈ : Channel Index (0-base), ���� 4����Ʈ : Module ID (1-base)\n\n
			��) ���1���� 1��ä��\n
			  Module ID : 1   (1-Base)\n
			  Channel Index : 0  (0-Base)\n
			  �� : 0x0000 0001  (1)\n\n

			  ���1���� 2��ä��\n
			  Module ID : 1   (1-Base)\n
			  Channel Index : 1  (0-Base)\n
			  �� : 0x0001 0001  (65537)\n\n

			  ���2���� 2��ä��\n
			  Module ID : 2   (1-Base)\n
			  Channel Index : 1  (0-Base)\n
			  �� : 0x0001 0002  (65538)\n\n

*@param		nStepNum	[int]\n
			�׽�Ʈ�� ���� step�� ��ȣ
*@return	null
*/
typedef void(*CALLBACK_STEPENDDATARECEIVE)(int nModIDandChIdex , int nStepNum);
CTS_DLL_API void __stdcall CallbackStepEndDataReceive(CALLBACK_STEPENDDATARECEIVE handler);

/**
*@brief		�׽�Ʈ �Ϸ� �̺�Ʈ
*@details	�׽�Ʈ�� ����� ä���� �̺�Ʈ�� �����մϴ�.
*@param		nModuleID	[int]\n
			������� ����� ModuleID(1-base, Moudle ID�� 1�� ��� 1, 3�� ��� 3)
*@param		nChIndex	[int]\n
			������� ����� ChannelIndex(1-base, Channel Index�� 1���� ��� 1, 3���� ��� 3)
*@return	null
*/
typedef void(*CALLBACK_TESTCOMPLETE)(int nModuleID , int nChIndex);
CTS_DLL_API void __stdcall CallbackTestComplete(CALLBACK_TESTCOMPLETE handler);

/**
*@brief		��� �˶� �̺�Ʈ
*@details	������� ��� �˶� �̺�Ʈ�� �����մϴ�.
*@param		nModuleID	[int] \n
			������� ����� ModuleID(1-base, Moudle ID�� 1�� ��� 1, 3�� ��� 3)
*@param		emgData		[CTS_EMG_DATA*] \n
			������� ��� �˶� ����ü
*@return	null
*/
typedef void(*CALLBACK_EMERGENCY)(int nModuleID, CTS_EMG_DATA* emgData);
CTS_DLL_API void __stdcall CallbackEmergency(CALLBACK_EMERGENCY handler);


/**
*@brief		ä�� pause �̺�Ʈ
*@details	��� puase state�� ����� �̺�Ʈ�� �����մϴ�.
*@param		nModuleID	[int]\n
			������� ����� ModuleID(1-base, Moudle ID�� 1�� ��� 1, 3�� ��� 3)
*@param		nChIndex	[int]\n
			������� ����� ChannelIndex(1-base, Channel Index�� 1���� ��� 1, 3���� ��� 3)
*@return	null 
*/
typedef void(*CALLBACK_PAUSE)(int nModuleID , int nChIndex);
CTS_DLL_API void __stdcall CallbackPause(CALLBACK_PAUSE handler);


/** @} */ //ctsAPI_group7 �Լ� ���� ��

//ctsAPI ���� �׷� ���� ��


////////////////////////////////////////////////////////////////////////
//API �������̽� �׽�Ʈ�� DEBUG ����� �Լ� ���� ����
CTS_DLL_API DEBUG_TEST* ctsApiDebugPtrStruct(DEBUG_TEST* pDebug1);
CTS_DLL_API DEBUG_TEST ctsApiDebugStruct(DEBUG_TEST stDebug1);
CTS_DLL_API int ctsApiDebugInteger(int nA);
CTS_DLL_API char* ctsApiDebugString(char* szString);
CTS_DLL_API CTS_EMG_DATA* ctsApiDebugPtrStruct2(CTS_EMG_DATA* pDebug1); //CTS ����ü �׽�Ʈ
//����� �Լ� ���� ��
////////////////////////////////////////////////////////////////////////