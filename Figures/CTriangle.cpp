#include <fstream>
#include <iostream>
#include <string>
#include <cmath>
#include "CTriangle.h"
#include "..\Actions/Action.h"
#include "..\ApplicationManager.h"
#include "..\Figures/CFigure.h"
#include "..\ColorFiles.h"


CTriangle::CTriangle(Point p1, Point p2, Point p3, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo) {
	point1 = p1;
	point2 = p2;
	point3 = p3;
}

CTriangle::CTriangle()
{
	Type = "Triangle";
}

string CTriangle::getType()
{
	return Type;
}

void CTriangle::Draw(Output* pOut) const {
	pOut->DrawTriangle(point1, point2, point3, FigGfxInfo, Selected);
}

bool CTriangle::IsPointInside(int x, int y) const { //p
	
	float x1 = point1.x; //a
	float y1 = point1.y; 
	float x2 = point2.x; //b
	float y2 = point2.y;
	float x3 = point3.x; //c
	float y3 = point3.y;

	float totalarea = 0.5 * abs((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1));//tri abc
	float area1 = 0.5 * abs((x1 - x) * (y2 - y) - (x2 - x) * (y1 - y));//tri pab
	float area2 = 0.5 * abs((x2 - x) * (y3 - y) - (x3 - x) * (y2 - y));//tri pbc
	float area3 = 0.5 * abs((x3 - x) * (y1 - y) - (x1 - x) * (y3 - y));//tri pac

	if (area1 + area2 + area3 == totalarea) {
		return true; 
	}
	else {
		return false;
	}

}

void CTriangle::PrintInfo(Output* pOut) const {
	string info = GetFigureInfo();
	pOut->PrintMessage(info);
}

string CTriangle::GetFigureInfo() const {
	return "Triangle: ID = " + to_string(ID) +
		", Point1 = (" + to_string(point1.x) +
		", " + to_string(point1.y) +
		"), Point2 = (" + to_string(point2.x) +
		", " + to_string(point2.y) +
		"), Point3 = (" + to_string(point3.x) +
		", " + to_string(point3.y) + ")";
}

void CTriangle::Save(ofstream& OutFile)
{
	OutFile << "Triangle" << "\t" << ID << "\t";
	OutFile << point1.x << "\t" << point1.y << "\t";
	OutFile << point2.x << "\t" << point2.y << "\t";
	OutFile << point3.x << "\t" << point3.y << "\t";
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

void CTriangle::SetPosition(int x, int y)
{
	point1.x += x;
	point1.y += y;
	point2.x += x;
	point2.y += y;
	point3.x += x;
	point3.y += y;
}

Point CTriangle::GetCenter() const
{
	Point center;
	center.x = (point1.x + point2.x + point3.x) / 3;
	center.y = (point1.y + point2.y + point3.y) / 3;
	return center;
}

void CTriangle::Rotate()
{
	Point temp = point1;
	point1 = point2;
	point2 = point3;
	point3 = temp;
}


void CTriangle::Load(ifstream& Infile)
{
	Infile >> ID >> point1.x >> point1.y >> point2.x >> point2.y >> point3.x >> point3.y >> DrawColor >> FillColor;

	FigGfxInfo.DrawClr = stringtoclr(DrawColor);
	FigGfxInfo.FillClr = stringtoclr(FillColor);
}