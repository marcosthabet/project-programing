#pragma once
#ifndef CIRCLE_H
#define CIRCLE_H
#include "CFigure.h"
#include"../GUI/Output.h"
class CCircle : public CFigure
{
private:
	Point center;
	int radius;
public:
	CCircle(Point c, int r, GfxInfo FigureGfxInfo);
	CCircle();
	virtual void Move(int, int);
	virtual void Draw(Output* pOut) const override;
	string getType() const;
	virtual bool IsPointInside(int x, int y) const override;
	virtual void PrintInfo(Output* pOut) const override;
	virtual string GetFigureInfo() const override;
	virtual void Load(ifstream& Infile) override;
	virtual  CFigure* Clone() const;
	
};

#endif