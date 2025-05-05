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


	//ask user for draw color
	pOut->PrintMessage("Select a draw color from the toolbar (Black, Yellow, Orange, Red, Green, Blue)");
	HexagonGfxInfo.DrawClr = pIn->GetUserColor();
	//check if fill toggle is on
	HexagonGfxInfo.isFilled = UI.IsFilled;
    //if filled, ask user for fill color
	if (HexagonGfxInfo.isFilled) {
		pOut->PrintMessage("Select a fill color from the toolbar (Black, Yellow, Orange, Red, Green, Blue)");
		HexagonGfxInfo.FillClr = pIn->GetUserColor();
	}
	else {
		HexagonGfxInfo.FillClr = HexagonGfxInfo.DrawClr; // Default to draw color if not filled
	}
	HexagonGfxInfo.BorderWdth = pOut->getCrntPenWidth();
    
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

