#include "CCircle.h"
#include <cmath>
#include <fstream>

CCircle::CCircle(Point C, int R, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo) {
    center = C;
    radius = R;
}

CCircle::CCircle()
{
	Type = "Circle";
}

string CCircle::getType() {
	return Type;
}

void CCircle::Draw(Output* pOut) const {
    pOut->DrawCircle(center, radius, FigGfxInfo, Selected);
}

bool CCircle::IsPointInside(int x, int y) const {

	int dx = x - center.x; //distance from click to center of circle
	int dy = y - center.y;
	int distance = sqrt(dx * dx + dy * dy); 
	if (distance <= radius) {
		return true; //point is inside the circle, should be selected
	}
	else {
		return false;
	}
}

void CCircle::PrintInfo(Output* pOut) const {
	string info = GetFigureInfo();
	pOut->PrintMessage(info);
}

string CCircle::GetFigureInfo() const {
	return "Circle: ID = " + to_string(ID) +
		", Center = (" + to_string(center.x) +
		", " + to_string(center.y) +
		"), Radius = " + to_string(radius);
}

void CCircle::Load(ifstream& Infile)
{
	Infile >> ID >> center.x >> center.y >> radius >> DrawColor >> FillColor;

	FigGfxInfo.DrawClr = stringtoclr(DrawColor);
	FigGfxInfo.FillClr = stringtoclr(FillColor);
}
