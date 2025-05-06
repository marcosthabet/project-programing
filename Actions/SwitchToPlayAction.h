#ifndef SWITCHTOPLAYCTION_H
#define SWITCHTOPLAYACTION_H
#pragma once
#include "Action.h"
class SwitchToPlayAction : public Action
{
public:
	SwitchToPlayAction(ApplicationManager* pApp);

	//Read 
	virtual void ReadActionParameters();

	//Add SwitchToPLayAction to ApplicationManager
	virtual void Execute();

	//Undo Action
	void Undo();

	//Redo Action
	void Redo();

};


#endif