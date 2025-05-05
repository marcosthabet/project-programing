#pragma once
#ifndef CSQUARE_H
#define CSQUARE_H
#include "CFigure.h"


class Csquare : public CFigure {
private:
	Point center;
	int length; // Length of the square's side, will be constant 
public:
	Csquare(Point, int, GfxInfo FigureGfxInfo);
	/*Csquare();
	string getType();*/
	virtual void Draw(Output* pOut) const;

	virtual bool IsPointInside(int x, int y) const;
	virtual void PrintInfo(Output* pOut) const;
	virtual string GetFigureInfo() const;
	string getType();
	virtual void Load(ifstream& Infile);
	virtual CFigure* Clone() const = 0;
};


#endif

