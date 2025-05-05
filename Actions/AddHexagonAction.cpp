#include "AddHexagonAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CHexagon.h"

AddHexagonAction::AddHexagonAction(ApplicationManager* pApp) : 
    Action(pApp) {
    HexagonGfxInfo.isFilled = false;
    HexagonGfxInfo.DrawClr = BLUE;
    HexagonGfxInfo.FillClr = WHITE;
    HexagonGfxInfo.BorderWdth = 1;
}

void AddHexagonAction::ReadActionParameters() {
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();

    pOut->PrintMessage("Add Hexagon: Click center point");
    pIn->GetPointClicked(Center.x, Center.y);

    HexagonGfxInfo.DrawClr = UI.DrawColor;
    HexagonGfxInfo.FillClr = UI.FillColor;
    HexagonGfxInfo.isFilled = UI.IsFilled;
    HexagonGfxInfo.BorderWdth = UI.PenWidth;

    pOut->ClearStatusBar();
}

void AddHexagonAction::Execute() {
    ReadActionParameters();
    CHexagon* hexagon = new CHexagon(Center, HexagonGfxInfo);
    pManager->AddFigure(hexagon);
    
    //Add the action to Undo list
    pManager->AddtoUndo(this);
}

void AddHexagonAction::Undo()
{
    pManager->AddtoRedo(this);
    DeletedFigure = pManager->DeleteLastFigure();
    pManager->RemovefromUndo();
}

void AddHexagonAction::Redo()
{
    pManager->AddFigure(DeletedFigure);
    pManager->AddtoUndo(this);
    pManager->RemovefromRedo();
}

