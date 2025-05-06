#pragma once
#include "Action.h"

class RotateAction :
    public Action
{
public:
	RotateAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	void Undo();
	void Redo();
};

