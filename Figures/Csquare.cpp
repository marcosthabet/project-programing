#include "Csquare.h"

//constructor 
Csquare::Csquare(Point p, int l, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo) {
	center = p;
	length = l;
}

void Csquare::Draw(Output* pOut) const {
	pOut->DrawSquare(center, length, FigGfxInfo, Selected);
	// Call Output::DrawSquare to draw a square on the screen
}
