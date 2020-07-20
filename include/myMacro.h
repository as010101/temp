#pragma once
#define SIG_MY_MONEY 332255//客户资金精确查询
//#define 332901//组合成份查询
//#define 332902//组合买入
//#define 332903//组合卖出
//#define 332253//银行余额查询
 
#define SIG_MY_ORDER 333002//普通委托
#define SIG_MY_SELL 333017//委托撤单
#define SIG_MY_ORDER_QUERY  333101  //证券委托查询
#define SIG_MY_HOLD_STOCK 333104    //持仓查询
#define SIG_MY_LOGIN 331100 //客户登录
#define SIG_MY_MONEY_QUERY 332254  //资金快速查询
#define SIG_MY_STOCKHOLDER 331300  //股东信息  
#define SIG_MY_ALL_STOCK  330300 //证券代码信息查询


//  银行查询
//pApi->SetPackValue("user_token", " ");
//pApi->SetPackValue("op_branch_no", "0");
//pApi->SetPackValue("op_entrust_way", "7");
//pApi->SetPackValue("op_station", "");
//pApi->SetPackValue("branch_no", "1");
//pApi->SetPackValue("client_id", "10000023");
//pApi->SetPackValue("password", "111111");
//pApi->SetPackValue("fund_password", " ");
//pApi->SetPackValue("bank_password", " ");
//pApi->SetPackValue("bank_no", "0");
//pApi->SetPackValue("money_type", "0");