#pragma once
#include <wx/wx.h>
#include "DrawingPanel.h"
#include "GameSettings.h"
#include "SettingsDialog.h"
#include <vector>

class MainWindow:public wxFrame {
private:
	DrawingPanel* drPanel = nullptr;
	wxBoxSizer* boxSizer = nullptr;
	std::vector<std::vector<bool>> gameBoard;
	GameSettings m_settings;
	int gridSize = 15;
	int generations = 0;
	int livingCells = 0;
	int timerMilli = 50;
	wxStatusBar* statusBar = nullptr;
	wxToolBar* toolBar = nullptr;
	wxTimer* timer = nullptr;
	wxMenuBar* menuBarRef = nullptr;

public:
	MainWindow();
	void OnButtonClick(wxCommandEvent& event);
	void WindowResize(wxSizeEvent& event);
	void InitGrid();
	void SetStatusText();
	void PlayButtonClick(wxCommandEvent& event);
	void PauseButtonClick(wxCommandEvent& event);
	void NextButtonClick(wxCommandEvent& event);
	void TrashButtonClick(wxCommandEvent& event);
	int NeighborCount(int row, int column);
	void CellGenerations();
	void Timer(wxTimerEvent& event);
	void MenuOption(wxCommandEvent& event, Dialog* dialogRef);
	void RandomizeOption(wxCommandEvent& event);
	void RandomizeWithSeed(wxCommandEvent& event);
	void RandomGrid(int num);
	~MainWindow();
	wxDECLARE_EVENT_TABLE();
};
