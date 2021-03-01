//#include "apiPlayer.h"
#include "playerList.h"
#include <msclr/marshal.h>
#include "Player.h"

SharpBridge::Player::Player(int id)
{
	//this->engineId = engineId;
	player = &apiPlayer::get(id);
}

float SharpBridge::Player::getHeading()
{
	return player->getHeading();
}

void SharpBridge::Player::setHeading(float h)
{
	player->setHeading(h);
}

SharpBridge::Vector3^ SharpBridge::Player::getPos()
{
	apiMath::Vector3 p = player->getPos();
	return gcnew Vector3(p.x, p.y, p.z);
}

void SharpBridge::Player::setPos(Vector3^ pos)
{
	apiMath::Vector3 p(pos->x, pos->y, pos->z);
	player->setPos(p);
}

int SharpBridge::Player::getID()
{
	return player->getID();
}

String^ SharpBridge::Player::getNick()
{
	return gcnew String(player->getNick());
}

void SharpBridge::Player::setNick(String^ nick)
{
	msclr::interop::marshal_context ctx;
	const char* converted = ctx.marshal_as<const char*>(nick);
	player->setNick(converted);
}

void SharpBridge::Player::sendMsg(String^ msg, unsigned int hex)
{
	msclr::interop::marshal_context ctx;
	const char* converted = ctx.marshal_as<const char*>(msg);
	player->sendMsg(converted, hex, 0);
}

void SharpBridge::Player::sendColoredMsg(int msgId)
{
	player->sendColoredMsg(msgId, 0);
}

void SharpBridge::Player::setSkinId(unsigned int id)
{
	if(playerList::isValidModel(id)) player->setSkin(playerList::getModel(id));
}

void SharpBridge::Player::setSkinModel(unsigned int model)
{
	player->setSkin(model);
}

unsigned int SharpBridge::Player::getSkinModel()
{
	return player->getSkin();
}

void SharpBridge::Player::setWorld(unsigned int vWorld)
{
	player->setWorld(vWorld);
}

unsigned int SharpBridge::Player::getWorld()
{
	return player->getWorld();
}

void SharpBridge::Player::giveWeapon(unsigned int weaponId, unsigned int ammo)
{
	player->giveWeapon(weaponId, ammo);
}

void SharpBridge::Player::removeWeapon(unsigned int weaponId) // Use weapon ID 0 to remove all weapons
{
	player->removeWeapon(weaponId);
}

void SharpBridge::Player::setHealth(int hp)
{
	player->setHealth(hp + 100);
}

int SharpBridge::Player::getHealth() //Ranges from 0-200 when the player is alive, negative values if dead
{
	return player->getHealth() - 100;
}

void SharpBridge::Player::setColor(unsigned int hex) //RGB
{
	player->setColor(hex);
}

unsigned int SharpBridge::Player::getColor()
{
	return player->getColor();
}

void SharpBridge::Player::spawn(Vector3^ pos) //Must be used when the credentials arrive
{
	apiMath::Vector3 v(pos->x, pos->y, pos->z);
	player->spawn(v);
}

void SharpBridge::Player::setRespawnPos(Vector3^ pos) //Must be used to set a new position only
{
	apiMath::Vector3 v(pos->x, pos->y, pos->z);
	player->setRespawnPos(v);
}

int SharpBridge::Player::getDriving() //Returns 0 if on foot
{
	return player->getDriving();
}

void SharpBridge::Player::getPassenger(int^ vehicle, int^ seat)
{
	int v, s;
	player->getPassenger(v, s);
	vehicle = v, seat = s;
}

int SharpBridge::Player::isInVehicle() //Checks for driving and passenger or returns 0 if on foot
{
	return player->isInVehicle();
}

void SharpBridge::Player::putInVehicle(int vehicleId, int seatId) //Seats: 0 driver, 1-3 passengers
{
	player->putInVehicle(vehicleId, seatId);
}

void SharpBridge::Player::removeFromVehicle()
{
	player->removeFromVehicle();
}

//drawText time should be 0 for infinite
void SharpBridge::Player::drawText(int classId, float x, float y, float sx, float sy, String^ txt, int time, unsigned int color)
{
	msclr::interop::marshal_context ctx;
	const char* converted = ctx.marshal_as<const char*>(txt);
	player->drawText(classId, x, y, sx, sy, converted, time, color);
}

