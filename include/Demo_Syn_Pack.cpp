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
	
	if (pApi->Register(Trans_Mode_SYN, Data_Proto_Pack) < 0)
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

	pApi->BeginPack();

	//增加字段名称 333002
	pApi->SetPackValue("user_token", " ");
	pApi->SetPackValue("op_branch_no", "0");
	pApi->SetPackValue("op_entrust_way", "7");
	pApi->SetPackValue("op_station", "");
	pApi->SetPackValue("branch_no", "1");
	pApi->SetPackValue("client_id", "10000023");
	pApi->SetPackValue("password", "111111");
	pApi->SetPackValue("password_type", "2");
	pApi->SetPackValue("exchange_type", "1");
	pApi->SetPackValue("stock_code", "600018");
	pApi->SetPackValue("entrust_amount", "100");
	pApi->SetPackValue("entrust_price", "0.1");
	pApi->SetPackValue("entrust_bs", "1");
	pApi->SetPackValue("entrust_prop", "0");
	pApi->EndPack();

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

	int iSet, iRow, iCol;
	char szKey[Field_Name_Length] = { 0 };
	char szValue[Field_Value_Length] = { 0 };
	iRow = pApi->GetCurRowCount();
	iCol = pApi->GetCurColCount();
	iSet = pApi->GetDataSetCount();
	for (int k = 0; k < iSet; k++)
	{
		pApi->GetCurDataSet(k);
		for (int i = 0; i < iRow; i++)
		{
			for (int j = 0; j < iCol; j++)
			{
				pApi->GetColName(j, szKey);
				pApi->GetColValue(j, szValue);
				printf("%s:%s\n", szKey, szValue);
			}
			pApi->GetNextRow();
		}
	}

	MY_PAUSE();

	pApi->Release();
#ifndef _WIN32
	dlclose(hdll);
#endif
	MY_PAUSE();
}
