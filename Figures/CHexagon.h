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
	virtual void Draw(Output* pOut) const;
};
#endif

