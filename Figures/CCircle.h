#pragma once
#ifndef CIRCLE_H
#define CIRCLE_H
#include "CFigure.h"
#include "..\defs.h"

class CCircle : public CFigure
{
private:
	Point center;
	int radius;
public:
	CCircle(Point c, int r, GfxInfo FigureGfxInfo);
	CCircle();
	virtual void MoveFigure(int, int);
	virtual void Draw(Output* pOut) const ;
	string getType();
	virtual bool IsPointInside(int x, int y) const ;
	virtual void PrintInfo(Output* pOut) const ;
	virtual string GetFigureInfo() const ;
	virtual void Load(ifstream& Infile) ;
	
	virtual Point GetCenter() const;
	virtual void SetPosition(int x, int y);
	virtual void Rotate();
	void Save(ofstream& OutFile);

};

#endif