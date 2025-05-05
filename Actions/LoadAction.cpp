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
	Input* pIn = pManager->GetInput();

	ifstream fin;

	fin.open(FileName + ".txt", ios::in);
	if (fin.fail())
	{
		pOut->PrintMessage(FileName + ".txt" + "doesn't exist");
	}
	else {
		pManager->ClearAll();

		fin >> ReadFigCount;
		for (int i = 0; i < ReadFigCount; i++)
		{
			fin >> ReadType;
			if (ReadType == "Square") CurrentFigure = new Csquare;
			else if (ReadType == "Hexagon") CurrentFigure = new CHexagon;
			else if (ReadType == "Circle") CurrentFigure = new CCircle;
			else if (ReadType == "Rectangle") CurrentFigure = new CRectangle;
			else if (ReadType == "Triangle") CurrentFigure = new CTriangle;
			else break;

			CurrentFigure->Load(fin);
			pManager->AddFigure(CurrentFigure);
		}
		pManager->UpdateInterface();
		pManager->UnSelect();
		fin.close();
		pOut->PrintMessage("File loaded");
	}
}


void LoadAction::Undo() {}
void LoadAction::Redo() {}
