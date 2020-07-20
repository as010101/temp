
#define _CRT_SECURE_NO_WARNINGS

#include "TradeSig.h"


///////��ʼ��
autoTrade::autoTrade()
{
	GetOptionMap();

}

void autoTrade::GetOptionMap()
{
	this->m_OptionMap.insert({ SIG_MY_ORDER ,"��ͨί��" });
	this->m_OptionMap.insert({ SIG_MY_SELL ,"ί�г���" });
	this->m_OptionMap.insert({ SIG_MY_ORDER_QUERY ,"֤ȯί�в�ѯ" });
	this->m_OptionMap.insert({ SIG_MY_HOLD_STOCK ,"�ֲֲ�ѯ" });
	this->m_OptionMap.insert({ SIG_MY_LOGIN ,"�ͻ���¼" });
	this->m_OptionMap.insert({ SIG_MY_MONEY_QUERY ,"�ʽ���ٲ�ѯ" });
	this->m_OptionMap.insert({ SIG_MY_STOCKHOLDER ,"�ɶ���Ϣ" });  ///
	//this->m_OptionMap.insert({ 339303 ,"��ʷί��" }); ///
	//this->m_OptionMap.insert({ 339304 ,"��ʷ֤ȯ�ɽ���ѯ" });
	//this->m_OptionMap.insert({ 330300 ,"֤ȯ������Ϣ��ѯ" });




}

OrderRequest autoTrade::GetOrderRequest()
{
	OrderRequest rlt;
	rlt.branch_no = 0;
	strcpy(rlt.op_entrust_way, "1");
	strcpy(rlt.op_station, " ");
	rlt.branch_no =1 ;
	strcpy(rlt.client_id, "101025702");
	strcpy(rlt.password, "111111");
	strcpy(rlt.password_type, "2");
	strcpy(rlt.exchange_type, "0");  //0  �ʽ�  1  �Ϻ�
	strcpy(rlt.stock_code, "688010");
	rlt.entrust_amount = 300;
	rlt.entrust_price=7.8;
	strcpy(rlt.entrust_bs, "1");  //   1 buy
	strcpy(rlt.entrust_prop, "0");

	return  rlt;
}

