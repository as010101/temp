#include "Spi_Pack.h"

#include <iostream>

using namespace std;

void CSpi::OnClose()
{
	cout << "Close" << endl;
}

void CSpi::OnDisConnect()
{
	cout << "DisConnect" << endl;
}

void CSpi::OnConnected()
{
	cout << "Connected" << endl;
}

void CSpi::OnRecvJsonMsg(char* pJsonMsg)
{
	cout << pJsonMsg << endl;
}

void CSpi::OnRecvPackMsg(int iFunid, int iRefid, int iIssueType, int iSet, int iRow, int iCol, char* szName, char* szValue)
{
	cout << "funid:" << iFunid << endl;
	cout << "refid:" << iRefid << endl;
	cout << "IssueType:" << iIssueType << endl;
	cout << "iSet:" << iSet << endl;
	cout << "iRow:" << iRow << endl;
	cout << "iCol:" << iCol << endl;
	cout << "szName:" << szName << endl;
	cout << "szValue:" << szValue << endl;
}

/* 反馈数据包模式数据集结束（Pack包模式）*/
void CSpi::OnRecvPackEndSet(int iFunid, int iRefid, int iIssueType, int iSet)
{
	cout << "EndSet:" << endl;
	cout << "funid:" << iFunid << endl;
	cout << "refid:" << iRefid << endl;
	cout << "IssueType:" << iIssueType << endl;
	cout << "iSet:" << iSet << endl;
}

/* 反馈数据包模式数据行结束（Pack包模式）*/
void CSpi::OnRecvPackEndRow(int iFunid, int iRefid, int iIssueType, int iSet, int iRow)
{
	cout << "EndRow:" << endl;
	cout << "funid:" << iFunid << endl;
	cout << "refid:" << iRefid << endl;
	cout << "IssueType:" << iIssueType << endl;
	cout << "iSet:" << iSet << endl;
	cout << "iRow:" << iRow << endl;
}