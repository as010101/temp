#include "XcTrade_Define.h"
#include "XcTradeApi.h"

inline void MY_PAUSE()
{
	printf("click any key to continue...\r\n");
	getchar();
}

int main()
{
#ifdef _WIN32  // windows下测试代码
	CXcTradeApi* pApi = CXcTradeApi::CreateTradeApi();
#else   // linux下测试代码
	typedef CXcTradeApi*(*p_Create)();
	p_Create API_Create = NULL;
	void* hdll = dlopen("libXcTradeApi.so", RTLD_LAZY);
	API_Create = (p_Create)dlsym(hdll, "CreateTradeApi");
	CXcTradeApi* pApi = API_Create();
#endif
	if (pApi->Register(Trans_Mode_SYN, Data_Proto_Json) < 0)
	{
		printf("register failed!\n");
		MY_PAUSE();
		return 0;
	}
	char *license = "license.dat";
	if (pApi->Connect("10.36.40.81:10088", license, System_UFX, "10000023") < 0)
	{
		printf("connect failed!\n");
		MY_PAUSE();
		return 0;
	}
	printf("Space:%d, Frequency:%d\n", pApi->GetSpace(), pApi->GetFrequency());
	MY_PAUSE();

	string startStr = "{";
	string endStr = "}";
	string strRequire_data = startStr
		+ "\"user_token\":\" \","
		+ "\"op_branch_no\":\"0\","
		+ "\"op_entrust_way\":\"7\","
		+ "\"input_content\":\"1\","
		+ "\"op_station\":\" \","
		+ "\"branch_no\":\"1\","
		+ "\"client_id\":\"10000023\","
		+ "\"account_content\":\"10000023\","
		+ "\"password\":\"111111\","
		+ "\"password_type\":\"2\","
		+ "\"exchange_type\":\"1\","
		+ "\"stock_code\":\"600018\","
		+ "\"entrust_amount\":\"100\","
		+ "\"entrust_price\":\"0.1\","
		+ "\"entrust_bs\":\"1\","
		+ "\"entrust_prop\":\"0\""
		+ endStr;
	int ret = pApi->SetJsonValue(strRequire_data.c_str());
	if (ret != 0)
	{
		printf("SetJsonValue!%d\n", ret);
		MY_PAUSE();
		return 0;
	}

	if (pApi->SendMsg(333002, 2, 1) < 0)
	{
		printf("sendmsg failed!\n");
		MY_PAUSE();
		return 0;
	}

	int ret1 = pApi->RecvMsg();
	if (ret1 < 0)
	{
		printf("recvmsg failed!\n");
		MY_PAUSE();
		return 0;
	}

	char* cResponse = new char[ret1];
	pApi->GetJsonValue(cResponse);
	cout << cResponse << endl;

	MY_PAUSE();

	pApi->Release();
#ifndef _WIN32
	dlclose(hdll);
#endif
	MY_PAUSE();
}