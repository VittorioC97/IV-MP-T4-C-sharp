#pragma once

#include "Blip.h"
#include "Checkpoint.h"
#include "Player.h"
#include "Vehicle.h"
#include "Object.h"
#include "Dialog.h"

namespace SharpBridge {
	public ref class Entities abstract sealed
	{
	public:
		static Blip^ createBlip(Vector3^ pos, int type, unsigned int color, unsigned int world, unsigned int streamDistance,
			bool showAll, System::String^ name);
		static Blip^ getBlip(int id);
		static void deleteBlip(int id);

		static Checkpoint^ createCheckPoint(Vector3^ pos, float radius, unsigned int hexColor, int type, int blipType, unsigned int vWorld);
		static Checkpoint^ getCheckPoint(int id);
		static void deleteCheckPoint(int id);

		static Player^ getPlayer(int id);
		static System::Collections::Generic::List<Player^>^ getPlayers();

		static Vehicle^ createVehicle(int mId, Vector3^ pos, Vector3^ rot, int c1, int c2, int c3, int c4, unsigned int vWorld);
		static Vehicle^ getVehicle(int id);

		static SharpBridge::Object^ createObject(Vector3^ pos, Quaternion^ rot, unsigned int objHex,
			unsigned int vWorld, bool hasOffset, unsigned int interior, int alpha);
		static SharpBridge::Object^ getObject(int id);

		static Dialog^ createDialog(unsigned int id, String^ windowName, unsigned int columns);
		static Dialog^ getDialog(unsigned int id);
		static void deleteDialog(unsigned int id);
	};
}
