#include "truelog.h"
#include <msclr/marshal.h>
_INITIALIZE_EASYLOGGINGPP

#include "Log.h"

void SharpBridge::Log::Write(System::String^ line)
{
	msclr::interop::marshal_context ctx;
	const char* converted = ctx.marshal_as<const char*>(line);

	LINFO << converted;
}