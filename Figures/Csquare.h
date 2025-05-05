#pragma once
#ifndef CSQUARE_H
#define CSQUARE_H
#include "CFigure.h"
#include "..\defs.h"


class Csquare : public CFigure {
private:
	Point center;
	int length; // Length of the square's side, will be constant 
public:
	Csquare(Point, int, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;

	virtual bool IsPointInside(int x, int y) const;
	virtual void PrintInfo(Output* pOut) const;
	virtual string GetFigureInfo() const;

	void SaveAll(ofstream& File);
};


#endif

