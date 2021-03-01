#pragma once
#include "apiPlayer.h"
#include "Math.h"

using namespace System;

namespace SharpBridge
{
	public ref class Player
	{
	private:
		apiPlayer::player* player;
		//unsigned long long engineId;

	public:
		Player(int id);

		float getHeading();
		void setHeading(float h);

		Vector3^  getPos();
		void setPos(Vector3^ pos);
		int getID();

		String^ getNick();
		void setNick(String^ nick);

		void sendMsg(String^ msg, unsigned int hex);
		void sendColoredMsg(int msgId);

		void setSkinId(unsigned int model);
		void setSkinModel(unsigned int id);
		unsigned int getSkinModel();

		void setWorld(unsigned int vWorld);
		unsigned int getWorld();

		void giveWeapon(unsigned int weaponId, unsigned int ammo);
		void removeWeapon(unsigned int weaponId); // Use weapon ID 0 to remove all weapons

		void setHealth(int hp);
		int getHealth(); //Ranges from 0-200 when the player is alive, negative values if dead

		void setColor(unsigned int hex); //RGB
		unsigned int getColor();

		void spawn(Vector3^ pos); //Must be used when the credentials arrive
		void setRespawnPos(Vector3^ pos); //Must be used to set a new position only

		int getDriving(); //Returns 0 if on foot
		void getPassenger(int^ vehicle, int^ seat);
		int isInVehicle(); //Checks for driving and passenger or returns 0 if on foot
		void putInVehicle(int vehicleId, int seatId); //Seats: 0 driver, 1-3 passengers
		void removeFromVehicle();

		//drawText time should be 0 for infinite
		void drawText(int classId, float x, float y, float sx, float sy, String^ txt, int time, unsigned int color);
		void updateText(int classId, String^ txt, unsigned int newColor);
		void drawInfoText(String^ txt, int time);
		void drawRect(int classId, float x, float y, float sx, float sy, unsigned int color);
		void wipeDrawClass(int classId);

		int getWeapon();
		int getAmmo();

		void setFrozen(bool b);

		void debugPlayer(int playerid);
		void debugVehicle(int vehicleid);

		void disconnect();

		int getPing(bool average);

		int getAnim();

		void showDialogList(unsigned int dialogId);

		void setClothes(unsigned int part, unsigned int value); //part is 0-8
		unsigned int getClothes(unsigned int part);
		void setProperty(unsigned int part, unsigned int value); //part is 0-1
		unsigned int getProperty(unsigned int part);

		void forceAnim(String^ animGroup, String^ animName, bool loop);
		void setSitIdleAnim(String^ animGroup, String^ animName, int num);
		void forceSitNow();
		void stopAnims();

		void setKeyHook(unsigned int virtualKey, bool addOrRemove); //Virtual keys can be found online

		String^ getIp();

		void showBlip(int blipId, bool show);

		void cam_setPos(Vector3^pos, unsigned int camWorld);
		void cam_setLookAt(Vector3^ pos);
		void cam_attachOnPlayer(int playerid);

		unsigned int getSerialSize(); //Returns the amount of serials
		String^ getSerial(unsigned int i);

		void checkSum(String^ file); //The result will arrive as a callback for registerPlayerCheckSum
		void checkHacks();

		bool isObjectSpawned(int id); //Returns whether the player has spawned the object
		bool isVehicleSpawned(int id);

		void requestWeapons(); //The result will arrive as a callback for registerPlayerWeaponsArrived
		unsigned int getWeaponsSize();
		void getWeaponData(unsigned int index, int% weapon, int% ammo); //Index throws exception, use getWeaponsSize for array size

		unsigned int getRoomKey();

		void playStream(String^ stream, Vector3^ pos); //Use 0 as pos for a frontend stream
		void stopStreams();

		void setArmor(int i);
		int getArmor();

		void setMoney(int i);
		void setDoorStat(unsigned int model, Vector3^ pos, bool status);

		int getGame();

		void customChat(int chat_id, int operation);

		void explodeAt(Vector3^ pos, int typ, float radius, bool audio, bool invisible, float cam);

		void playSound(String^ name, int uniqueId, Vector3^ pos);
		void stopSound(int uniqueId);

		void ts_toggleVoice(bool b);
		void ts_allowVoiceTo(int playerId, bool b);
		void ts_connect(String^ ip);

		void setVehicleCol(int vehicleid, bool col);
		void setDrawFlags(int playerid, bool blip, bool nameDraw);
		//bool getDrawFlag(int flag);
		void setHudFlags(bool hud, bool radar);


		void setStreamDistance(float f);
	};
}