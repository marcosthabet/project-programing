#include "SelectFigureAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"

SelectFigureAction::SelectFigureAction(ApplicationManager* pApp) :
	Action(pApp)
{
	figure = NULL;
}

void SelectFigureAction::ReadActionParameters()
{

	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	
	pOut->PrintMessage("Click on a figure to select it");
	pIn->GetPointClicked(P.x, P.y);
	pOut->ClearStatusBar();
	figure = pManager->GetFigure(P.x, P.y); //uses appmngr to find figure clicked at, null if no figure found
}

void SelectFigureAction::Execute()
{
    ReadActionParameters();
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();

    if (figure == NULL) {
        //clicking on an empty area
        pManager->UnSelect(); // Clear all selected figures
        pOut->PrintMessage("No figure selected");
    }
    else {
		//figure already selected
        bool isselected = false;
        for (int i = 0; i < pManager->GetSelectedCount(); i++)
        {
            if (pManager->GetSelectedFigs()[i] == figure)
            {
                isselected = true;
                pManager->RemoveSelectedFig(figure); //unselect it
                pOut->PrintMessage("Figure deselected: " + figure->GetFigureInfo());
                break;
            }
        }
        if (!isselected)
        {
            pManager->AddSelectedFig(figure); //select list
            pOut->PrintMessage("Figure selected: " + figure->GetFigureInfo());
        }
       
        pManager->PrintSelectedInfo();
    }

    pManager->UpdateInterface();
    pIn->ResetSelectMode(); //reset select mode after action
}

//to be checked!!!!
void SelectFigureAction::Undo()
{
    // Undo logic: Reverse the selection state
    if (figure == NULL) {
        // If no figure was selected, undoing means re-selecting previously selected figures
        // This is a simplification; you might need to store previous state
        return;
    }
    else {
        bool isselected = false;
        for (int i = 0; i < pManager->GetSelectedCount(); i++) {
            if (pManager->GetSelectedFigs()[i] == figure) {
                isselected = true;
                pManager->RemoveSelectedFig(figure); // Unselect if it was selected
                break;
            }
        }
        if (!isselected) {
            pManager->AddSelectedFig(figure); // Re-select if it was unselected
        }
    }
    pManager->UpdateInterface();
}
void SelectFigureAction::Redo()
{
    //reselect figure if it was unselected, or unselect if it was selected
    if (figure == NULL) {
        pManager->UnSelect();
    }
    else {
        bool isselected = false;
        for (int i = 0; i < pManager->GetSelectedCount(); i++) {
            if (pManager->GetSelectedFigs()[i] == figure) {
                isselected = true;
                pManager->RemoveSelectedFig(figure);
                break;
            }
        }
        if (!isselected) {
            pManager->AddSelectedFig(figure);
        }
    }
    pManager->UpdateInterface();
}