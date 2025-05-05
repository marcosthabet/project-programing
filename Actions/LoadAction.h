#pragma once
#ifndef LOAD_H
#define LOAD_H

#include "Action.h"
#include "..\Figures\CFigure.h"  

class LoadAction : public Action
{
	string FileName;
	CFigure* CurrentFigure;
	int ReadFigCount;
	string ReadDrawColor, ReadFillColor, ReadType;
public:
	LoadAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	void Undo();
	void Redo();
};
#endif
