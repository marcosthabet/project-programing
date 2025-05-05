#pragma once
#include "RotateAction.h"
#include "..\ApplicationManager.h"
#include "..\Figures/CFigure.h"

RotateAction::RotateAction(ApplicationManager* pApp) : Action(pApp)
{
}

void RotateAction::ReadActionParameters()
{
}

void RotateAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->ClearStatusBar();

	// Get the selected figures
	pOut->PrintMessage("Select figures to rotate:");
	int x, y;
	pIn->GetPointClicked(x, y);
	CFigure* selectedFig = pManager->GetFigure(x, y);

	if (selectedFig == NULL)
	{
		pOut->PrintMessage("No figure selected. Please select a figure:");
		return;
	}

	// Rotate the selected figure
		selectedFig->Rotate();
	
	pManager->UpdateInterface();
	pOut->PrintMessage("The selected figures have been rotated!!");
}

void RotateAction::Undo()
{
}

void RotateAction::Redo()
{
}






