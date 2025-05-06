#include "AddRectAction.h"
#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddRectAction::AddRectAction(ApplicationManager* pApp) :Action(pApp),
P1{ 0, 0 }, P2{ 0, 0 } //Initialize the points to (0,0)
{
	//Initialize the rectangle graphics info
	RectGfxInfo.BorderWdth =1;
	RectGfxInfo.isFilled = false;//default is not filled
	RectGfxInfo.DrawClr = BLUE;
	RectGfxInfo.FillClr = WHITE;

}


void AddRectAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Rectangle: Click at first corner");
	
	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);


	//for validation
	pIn->Point_Validation(P2, pOut);
	pIn->Repeatability_Validation(P1, P2, pOut);


	pOut->PrintMessage("New Rectangle: Click at second corner");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	//ask user for draw color
	pOut->PrintMessage("Select a draw color from the toolbar (Black, Yellow, Orange, Red, Green, Blue)");
	RectGfxInfo.DrawClr = pIn->GetUserColor();
	//check if fill toggle is on
	RectGfxInfo.isFilled = UI.IsFilled;
	//if filled, ask user for fill color
	if (RectGfxInfo.isFilled) {
		pOut->PrintMessage("Select a fill color from the toolbar (Black, Yellow, Orange, Red, Green, Blue)");
		RectGfxInfo.FillClr = pIn->GetUserColor();
	}
	else {
		RectGfxInfo.FillClr = RectGfxInfo.DrawClr; // Default to draw color if not filled
	}
	RectGfxInfo.BorderWdth = pOut->getCrntPenWidth();
	pOut->ClearStatusBar();

}

//Execute the action
void AddRectAction::Execute() 
{
	//This action needs to read some parameters first
	ReadActionParameters();
	
	//Create a rectangle with the parameters read from the user
	CRectangle *R=new CRectangle(P1, P2, RectGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(R);
	//Add the action to Undo list
	pManager->AddtoUndo(this);

	
}

void AddRectAction::Undo()
{
	pManager->AddtoRedo(this);
	DeletedFigure = pManager->DeleteLastFigure();
	pManager->RemovefromUndo();
}

void AddRectAction::Redo()
{
	pManager->AddFigure(DeletedFigure);
	pManager->AddtoUndo(this);
	pManager->RemovefromRedo();
}
