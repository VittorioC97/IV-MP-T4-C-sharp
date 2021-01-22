#include "ServerEvents.h"

public ref class BridgeEvents abstract sealed
{
public: 
	static Dictionary<String^, SharpBridge::ServerEvents^>^ moduleEvents;

	static void initContainer();
	static void addEventsClass(String^ id, SharpBridge::ServerEvents^ e);
};