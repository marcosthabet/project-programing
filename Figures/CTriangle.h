#pragma once

#ifndef CTRIANGLE_H
#define CTRIANGLE_H
#include "CFigure.h"

class CTriangle : public CFigure {
private:
	Point point1, point2, point3; // Points of the triangle
public:
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const; // Draws the triangle
};
#endif

