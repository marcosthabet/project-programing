#include "../Actions/DeleteAction.h"
#include "../Actions/SelectFigureAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CFigure.h"

DeleteAction::DeleteAction(ApplicationManager* pApp) : Action(pApp)
{
}
void DeleteAction::ReadActionParameters()
{
}
void DeleteAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	ToBeDeleted = pManager->GetSelectedFigs();

	if (ToBeDeleted)
	{
		pManager->Delete(*ToBeDeleted);
		pManager->RemoveSelectedFig(*ToBeDeleted); //unselect it
		pOut->ClearDrawArea();  //this may cause an error

	}

	else
	{
		pOut->PrintMessage("Please select a figure first to delete it");
	}

}

void DeleteAction::Undo()
{
	pManager->AddFigure(*ToBeDeleted);
	pManager->RemovefromUndo();
}

void DeleteAction::Redo()
{
	if (ToBeDeleted != NULL)
	{
		Output* pOut = pManager->GetOutput();
		pManager->Delete(*ToBeDeleted);
		pManager->AddtoUndo(this);
		pOut->ClearDrawArea();
		pManager->RemovefromRedo();
	}
}
