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

	SquareGfxInfo.DrawClr = UI.DrawColor;
	SquareGfxInfo.FillClr = UI.FillColor;
	SquareGfxInfo.isFilled = UI.IsFilled;
	SquareGfxInfo.BorderWdth = UI.PenWidth;

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
