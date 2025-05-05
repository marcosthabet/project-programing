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

void CTriangle::SaveAll(ofstream& File)
{
	File << "Triangle" << "\t" << ID << "\t";
	File << point1.x << "\t" << point1.y << "\t";
	File << point2.x << "\t" << point2.y << "\t";
	File << point3.x << "\t" << point3.y << "\t";
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
