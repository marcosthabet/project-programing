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
	pOut->PrintMessage("New Triangle: Click at second point");
	pIn->GetPointClicked(point2.x, point2.y);
	pOut->PrintMessage("New Triangle: Click at third point");
	pIn->GetPointClicked(point3.x, point3.y);

	TriangleGfxInfo.isFilled = false;
	TriangleGfxInfo.DrawClr = pOut->getCrntDrawColor();
	TriangleGfxInfo.FillClr = pOut->getCrntFillColor();
	TriangleGfxInfo.BorderWdth = pOut->getCrntPenWidth();

	pOut->ClearStatusBar();
}

void AddTriangleAction::Execute() {
	ReadActionParameters();
	CTriangle* triangle = new CTriangle(point1, point2, point3, TriangleGfxInfo);
	pManager->AddFigure(triangle);
}