//��¼
void autoTrade::Login(const string& account, const string& passWord )
{

	this->m_currMsgAccount = stoi(account);        ///������Ϣ�����˻�
	{

		this->m_pApi->BeginPack();
		//��¼
		//pApi->SetPackValue("user_token", " ");
		this->m_pApi->SetPackValue("op_branch_no", "0");
		this->m_pApi->SetPackValue("op_entrust_way", "1");
		this->m_pApi->SetPackValue("op_station", " ");
		this->m_pApi->SetPackValue("branch_no", "1");
		this->m_pApi->SetPackValue("client_id", "101025702");
		this->m_pApi->SetPackValue("password", "111111");
		this->m_pApi->SetPackValue("password_type", "2");
		this->m_pApi->SetPackValue("input_content", "1");
		this->m_pApi->SetPackValue("content_type", "0");
		this->m_pApi->SetPackValue("account_content", "101025702");
		this->m_pApi->SetPackValue("terminal_version", "demo");
		this->m_pApi->SetPackValue("client_ip", "127.0.0.1");
		this->m_pApi->SetPackValue("client_mac", "demo");
		this->m_pApi->EndPack();

		int ret1 = this->m_pApi->SendMsg(SIG_MY_LOGIN, 2, 1);
		if (ret1 < 0)
		{
			printf("sendmsg failed!\n");
			return;
		}

	}

}
//ί����
void autoTrade::OrderBuy(OrderRequest&& request)
{


	{


		this->m_pApi->BeginPack();
		//string str = request.branch_no;
	//	this->m_pApi->SetPackValue("user_token", "ZosNDoDNHYL3QzCKHXwB4Zn0HB+sNua2YWFhYQ==");
		this->m_pApi->SetPackValue("op_branch_no", to_string(request.branch_no).c_str());
		this->m_pApi->SetPackValue("op_entrust_way", request.op_entrust_way);
		this->m_pApi->SetPackValue("op_station", request.op_station);
		this->m_pApi->SetPackValue("branch_no", to_string(request.branch_no).c_str());
		this->m_pApi->SetPackValue("client_id", request.client_id);
		this->m_pApi->SetPackValue("password", request.password);
		this->m_pApi->SetPackValue("password_type", request.password_type);
		this->m_pApi->SetPackValue("exchange_type", request.exchange_type);
		this->m_pApi->SetPackValue("stock_code", request.stock_code);
		this->m_pApi->SetPackValue("entrust_amount", to_string(request.entrust_amount).c_str());
		this->m_pApi->SetPackValue("entrust_price", to_string(request.entrust_price).c_str());
		this->m_pApi->SetPackValue("entrust_bs", request.entrust_bs);  //  1 buy
		this->m_pApi->SetPackValue("entrust_prop",request.entrust_prop);
		//pApi->SetPackValue("subsystemno", "2");

		this->m_pApi->EndPack();

		int ret1 = this->m_pApi->SendMsg(SIG_MY_ORDER, 2, 1);
		if (ret1 < 0)
		{
			printf("sendmsg failed!\n");
		
			return ;
		}
	}



}
//ί����
void autoTrade::OrderSell(OrderRequest& request)
{

	{
		this->m_pApi->BeginPack();

		//	this->m_pApi->SetPackValue("user_token", "ZosNDoDNHYL3QzCKHXwB4Zn0HB+sNua2YWFhYQ==");
		this->m_pApi->SetPackValue("op_branch_no", to_string(request.branch_no).c_str());
		this->m_pApi->SetPackValue("op_entrust_way", request.op_entrust_way);
		this->m_pApi->SetPackValue("op_station", request.op_station);
		this->m_pApi->SetPackValue("branch_no", to_string(request.branch_no).c_str());
		this->m_pApi->SetPackValue("client_id", request.client_id);
		this->m_pApi->SetPackValue("password", request.password);
		this->m_pApi->SetPackValue("password_type", request.password_type);
		this->m_pApi->SetPackValue("exchange_type", request.exchange_type);
		this->m_pApi->SetPackValue("stock_code", request.stock_code);
		this->m_pApi->SetPackValue("entrust_amount", to_string(request.entrust_amount).c_str());
		this->m_pApi->SetPackValue("entrust_price", to_string(request.entrust_price).c_str());
		this->m_pApi->SetPackValue("entrust_bs", request.entrust_bs);  //  1 buy
		this->m_pApi->SetPackValue("entrust_prop", request.entrust_prop);
		//pApi->SetPackValue("subsystemno", "2");

		this->m_pApi->EndPack();

		int ret1 = this->m_pApi->SendMsg(SIG_MY_ORDER, 2, 1);
		if (ret1 < 0)
		{
			printf("sendmsg failed!\n");

			return;
		}
	}

}
//����
void autoTrade::OrderCancel(OrderRequest& request)
{

	{
		this->m_pApi->BeginPack();
	
		this->m_pApi->SetPackValue("op_branch_no", to_string(request.branch_no).c_str());
		this->m_pApi->SetPackValue("op_entrust_way", request.op_entrust_way);
		this->m_pApi->SetPackValue("op_station", request.op_station);
		this->m_pApi->SetPackValue("branch_no", to_string(request.branch_no).c_str());
		this->m_pApi->SetPackValue("client_id", request.client_id);
		this->m_pApi->SetPackValue("password", request.password);
		this->m_pApi->SetPackValue("password_type", request.password_type);
		this->m_pApi->SetPackValue("exchange_type", request.exchange_type);
		this->m_pApi->SetPackValue("stock_code", request.stock_code);
		this->m_pApi->SetPackValue("entrust_amount", to_string(request.entrust_amount).c_str());
		this->m_pApi->SetPackValue("entrust_price", to_string(request.entrust_price).c_str());
		this->m_pApi->SetPackValue("entrust_bs", request.entrust_bs);  //  1 buy
		this->m_pApi->SetPackValue("entrust_prop", request.entrust_prop);
		this->m_pApi->EndPack();

		int ret1 = this->m_pApi->SendMsg(SIG_MY_SELL, 2, 1);
		if (ret1 < 0)
		{
			printf("sendmsg failed!\n");

			return ;
		}
	}


}

