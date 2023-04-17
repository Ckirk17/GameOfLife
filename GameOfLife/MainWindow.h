#pragma once
#include <wx/wx.h>
#include "DrawingPanel.h"

wxBEGIN_EVENT_TABLE(MainWindow, wxFrame)
	EVT_SIZE(MainWindow::WindowResize)
	EVT_MENU(12000, MainWindow::PlayButtonClick)
	EVT_MENU(13000, MainWindow::PauseButtonClick)
	EVT_MENU(14000, MainWindow::NextButtonClick)
	EVT_MENU(15000, MainWindow::TrashButtonClick)
	EVT_TIMER(12500, MainWindow::Timer)
wxEND_EVENT_TABLE()

class MainWindow:public wxFrame {
private:
	DrawingPanel* drPanel = nullptr;
	wxBoxSizer* boxSizer = nullptr;
	std::vector<std::vector<bool>> gameBoard;
	int gridSize = 15;
	int generations = 0;
	int livingCells = 0;
	int timerMilli = 50;
	wxStatusBar* statusBar = nullptr;
	wxToolBar* toolBar = nullptr;
	wxTimer* timer = nullptr;

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
	~MainWindow();
	wxDECLARE_EVENT_TABLE();
};
