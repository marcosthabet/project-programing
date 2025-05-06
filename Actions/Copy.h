#pragma once
#include "Action.h"



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