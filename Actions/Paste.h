#pragma once
#include "Action.h"
class Paste :
    public Action
{
    Point PastePoint;
public:
    Paste(ApplicationManager* pAap);
    virtual void ReadActionParameter();
	virtual void Execute();
};

