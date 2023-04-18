#include "DrawingPanel.h"
#include "wx/graphics.h"
#include "wx/dcbuffer.h"

wxBEGIN_EVENT_TABLE(DrawingPanel, wxPanel)
EVT_PAINT(DrawingPanel::OnPaint)
EVT_LEFT_UP(DrawingPanel::MouseButtonClick)
wxEND_EVENT_TABLE()

DrawingPanel::DrawingPanel(wxWindow* parent, std::vector<std::vector<bool>>& gameBoard) : wxPanel(parent, wxID_ANY, wxPoint(0,0), wxSize(0,0)),RefGameBoard(gameBoard){
	SetBackgroundStyle(wxBG_STYLE_PAINT);
	SetDoubleBuffered(true);
	this->Bind(wxEVT_PAINT, &DrawingPanel::OnPaint, this);
	this->Bind(wxEVT_LEFT_UP, &DrawingPanel::MouseButtonClick, this);
}

void DrawingPanel::OnPaint(wxPaintEvent&) {
	wxAutoBufferedPaintDC dc(this);
	dc.Clear();

	wxGraphicsContext* context = wxGraphicsContext::Create(dc);
	if (!context) { return; }

	context->SetPen(*wxBLACK);
	context->SetBrush(*wxWHITE); \
	context->DrawRectangle(50, 50, 100, 100);

	int panelHeight;
	int panelWidth;

	GetSize(&panelWidth, &panelHeight);

	int cellHt = panelHeight / gridSize;
	int cellWidth = panelWidth / gridSize;

	int rows = RefGameBoard.size();
	int columns = RefGameBoard[0].size();

	for (int i = 0; i < rows; i++) {
		for (int x = 0; x < columns; x++) {

			int X = i + cellWidth;
			int Y = x + cellHt;

			if (RefGameBoard[i][x] == true) {
				context->SetBrush(*wxLIGHT_GREY);
			}
			else {
				context->SetBrush(*wxWHITE);
			}
			context->DrawRectangle(X, Y, 20, 20);
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

	RefGameBoard[boardVal1][boardVal2];

	Refresh();
}

DrawingPanel::~DrawingPanel(){

}
