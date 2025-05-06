#pragma once
#ifndef ADD_CIRCLE_ACTION_H
#define ADD_CIRCLE_ACTION_H
#include "Action.h"

class AddCircleAction : public Action
{
private:
	Point center, edge; 
	int radius; 
	GfxInfo CircleGfxInfo; 
public:
	AddCircleAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
    void Undo();
	void Redo();
};
#endif

