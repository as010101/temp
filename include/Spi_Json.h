#pragma once
#include "XcTradeApi.h"
class CSpi :public CXcTradeSpi
{
public:
	/* 断开提示*/
	void OnClose(void);

	/* 断线中，正在尝试重连 */
	void OnDisConnect(void);

	/* 重连成功 */
	void OnConnected(void);

	/* 反馈JSON模式应答数据（JSON模式）*/
	void OnRecvJsonMsg(char* pJsonMsg);

};

