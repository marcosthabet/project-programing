#include "CCircle.h"

CCircle::CCircle(Point C, int R, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo) {
    center = C;
    radius = R;
}

void CCircle::Draw(Output* pOut) const {
    pOut->DrawCircle(center, radius, FigGfxInfo, Selected);
}

