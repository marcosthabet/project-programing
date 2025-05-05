#pragma once
#ifndef SELECTFIGUREACTION_H
#define SELECTFIGUREACTION_H
#include "Action.h"

class SelectFigureAction : public Action
{
private:
	Point P; //point where user clicked
	CFigure* figure; //pointer to selected figure
public:
	SelectFigureAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

#endif