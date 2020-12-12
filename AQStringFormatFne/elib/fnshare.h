/*
    版权声明：
    本文件版权为易语言作者吴涛所有，仅授权给第三方用作开发易语言支持库，禁止用于其他任何场合。
*/

//本单元不使用MFC类, 可供编写跨平台的支持库或非窗口组件支持库使用



#ifndef __FN_SHARE_H
#define __FN_SHARE_H
// 使用指定数据建立易程序中使用的字节集数据。

#ifdef __COMPILE_FNR	// 此宏在编译配置中设置
	#define	_WT(text)	""
#else
	#define	_WT(text)	_T(text)
#endif

#endif //#ifndef __FN_SHARE_H

//#define	_WT(text)	                    _T(text)