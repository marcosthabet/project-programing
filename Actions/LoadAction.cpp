#include "LoadAction.h"

#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CTriangle.h"
#include "..\Figures\CHexagon.h"
#include "..\Figures\CSquare.h"
#include "..\Figures\CCircle.h"
#include <fstream>
#include <string>
using namespace std;

LoadAction::LoadAction(ApplicationManager* pApp) : Action(pApp)
{
	CurrentFigure = NULL;
}

void LoadAction::ReadActionParameters()
{
	Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Loading...., enter the name of your saved file: ");
	FileName = pIn->GetSrting(pOut) + ".txt";
}

void LoadAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	pOut->ClearDrawArea();
	pManager->ClearAll();
	ifstream InFile(FileName);
	if (InFile.is_open())
	{
		set the drawing color
		InFile >> ReadDrawColor; pOut->setCrntDrawColor(StringToColor(ReadDrawColor));
		set the fill color
		InFile >> ReadFillColor;
		if (ReadFillColor == "NO_FILL")
		{
			UI.IsFilled = false;
			UI.FillColor = UI.BkGrndColor;
		}
		else
		{
			pOut->setCrntFillColor(StringToColor(ReadFillColor));
			pOut->SetFilled(true);
		}

		InFile >> ReadFigCount;

		Loop to read the type of each figure and set the CurrentFigure pointer to it
		for (int i = 0; i < ReadFigCount; i++)
		{
			InFile >> ReadType;
			if (ReadType == "Rectangle")
			{
				CurrentFigure = new CRectangle();
			}
			else if (ReadType == "Triangle")
			{
				CurrentFigure = new CTriangle();
			}
			else if (ReadType == "Hexagon")
			{
				CurrentFigure = new CHexagon();
			}
			else if (ReadType == "Square")
			{
				CurrentFigure = new Csquare();
			}
			else if (ReadType == "Circle")
			{
				CurrentFigure = new CCircle();
			}
			if the read type matches any of the available shapes 
			if (CurrentFigure)
			{
				CurrentFigure->Load(InFile);
				pManager->AddFigure(CurrentFigure, false);
			}
		}
		pManager->UpdateInterface();
		InFile.close();
	}
	else
	{
		pOut->PrintMessage("File not found, it may have been moved or deleted, try again");
	}
}



void LoadAction::Undo() {}
void LoadAction::Redo() {}
