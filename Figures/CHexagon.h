#pragma once
#ifndef CHEXAGON_H
#define CHEXAGON_H
#include "CFigure.h"
#include "..\defs.h"


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
	virtual void Draw(Output* pOut) const ;
	virtual bool IsPointInside(int x, int y) const ;
	virtual void PrintInfo(Output* pOut) const ;
	virtual string GetFigureInfo() const ;
	string getType();
	virtual void Load(ifstream& Infile) ;

	virtual Point GetCenter() const;
	virtual void SetPosition(int x, int y);
	virtual void Rotate();
	virtual void Save(ofstream& OutFile);

};
#endif

