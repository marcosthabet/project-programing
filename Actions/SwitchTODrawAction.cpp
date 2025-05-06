#include "SwitchToDrawAction.h"
#include "Action.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"


SwitchToDrawAction::SwitchToDrawAction(ApplicationManager* pApp) : Action(pApp)
{
}

void SwitchToDrawAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Switch to Draw Mode");
}

void SwitchToDrawAction::Execute()
{
	//Get a Pointer  Output Interfaces
	Output* pOut = pManager->GetOutput();

	ReadActionParameters();

	//Switching to Play Mode
	UI.InterfaceMode = MODE_DRAW;
	pOut->CreateDrawToolBar();
	pOut->ClearDrawArea();
	pManager->UpdateInterface();
	pOut->ClearStatusBar();
}

void SwitchToDrawAction::Undo()
{
}

void SwitchToDrawAction::Redo()
{
}
