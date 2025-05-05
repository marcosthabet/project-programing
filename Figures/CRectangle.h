#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"
#include "..\defs.h"


class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;

	virtual bool IsPointInside(int x, int y) const;
	virtual void PrintInfo(Output* pOut) const;
	virtual string GetFigureInfo() const;

	void SaveAll(ofstream& File);
};

#endif