//�����ʽ��ѯ
void autoTrade::QuryMoney()
{}

//֤ȯί�в�ѯ
void autoTrade::QuryOrderStock()
{


	{
		this->m_pApi->BeginPack();

//		this->m_pApi->SetPackValue("user_token", "VqboDbTYuib3QzCKHXwB4Zn0HB+sNua2YWFhYQ==");
		this->m_pApi->SetPackValue("op_branch_no", "0");
		this->m_pApi->SetPackValue("op_entrust_way", "7");
		this->m_pApi->SetPackValue("op_station", " ");
		this->m_pApi->SetPackValue("branch_no", "1");
		this->m_pApi->SetPackValue("client_id", "101025702");
		this->m_pApi->SetPackValue("fund_account", "101025702");
		this->m_pApi->SetPackValue("password", "111111");
		this->m_pApi->SetPackValue("password_type", "2");
		this->m_pApi->SetPackValue("exchange_type", "1");

		//pApi->SetPackValue("subsystemno", "2");

		this->m_pApi->EndPack();

		int ret1 = this->m_pApi->SendMsg(SIG_MY_ORDER_QUERY, 2, 1);
		if (ret1 < 0)
		{
			printf("sendmsg failed!\n");

			return;
		}
	}



}


////�ͻ�֤ȯ��ѯ
//void autoTrade::QuryAllStock()
//{
//
//
//	{
//		this->m_pApi->BeginPack();
//
//		//		this->m_pApi->SetPackValue("user_token", "VqboDbTYuib3QzCKHXwB4Zn0HB+sNua2YWFhYQ==");
//		this->m_pApi->SetPackValue("op_branch_no", "0");
//		this->m_pApi->SetPackValue("op_entrust_way", "7");
//		this->m_pApi->SetPackValue("op_station", " ");
//		this->m_pApi->SetPackValue("branch_no", "1");
//		this->m_pApi->SetPackValue("client_id", "101025702");
//		this->m_pApi->SetPackValue("fund_account", "101025702");
//		this->m_pApi->SetPackValue("password", "111111");
//		//pApi->SetPackValue("subsystemno", "2");
//
//		this->m_pApi->EndPack();
//
//		int ret1 = this->m_pApi->SendMsg(333620, 2, 1);
//		if (ret1 < 0)
//		{
//			printf("sendmsg failed!\n");
//
//			return;
//		}
//	}
//
//
//
//}


//�ɶ���Ϣ
void autoTrade::stkacct_qry()
{


	{
		this->m_pApi->BeginPack();

		//		this->m_pApi->SetPackValue("user_token", "VqboDbTYuib3QzCKHXwB4Zn0HB+sNua2YWFhYQ==");
		this->m_pApi->SetPackValue("op_branch_no", "0");
		this->m_pApi->SetPackValue("op_entrust_way","7");
		this->m_pApi->SetPackValue("op_station", " ");
		this->m_pApi->SetPackValue("branch_no", "10");
		this->m_pApi->SetPackValue("password", "111111");
		this->m_pApi->SetPackValue("client_id", "101025702");
		//this->m_pApi->SetPackValue("user_token", "su6nMi03Q85kKkaUtNQOxv3XyXNsDPpuYWFhYQ==");
		//this->m_pApi->SetPackValue("exchange_type", "0");
//		this->m_pApi->SetPackValue("fund_account", "101025702");
		//pApi->SetPackValue("subsystemno", "2");

		this->m_pApi->EndPack();

		int ret1 = this->m_pApi->SendMsg(SIG_MY_STOCKHOLDER, 2, 1);
		if (ret1 < 0)
		{
			printf("sendmsg failed!\n");

			return;
		}
	}



}


