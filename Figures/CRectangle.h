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
	CRectangle();
	virtual void Draw(Output* pOut) const override;
	string getType() const;
	virtual bool IsPointInside(int x, int y) const override;
	virtual void PrintInfo(Output* pOut) const override;
	virtual string GetFigureInfo() const override;
	virtual CFigure* Clone() const override;
	virtual void Load(ifstream& Infile) override;
	virtual void Draw(Output* pOut) const ;
	string getType();
	virtual bool IsPointInside(int x, int y) const ;
	virtual void PrintInfo(Output* pOut) const ;
	virtual string GetFigureInfo() const ;
	virtual void Load(ifstream& Infile) ;

	virtual Point GetCenter() const;
	virtual void SetPosition(int x, int y);
	virtual void Rotate();
	virtual void Save(ofstream& OutFile);
};

#endif