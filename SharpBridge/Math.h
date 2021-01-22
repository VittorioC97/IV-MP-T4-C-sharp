#pragma once
#include <math.h>
using namespace System;

namespace SharpBridge {
	public ref class Vector3 {
	public:
		float x, y, z;

		Vector3()
		{
			x = y = z = 0.0f;
		}
		
		Vector3(float x, float y, float z)
		{
			this->x = x, this->y = y, this->z = z;
		}

		void copyFrom(Vector3^ v)
		{
			this->x = v->x, this->y = v->y, this->z = v->z;
		}

		float distance(Vector3^ v)
		{
			return sqrtf(powf(x-v->x, 2) + powf(y-v->y, 2) + powf(z - v->z, 2));
		}

		/*void fromQuaternion()
		{

		}*/
	};

	public ref class Quaternion {
	public:
		float x, y, z, w;

		Quaternion()
		{
			x = y = z = w = 0.0f;
		}

		Quaternion(float x, float y, float z, float w)
		{
			this->x = x, this->y = y, this->z = z, this->w = w;
		}

		void copyFrom(Vector3^ v)
		{
			this->x = v->x, this->y = v->y, this->z = v->z;
		}

		float distance(Vector3^ v)
		{
			return sqrtf(powf(x - v->x, 2) + powf(y - v->y, 2) + powf(z - v->z, 2));
		}

		/*void fromVector3()
		{

		}*/
	};
}