#include <fstream>
#include <iostream>
#include <string>
#include <cmath>
#include "CHexagon.h"
#include "..\Actions/Action.h"
#include "..\ApplicationManager.h"
#include "..\Figures/CFigure.h"
#include "..\ColorFiles.h"
#include <fstream>

CHexagon::CHexagon(Point c, GfxInfo FigureGfxInfo) :
	CFigure(FigureGfxInfo) {
	center = c;
}
CHexagon::CHexagon()
{
	Type = "Hexagon";
}

void CHexagon::Draw(Output* pOut) const {
	pOut->DrawHexagon(center, FigGfxInfo, Selected);
}

bool CHexagon::IsPointInside(int x, int y) const {

	int dx = x - center.x; //distance from click to center of hex
	int dy = y - center.y;
	int distance = sqrt(dx * dx + dy * dy);
	if (distance <= 130) {
		return true; //point is inside the hex, should be selected
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

void CHexagon::Save(ofstream& File)
{
	File << "Hexagon" << "\t" << ID << "\t";
	File << center.x << "\t" << center.y << "\t";
	File << ColorFiles::ColorChoice(FigGfxInfo.DrawClr) << "\t";
	if (FigGfxInfo.isFilled)
	{
		File << ColorFiles::ColorChoice(FigGfxInfo.FillClr) << "\t";
	}
	else
	{
		File << "NoFill" << "\t";
	}
}


string CHexagon::getType()
{
	return Type;
}

void CHexagon::Load(ifstream& Infile)  
{  
   Infile >> ID >> center.x >> center.y >> DrawColor >> FillColor;  
   FigGfxInfo.DrawClr = stringtoclr(DrawColor);  
   FigGfxInfo.FillClr = stringtoclr(FillColor);  
}
