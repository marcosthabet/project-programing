#include "ExitAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Output.h"

ExitAction::ExitAction(ApplicationManager* pApp) : Action(pApp) {}

void ExitAction::ReadActionParameters() {
    
}

void ExitAction::Execute() {
    Output* pOut = pManager->GetOutput();
    pOut->PrintMessage("Exiting application...");
   
    exit(0); 
}