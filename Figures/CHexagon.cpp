#include "CHexagon.h"

CHexagon::CHexagon(Point c, GfxInfo FigureGfxInfo) :
	CFigure(FigureGfxInfo) {
	center = c;
}
void CHexagon::Draw(Output* pOut) const {
	pOut->DrawHexagon(center, FigGfxInfo, Selected);
}

bool CHexagon::IsPointInside(int x, int y) const {

	int dx = x - center.x; //distance from click to center of hex
	int dy = y - center.y;
	int distance = sqrt(dx * dx + dy * dy);
	if (distance <= 130) {
		return true; //point is inside the circle, should be selected
	}
	else {
		return false;
	}
}
void CHexagon::PrintInfo(Output* pOut) const {
	string info = GetFigureInfo();
	pOut->PrintMessage(info);
}

string CHexagon::GetFigureInfo() const {
	return "Hexagon: ID = " + to_string(ID) +
		", Center = (" + to_string(center.x) +
		", " + to_string(center.y) + ")";
}