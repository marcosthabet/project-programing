#include "CHexagon.h"

CHexagon::CHexagon(Point c, GfxInfo FigureGfxInfo) :
	CFigure(FigureGfxInfo) {
	center = c;
}
void CHexagon::Draw(Output* pOut) const {
	pOut->DrawHexagon(center, FigGfxInfo, Selected);
}
