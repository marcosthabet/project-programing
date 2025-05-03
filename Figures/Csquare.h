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
	virtual void Draw(Output* pOut) const;
};


#endif

