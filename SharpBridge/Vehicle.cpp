#include "Vehicle.h"

SharpBridge::Vehicle::Vehicle(int id)
{
	veh = &apiVehicle::getVehicle(id);
}

SharpBridge::Vector3^ SharpBridge::Vehicle::getPosition()
{
	apiMath::Vector3 v = veh->getPosition();
	return gcnew Vector3(v.x, v.y, v.z);
}

SharpBridge::Vector3^ SharpBridge::Vehicle::getVelocity()
{
	apiMath::Vector3 v = veh->getVelocity();
	return gcnew Vector3(v.x, v.y, v.z);
}

SharpBridge::Vector3^ SharpBridge::Vehicle::getRotation()
{
	apiMath::Vector3 v = veh->getRotation();
	return gcnew Vector3(v.x, v.y, v.z);
}

SharpBridge::Vector3^ SharpBridge::Vehicle::getTurnVelocity()
{
	apiMath::Vector3 v = veh->getTurnVelocity();
	return gcnew Vector3(v.x, v.y, v.z);
}

int SharpBridge::Vehicle::getId()
{
	return veh->getId();
}

int SharpBridge::Vehicle::getDriver()
{
	return veh->getDriver();
}

void SharpBridge::Vehicle::setTune(unsigned int part, bool on)
{
	if(part < 0 || part > 9) return;
	veh->setTune(part, on);
}

bool SharpBridge::Vehicle::isTuned(unsigned int part)
{
	if(part < 0 || part > 9) return false;
	return veh->isTuned(part);
}

void SharpBridge::Vehicle::setColor(int color1, int color2, int color3, int color4)
{
	veh->setColor(color1, color2, color3, color4);
}

int SharpBridge::Vehicle::getColor(unsigned int slotId)
{
	if(slotId < 0 || slotId > 3) return 0;
	return veh->getColor(slotId);
}

void SharpBridge::Vehicle::setIndicator(unsigned int indicator, bool onOrOff)
{
	if(indicator < 0 || indicator > 1) return;
	veh->setIndicator(indicator, onOrOff);
}

bool SharpBridge::Vehicle::getIndicator(unsigned int indicator)
{
	if(indicator < 0 || indicator > 1) return false;
	return veh->getIndicator(indicator);
}

void SharpBridge::Vehicle::setPosition(Vector3^ v)
{
	apiMath::Vector3 p(v->x, v->y, v->z);
	veh->setPosition(p);
}

void SharpBridge::Vehicle::setRotation(Vector3^ v)
{
	apiMath::Vector3 p(v->x, v->y, v->z);
	veh->setRotation(p);
}

void SharpBridge::Vehicle::setVelocity(Vector3^ v)
{
	apiMath::Vector3 p(v->x, v->y, v->z);
	veh->setVelocity(p);
}

void SharpBridge::Vehicle::setLivery(int livery)
{
	veh->setLivery(livery);
}

void SharpBridge::Vehicle::setDirtLevel(float level)
{
	veh->setDirtLevel(level);
}

int SharpBridge::Vehicle::getEngineHealth()
{
	return veh->getEngineHealth();
}

void SharpBridge::Vehicle::setEngineHealth(int hp, bool fixVisual)
{
	veh->setEngineHealth(hp, fixVisual);
}


bool SharpBridge::Vehicle::getTire(unsigned int index) //Index is 0-5
{
	if(index < 0 || index > 5) return false;
	return veh->getTire(index);
}

void SharpBridge::Vehicle::setTire(unsigned int index, bool status)
{
	if(index < 0 || index > 5) return;
	veh->setTire(index, status);
}

float SharpBridge::Vehicle::getGasPedal()
{
	return veh->getGasPedal();
}

float SharpBridge::Vehicle::getSteering()
{
	return veh->getSteering();
}

int SharpBridge::Vehicle::getBreakOrGas()
{
	return veh->getBreakOrGas();
}

void SharpBridge::Vehicle::setEngineFlags(int flags) //0 off, 1 off but startable, 2 on
{
	veh->setEngineFlags(flags);
}

int SharpBridge::Vehicle::getEngineFlags()
{
	return veh->getEngineFlags();
}

void SharpBridge::Vehicle::setMemBit(unsigned int offset, int dataType, float value)
{
	veh->setMemBit(offset, dataType, value);
}

void SharpBridge::Vehicle::setTrunk(bool open)
{
	veh->setTrunkHood(true, open);
}

void SharpBridge::Vehicle::setHood(bool open)
{
	veh->setTrunkHood(false, open);
}

bool SharpBridge::Vehicle::getTrunk(bool trunk)
{
	return veh->getTrunkHood(true);
}

bool SharpBridge::Vehicle::getHood(bool trunk)
{
	return veh->getTrunkHood(false);
}

void SharpBridge::Vehicle::setStreamDistance(float f)
{
	veh->setStreamDistance(f);
}
