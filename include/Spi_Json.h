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

};

