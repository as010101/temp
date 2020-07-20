#include "Spi_Pack.h"
#include "TradeSig.h"
#include <iostream>

using namespace std;

vector<pair<string, string>> MessageBuff = {};///��Ϣ�������
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

/* �������ݰ�ģʽ���ݼ�������Pack��ģʽ��*/
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
	string str = "δ��������";
	if (mapValue != this->m_pTradeObject->m_OptionMap.end())
	{
		str = (*mapValue).second;
	}
	cout << "--------"<<str <<"---------"<< endl;
	cout << "------�������ݰ�ģʽ���ݼ�����-------------" << endl;

	this->m_pTradeObject->m_AllMyMsg.insert(make_pair(iFunid, m_currDataSet));   ///�µĹ�����Ḳ�ǾɵĹ�������Ϣ
	m_currDataSet.clear();
	//cout << "funid:" << iFunid << endl;
	//cout << "refid:" << iRefid << endl;
	//cout << "IssueType:" << iIssueType << endl;
	//cout << "iSet:" << iSet << endl;
}

/* �������ݰ�ģʽ�����н�����Pack��ģʽ��*/
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
	string str = "δ��������";
	if (mapValue != this->m_pTradeObject->m_OptionMap.end())
	{
		str = (*mapValue).second;
	}
	//cout << "--------" << str << "---------" << endl;
	m_currDataSet.push_back(MessageBuff);
	MessageBuff.clear();
	//cout << "------�������ݰ�ģʽ�����н���-------------" << endl;
	//cout << "funid:" << iFunid << endl;
	//cout << "refid:" << iRefid << endl;
	//cout << "IssueType:" << iIssueType << endl;
	//cout << "iSet:" << iSet << endl;
	//cout << "iRow:" << iRow << endl;
}