void SharpBridge::Player::updateText(int classId, String^ txt, unsigned int newColor)
{
	msclr::interop::marshal_context ctx;
	const char* converted = ctx.marshal_as<const char*>(txt);
	player->updateText(classId, converted, newColor);
}

void SharpBridge::Player::drawInfoText(String^ txt, int time)
{
	msclr::interop::marshal_context ctx;
	const char* converted = ctx.marshal_as<const char*>(txt);
	player->drawInfoText(converted, time);
}

void SharpBridge::Player::drawRect(int classId, float x, float y, float sx, float sy, unsigned int color)
{
	player->drawRect(classId, x, y, sx, sy, color);
}

void SharpBridge::Player::wipeDrawClass(int classId)
{
	player->wipeDrawClass(classId);
}

int SharpBridge::Player::getWeapon()
{
	return player->getWeapon();
}

int SharpBridge::Player::getAmmo()
{
	return player->getAmmo();
}

void SharpBridge::Player::setFrozen(bool b)
{
	player->setFrozen(b);
}

void SharpBridge::Player::debugPlayer(int playerid)
{
	player->debugPlayer(playerid);
}

void SharpBridge::Player::debugVehicle(int vehicleid)
{
	player->debugVehicle(vehicleid);
}

void SharpBridge::Player::disconnect()
{
	player->disconnect();
}

int SharpBridge::Player::getPing(bool average)
{
	return player->getPing(average);
}

int SharpBridge::Player::getAnim()
{
	return player->getAnim();
}

void SharpBridge::Player::showDialogList(unsigned int dialogId)
{
	player->showDialogList(dialogId);
}

void SharpBridge::Player::setClothes(unsigned int part, unsigned int value)//part is 0-8
{
	if(part < 0 || part > 8) return;
	player->setClothes(part, value);
}

unsigned int SharpBridge::Player::getClothes(unsigned int part)
{
	if(part < 0 || part > 8) return 0;
	return player->getClothes(part);
}

void SharpBridge::Player::setProperty(unsigned int part, unsigned int value) //part is 0-1
{
	if(part < 0 || part > 1) return;
	player->setProperty(part, value);
}

unsigned int SharpBridge::Player::getProperty(unsigned int part)
{
	if(part < 0 || part > 1) return 0;
	return player->getProperty(part);
}

void SharpBridge::Player::forceAnim(String^ animGroup, String^ animName, bool loop)
{
	msclr::interop::marshal_context ctx;
	const char* ag = ctx.marshal_as<const char*>(animGroup);
	const char* an = ctx.marshal_as<const char*>(animName);
	player->forceAnim(ag, an, loop);
}

void SharpBridge::Player::setSitIdleAnim(String^ animGroup, String^ animName, int num)
{
	msclr::interop::marshal_context ctx;
	const char* ag = ctx.marshal_as<const char*>(animGroup);
	const char* an = ctx.marshal_as<const char*>(animName);
	player->setSitIdleAnim(ag, an, num);
}

void SharpBridge::Player::forceSitNow()
{
	player->forceSitNow();
}

void SharpBridge::Player::stopAnims()
{
	player->stopAnims();
}

void SharpBridge::Player::setKeyHook(unsigned int virtualKey, bool addOrRemove) //Virtual keys can be found online
{
	player->setKeyHook(virtualKey, addOrRemove);
}

String^ SharpBridge::Player::getIp()
{
	return gcnew String(player->getIp());
}

void SharpBridge::Player::showBlip(int blipId, bool show)
{
	player->showBlip(blipId, show);
}

void SharpBridge::Player::cam_setPos(Vector3^ pos, unsigned int camWorld)
{
	if(pos == nullptr) return player->cam_setPos(NULL, camWorld);
	apiMath::Vector3 v(pos->x, pos->y, pos->z);
	player->cam_setPos(&v, camWorld);
}

void SharpBridge::Player::cam_setLookAt(Vector3^ pos)
{
	apiMath::Vector3 v(pos->x, pos->y, pos->z);
	player->cam_setLookAt(v);
}

void SharpBridge::Player::cam_attachOnPlayer(int playerid)
{
	player->cam_attachOnPlayer(playerid);
}

unsigned int SharpBridge::Player::getSerialSize() //Returns the amount of serials
{
	return player->getSerialSize();
}

