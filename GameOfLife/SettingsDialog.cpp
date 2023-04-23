#include "SettingsDialog.h"
#include "MainWindow.h"
#include "GameSettings.h"
#include "wx/spinctrl.h"

Dialog::Dialog(MainWindow*, GameSettings*) : wxDialog(nullptr, 10, "Dialog") {
	wxBoxSizer* mainBoxPtr = new wxBoxSizer(wxVERTICAL);
	SetSizer(mainBoxPtr);

	//Need both child box sizers here
	//wxBoxSizer 
}