#include "vehicleList.h"
#include <msclr/marshal.h>
#include "VehicleModels.h"

bool SharpBridge::VehicleModels::isValidModel(int id)
{
	return vehicleList::isValidModel(id);
}

int SharpBridge::VehicleModels::getModelByName(String^ carName)
{
	msclr::interop::marshal_context ctx;
	const char* converted = ctx.marshal_as<const char*>(carName);

	return vehicleList::getIdByName(converted);
}

String^ SharpBridge::VehicleModels::getModelName(int id)
{
	return gcnew String(vehicleList::getModelName(id));
}