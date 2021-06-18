#pragma once

#include "Math.h"

namespace SharpBridge {
	public ref class Object
	{
	private:
		int id;

	public:
		Object(int id);
		void Destroy();

		Vector3^ getPos();
		Quaternion^ getRot();
		unsigned int getWorld();
		unsigned int getModel();

		//Commented methods are not exported by the SDK

		/*bool hasOffset();
		unsigned int getInterior();
		int getAlpha();

		void setPos(Vector3^ pos);
		void setRot(Quaternion^ rot);*/

		void setStreamDis(float dis);
		//float getStream();

		void moveObject(Vector3^ pos, Quaternion^ rot, unsigned int time);

		void setAudio(String^ audioName, int offset);
	};
}