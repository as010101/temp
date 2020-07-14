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

	/* 反馈数据包模式应答数据（Pack包模式）*/
	void OnRecvPackMsg(int iFunid, int iRefid, int iIssueType, int iSet, int iRow, int iCol, char* szName, char* szValue);

	/* 反馈数据包模式数据集结束（Pack包模式）*/
	void OnRecvPackEndSet(int iFunid, int iRefid, int iIssueType, int iSet);

	/* 反馈数据包模式数据行结束（Pack包模式）*/
	void OnRecvPackEndRow(int iFunid, int iRefid, int iIssueType, int iSet, int iRow);

};
