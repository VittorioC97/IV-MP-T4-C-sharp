#include "apiMath.h"
#include <exporting.h>

#ifndef apiObjects_H
#define apiObjects_H

namespace apiObjects
{
	class object
	{
		private:
			apiMath::Vector3 pos;
			apiMath::Quaternion rot;

			unsigned int objHex;
			unsigned int vWorld;

			unsigned int interior;
			int alpha;
			bool hasOffSet;

			float streamDistance;

		public:
			object(apiMath::Vector3 pos, apiMath::Quaternion rot, unsigned int objHex, 
				unsigned int vWorld, bool hasOffset, unsigned int interior, int alpha);
			~object();

			void copyPos(apiMath::Vector3& buf){ buf = pos; }

			DLL apiMath::Vector3 getPos();
			DLL apiMath::Quaternion getRot();
			DLL unsigned int getWorld();
			DLL unsigned int getModel();

			bool hasOffset();
			unsigned int getInterior();
			int getAlpha();

			void setPos(apiMath::Vector3 pos);
			void setRot(apiMath::Quaternion rot);

			DLL void setStreamDis(float dis) { this->streamDistance = dis; }
			float getStream() { return this->streamDistance; }
	};

	DLL int addNew(apiMath::Vector3 pos, apiMath::Quaternion rot, unsigned int objHex, 
		unsigned int vWorld, bool hasOffset, unsigned int interior, int alpha);
	DLL void remove(int id);
	DLL bool isValid(int id);
	DLL object* get(int id); //Throws exception

	DLL void moveObject(int id, apiMath::Vector3 pos, apiMath::Quaternion rot, unsigned int time);

	DLL void setAudio(int id, char* audioName, int offset);
}

#endif