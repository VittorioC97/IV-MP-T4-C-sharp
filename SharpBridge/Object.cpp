#include <msclr/marshal.h>
#include "Object.h"
#include "apiObjects.h"

SharpBridge::Object::Object(int id)
{
	this->id = id;
}

SharpBridge::Vector3^ SharpBridge::Object::getPos()
{
	apiMath::Vector3 p = apiObjects::get(id)->getPos();
	return gcnew Vector3(p.x, p.y, p.x);
}

SharpBridge::Quaternion^ SharpBridge::Object::getRot()
{
	apiMath::Quaternion q = apiObjects::get(id)->getRot();
	return gcnew Quaternion(q.X, q.Y, q.Z, q.W);
}

unsigned int SharpBridge::Object::getWorld()
{
	return apiObjects::get(id)->getWorld();
}

unsigned int SharpBridge::Object::getModel()
{
	return apiObjects::get(id)->getModel();
}

/*bool SharpBridge::Object::hasOffset()
{
	//return apiObjects::get(id)->hasOffset();
}

unsigned int SharpBridge::Object::getInterior()
{
	//return apiObjects::get(id)->getInterior();
}

int SharpBridge::Object::getAlpha()
{
	//return apiObjects::get(id)->getAlpha();
}

void SharpBridge::Object::setPos(Vector3^ pos)
{
	//apiObjects::get(id)->setPos(apiMath::Vector3(pos->x, pos->y, pos->z));
}

void SharpBridge::Object::setRot(Quaternion^ rot)
{
	//apiObjects::get(id)->setRot(apiMath::Quaternion(rot->x, rot->y, rot->z, rot->w));
}*/

void SharpBridge::Object::setStreamDis(float dis)
{
	apiObjects::get(id)->setStreamDis(dis);
}

/*float SharpBridge::Object::getStream()
{
	//return apiObjects::get(id)->getStream();
}*/

void SharpBridge::Object::moveObject(Vector3^ pos, Quaternion^ rot, unsigned int time)
{
	apiObjects::moveObject(id, apiMath::Vector3(pos->x, pos->y, pos->z),
		apiMath::Quaternion(rot->x, rot->y, rot->z, rot->w), time);
}

void SharpBridge::Object::setAudio(String^ audioName, int offset)
{
	msclr::interop::marshal_context ctx;
	const char* converted = ctx.marshal_as<const char*>(audioName);
	char* s = _strdup(converted);
	apiObjects::setAudio(id, s, offset);
}