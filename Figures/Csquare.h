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
	Csquare();
	virtual void Draw(Output* pOut) const;

	virtual bool IsPointInside(int x, int y) const override;
	virtual void PrintInfo(Output* pOut) const override;
	virtual string GetFigureInfo() const override;
	string getType() const;
	virtual void Load(ifstream& Infile) override;
	virtual CFigure* Clone() const override;
};


#endif

