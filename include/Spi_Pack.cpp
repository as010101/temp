#include "Spi_Pack.h"
#include "TradeSig.h"
#include <iostream>

using namespace std;

vector<pair<string, string>> MessageBuff = {};///消息缓存变量
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
	if (iFunid == 331100)
	{
		int d = 1;
	}
	//cout << "funid:" << iFunid << endl;
	//cout << "refid:" << iRefid << endl;
	//cout << "IssueType:" << iIssueType << endl;
	//cout << "iSet:" << iSet << endl;
	//cout << "iRow:" << iRow << endl;
	//cout << "iCol:" << iCol << endl;
	//cout << "szName:" << szName << endl;
	//cout << "szValue:" << szValue << endl;
	MessageBuff.push_back(make_pair(szName,szValue));
//	cout << this << endl;
}

/* 反馈数据包模式数据集结束（Pack包模式）*/
void CSpi::OnRecvPackEndSet(int iFunid, int iRefid, int iIssueType, int iSet)
{
	auto iter_begin = m_currDataSet.begin();
	while (iter_begin != m_currDataSet.end())
	{
		auto& eles = *iter_begin;
		for (auto& myeles : eles)
		{
			cout<<"key:"<<myeles.first<<endl;
			cout<<"value:"<<myeles.second<<endl;

		}
		cout << "-------------------" << endl;
			iter_begin++;
	}
	auto mapValue = this->m_pTradeObject->m_OptionMap.find(iFunid);
	string str = "未命名操作";
	if (mapValue != this->m_pTradeObject->m_OptionMap.end())
	{
		str = (*mapValue).second;
	}
	cout << "--------"<<str <<"---------"<< endl;
	cout << "------反馈数据包模式数据集结束-------------" << endl;

	this->m_pTradeObject->m_AllMyMsg.insert(make_pair(iFunid, m_currDataSet));   ///新的功能码会覆盖旧的功能码消息
	m_currDataSet.clear();
	//cout << "funid:" << iFunid << endl;
	//cout << "refid:" << iRefid << endl;
	//cout << "IssueType:" << iIssueType << endl;
	//cout << "iSet:" << iSet << endl;
}

/* 反馈数据包模式数据行结束（Pack包模式）*/
void CSpi::OnRecvPackEndRow(int iFunid, int iRefid, int iIssueType, int iSet, int iRow)
{
	//for (auto& ele : MessageBuff)
	//{
	//	cout << "szName:" << ele.first << endl;
	//	cout << "szValue:" << ele.second << endl;
	//}
	//
	//auto& opStack = this->m_pTradeObject->m_optionOrder;
	//if (opStack.size() > 0)
	//{
	//	int num1 = opStack.top();
	//	map < int, vector < pair<string, string>> > num2;
	//	num2.insert({ num1, MessageBuff });
	//	//this->m_pTradeObject->m_allMessage.insert(make_pair(iFunid, num2));
	//	//opStack.p
	//}


	
	auto mapValue = this->m_pTradeObject->m_OptionMap.find(iFunid);
	string str = "未命名操作";
	if (mapValue != this->m_pTradeObject->m_OptionMap.end())
	{
		str = (*mapValue).second;
	}
	//cout << "--------" << str << "---------" << endl;
	m_currDataSet.push_back(MessageBuff);
	MessageBuff.clear();
	//cout << "------反馈数据包模式数据行结束-------------" << endl;
	//cout << "funid:" << iFunid << endl;
	//cout << "refid:" << iRefid << endl;
	//cout << "IssueType:" << iIssueType << endl;
	//cout << "iSet:" << iSet << endl;
	//cout << "iRow:" << iRow << endl;
}