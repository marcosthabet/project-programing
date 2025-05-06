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
#include "..\GUI\Output.h"
CHexagon::CHexagon(Point c, GfxInfo FigureGfxInfo) :
	CFigure(FigureGfxInfo) {
	center = c;
}
CHexagon::CHexagon()
{
	Type = "Hexagon";
}

CFigure* CHexagon::Clone() const
{
	return new CHexagon(*this);
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

void CHexagon::Save(ofstream& OutFile)
{
	OutFile << "Hexagon" << "\t" << ID << "\t";
	OutFile << center.x << "\t" << center.y << "\t";
	OutFile << ColorFiles::ColorChoice(FigGfxInfo.DrawClr) << "\t";
	if (FigGfxInfo.isFilled)
	{
		OutFile << ColorFiles::ColorChoice(FigGfxInfo.FillClr) << "\t";
	}
	else
	{
		OutFile << "NoFill" << "\t";
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

Point CHexagon::GetCenter() const
{
	return center;
}

void CHexagon::SetPosition(int x, int y)
{
	center.x = x;
	center.y = y;
}

void CHexagon::Rotate()
{
}


