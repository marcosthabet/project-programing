#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include "SaveAction.h"
#include "..\Actions/Action.h"
#include "..\ApplicationManager.h"
#include "..\GUI/Input.h"
#include "..\GUI/Output.h"
#include "..\ColorFiles.h"
using namespace std;


SaveAction::SaveAction(ApplicationManager* pApp) : Action(pApp)
{
}

void SaveAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	// Get the filename from the user
	pOut->PrintMessage("Enter the filename:");
	FileName = pIn->GetFileName(pOut) + ".txt";

}

void SaveAction::Execute()
{
	ReadActionParameters();
	if (FileName.empty()) // If the filename is empty
		return;

	ofstream outFile(FileName);
	if (!outFile.is_open())
	{
		pManager->GetOutput()->PrintMessage("Error opening file for writing.");
		return;
	}

	Output* pOut = pManager->GetOutput();

	color DrawColor = pOut->getCrntDrawColor(); // Get the current draw color
	color FillColor = pOut->getCrntFillColor(); // Get the current fill color

	outFile << ColorFiles::ColorChoice(DrawColor) << endl; // Save the draw color to the file
	outFile << ColorFiles::ColorChoice(FillColor) << endl; // Save the fill color to the file

	int figCount = pManager->GetFigCount(); // Get the number of figures
	outFile << figCount << endl; // Save the number of figures to the file
	for (int i = 0; i < figCount; ++i)
	{
		CFigure* pFig = pManager->GetFigure(i);
		if (pFig != nullptr)
		{
			pFig->Save(outFile); // Save the figure to the file
		}
		else
		{
			cout << "Null figure at index" << i + 1 << endl;
		}
	}
	outFile.close(); // Close the file
	pOut->PrintMessage("File " + FileName + " saved successfully");
}

void SaveAction::Undo()
{
}

void SaveAction::Redo()
{
}