////��ʷ֤ȯ�ɽ���ѯ
//void autoTrade::history_business_qry()
//{
//
//
//	{
//		this->m_pApi->BeginPack();
//
//		//		this->m_pApi->SetPackValue("user_token", "VqboDbTYuib3QzCKHXwB4Zn0HB+sNua2YWFhYQ==");
//		this->m_pApi->SetPackValue("op_branch_no", "0");
//		this->m_pApi->SetPackValue("op_entrust_way", "7");
//		this->m_pApi->SetPackValue("op_station", " ");
//		this->m_pApi->SetPackValue("branch_no", "1");
//		this->m_pApi->SetPackValue("password", "111111");
//		this->m_pApi->SetPackValue("client_id", "101025702");
//		this->m_pApi->SetPackValue("fund_account", "101025702");
//		this->m_pApi->SetPackValue("start_date", "20200717");
//		this->m_pApi->SetPackValue("end_date", "20200717");
//		//		this->m_pApi->SetPackValue("fund_account", "101025702");
//				//pApi->SetPackValue("subsystemno", "2");
//
//		this->m_pApi->EndPack();
//
//		int ret1 = this->m_pApi->SendMsg(339304, 2, 1);
//		if (ret1 < 0)
//		{
//			printf("sendmsg failed!\n");
//
//			return;
//		}
//	}
//
//
//
//}
//
//
////��ʷί�в�ѯ
//void autoTrade::history_order_qry()
//{
//
//
//	{
//		this->m_pApi->BeginPack();
//
//		//		this->m_pApi->SetPackValue("user_token", "VqboDbTYuib3QzCKHXwB4Zn0HB+sNua2YWFhYQ==");
//		this->m_pApi->SetPackValue("op_branch_no", "0");
//		this->m_pApi->SetPackValue("op_entrust_way", "7");
//		this->m_pApi->SetPackValue("op_station", " ");
//		this->m_pApi->SetPackValue("branch_no", "1");
//		this->m_pApi->SetPackValue("password", "111111");
//		this->m_pApi->SetPackValue("client_id", "101025702");
//		this->m_pApi->SetPackValue("fund_account", "101025702");
//		this->m_pApi->SetPackValue("start_date", "20200717");
//		this->m_pApi->SetPackValue("end_date", "20200717");
//		//		this->m_pApi->SetPackValue("fund_account", "101025702");
//				//pApi->SetPackValue("subsystemno", "2");
//
//		this->m_pApi->EndPack();
//
//		int ret1 = this->m_pApi->SendMsg(339303, 2, 1);
//		char* p = this->m_pApi->GetLastErrorMsg();
//		if (ret1 < 0)
//		{
//			printf("sendmsg failed!\n");
//
//			return;
//		}
//	}
//
//
//
//}

///�ֲֲ�ѯ
void autoTrade::QuryRepository()
{


	{
		this->m_pApi->BeginPack();

//		this->m_pApi->SetPackValue("user_token", "VqboDbTYuib3QzCKHXwB4Zn0HB+sNua2YWFhYQ==");
		this->m_pApi->SetPackValue("op_branch_no", "0");
		this->m_pApi->SetPackValue("op_entrust_way", "7");
		this->m_pApi->SetPackValue("op_station", " ");
		this->m_pApi->SetPackValue("branch_no", "1");
		this->m_pApi->SetPackValue("client_id", "101025702");
		this->m_pApi->SetPackValue("fund_account", "101025702");
		this->m_pApi->SetPackValue("password", "111111");
		this->m_pApi->SetPackValue("password_type", "2");
		this->m_pApi->SetPackValue("exchange_type", "1");

		//pApi->SetPackValue("subsystemno", "2");

		this->m_pApi->EndPack();

		int ret1 = this->m_pApi->SendMsg(SIG_MY_HOLD_STOCK, 2, 1);
		if (ret1 < 0)
		{
			printf("sendmsg failed!\n");

			return;
		}
	}



}

//

void CharToString(string &s,char *t)
{


}

