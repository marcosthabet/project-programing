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
	//CCircle();
	virtual void Draw(Output* pOut) const;

	virtual bool IsPointInside(int x, int y) const; 
	virtual void PrintInfo(Output* pOut) const;
	virtual string GetFigureInfo() const; 
	
};

#endif