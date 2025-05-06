#pragma once
#include "Action.h"
#include"..\Figures\CFigure.h"
#include"..\Figures\CCircle.h"
#include"..\Figures\CHexagon.h"
#include"..\Figures\CRectangle.h"
#include"..\Figures\Csquare.h"
#include"..\Figures\CTriangle.h"
class Cut :
    public Action
{
	CFigure* SelectedFig;

public:
	Cut(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();

};

