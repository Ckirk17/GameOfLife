#pragma once
#include "wx/wx.h"

wxBEGIN_EVENT_TABLE(DrawingPanel, wxPanel)
	EVT_PAINT(DrawingPanel::OnPaint)
	EVT_LEFT_UP(DrawingPanel::MouseButtonClick)
wxEND_EVENT_TABLE()

class DrawingPanel : public wxPanel {
private:
	int gridSize = 15;
	int cellSize = 10;
	std::vector<std::vector<bool>>& gameBoard;

public:
	DrawingPanel(wxFrame* parent, std::vector<std::vector<bool>>& gameBoard);
	void OnPaint(wxPaintEvent&);
	void SetSize(wxSize& size);
	void SetGridSize(int gridSize);
	void MouseButtonClick(wxMouseEvent& event);
	~DrawingPanel();
	wxDECLARE_EVENT_TABLE();
};