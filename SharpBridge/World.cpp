#include "World.h"

void SharpBridge::World::setWeather(unsigned int weather)
{
	world->setWeather(weather);
}

void SharpBridge::World::setTime(unsigned int hour, unsigned int minutes)
{
	world->setTime(hour, minutes);
}

void SharpBridge::World::setMinuteDuration(unsigned int duration)
{
	world->setMinuteDuration(duration);
}

void SharpBridge::World::streamWorldChanges()
{
	world->streamWorldChanges();
}

void SharpBridge::World::getTime(unsigned int^ hour, unsigned int^ minutes)
{
	unsigned int h, m;
	world->getTime(h, m);
	hour = h, minutes = m;
}

unsigned int SharpBridge::World::getWeather()
{
	return world->getWeather();
}

unsigned int SharpBridge::World::getMinuteDuration()
{
	return world->getMinuteDuration();
}