#include "ExitAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Output.h"

ExitAction::ExitAction(ApplicationManager* pApp) : Action(pApp) {}

void ExitAction::ReadActionParameters() {
    // No parameters to read
}

void ExitAction::Execute() {
    Output* pOut = pManager->GetOutput();
    pOut->PrintMessage("Exiting application...");
    // ApplicationManager destructor will handle cleanup
    exit(0); // Exit the application
}