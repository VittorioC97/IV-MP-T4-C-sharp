#include "apiBlips.h"
#include <msclr/marshal.h>
#include "Blip.h"
#include "Math.h"

SharpBridge::Blip::Blip(int id)
{
	this->id = id;
}

void SharpBridge::Blip::setName(String^ name)
{
	msclr::interop::marshal_context ctx;
	const char* converted = ctx.marshal_as<const char*>(name);

	apiBlips::setName(this->id, converted);
}

int SharpBridge::Blip::getId()
{
	return this->id;
}