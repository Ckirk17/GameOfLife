#pragma once
#include "wx/wx.h"
#include "GameSettings.h"

class DrawingPanel : public wxPanel {
private:
	int gridSize = 15;
	int cellSize = 10;
	std::vector<std::vector<bool>>& RefGameBoard;
	GameSettings* settingsRef;
	std::vector<std::vector<int>> neighborCellCount;

public:
	DrawingPanel(wxWindow* parent, std::vector<std::vector<bool>>& gameBoard);
	void OnPaint(wxPaintEvent& event);
	void SetSize(wxSize& size);
	void SetGridSize(int gridSize);
	void MouseButtonClick(wxMouseEvent& event);
	void SetSetting(GameSettings* settings);
	~DrawingPanel();
	wxDECLARE_EVENT_TABLE();
};