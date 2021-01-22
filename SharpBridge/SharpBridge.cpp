#include <Windows.h>
#include "SharpBridge.h"
#include "mainNetwork.h"
#include "ServerEvents.h"
#include "BridgeEvents.h"
#include <ctime>
#include <stdio.h>
#include <msclr/marshal.h>

void SharpBridge::bridgeServer::startIVMPServer()
{
	if(running) return;
	pulseRate = 50;
	running = true;
	initRaknet(8888, "Sharp Test", "Somewhere", "www.iv-mp.eu", false, true);
	BridgeEvents::initContainer();
}

void SharpBridge::bridgeServer::controlServerNow()
{
	clock_t lTime = 0;
	while(true)
	{
		clock_t cTime = clock();
		pulseServer();
		Sleep(pulseRate);
		if(cTime > lTime)
		{
			lTime = cTime + 500;
		}
	}
}

void SharpBridge::bridgeServer::registerModuleEvents(String^ id, ServerEvents^ e)
{
	BridgeEvents::addEventsClass(id, e);
}