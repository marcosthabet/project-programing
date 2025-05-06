
#include <fstream>
#include <iostream>
#include <string>
#include <cmath>
#include "CRectangle.h"
#include "..\Actions/Action.h"
#include "..\ApplicationManager.h"
#include "..\Figures/CFigure.h"
#include "..\ColorFiles.h"
#include "..\GUI\Output.h"
#include <fstream>




CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}

CRectangle::CRectangle()
{
	Type = "Rectangle";
}

string CRectangle::getType()
{
	return Type;
}
	

void CRectangle::Draw(Output* pOut) const 
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

bool CRectangle::IsPointInside(int x, int y) const
{
	if (((x >= Corner1.x && x <= Corner2.x) || (x <= Corner1.x && x >= Corner2.x)) //within the two x coords, whichever x is bigger
		&& //and also has to be within the y coords
		((y >= Corner1.y && y <= Corner2.y) || (y <= Corner1.y && y >= Corner2.y))) {
		return true;
	}
	else {
		return false;
	}
}

void CRectangle::PrintInfo(Output* pOut) const
{
	string info = GetFigureInfo();
	pOut->PrintMessage(info);
}

string CRectangle::GetFigureInfo() const
{
	return "Rectangle: ID = " + to_string(ID) +
		", Corner1 = (" + to_string(Corner1.x) +
		", " + to_string(Corner1.y) +
		"), Corner2 = (" + to_string(Corner2.x) +
		", " + to_string(Corner2.y) + ")";
}     

void CRectangle::SaveAll(ofstream& File)
{
	File << "Rectangle" << "\t" << ID << "\t";
	File << Corner1.x << "\t" << Corner1.y << "\t";
	File << Corner2.x << "\t" << Corner2.y << "\t";
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


void CRectangle::Load(ifstream& Infile)
{
	Infile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> DrawColor >> FillColor;
	FigGfxInfo.DrawClr = stringtoclr(DrawColor);
	FigGfxInfo.FillClr = stringtoclr(FillColor);
}


Point CRectangle::GetCenter() const
{
	// Return the center point of the rectangle (average of corners)
	return Point{ (Corner1.x + Corner2.x) / 2, (Corner1.y + Corner2.y) / 2 };
}

void CRectangle::SetPosition(int x, int y)
{
	// Move the rectangle by adjusting both corners (simplified)
	int dx = x - GetCenter().x;
	int dy = y - GetCenter().y;
	Corner1.x += dx;
	Corner1.y += dy;
	Corner2.x += dx;
	Corner2.y += dy;
}

void CRectangle::Rotate()
{
	// Dummy rotation (e.g., swap corners, no actual rotation logic yet)
	Point temp = Corner1;
	Corner1 = Corner2;
	Corner2 = temp;
}

void CRectangle::Save(ofstream& OutFile)
{
	// Use SaveAll logic for now
	SaveAll(OutFile);
}