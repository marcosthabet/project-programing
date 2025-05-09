#pragma once
#include "Action.h"

class ExitAction : public Action {
public:
    ExitAction(ApplicationManager* pApp);
    virtual void ReadActionParameters();
    virtual void Execute();
    virtual void Undo() {}
    virtual void Redo() {}
};
