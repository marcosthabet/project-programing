#include "..\DeleteAction.h"

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
	ToBeDeleted = pManager->GetLastSelected();

	if (ToBeDeleted)
	{
		pManager->Delete(ToBeDeleted);
		ToBeDeleted->SetSelected(false);
		pOut->ClearDrawArea();  //this may cause an error

	}

	else
	{
		pOut->PrintMessage("Please select a figure first to delete it");
	}

}

void DeleteAction::Undo()
{
	pManager->AddFigure(ToBeDeleted);
	pManager->RemovefromUndo();
}
