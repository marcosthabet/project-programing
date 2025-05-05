#pragma once
#ifndef ADD_SQUARE_ACTION_H
#define ADD_SQUARE_ACTION_H

#include "Action.h"


class AddSquareAction : public Action
{
private:
	Point Center; 
	GfxInfo SquareGfxInfo; 
public:
	AddSquareAction(ApplicationManager* pApp); //Reads square parameters
	virtual void ReadActionParameters(); //Adds square to the ApplicationManager
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
};

#endif