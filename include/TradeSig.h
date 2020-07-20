#pragma once

#include <stack>
#include <map>
#include <string>
#include <vector>
#include "XcTradeApi.h"
#include "myMacro.h"
using namespace std;
enum class OptionType : unsigned char
{
	Login,
	Order,
	QuryMoney,
	OrderCancel,
	OrderBuy
};



using  TYPE_fund_account=char [18];      //       �ʲ��˻�
using  TYPE_exchange_type=char[4];		//	�������
using  TYPE_stock_account= char [11];	//		֤ȯ�˺�
using  TYPE_stock_code=char [6];		//		֤ȯ����
using  TYPE_stock_name=char [32];	//		֤ȯ����
using  TYPE_stock_type=char [4];		//		֤ȯ���
using  TYPE_hold_amount=int	;		//		��������
using  TYPE_current_amount=int;		//		��ǰ����
using  TYPE_enable_amount=int;		//		��������


struct holdStock
{
	TYPE_fund_account fund_account;      //       �ʲ��˻�
	TYPE_exchange_type exchange_type;		//	�������
	TYPE_stock_account stock_account;	//		֤ȯ�˺�
	TYPE_stock_code stock_code;		//		֤ȯ����
	TYPE_stock_name stock_name;	//		֤ȯ����
	TYPE_stock_type stock_type;		//		֤ȯ���
	TYPE_hold_amount hold_amount;		//		��������
	TYPE_current_amount current_amount;		//		��ǰ����
	TYPE_enable_amount enable_amount;		//		��������
//	real_buy_amount			//	�ر���������
//	real_sell_amount		//	�ر���������
//	uncome_buy_amount		//	δ����������
//	uncome_sell_amount		//	δ����������
//	entrust_sell_amount		//	ί����������
//	last_price				//	���¼�
//	cost_price				//	�ɱ���
//	keep_cost_price			//	������
//	income_balance			//	ӯ�����
//	hand_flag				//	�ֱ�־
//	market_value			//	֤ȯ��ֵ
//	av_buy_price			//	�������
//	av_income_balance		//	ʵ��ӯ��
//	cost_balance			//	�ֲֳɱ�
//	position_str			//	��λ��
//	delist_flag				//	���б�־
//	delist_date				//	��������
//	par_value				//	��ֵ
//	income_balance_nofare	//	�޷���ӯ��
//	frozen_amount			//	��������
//	profit_ratio			//	ӯ������(%)
};






using TYPE_op_branch_no = int;
using TYPE_op_entrust_way = char[1];
using TYPE_op_station = char[255];
using TYPE_branch_no = int;
using TYPE_client_id = char[18];
using TYPE_fund_account = char[18];
using TYPE_password = char[15];
using TYPE_password_type = char[1];
using TYPE_user_token = char[512];
using TYPE_entrust_amount = int;
using TYPE_entrust_price = double;
using TYPE_entrust_bs = char[1];
using TYPE_entrust_prop = char[3];
using TYPE_batch_no = int;

struct OrderRequest
{
	 TYPE_op_branch_no op_branch_no;
	 TYPE_op_entrust_way op_entrust_way;
	 TYPE_op_station op_station;
	 TYPE_branch_no branch_no;
	 TYPE_client_id client_id;
	 TYPE_fund_account fund_account;
	 TYPE_password password;
	 TYPE_password_type password_type;
	 TYPE_user_token user_token;
	 TYPE_entrust_amount entrust_amount;
	 TYPE_entrust_price entrust_price;
	 TYPE_entrust_bs entrust_bs;
	 TYPE_entrust_prop entrust_prop;
	 TYPE_stock_code stock_code;
	 TYPE_exchange_type  exchange_type;
};









class autoTrade
{
public:
	autoTrade();
	std::stack<int> m_optionOrder = {}; //�첽�ص�����Ϣ�����ȷ�������õ�����Ϣ���˴�ʹ��ջ
	map<int, vector<vector<pair<string, string>>> >  m_AllMyMsg; //��Ϣ����   ÿ�����Ͷ�Ӧ�����ݼ�
//	std::map < string, std::map<int, vector<pair<string, string>  >  >>   m_allMessage = {};                   ///  �˻�   ���յ���Ϣ��(ÿ�ֱ�Ψһ��ʶ)  ���ն���������Ϣ ÿ��������Ϣ������ֶ�
   // vector<pair<string, string>> m_messageBuff = {};//ÿ�ε���Ϣ�ݴ���

	void Login(const string &account, const string& passWord=" ");
	void OrderBuy(OrderRequest &&);
	void OrderSell(OrderRequest&);
	void OrderCancel(OrderRequest&);
	void QuryMoney();
	void QuryOrderStock();
	void QuryRepository();
	void GetOptionMap();
	void QuryAllStock();
	void stkacct_qry();
	void history_business_qry();
	void history_order_qry();
	OrderRequest GetOrderRequest();




	map<int, string>  m_OptionMap;
	CXcTradeApi* m_pApi = nullptr;
	int m_currMsgAccount = 0;
	//vector<msgContainer> m_MsgContainerObj;
private:

};

class msgContainer
{
public:
	int m_Account = 0;
	map<int, vector<vector<pair<string, string>>> >  m_AllMyMsg; //��Ϣ����   ÿ�����Ͷ�Ӧ�����ݼ�
};

//��ͨί��
//struct  order
//{
//	
//
//
//};
