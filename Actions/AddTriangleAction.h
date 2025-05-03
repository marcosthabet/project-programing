#pragma once
#ifndef ADD_TRIANGLE_ACTION_H
#define ADD_TRIANGLE_ACTION_H
#include "Action.h"

class AddTriangleAction : public Action
{
private:
	Point point1, point2, point3;
	GfxInfo TriangleGfxInfo;
public:
	AddTriangleAction(ApplicationManager* pApp); 
	virtual void ReadActionParameters();
	virtual void Execute();
};
#endif
