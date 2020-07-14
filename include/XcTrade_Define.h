#pragma once

// ���⹦�ܺ�
#define Fn_620000 620000  // ����
#define Fn_620001 620001  // ����
#define Fn_620002 620002  // �˶�
#define Fn_620003 620003  // ����

// ��̨ϵͳ
#define System_UFX  10  // UFX��̨
#define System_UF20 20  // UF20��̨

// ���ݳ���
#define Field_Name_Length 256
#define Field_Value_Length 512

// ͨѶģʽ
#define Trans_Mode_SYN 0  // ͬ��
#define Trans_Mode_ASY 1  // �첽

// ����Э��
#define Data_Proto_Pack 0 // Ĭ�����ݰ�
#define Data_Proto_Json 1 // jsonͨ�ø�ʽ

// ��������
#define Type_Int 'I'  // int
#define Type_Char 'C' // char
#define Type_String 'S' // string
#define Type_Float 'F' // float

// �����ֶ�
#define Field_op_branch_no "op_branch_no"  //
#define Field_op_entrust_way "op_entrust_way" //
#define Field_op_station "op_station" //
#define Field_fund_account "fund_account" //

#ifdef _WIN32
#define My_Strcpy(dst, dst_len, src) \
{\
strcpy_s(dst, dst_len, src);\
}
#else
#include <sys/types.h>
#define My_Strcpy(dst, dst_len, src) \
{\
strncpy(dst, src, dst_len);\
}
#endif

#ifndef Xc_LoadLibrary
#ifdef _WIN32
#define Xc_LoadLibrary(name) LoadLibrary(name)
#define Xc_GetProcAddress GetProcAddress
#define Xc_FreeLibrary FreeLibrary
#define Xc_Module HMODULE
#else
#include <dlfcn.h>
#define Xc_LoadLibrary(name) dlopen(name,RTLD_LAZY)
#define Xc_Module void*
#define Xc_FreeLibrary dlclose
#define Xc_GetProcAddress dlsym
#define sprintf_s snprintf
#define _Longlong long long
#endif
#endif