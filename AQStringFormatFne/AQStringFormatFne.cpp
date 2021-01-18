// AQStringFormatFne.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"
#include "AQStringFormatFne.h"
#include <stdio.h>


BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
    switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
		case DLL_PROCESS_DETACH:
			break;
    }
    return TRUE;
}


#ifndef __E_STATIC_LIB
PLIB_INFO WINAPI GetNewInf ()
{ 
	return &s_LibInfo;
} 
#endif 

INT WINAPI AQ_StringFormat_NotifySys (INT nMsg, DWORD dwParam1, DWORD dwParam2)
{
	if (AQ_StringFormat_g_fnNotifySys)
		return AQ_StringFormat_g_nLastNotifyResult = AQ_StringFormat_g_fnNotifySys (nMsg, dwParam1, dwParam2);
	else
		return AQ_StringFormat_g_nLastNotifyResult = 0;
}

INT WINAPI _AQ_StringFormat_ProcessNotifyLib (INT nMsg, DWORD dwParam1, DWORD dwParam2)
{
	INT nRet = NR_OK;
	switch (nMsg)
	{
	case NL_SYS_NOTIFY_FUNCTION:
		AQ_StringFormat_g_fnNotifySys = (PFN_NOTIFY_SYS)dwParam1;
		break;
	default:
		nRet = NR_ERR;
		break;
	}
	return nRet;
}

EXTERN_C INT WINAPI AQ_StringFormat_ProcessNotifyLib (INT nMsg, DWORD dwParam1, DWORD dwParam2)
{
#ifndef __E_STATIC_LIB
	if(nMsg == NL_GET_CMD_FUNC_NAMES)
		return (INT) g_CmdNames;
	else if(nMsg == NL_GET_NOTIFY_LIB_FUNC_NAME)
		return (INT) "AQ_StringFormat_ProcessNotifyLib";
	else if(nMsg == NL_GET_DEPENDENT_LIBS)
		return NULL;
#endif
	return _AQ_StringFormat_ProcessNotifyLib(nMsg, dwParam1, dwParam2);
}


// ʹ��ָ���ı����ݽ����׳�����ʹ�õ��ı����ݡ�
// nTextLen����ָ���ı����ֵĳ��ȣ������������㣩��
char* AQ_StringFormat_CloneTextData(char* ps, INT nTextLen)
{
	if (nTextLen <= 0)
		return NULL;
	
	char* pd = (char*)AQ_StringFormat_g_fnNotifySys(NRS_MALLOC, (DWORD)(nTextLen + 1), 0);
	memcpy(pd, ps, nTextLen);
	pd[nTextLen] = '\0';
	return pd;
}

char* AQ_StringFormat_CloneTextData(char* ps)  
{  
    if (ps == NULL || *ps == '\0')  
        return NULL;  
	
    INT nTextLen = strlen (ps);  
    char* pd = (char*)AQ_StringFormat_g_fnNotifySys (NRS_MALLOC, (DWORD)(nTextLen + 1), 0);  
    memcpy (pd, ps, nTextLen);  
    pd [nTextLen] = '\0';  
    return pd;  
}  

void AQ_StringFormat_GReportError (char* szErrText)  
{  
    AQ_StringFormat_g_fnNotifySys (NRS_RUNTIME_ERR, (DWORD)szErrText, 0);  
}  

// ������������ݲ����׵�ַ����Ա��Ŀ��
LPBYTE AQ_StringFormat_GetAryElementInf(void* pAryData, LPINT pnElementCount)
{
	LPINT pnData = (LPINT)pAryData;
	INT nArys = *pnData++;  // ȡ��ά����
	// �����Ա��Ŀ��
	INT nElementCount = 1;
	while (nArys > 0)
	{
		nElementCount *= *pnData++;
		nArys--;
	}
	
	if (pnElementCount != NULL)
		*pnElementCount = nElementCount;
	return (LPBYTE)pnData;
}

HWND _eLogHwnd;

BOOL __stdcall EnumChildCallback(HWND hwnd, LPARAM lp) {

	//BOOL (CALLBACK* WNDENUMPROC)(HWND, LPARAM)
	if (GetDlgCtrlID(hwnd) == 1011) {
		_eLogHwnd = hwnd;
		return false;
	}
	return true;
}


