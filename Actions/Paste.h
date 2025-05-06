#pragma once
#include "Action.h"
#include"..\Figures\CFigure.h"
#include"..\Figures\CCircle.h"
#include"..\Figures\CHexagon.h"
#include"..\Figures\CRectangle.h"
#include"..\Figures\CSquare.h"
#include"..\Figures\CTriangle.h"

class Paste : public Action
{
	Point Clicked;
	CFigure* ClipboardFigure;
public:
	Paste(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};
