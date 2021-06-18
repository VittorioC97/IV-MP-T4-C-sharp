#pragma once
#include "apiVehicle.h"
#include "Math.h"
using namespace System;

namespace SharpBridge{
	public ref class Vehicle
	{
	private:
		apiVehicle::vehicle* veh;

	public:
		Vehicle(int id);
		void Destroy();

		Vector3^ getPosition();
		Vector3^ getVelocity();
		Vector3^ getRotation();
		Vector3^ getTurnVelocity();

		int getId();
		unsigned int getModel();
		int getDriver(); //Returns the current driver ID or 0
		void setTune(unsigned int part, bool on); //part is 0-9
		bool isTuned(unsigned int part);
		void setColor(int color1, int color2, int color3, int color4);
		int getColor(unsigned int slotId);
		void setIndicator(unsigned int indicator, bool onOrOff); //indicators are 0-1
		bool getIndicator(unsigned int indicator);

		void setPosition(Vector3^ v);
		void setRotation(Vector3^ v);
		void setVelocity(Vector3^ v);

		void setLivery(int livery);
		void setDirtLevel(float level);

		int getEngineHealth();
		void setEngineHealth(int hp, bool fixVisual);

		bool getTire(unsigned int index); //Index is 0-5
		void setTire(unsigned int index, bool status);

		float getGasPedal();
		float getSteering();
		int getBreakOrGas();

		void setEngineFlags(int flags); //0 off, 1 off but startable, 2 on
		int getEngineFlags();

		void setMemBit(unsigned int offset, int dataType, float value);

		void setTrunk(bool open);
		bool getTrunk(bool trunk);

		void setHood(bool open);
		bool getHood(bool trunk);

		void setStreamDistance(float f);
	};
}

