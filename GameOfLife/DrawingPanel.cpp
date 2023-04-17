#include "DrawingPanel.h"
#include "wx/graphics.h"
#include "wx/dcbuffer.h"

DrawingPanel::DrawingPanel(wxFrame* parent, std::vector<std::vector<bool>>& gameBoard) : wxPanel(parent, wxID_ANY, wxPoint(0,0), wxSize(0,0)){
	SetBackgroundStyle(wxBG_STYLE_PAINT);
	SetDoubleBuffered(true);
	this->Bind(wxEVT_PAINT, &DrawingPanel::OnPaint, this);
	this->Bind(wxEVT_LEFT_UP, &DrawingPanel::MouseButtonClick, this);
	std::vector<std::vector<bool>>& gameBoard = {false, false};
}

void DrawingPanel::OnPaint(wxPaintEvent&) {
	wxAutoBufferedPaintDC dc(this);
	dc.Clear();

	wxGraphicsContext* context = wxGraphicsContext::Create(dc);
	if (!context) { return; }

	context->SetPen(*wxBLACK);
	context->SetBrush(*wxWHITE);

	int startPtX = 0;
	int startPtY = 0;
	int cellHt;
	int cellWidth;

	wxSize size = GetSize();
	int varW = size.GetWidth() / gridSize;
	int varH = size.GetHeight() / gridSize;

	for (int i = 0; i < gridSize; i++) {
		for (int x = 0; x < gridSize; x++) {

			context->DrawRectangle(startPtX, startPtY, 20, 20);

			startPtX += 20;
			startPtY += 20;

			if (gameBoard[i][x] == true) {
				context->SetBrush(*wxLIGHT_GREY);
			}
			else {
				context->SetBrush(*wxWHITE);
			}
		}
	}
}

void DrawingPanel::SetSize(wxSize& size) {
	wxSize _size = this->GetSize();

	SetSize(_size);

	Refresh();
}

void DrawingPanel::SetGridSize(int gridSize) {

}

void DrawingPanel::MouseButtonClick(wxMouseEvent& event){
	int x = event.GetX();
	int y = event.GetY();

	wxSize size = GetSize();
	int boardVal1 = x / size.GetWidth();
	int boardVal2 = y / size.GetHeight();

	gameBoard[boardVal1][boardVal2];

	Refresh();
}

DrawingPanel::~DrawingPanel(){

}
