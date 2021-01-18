
// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the AQSTRINGFORMATFNE_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// AQSTRINGFORMATFNE_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.

#include "stdafx.h"

#ifdef AQSTRINGFORMATFNE_EXPORTS
#define AQSTRINGFORMATFNE_API __declspec(dllexport)
#else
#define AQSTRINGFORMATFNE_API __declspec(dllimport)
#endif

INT AQ_StringFormat_g_nLastNotifyResult; 
PFN_NOTIFY_SYS AQ_StringFormat_g_fnNotifySys = NULL; 

EXTERN_C INT WINAPI AQ_StringFormat_ProcessNotifyLib(INT nMsg, DWORD dwParam1, DWORD dwParam2);

char* AQ_StringFormat_CloneTextData(char* ps, INT nTextLen);
char* AQ_StringFormat_CloneTextData(char* ps)  ;


EXTERN_C void fn_wsprintf(PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf);
//#ifndef __E_STATIC_LIB


PFN_EXECUTE_CMD s_RunFunc [] =
{
	fn_wsprintf,
};


static const char* const g_CmdNames[] = 
{
	_WT("fn_wsprintf"),
};


//////////////////ARGINFO/////////////////////////////////////////

 static ARG_INFO s_ArgInfo[] =  
 {  
     {  
     /*name*/       _T("格式文本"),  
     /*explain*/    _T("格式文本"),  
     /*bmp inx*/    0,  
     /*bmp num*/    0,  
     /*type*/       SDT_TEXT,  
     /*default*/    0,  
     /*state*/      NULL,  
     }, {  
     /*name*/       _T("参数"),  
     /*explain*/    _T("参数"),  
     /*bmp inx*/    0,  
     /*bmp num*/    0,  
     /*type*/       _SDT_ALL,  
     /*default*/    0,  
     /*state*/       AS_DEFAULT_VALUE_IS_EMPTY,  
     }  
 };  
  
 static CMD_INFO s_CmdInfo[] =  
 {  
	 {
	 /*name*/        _T("StringFormat"),  
	 /*egname*/      _T("StringFormat"),  
	 /*explain*/     _T("格式化文本，缓冲区长度为4096，不支持字节集型"),  
	 /*category*/    1,  
	 /*state*/       CT_ALLOW_APPEND_NEW_ARG,  
	 /*ret*/         SDT_TEXT,  
	 /*reserved*/    0,  
	 /*level*/       LVL_SIMPLE,  
	 /*bmp inx*/     0,  
	 /*bmp num*/     0,  
	 /*ArgCount*/    2,  
	 /*arg lp*/      s_ArgInfo,  
	}
 
 };  

// {7D4D78AF-4803-4269-8311-C2520175DF92}
//IMPLEMENT_OLECREATE(<<class>>, <<external_name>>, 
//0x7d4d78af, 0x4803, 0x4269, 0x83, 0x11, 0xc2, 0x52, 0x1, 0x75, 0xdf, 0x92);



static LIB_INFO s_LibInfo = 
{
	/*Lib Format Ver*/	LIB_FORMAT_VER,
	/*guid str*/		_WT("EA968347-300C-4515-93CA-F1D3BA3DF66F"),
	/*m_nMajorVersion*/	1,
	/*m_nMinorVersion*/	2,
	/*m_nBuildNumber*/	1,
	/*m_nRqSysMajorVer*/	3,
	/*m_nRqSysMinorVer*/	0,
	/*m_nRqSysKrnlLibMajorVer*/	3,
	/*m_nRqSysKrnlLibMinorVer*/	0,
	/*name*/	_WT ("爱琴格式化文本V2"),
	/*lang*/ 	__GBK_LANG_VER,
	/*explain*/ 	_WT("爱琴格式化文本V2"),
	/*dwState*/ 	NULL,
	/*szAuthor*/ 	_WT(""),
	/*szZipCode*/ 	_WT(""),
	/*szAddress*/ 	_WT(""),
	/*szPhoto*/_WT(""),
	/*szFax*/ 	_WT(""),
	/*szEmail*/ 	_WT(""),
	/*szHomePage*/ 	_WT(""),
	/*szOther*/ 	_WT("爱琴格式化文本V2"),
	/*type count*/	    NULL,//sizeof (s_DataType) / sizeof (s_DataType [0]),//0,//
	/*PLIB_DATA_TYPE_INFO*/	NULL,//s_DataType,//NULL,//
	/*CategoryCount*/	13,
	/*category*/	_WT("0000基本命令\0"),
		/*CmdCount*/	sizeof (s_CmdInfo) / sizeof (s_CmdInfo [0]),
		/*BeginCmd*/	s_CmdInfo,
		/*m_pCmdsFunc*/	s_RunFunc,
		/*pfnRunAddInFn*/	NULL,
		/*szzAddInFnInfo*/	NULL,
		/*pfnNotify*/		AQ_StringFormat_ProcessNotifyLib,
		/*pfnRunSuperTemplate*/	NULL,
		/*szzSuperTemplateInfo*/NULL,
		/*nLibConstCount*/	NULL, //sizeof(s_ConstInfo) / sizeof(s_ConstInfo[0]),
		/*pLibConst*/ 		NULL,//s_ConstInfo,
		/*szzDependFiles*/	NULL
};
