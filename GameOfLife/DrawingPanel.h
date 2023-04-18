#pragma once
#include "wx/wx.h"

class DrawingPanel : public wxPanel {
private:
	int gridSize = 15;
	int cellSize = 10;
	std::vector<std::vector<bool>>& RefGameBoard;

public:
	DrawingPanel(wxWindow* parent, std::vector<std::vector<bool>>& gameBoard);
	void OnPaint(wxPaintEvent& event);
	void SetSize(wxSize& size);
	void SetGridSize(int gridSize);
	void MouseButtonClick(wxMouseEvent& event);
	~DrawingPanel();
	wxDECLARE_EVENT_TABLE();
};