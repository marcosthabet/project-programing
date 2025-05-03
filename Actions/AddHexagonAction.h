#pragma once
#ifndef ADD_HEXAGON_ACTION_H
#define ADD_HEXAGON_ACTION_H

#include "Action.h"

class AddHexagonAction : public Action {
private:
    Point Center;
    GfxInfo HexagonGfxInfo;
public:
    AddHexagonAction(ApplicationManager* pApp);
    virtual void ReadActionParameters();
    virtual void Execute();
};

#endif
