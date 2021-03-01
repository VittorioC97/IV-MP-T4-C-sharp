#include <msclr/marshal.h>
#include "apiObjects.h"
#include "Entities.h"
#include "apiBlips.h"
#include "apiCheckPoints.h"


SharpBridge::Blip^ SharpBridge::Entities::createBlip(Vector3^ pos, int type, unsigned int color, unsigned int world, unsigned int streamDistance,
	bool showAll, System::String^ name){

	apiMath::Vector3 p(pos->x, pos->y, pos->z);
	msclr::interop::marshal_context ctx;
	const char* converted = ctx.marshal_as<const char*>(name);

	return gcnew Blip(apiBlips::add(p, type, color, world, streamDistance, showAll, converted));
}

SharpBridge::Blip^ SharpBridge::Entities::getBlip(int id)
{
	return apiBlips::isValid(id) ? gcnew Blip(id) : nullptr;
}

void SharpBridge::Entities::deleteBlip(int id)
{
	apiBlips::remove(id);
}

SharpBridge::Checkpoint^ SharpBridge::Entities::createCheckPoint(Vector3^ pos, float radius, unsigned int hexColor, int type,
	int blipType, unsigned int vWorld) {

	apiMath::Vector3 v(pos->x, pos->y, pos->z);
	return gcnew Checkpoint(apiCheckPoint::addNew(v, radius, hexColor, type, blipType, vWorld));
}

SharpBridge::Checkpoint^ SharpBridge::Entities::getCheckPoint(int id)
{
	return apiCheckPoint::isValid(id) ? gcnew Checkpoint(id) : nullptr;
}

void SharpBridge::Entities::deleteCheckPoint(int id)
{
	apiCheckPoint::remove(id);
}

SharpBridge::Player^ SharpBridge::Entities::getPlayer(int id)
{
	return apiPlayer::isOn(id) ? gcnew Player(id) : nullptr;
}

System::Collections::Generic::List<SharpBridge::Player^>^ SharpBridge::Entities::getPlayers()
{
	System::Collections::Generic::List<Player^>^ list = gcnew System::Collections::Generic::List<Player^>();
	std::vector<apiPlayer::player*> vec;
	apiPlayer::getPlayers(vec);
	size_t i = 0, s = vec.size();
	for(i; i < s; i++) list->Add(gcnew Player(vec[i]->getID()));
	return list;
}

SharpBridge::Vehicle^ SharpBridge::Entities::createVehicle(int mId, Vector3^ pos, Vector3^ rot, int c1, int c2, int c3, int c4, unsigned int vWorld)
{
	apiMath::Vector3 p(pos->x, pos->y, pos->z), r(rot->x, rot->y, rot->z);
	return gcnew Vehicle(apiVehicle::addVehicle(mId, p, r, c1, c2, c3, c4, vWorld));
}

SharpBridge::Vehicle^ SharpBridge::Entities::getVehicle(int id)
{
	return apiVehicle::isVehicle(id) ? gcnew Vehicle(id) : nullptr;
}

void SharpBridge::Entities::deleteVehicle(int id)
{
	apiVehicle::deleteVehicle(id);
}

SharpBridge::Object^ SharpBridge::Entities::createObject(Vector3^ pos, Quaternion^ rot, unsigned int objHex,
	unsigned int vWorld, bool hasOffset, unsigned int interior, int alpha) {

	apiMath::Vector3 p(pos->x, pos->y, pos->z);
	apiMath::Quaternion q(rot->x, rot->y, rot->z, rot->w);

	return gcnew SharpBridge::Object(apiObjects::addNew(p, q, objHex, vWorld, hasOffset, interior, alpha));
}

SharpBridge::Object^ SharpBridge::Entities::getObject(int id)
{
	return apiObjects::isValid(id) ? gcnew SharpBridge::Object(id) : nullptr;
}

void SharpBridge::Entities::deleteObject(int id)
{
	apiObjects::remove(id);
}

SharpBridge::Dialog^ SharpBridge::Entities::createDialog(unsigned int id, String^ windowName, unsigned int columns)
{
	msclr::interop::marshal_context ctx;
	const char* converted = ctx.marshal_as<const char*>(windowName);
	char* c = _strdup(converted);

	return gcnew Dialog(apiDialog::addNew(id, c, columns));
}

SharpBridge::Dialog^ SharpBridge::Entities::getDialog(unsigned int id)
{
	return apiDialog::isValid(id) ? gcnew Dialog(id) : nullptr;
}

void SharpBridge::Entities::deleteDialog(unsigned int id)
{
	apiDialog::remove(id);
}