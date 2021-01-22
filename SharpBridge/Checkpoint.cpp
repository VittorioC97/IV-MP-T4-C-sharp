#include "Checkpoint.h"
#include "apiCheckPoints.h"

SharpBridge::Checkpoint::Checkpoint(int id)
{
	this->id = id;
}

SharpBridge::Vector3^ SharpBridge::Checkpoint::getPos()
{
	apiMath::Vector3 p;
	apiCheckPoint::get(id)->copyPos(p);
	
	return gcnew Vector3(p.x, p.y, p.z);
}

float SharpBridge::Checkpoint::getRadius()
{
	return apiCheckPoint::get(id)->getRadius();
}

int SharpBridge::Checkpoint::getType()
{
	return apiCheckPoint::get(id)->getType();
}

unsigned int SharpBridge::Checkpoint::getWorld()
{
	return apiCheckPoint::get(id)->getWorld();
}

unsigned int SharpBridge::Checkpoint::getColor()
{
	return apiCheckPoint::get(id)->getColor();
}

int SharpBridge::Checkpoint::getBlip()
{
	return apiCheckPoint::get(id)->getBlip();
}

void SharpBridge::Checkpoint::setStreamDistance(float d)
{
	apiCheckPoint::get(id)->setStream(d);
}

float SharpBridge::Checkpoint::getStreamDistance()
{
	return apiCheckPoint::get(id)->getStream();
}