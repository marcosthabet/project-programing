#include "AddTriangleAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CTriangle.h"

AddTriangleAction::AddTriangleAction(ApplicationManager* pApp) :
	Action(pApp) {
	TriangleGfxInfo.BorderWdth = 1;
	TriangleGfxInfo.isFilled = false;
	TriangleGfxInfo.DrawClr = BLUE;
	TriangleGfxInfo.FillClr = WHITE;
	
}

void AddTriangleAction::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//reads coordinates of the 3 triangle vertices
	pOut->PrintMessage("New Triangle: Click at first point");
	pIn->GetPointClicked(point1.x, point1.y);

	pIn->Point_Validation(point1, pOut);

	pOut->PrintMessage("New Triangle: Click at second point");
	pIn->GetPointClicked(point2.x, point2.y);

	pIn->Point_Validation(point2, pOut);
	pIn->Repeatability_Validation(point1, point2, pOut); //check if the two points are the same

	pOut->PrintMessage("New Triangle: Click at third point");
	pIn->GetPointClicked(point3.x, point3.y);

	pIn->Point_Validation(point3, pOut);
	pIn->Repeatability_Validation(point1, point3, pOut);
	pIn->Repeatability_Validation(point2, point3, pOut); 



	//ask user for draw color
	pOut->PrintMessage("Select a draw color from the toolbar (Black, Yellow, Orange, Red, Green, Blue)");
	TriangleGfxInfo.DrawClr = pIn->GetUserColor();
	pOut->setCrntDrawColor(TriangleGfxInfo.DrawClr);


	//check if fill toggle is on
	TriangleGfxInfo.isFilled = UI.IsFilled;


	//if filled, ask user for fill color
	if (TriangleGfxInfo.isFilled) {
		pOut->PrintMessage("Select a fill color from the toolbar (Black, Yellow, Orange, Red, Green, Blue)");
		TriangleGfxInfo.FillClr = pIn->GetUserColor();
		pOut->setCrntFillColor(TriangleGfxInfo.FillClr);
	}
	else {
		TriangleGfxInfo.FillClr = TriangleGfxInfo.DrawClr; //default to draw color if not filled
		pOut->setCrntFillColor(TriangleGfxInfo.FillClr);
	}

	TriangleGfxInfo.BorderWdth = pOut->getCrntPenWidth();
	pOut->ClearStatusBar();
}

void AddTriangleAction::Execute() {
	ReadActionParameters();
	CTriangle* triangle = new CTriangle(point1, point2, point3, TriangleGfxInfo);
	pManager->AddFigure(triangle);
	triangle->SetSelected(false);

	//Add the action to Undo list
	pManager->AddtoUndo(this);
}

void AddTriangleAction::Undo()
{
	pManager->AddtoRedo(this);
	DeletedFigure = pManager->DeleteLastFigure();
	pManager->RemovefromUndo();
}

void AddTriangleAction::Redo()
{
	pManager->AddFigure(DeletedFigure);
	pManager->AddtoUndo(this);
	pManager->RemovefromRedo();
}


