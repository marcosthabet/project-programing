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
	pOut->ClearStatusBar();

	// Get the filename from the user
	pOut->PrintMessage("Enter the filename:");
	FileName = pIn->GetFileName(pOut) + ".txt";          // Get the filename from the user

	// Check if the filename is valid
	if (FileName.empty())
	{
		pOut->PrintMessage("Invalid filename. Please try again.");
		return;
	}

	// Check if the file already exists
	ifstream inFile(FileName + ".txt");
	if (inFile.good())
	{
		pOut->PrintMessage("File already exists. Do you want to overwrite it? (y/n)");
		char choice = pIn->GetChar(pOut);
		if (choice != 'y' && choice != 'Y')
		{
			pOut->PrintMessage("You cancelled the save action!");
			FileName.clear(); // Prevent saving
		}
	}

	inFile.close();
}

void SaveAction::Execute()
{
	ReadActionParameters();
	if (FileName.empty()) // If the filename is empty
		return;

	ofstream outFile(FileName + ".txt"); 
	if (!outFile.is_open())
	{
		pManager->GetOutput()->PrintMessage("Error opening file for writing.");
		return;
	}

	color DrawColor = pManager->GetOutput()->getCrntDrawColor(); // Get the current draw color
	color FillColor = pManager->GetOutput()->getCrntFillColor(); // Get the current fill color

	outFile << ColorFiles::ColorChoice(DrawColor) << endl; // Save the draw color to the file
	outFile << ColorFiles::ColorChoice(FillColor) << endl; // Save the fill color to the file

	int figCount = pManager->GetFigCount(); // Get the number of figures
	outFile << figCount << endl; // Save the number of figures to the file
	for (int i = 0; i < figCount; ++i)
	{
		CFigure* pFig = pManager->GetFigure(i); // Get the figure
		if (pFig != nullptr)
		{
			pFig->Save(outFile); // Save the figure to the file
		}
	}
	outFile.close(); // Close the file
	pManager->GetOutput()->PrintMessage("File"+ FileName + ".txt saved successfully");
}

void SaveAction::Undo()
{
}

void SaveAction::Redo()
{
}



