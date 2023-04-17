#include "MainWindow.h"
#include "DrawingPanel.h"
#include "wx/graphics.h"
#include "wx/dcbuffer.h"
#include "play.xpm"
#include "pause.xpm"
#include "next.xpm"
#include "trash.xpm"

MainWindow::MainWindow() :wxFrame(nullptr, wxID_ANY, "Game of Life", wxPoint(100,100), wxSize(500,500)) {
	statusBar = CreateStatusBar();
	toolBar = CreateToolBar();

	timer = new wxTimer(this, 12500);

	wxBitmap playIcon(play_xpm);

	toolBar->AddTool(12000, "Play", playIcon);

	wxBitmap pauseIcon(pause_xpm);

	toolBar->AddTool(13000, "Pause", pauseIcon);

	wxBitmap nextIcon(next_xpm);

	toolBar->AddTool(14000, "Next", nextIcon);

	wxBitmap trashIcon(trash_xpm);

	toolBar->AddTool(15000, "trash", trashIcon);

	toolBar->Realize();
	
	drPanel = new DrawingPanel(this, gameBoard, wxSize(100, 100));
	boxSizer = new wxBoxSizer(wxVERTICAL);

	boxSizer->Add(drPanel, 1, wxEXPAND, wxALL);

	this->SetSizer(boxSizer);

	this->Bind(wxEVT_SIZE, &MainWindow::WindowResize, this);
	MainWindow::InitGrid();

	this->Layout();
}

void MainWindow::OnButtonClick(wxCommandEvent& event) {
	//Finding X,Y coordinates of mouse click
	int ID = event.GetId();

	if (ID == 101) {
		SetSize(wxSize(GetSize().x + 10, GetSize().y + 10));
	}
	else
	{
		SetSize(wxSize(GetSize().x - 10, GetSize().y - 10));
	}
}

void MainWindow::WindowResize(wxSizeEvent& event) {
	wxSize _size = this->GetSize();
	
	if (drPanel != nullptr) {
		drPanel->SetSize(_size);
	}
	
	drPanel->Refresh();
	event.Skip();
}

void MainWindow::InitGrid() {
	for (int i = 0; i < gridSize; i++) {
		for (int x = 0; x < gridSize; x++) {
			gameBoard.resize(gridSize);
		}
	}
	drPanel->SetGridSize(gridSize);
}

void MainWindow::SetStatusText() {

}

void MainWindow::PlayButtonClick(wxCommandEvent& even){
	timer->Start(timerMilli);
}


void MainWindow::PauseButtonClick(wxCommandEvent& event){
	timer->Stop();
}

void MainWindow::NextButtonClick(wxCommandEvent& event){

}

void MainWindow::TrashButtonClick(wxCommandEvent& event){

}


int MainWindow::NeighborCount(int row, int column){
	for (int i = -1; i < 2; i++) {
		for (int c = -1; c < 2; c++) {
			if (i == 0 && c == 0) {
				continue;
			}
		}
	}

	return 0;
}

void MainWindow::CellGenerations() {
	std::vector<std::vector<bool>> sandbox;

	for (int i = 0; i < gridSize; i++) {
		for (int x = 0; x < gridSize; x++)
		{
			sandbox.resize(gridSize);
		}
	}

	drPanel->Refresh();
}

void MainWindow::Timer(wxTimerEvent& event) {
	CellGenerations();
}

MainWindow::~MainWindow()
{

}