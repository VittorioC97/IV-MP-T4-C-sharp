#pragma once
#include "apiDialog.h"

namespace SharpBridge
{
	public ref class Dialog
	{
	private:
		apiDialog::dialogList* diag;

	public:
		Dialog(unsigned int id);

		void setColumnsHeaders(System::String^ s);
		void setBtnNames(System::String^ b1, System::String^ b2);
		void addRow(System::String^ s, int customId);
		void clearRows();
		void save();
	};
}