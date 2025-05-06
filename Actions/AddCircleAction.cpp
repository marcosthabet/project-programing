#include "AddCircleAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CCircle.h"

AddCircleAction::AddCircleAction(ApplicationManager* pApp) : Action(pApp) {
	CircleGfxInfo.isFilled = false;
	CircleGfxInfo.DrawClr = BLUE;
	CircleGfxInfo.FillClr = WHITE;
	CircleGfxInfo.BorderWdth = 1;
}

void AddCircleAction::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Circle: Click center point");
	pIn->GetPointClicked(center.x, center.y);
	pIn->Point_Validation(center, pOut);

	pOut->PrintMessage("New Circle: Click edge point");
	pIn->GetPointClicked(edge.x, edge.y);
	pIn->Circle_Validation(center, edge, CircleGfxInfo, pOut);
	

	// calculate the radius based on the distance from center to edge
	//since drawcircle function needs radius explicitly
	radius = sqrt(pow(edge.x - center.x, 2) + pow(edge.y - center.y, 2));


	//ask user for draw color
	pOut->PrintMessage("Select a draw color from the toolbar (Black, Yellow, Orange, Red, Green, Blue)");
	CircleGfxInfo.DrawClr = pIn->GetUserColor();
	pOut->setCrntDrawColor(CircleGfxInfo.DrawClr);


	//check if fill toggle is on
	CircleGfxInfo.isFilled = UI.IsFilled;
	//if filled, ask user for fill color
	if (CircleGfxInfo.isFilled) {
		pOut->PrintMessage("Select a fill color from the toolbar (Black, Yellow, Orange, Red, Green, Blue)");
		CircleGfxInfo.FillClr = pIn->GetUserColor();
		pOut->setCrntFillColor(CircleGfxInfo.FillClr);
	}
	else {
		CircleGfxInfo.FillClr = CircleGfxInfo.DrawClr; // Default to draw color if not filled
		pOut->setCrntFillColor(CircleGfxInfo.FillClr);
	}
	CircleGfxInfo.BorderWdth = pOut->getCrntPenWidth();
	pOut->ClearStatusBar();
}

void AddCircleAction::Execute() {
	ReadActionParameters();
	CCircle* circle = new CCircle(center, radius, CircleGfxInfo);
	pManager->AddFigure(circle);
	circle->SetSelected(false);
	//Add the action to Undo list
	pManager->AddtoUndo(this);
}

void AddCircleAction::Undo()
{
	pManager->AddtoRedo(this);
	DeletedFigure = pManager->DeleteLastFigure();
	pManager->RemovefromUndo();
}
void AddCircleAction::Redo()
{
	pManager->AddtoUndo(this);
	pManager->AddFigure(DeletedFigure);
	pManager->RemovefromRedo();
}