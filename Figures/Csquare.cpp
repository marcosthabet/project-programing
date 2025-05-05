#include "Csquare.h"
#include <fstream>

//constructor 
Csquare::Csquare(Point p, int l, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo) {
	center = p;
	length = l;
}

Csquare::Csquare()
{
	Type = "Square";
}
string Csquare::getType()
{
	return Type;
}

void Csquare::Draw(Output* pOut) const 
{
	pOut->DrawSquare(center, length, FigGfxInfo, Selected);
}


bool Csquare::IsPointInside(int x, int y) const {
	int half = length / 2;
	if ((x >= (center.x - half) && x < +(center.x + half)) //point between right and left side
		&& (y >= (center.y - half) && y <= (center.y + half))) //point between top and bottom side
	{
		return true;
	}
	else {
		return false;
	}
	
}	
void Csquare::PrintInfo(Output* pOut) const {
	string info = GetFigureInfo();
	pOut->PrintMessage(info);
}

string Csquare::GetFigureInfo() const {
	return "Square: ID = " + to_string(ID) +
		", Center = (" + to_string(center.x) +
		", " + to_string(center.y) +
		"), Length = " + to_string(length);
}

void Csquare::Load(ifstream& Infile)  
{  
	Infile >> ID >> center.x >> center.y >> DrawColor >> FillColor;  
	FigGfxInfo.DrawClr = stringtoclr(DrawColor);
	FigGfxInfo.FillClr = stringtoclr(FillColor);
}