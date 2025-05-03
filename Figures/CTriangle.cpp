#include "CTriangle.h"

CTriangle::CTriangle(Point p1, Point p2, Point p3, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo) {
	point1 = p1;
	point2 = p2;
	point3 = p3;
}

void CTriangle::Draw(Output* pOut) const {
	pOut->DrawTriangle(point1, point2, point3, FigGfxInfo, Selected);
}
