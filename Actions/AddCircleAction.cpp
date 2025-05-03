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
	pOut->PrintMessage("New Circle: Click edge point");
	pIn->GetPointClicked(edge.x, edge.y);

	// calculate the radius based on the distance from center to edge
	//since drawcircle function needs radius explicitly
	radius = sqrt(pow(edge.x - center.x, 2) + pow(edge.y - center.y, 2));

	CircleGfxInfo.isFilled = false;
	CircleGfxInfo.DrawClr = pOut->getCrntDrawColor();
	CircleGfxInfo.FillClr = pOut->getCrntFillColor();
	CircleGfxInfo.BorderWdth = pOut->getCrntPenWidth();

	pOut->ClearStatusBar();
}

void AddCircleAction::Execute() {
	ReadActionParameters();
	CCircle* circle = new CCircle(center, radius, CircleGfxInfo);
	pManager->AddFigure(circle);
}
