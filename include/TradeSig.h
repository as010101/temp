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



using  TYPE_fund_account=char [18];      //       资产账户
using  TYPE_exchange_type=char[4];		//	交易类别
using  TYPE_stock_account= char [11];	//		证券账号
using  TYPE_stock_code=char [6];		//		证券代码
using  TYPE_stock_name=char [32];	//		证券名称
using  TYPE_stock_type=char [4];		//		证券类别
using  TYPE_hold_amount=int	;		//		持有数量
using  TYPE_current_amount=int;		//		当前数量
using  TYPE_enable_amount=int;		//		可用数量


struct holdStock
{
	TYPE_fund_account fund_account;      //       资产账户
	TYPE_exchange_type exchange_type;		//	交易类别
	TYPE_stock_account stock_account;	//		证券账号
	TYPE_stock_code stock_code;		//		证券代码
	TYPE_stock_name stock_name;	//		证券名称
	TYPE_stock_type stock_type;		//		证券类别
	TYPE_hold_amount hold_amount;		//		持有数量
	TYPE_current_amount current_amount;		//		当前数量
	TYPE_enable_amount enable_amount;		//		可用数量
//	real_buy_amount			//	回报买入数量
//	real_sell_amount		//	回报卖出数量
//	uncome_buy_amount		//	未回买入数量
//	uncome_sell_amount		//	未回卖出数量
//	entrust_sell_amount		//	委托卖出数量
//	last_price				//	最新价
//	cost_price				//	成本价
//	keep_cost_price			//	保本价
//	income_balance			//	盈亏金额
//	hand_flag				//	手标志
//	market_value			//	证券市值
//	av_buy_price			//	买入均价
//	av_income_balance		//	实现盈亏
//	cost_balance			//	持仓成本
//	position_str			//	定位串
//	delist_flag				//	退市标志
//	delist_date				//	退市日期
//	par_value				//	面值
//	income_balance_nofare	//	无费用盈亏
//	frozen_amount			//	冻结数量
//	profit_ratio			//	盈亏比例(%)
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
	std::stack<int> m_optionOrder = {}; //异步回调的消息总是先返回最近得到的消息，此处使用栈
	map<int, vector<vector<pair<string, string>>> >  m_AllMyMsg; //消息类型   每种类型对应的数据集
//	std::map < string, std::map<int, vector<pair<string, string>  >  >>   m_allMessage = {};                   ///  账户   接收的消息集(每种被唯一标识)  接收多种类型消息 每种类型消息有许多字段
   // vector<pair<string, string>> m_messageBuff = {};//每次的消息暂存区

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
	map<int, vector<vector<pair<string, string>>> >  m_AllMyMsg; //消息类型   每种类型对应的数据集
};

//普通委托
//struct  order
//{
//	
//
//
//};
