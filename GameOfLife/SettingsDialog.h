#pragma once
#include <wx/wx.h>
#include "MainWindow.h"
#include "GameSettings.h"

class Dialog : public wxDialog {
	Dialog(MainWindow*, GameSettings*);
};