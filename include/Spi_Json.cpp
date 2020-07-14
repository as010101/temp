#include "Spi_Json.h"

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
