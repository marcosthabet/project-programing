#include "Copy.h"
#include "../GUI/Output.cpp"
#include "../ApplicationManager.h"





Copy::Copy(ApplicationManager* pApp) : Action(pApp) {}
void Copy::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Figure is copied");
	SelectedFig = *pManager->GetSelectedFigs();
}

void Copy::Execute() {
	ReadActionParameters();
	CFigure* CopiedFig = NULL;
	CFigure* CopiedFig = SelectedFig->Clone(); 


	}



