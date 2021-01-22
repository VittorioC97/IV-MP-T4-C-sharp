#include <msclr/marshal.h>
#include "Dialog.h"

SharpBridge::Dialog::Dialog(unsigned int id)
{
	diag = apiDialog::get(id);
}

void SharpBridge::Dialog::setColumnsHeaders(System::String^ s)
{
	msclr::interop::marshal_context ctx;
	const char* converted = ctx.marshal_as<const char*>(s);

	diag->setColumnsHeaders(converted);
}

void SharpBridge::Dialog::setBtnNames(System::String^ b1, System::String^ b2)
{
	msclr::interop::marshal_context ctx;
	const char* s1 = ctx.marshal_as<const char*>(b1);
	const char* s2 = ctx.marshal_as<const char*>(b2);
	diag->setBtnNames(s1, s2);
}

void SharpBridge::Dialog::addRow(System::String^ s, int customId)
{
	msclr::interop::marshal_context ctx;
	const char* s1 = ctx.marshal_as<const char*>(s);
	diag->addRow(s1, customId);
}

void SharpBridge::Dialog::clearRows()
{
	diag->clearRows();
}

void SharpBridge::Dialog::save()
{
	diag->save();
}