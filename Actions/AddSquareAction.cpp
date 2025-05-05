#include "AddSquareAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
#include "..\Figures\Csquare.h"


AddSquareAction::AddSquareAction(ApplicationManager* pApp) :
	Action(pApp), Center{ 0, 0 }
{
	//Initialize the square graphics info
	SquareGfxInfo.BorderWdth = 1;
	SquareGfxInfo.isFilled = false; 
	SquareGfxInfo.DrawClr = BLUE;
	SquareGfxInfo.FillClr = WHITE;
}

void AddSquareAction::ReadActionParameters()
{
	
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Square: Click at center point");
	pIn->GetPointClicked(Center.x, Center.y);

	//for validation
	pIn->Square_Validation(Center, pOut);

	//ask user for draw color
	pOut->PrintMessage("Select a draw color from the toolbar (Black, Yellow, Orange, Red, Green, Blue)");
	SquareGfxInfo.DrawClr = pIn->GetUserColor();
	//check if fill toggle is on
	SquareGfxInfo.isFilled = UI.IsFilled;
	//if filled, ask user for fill color
	if (SquareGfxInfo.isFilled) {
		pOut->PrintMessage("Select a fill color from the toolbar (Black, Yellow, Orange, Red, Green, Blue)");
		SquareGfxInfo.FillClr = pIn->GetUserColor();
	}
	else {
		SquareGfxInfo.FillClr = SquareGfxInfo.DrawClr; // Default to draw color if not filled
	}
	SquareGfxInfo.BorderWdth = pOut->getCrntPenWidth();

	pOut->ClearStatusBar();
}

void AddSquareAction::Execute()
{
	ReadActionParameters();
	const int fixedlength = 200; // fixed side length
	Csquare* square = new Csquare(Center, fixedlength, SquareGfxInfo);
	pManager->AddFigure(square);

	//Add the action to Undo list
	pManager->AddtoUndo(this);

}
void AddSquareAction::Undo()
{
	pManager->AddtoRedo(this);
	DeletedFigure = pManager->DeleteLastFigure();
	pManager->RemovefromUndo();
}
void AddSquareAction::Redo()
{
	pManager->AddFigure(DeletedFigure);
	pManager->AddtoUndo(this);
	pManager->RemovefromRedo();
}
