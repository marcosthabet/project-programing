#pragma once
#ifndef SELECT_FIGURE_ACTION_H
#define SELECT_FIGURE_ACTION_H

#include "Action.h"
#include "..\ApplicationManager.h"
#include "..\Figures\CFigure.h"

class SelectFigureAction : public Action
{
private:
    Point P; // Point where the user clicked
    CFigure* figure; // Pointer to the selected figure

public:
    SelectFigureAction(ApplicationManager* pApp);

    virtual void ReadActionParameters();

    virtual void Execute();

    void Undo(); 

    void Redo();
};

#endif