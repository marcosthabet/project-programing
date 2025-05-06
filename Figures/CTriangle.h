#pragma once

#ifndef CTRIANGLE_H
#define CTRIANGLE_H
#include "CFigure.h"

class CTriangle : public CFigure {
private:
	Point point1, point2, point3; // 3 vertices
public:
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo);
	CTriangle();
	virtual void Draw(Output* pOut) const override;
	virtual bool IsPointInside(int x, int y) const override;
	virtual void PrintInfo(Output* pOut) const override;
	virtual string GetFigureInfo() const override;
	virtual CFigure* Clone() const override;

	string getType() const;
	virtual void Load(ifstream& Infile);
};
#endif

