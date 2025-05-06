#pragma once  
#include "SwapAction.h"
#include "..\ApplicationManager.h"
#include "..\Figures/CFigure.h"

SwapAction::SwapAction(ApplicationManager* pApp) : Action(pApp)
{
}

void SwapAction::ReadActionParameters()
{
}

void SwapAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->ClearStatusBar();

// Get the selected figures
	pOut->PrintMessage("Select first figure to swap:");
	int x1, y1;
	pIn->GetPointClicked(x1, y1);
	CFigure* Fig1 = pManager->GetFigure(x1,y1);

	if (Fig1 == NULL)
	{
		pOut->PrintMessage("No figure selected. Please select a figure:");
		return;
	}

	pOut->PrintMessage("Select second figure to swap:");
	int x2, y2;
	pIn->GetPointClicked(x2, y2);
	CFigure* Fig2 = pManager->GetFigure(x2, y2);

	if (Fig2 == NULL || Fig1 == Fig2)
	{
		pOut->PrintMessage("No figure selected. Please select a figure:");
		return;
	}

	Point ref1 = Fig1->GetCenter();
	Point ref2 = Fig2->GetCenter();

	// Swap the positions of the two figures
	Fig1->SetPosition(ref2.x, ref2.y);
	Fig2->SetPosition(ref1.x, ref1.y);

	pManager->UpdateInterface();

	pOut->PrintMessage("The positions of the two selected figures are swapped!!");
}

void SwapAction::Undo()
{
}

void SwapAction::Redo()
{
}
