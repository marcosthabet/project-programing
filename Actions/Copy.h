#pragma once
#include "Action.h"
#include "../Figures/CFigure.cpp"
#include "../Figures/CCircle.cpp"
#include "../Figures/CHexagon.cpp"
#include "../Figures/CRectangle.cpp"
#include "../Figures/Csquare.cpp"
#include "../Figures/CTriangle.cpp"



class Copy :
    public Action
{
    CFigure* SelectedFig;
    bool Selected;
public:
    Copy(ApplicationManager* pApp);
    virtual void ReadActionParameters();
    virtual void Execute();
};