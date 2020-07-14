#pragma once
#include "XcTradeApi.h"

class CSpi :public CXcTradeSpi
{
public:
	/* �Ͽ���ʾ*/
	void OnClose(void);

	/* �����У����ڳ������� */
	void OnDisConnect(void);

	/* �����ɹ� */
	void OnConnected(void);

	/* ����JSONģʽӦ�����ݣ�JSONģʽ��*/
	void OnRecvJsonMsg(char* pJsonMsg);

	/* �������ݰ�ģʽӦ�����ݣ�Pack��ģʽ��*/
	void OnRecvPackMsg(int iFunid, int iRefid, int iIssueType, int iSet, int iRow, int iCol, char* szName, char* szValue);

	/* �������ݰ�ģʽ���ݼ�������Pack��ģʽ��*/
	void OnRecvPackEndSet(int iFunid, int iRefid, int iIssueType, int iSet);

	/* �������ݰ�ģʽ�����н�����Pack��ģʽ��*/
	void OnRecvPackEndRow(int iFunid, int iRefid, int iIssueType, int iSet, int iRow);

};
