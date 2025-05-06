#pragma once
#ifndef CHEXAGON_H
#define CHEXAGON_H
#include "CFigure.h"


class CHexagon : public CFigure
{
private:
	Point center;
public:
	CHexagon(Point, GfxInfo FigureGfxInfo);
	CHexagon();
	virtual void Draw(Output* pOut) const ;
	virtual bool IsPointInside(int x, int y) const ;
	virtual void PrintInfo(Output* pOut) const ;
	virtual string GetFigureInfo() const ;
	string getType();
	virtual void Load(ifstream& Infile) ;

};
#endif

