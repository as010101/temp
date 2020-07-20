#pragma comment (lib,"XcTradeApi.lib")
#include "XcTrade_Define.h"
#include "XcTradeApi.h"
#include "Spi_Pack.h"
#include "myMacro.h"
#include "TradeSig.h"
#include <thread>
#pragma comment (lib,"XcTradeApi.lib")
inline void MY_PAUSE()
{
	printf("click any key to continue...\r\n");
	getchar();
}

void Login()
{
}
int main()
{
#ifdef _WIN32  // windows�²��Դ���
	CXcTradeApi* pApi = CXcTradeApi::CreateTradeApi();
	
#else   // linux�²��Դ���
	typedef CXcTradeApi*(*p_Create)();
	p_Create API_Create = NULL;
	void* hdll = dlopen("libXcTradeApi.so", RTLD_LAZY);
	API_Create = (p_Create)dlsym(hdll, "CreateTradeApi");
	CXcTradeApi* pApi = API_Create();
#endif
	autoTrade* pTrade = new autoTrade;
	CXcTradeSpi* pSpi = new CSpi(pTrade);
	//CXcTradeSpi* pSpi = new CSpi();

    pTrade->m_pApi = pApi;

	if (pApi->Register(Trans_Mode_ASY, Data_Proto_Pack, pSpi) < 0)
	{
		printf("register failed!\n");
		MY_PAUSE();
		return 0;
	}
	char *license = const_cast<char *>("license.dat");
	if (pApi->Connect(const_cast < char*>("180.169.89.22:10188"), license, System_UFX, const_cast <char*>("101025702")) < 0)
	{
		const char* p = pApi->GetLastErrorMsg();
		printf("connect failed!\n");
		printf(p);
		MY_PAUSE();
		return 0;
	}
	printf("Space:%d, Frequency:%d\n", pApi->GetSpace(), pApi->GetFrequency());

	char* p = pApi->GetLastErrorMsg();
	string ID = "101025702";
		//��¼
	pTrade->Login(ID);
	//ί����

	pTrade->OrderBuy(pTrade->GetOrderRequest());
	//
	//pTrade->OrderCancel();
	//pTrade->OrderSell();
	//�ֲֲ�ѯ
	//pTrade->QuryRepository();
	//֤ȯ��ѯ
	pTrade->QuryOrderStock();
	//ί����
	//pTrade->OrderCancel();
	//�ɶ���Ϣ
	//pTrade->stkacct_qry();
	//��ʷ֤ȯ�ɽ���ѯ
 //  pTrade->history_business_qry();

	//��ʷί�в�ѯ
//	pTrade->history_order_qry();

	//�ͻ�֤ȯ��ѯ
//	pTrade->QuryAllStock();




	std::this_thread::sleep_for(std::chrono::seconds(5));
		
	cout << "end---" << endl;
	//MY_PAUSE();

	pApi->Release();
#ifndef _WIN32
	dlclose(hdll);
#endif
	//MY_PAUSE();
	return 0;
}

