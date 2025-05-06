#pragma once

#ifndef CTRIANGLE_H
#define CTRIANGLE_H
#include "CFigure.h"
#include "..\defs.h"

class CTriangle : public CFigure {
private:
	Point point1, point2, point3; // 3 vertices
public:
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo);
	CTriangle();
	virtual void Draw(Output* pOut) const;
	virtual bool IsPointInside(int x, int y) const;
	virtual void PrintInfo(Output* pOut) const;
	virtual string GetFigureInfo() const;
	
	void Save(ofstream& File);

	

	string getType();
	virtual void Load(ifstream& Infile);
};
#endif

