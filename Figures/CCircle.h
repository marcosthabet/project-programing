#pragma once
#ifndef CIRCLE_H
#define CIRCLE_H
#include "CFigure.h"

class CCircle : public CFigure
{
private:
	Point center;
	int radius;
public:
	CCircle(Point c, int r, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	
};

#endif