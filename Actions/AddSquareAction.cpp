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

	SquareGfxInfo.isFilled = false; 
	SquareGfxInfo.DrawClr = pOut->getCrntDrawColor();
	SquareGfxInfo.FillClr = pOut->getCrntFillColor();
	SquareGfxInfo.BorderWdth = pOut->getCrntPenWidth();

	pOut->ClearStatusBar();
}

void AddSquareAction::Execute()
{
	ReadActionParameters();
	const int fixedlength = 200; // fixed side length
	Csquare* square = new Csquare(Center, fixedlength, SquareGfxInfo);
	pManager->AddFigure(square);
}