/*
    ��Ȩ������
    ���ļ���ȨΪ�����������������У�����Ȩ����������������������֧�ֿ⣬��ֹ���������κγ��ϡ�
*/

//����Ԫ��ʹ��MFC��, �ɹ���д��ƽ̨��֧�ֿ��Ǵ������֧�ֿ�ʹ��



#ifndef __FN_SHARE_H
#define __FN_SHARE_H
// ʹ��ָ�����ݽ����׳�����ʹ�õ��ֽڼ����ݡ�

#ifdef __COMPILE_FNR	// �˺��ڱ�������������
	#define	_WT(text)	""
#else
	#define	_WT(text)	_T(text)
#endif

#endif //#ifndef __FN_SHARE_H

//#define	_WT(text)	                    _T(text)