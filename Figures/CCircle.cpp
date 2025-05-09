#include <fstream>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include "CCircle.h"
#include "..\Actions/Action.h"
#include "..\ApplicationManager.h"
#include "..\Figures/CFigure.h"
#include "..\ColorFiles.h"

CCircle::CCircle(Point C, int R, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo) {
    center = C;
    radius = R;
}

void CCircle::Move(int x, int y)
{
	Center.x = x;
	Center.y = y;
	OuterPoint.x = x + Radius;
	OuterPoint.y = y;
	FitInsideDrawArea();
}

CCircle::CCircle()
{
	Type = "Circle";}
CFigure* CCircle::Clone() const 
{
    return new CCircle(*this); 
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

void CCircle:: Load(ifstream& Infile)
{
	Infile >> ID >> center.x >> center.y >> radius >> DrawColor >> FillColor;

	FigGfxInfo.DrawClr = stringtoclr(DrawColor);
	FigGfxInfo.FillClr = stringtoclr(FillColor);
}

Point CCircle::GetCenter() const
{
	return center;
}

void CCircle::SetPosition(int x, int y)
{
	center.x = x;
	center.y = y;
}

void CCircle::Rotate()
{
}


void CCircle::Save(ofstream& OutFile)
{
	OutFile << "Circle" << "\t" << ID << "\t";
	OutFile << center.x << "\t" << center.y << "\t";
	OutFile << radius << "\t";
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
void CCircle::MoveFigure(int x, int y)
{
	Center.x = x;
	Center.y = y;
	OuterPoint.x = x + Radius;
	OuterPoint.y = y;
	FitInsideDrawArea();
}
