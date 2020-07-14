#pragma once

#include <stdio.h>
#include <iostream>
#if defined(_WIN32)
#ifdef LIB_XC_API_EXPORT
#define XC_API_EXPORT __declspec(dllexport)
#else
#define XC_API_EXPORT __declspec(dllimport)
#endif
#else
#define XC_API_EXPORT 
#endif

using namespace std;

class CXcTradeSpi
{
public:

	/* �Ͽ���ʾ*/
	virtual void OnClose(void) {};

	/* �����У����ڳ������� */
	virtual void OnDisConnect(void) {};

	/* �����ɹ� */
	virtual void OnConnected(void) {};

	/* ����JSONģʽӦ�����ݣ�JSONģʽ��*/
	virtual void OnRecvJsonMsg(char* pJsonMsg) {};

	/* �������ݰ�ģʽӦ�����ݣ�Pack��ģʽ��*/
	virtual void OnRecvPackMsg(int iFunid, int iRefid, int iIssueType, int iSet, int iRow, int iCol, char* szName, char* szValue) {};

	/* �������ݰ�ģʽ���ݼ�������Pack��ģʽ��*/
	virtual void OnRecvPackEndSet(int iFunid, int iRefid, int iIssueType, int iSet) {};

	/* �������ݰ�ģʽ�����н�����Pack��ģʽ��*/
	virtual void OnRecvPackEndRow(int iFunid, int iRefid, int iIssueType, int iSet, int iRow) {};

};

class XC_API_EXPORT CXcTradeApi
{
public:
	/* ����Apiָ�� */
	static CXcTradeApi *CreateTradeApi();
	/* ע�ᣨָ��ͨѶģʽ������Э�飬�첽ģʽ�µ�SPI·����*/
	virtual int Register(int iTransMode, int iDataProto, CXcTradeSpi* pSpi = NULL) = 0;
	/* ���ӣ���Ҫlicense��������������*/
	virtual int Connect(char* pIP_Port, char* pLicensePath, int iSystemID, char* pFund_Account) = 0;
	/* ��ʼ��������ݰ�ģʽ��������������*/
	virtual void BeginPack(void) = 0;
	/* ������������ݰ�ģʽ��������������*/
	virtual void EndPack(void) = 0;
	/* д�����ݰ����ݣ����ݰ�ģʽ��������������*/
	virtual int SetPackValue(const char* pKeyName, const char* pValue) = 0;
	/* д��JSON���ݣ�ͨ��JSONģʽ��������������*/
	virtual int SetJsonValue(const char* pJsonStr) = 0;
	/* �������ݣ�ͬ��ģʽ�°����������ݲ�д�����ݶ��У�������������*/
	virtual int SendMsg(int iFunctionID, int iSubSystemNo = 0, int iBranchNo = 0) = 0;
	/* �������ݣ�ͬ��ģʽ�´����ݶ�������ȡ���ݵ���ǰ���ݼ���Ա��������������*/
	virtual int RecvMsg() = 0;
	/* ��ȡ���ݼ�������ͬ�������ݰ�ģʽ��������������*/
	virtual int GetDataSetCount() = 0;
	/* ��ȡ������ͬ�������ݰ�ģʽ��������������*/
	virtual int GetCurRowCount() = 0;
	/* ��ȡ������ͬ�������ݰ�ģʽ��������������*/
	virtual int GetCurColCount() = 0;
	/* ��λ��ǰ���ݼ���ͬ�������ݰ�ģʽ��������������*/
	virtual bool GetCurDataSet(int iIndex) = 0;
	/* ��ȡ������ͬ�������ݰ�ģʽ��������������*/
	virtual bool GetColName(int iCol, char* szName) = 0;
	/* ��ȡ��ǰ����ֵ��ͬ�������ݰ�ģʽ��������������*/
	virtual bool GetColValue(int iCol, char* szValue) = 0;
	/* ָ����һ�У�ͬ�������ݰ�ģʽ��������������*/
	virtual void GetNextRow() = 0;
	/* ��ȡJSON��ֵ��JSON��ģʽ��������������*/
	virtual int GetJsonValue(char* pJsonStr) = 0;
	/* �ͷ���Դ������������*/
	virtual void Release() = 0;
	/* ��ȡ�û����ֵ */
	virtual int GetSpace() = 0;
	/* ��ȡ�û�Ƶ��ֵ */
	virtual int GetFrequency() = 0;
	/* ��ȡ���������Ϣ */
	virtual char* GetLastErrorMsg() = 0;
protected:
	~CXcTradeApi() {};
};