//���͵�e���Դ����ı�
void OutputStringToELog(char* szbuf) {
	HWND hwnd = FindWindowExA(0, 0, "ENewFrame", NULL);
	EnumChildWindows(hwnd, EnumChildCallback, 0);
	if (_eLogHwnd) {
		SendMessageA(_eLogHwnd, 194, 1, (long)szbuf);
		SendMessageA(_eLogHwnd, 194, 1, (long)"\r\n");
	}
} 





//���ܺ�������װ

int sprintf_wsprintf(char* szbuf, char *fmt, ... ) { 
	va_list argptr; 
	int iChrWritten; 
	va_start(argptr, fmt); 
	iChrWritten = _vsnprintf(szbuf, 4096, fmt, argptr); 
	va_end(argptr); 
	return iChrWritten; 
} 

//�ֽڼ����ı�
EXTERN_C void fn_hexToString(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf) {
     LPBYTE pData;  
     INT nDataSize;  

     pData = (LPBYTE)pArgInf [0].m_pAryData + sizeof (INT) * 2;  
     nDataSize = *(LPINT)(pData - sizeof (INT));  

}

//�ı����ֽڼ�
EXTERN_C void fn_stringToHex(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf) {
	
} 


EXTERN_C void fn_wsprintf(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf) { 
	//������
	LPSTR pszoutbuf = new char[4096];

	LPSTR pszinbuf = pArgInf[0].m_pText; 

	//OutputStringToELog(pszinbuf);

	int iResult = 0; 
	LPVOID pptr; 
	float pp = 0.f; 
	int hint,lint; 
	int iArgCount = nArgCount; 
	__int64 F = 0xffffffff;

	for(int j = 1; j < nArgCount; j++) { 
		//LPSTR outBuf = new char[1024];

		int i = nArgCount - j ; 

		//wsprintfA(outBuf, "%d - %d", i, pArgInf[i].m_dtDataType);
		//sprintf_wsprintf();

		//OutputStringToELog(outBuf);

		//delete []outBuf;

		
		switch (pArgInf[i].m_dtDataType) { 
				//�ı� 
			case SDT_TEXT: 
				pptr = pArgInf[i].m_ppText; 
				_asm {push pptr}
				break; 
				//���� 
			case SDT_DATE_TIME: 
				pptr = pArgInf[i].m_pDate; 
				_asm {push pptr}
				break; 
				//��ֵ���� 
			case SDT_BYTE: 
				pptr = pArgInf[i].m_pByte; 
				_asm {push pptr}
				break; 
			case SDT_SHORT: 
				pptr = pArgInf[i].m_pShort; 
				_asm {push pptr}
				break; 
			case SDT_INT: 
				pptr = pArgInf[i].m_pInt; 
				_asm {push pptr} 
				break; 
			case SDT_INT64: //�������� 
				//hint=HIINT(pArgInf[i].m_int64); 
				//lint=LOINT(pArgInf[i].m_int64); 
				//hint= pArgInf[i].m_int64 << 32 >> 32; 
				//lint= pArgInf[i].m_int64 >> 32; 
				
				lint= pArgInf[i].m_int64 & F; //i & F �õ�32�ֽ�
				hint = (pArgInf[i].m_int64 >> 32) & F; //�ø�32λ��
				__asm 
				{ 
					push hint 
					push lint 
				} 
				iArgCount++; 
				break; 
			case SDT_FLOAT: //������ 
				pp = pArgInf[i].m_float; 
				__asm 
				{ 
					fld pp 
					sub esp,8 
					fstp qword ptr [esp] 
				} 
				iArgCount++; 
				// D945 FC fld dword ptr [ebp-4] 
				// 83EC 08 sub esp, 8 ; /<%f> 
				// DD1C24 fstp qword ptr [esp] ; | 
				break; 
			case SDT_DOUBLE: 
				pp=(float)pArgInf[i].m_double; 
				__asm 
				{ 
					fld pp 
					sub esp,8 
					fstp qword ptr [esp] 
				} 
				iArgCount++; 
				break; 
			case SDT_BOOL: 
				pptr = pArgInf[i].m_pBool; 
				_asm { push pptr}
				break; 
			default: 
				AQ_StringFormat_GReportError("��֧�ֵ���������"); 
				return; 
		} 
	} 

	//pptr = pRetData->m_pInt; 

	__asm 
	{ 
		push pszinbuf 
		push pszoutbuf 
		call sprintf_wsprintf 
		mov edx,iArgCount 
		dec edx 
		imul edx,4 
		add esp,edx 
		mov pptr,eax 
	} 

	pRetData->m_pText = AQ_StringFormat_CloneTextData(pszoutbuf, 4096);

	delete []pszoutbuf;
}