String^ SharpBridge::Player::getSerial(unsigned int i)
{
	return gcnew String(player->getSerial(i));
}

void SharpBridge::Player::checkSum(String^ file) //The result will arrive as a callback for registerPlayerCheckSum
{
	msclr::interop::marshal_context ctx;
	const char* converted = ctx.marshal_as<const char*>(file);
	player->checkSum(converted);
}

void SharpBridge::Player::checkHacks()
{
	player->checkHacks();
}

bool SharpBridge::Player::isObjectSpawned(int id) //Returns whether the player has spawned the object
{
	return player->isObjectSpawned(id);
}

bool SharpBridge::Player::isVehicleSpawned(int id)
{
	return player->isVehicleSpawned(id);
}

void SharpBridge::Player::requestWeapons() //The result will arrive as a callback for registerPlayerWeaponsArrived
{
	player->requestWeapons();
}

unsigned int SharpBridge::Player::getWeaponsSize()
{
	return player->getWeaponsSize();
}

void SharpBridge::Player::getWeaponData(unsigned int index, int% weapon, int%  ammo) //Index throws exception, use getWeaponsSize for array size
{
	int w, a;
	player->getWeaponData(index, w, a);
	weapon = w, ammo = a;
}

unsigned int SharpBridge::Player::getRoomKey()
{
	return player->getRoomKey();
}

void SharpBridge::Player::playStream(String^ stream, Vector3^ pos) //Use 0 as pos for a frontend stream
{
	if(!pos) return player->playStream(NULL, NULL);

	msclr::interop::marshal_context ctx;
	const char* converted = ctx.marshal_as<const char*>(stream);
	
	apiMath::Vector3 v(pos->x, pos->y, pos->z);
	player->playStream(converted, &v);
}

void SharpBridge::Player::stopStreams()
{
	player->stopStreams();
}

void SharpBridge::Player::setArmor(int i)
{
	player->setArmor(i);
}

int SharpBridge::Player::getArmor()
{
	return player->getArmor();
}

void SharpBridge::Player::setMoney(int i)
{
	player->setMoney(i);
}

void SharpBridge::Player::setDoorStat(unsigned int model, Vector3^ pos, bool status)
{
	if(!pos) return player->setDoorStat(model, NULL, status);

	apiMath::Vector3 v(pos->x, pos->y, pos->z);
	player->setDoorStat(model, &v, status);
}

int SharpBridge::Player::getGame()
{
	return player->getGame();
}

void SharpBridge::Player::customChat(int chat_id, int operation)
{
	player->customChat(chat_id, operation);
}

void SharpBridge::Player::explodeAt(Vector3^ pos, int typ, float radius, bool audio, bool invisible, float cam)
{
	apiMath::Vector3 v(pos->x, pos->y, pos->z);
	player->explodeAt(v, typ, radius, audio, invisible, cam);
}

void SharpBridge::Player::playSound(String^ name, int uniqueId, Vector3^ pos)
{
	msclr::interop::marshal_context ctx;
	const char* converted = ctx.marshal_as<const char*>(name);

	if(!pos) return player->playSound(converted, uniqueId, NULL);
	apiMath::Vector3 v(pos->x, pos->y, pos->z);
	player->playSound(converted, uniqueId, &v);
}

void SharpBridge::Player::stopSound(int uniqueId)
{
	player->stopSound(uniqueId);
}

void SharpBridge::Player::ts_toggleVoice(bool b)
{
	player->ts_toggleVoice(b);
}

void SharpBridge::Player::ts_allowVoiceTo(int playerId, bool b)
{
	player->ts_allowVoiceTo(playerId, b);
}

void SharpBridge::Player::ts_connect(String^ ip)
{
	msclr::interop::marshal_context ctx;
	const char* converted = ctx.marshal_as<const char*>(ip);
	player->ts_connect(converted);
}

void SharpBridge::Player::setVehicleCol(int vehicleid, bool col)
{
	player->setVehicleCol(vehicleid, col);
}

void SharpBridge::Player::setDrawFlags(int playerid, bool blip, bool nameDraw)
{
	player->setDrawFlags(playerid, blip, nameDraw);
}

//bool getDrawFlag(int flag);
void SharpBridge::Player::setHudFlags(bool hud, bool radar)
{
	player->setHudFlags(hud, radar);
}

void SharpBridge::Player::setStreamDistance(float f)
{
	player->setStreamDistance(f);
}