#include <Windows.h>
#include "SharpBridge.h"
#include "mainNetwork.h"
#include "ServerEvents.h"
#include "BridgeEvents.h"
#include <ctime>
#include <stdio.h>
#include "Timer.h"
#include <msclr/marshal.h>

void SharpBridge::bridgeServer::startIVMPServer(int port, String^ serverName, String^ serverLocation, String^ serverSite, 
	bool masterList, bool gtaIV) {
	if(running) return;

	msclr::interop::marshal_context ctx;

	pulseRate = 50;
	running = true;
	initRaknet(8888, ctx.marshal_as<const char*>(serverName), ctx.marshal_as<const char*>(serverLocation), 
		ctx.marshal_as<const char*>(serverSite), masterList, gtaIV);
	BridgeEvents::initContainer();
}

void SharpBridge::bridgeServer::controlServerNow()
{
	while(true)
	{
		clock_t cTime = clock();
		pulseServer();
		SharpBridge::Timer::Manager::Pulse(cTime);
		Sleep(pulseRate);
	}
}

void SharpBridge::bridgeServer::registerModuleEvents(String^ id, ServerEvents^ e)
{
	BridgeEvents::addEventsClass(id, e);
}