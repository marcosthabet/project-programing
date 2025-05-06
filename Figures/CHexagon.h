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
	virtual void Draw(Output* pOut) const override;
	virtual bool IsPointInside(int x, int y) const override;
	virtual void PrintInfo(Output* pOut) const override;
	virtual string GetFigureInfo() const override;
	virtual CFigure* Clone() const override;
	string getType() const;
	virtual void Load(ifstream& Infile) override;

};
#endif

