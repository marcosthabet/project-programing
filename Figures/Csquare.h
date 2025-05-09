#pragma once
#ifndef CSQUARE_H
#define CSQUARE_H
#include "CFigure.h"
#include "..\defs.h"


class Csquare : public CFigure {
private:
	Point center;
	int length; // Length of the square's side, will be constant 
public:
	Csquare(Point, int, GfxInfo FigureGfxInfo);
	Csquare();
	string getType();
	virtual void Draw(Output* pOut) const;

	virtual bool IsPointInside(int x, int y) const override;
	virtual void PrintInfo(Output* pOut) const override;
	virtual string GetFigureInfo() const override;
	string getType() const;
	virtual void Load(ifstream& Infile) override;
	virtual CFigure* Clone() const override;
	virtual bool IsPointInside(int x, int y) const;
	virtual void PrintInfo(Output* pOut) const;
	virtual string GetFigureInfo() const;

	virtual void SetPosition(int x, int y);

	virtual Point GetCenter() const;

	virtual void Rotate();

	virtual void Save(ofstream& OutFile);
	
	virtual void Load(ifstream& Infile) ;
};


#endif

