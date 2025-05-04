#include "ApplicationManager.h"
#include "Figures/CFigure.h"
#include "GUI/Input.h"
#include "GUI/Output.h"
#include "Actions/AddRectAction.h"
#include "Actions/AddSquareAction.h"
#include "Actions/AddTriangleAction.h"
#include "Actions/AddHexagonAction.h"
#include "Actions/AddCircleAction.h"
#include "../phase 2/Actions/DeleteAction.h"
#include "Actions/SelectFigureAction.h"
#include "Actions/Action.h"

#include <Windows.h>
#include "MMSystem.h"
//Constructor
ApplicationManager::ApplicationManager() :
	FigCount(0), SelectedFig(NULL), Clipboard(NULL), pIn(NULL), pOut(NULL) {

//Create an array of figure pointers and set them to NULL		
	for (int i = 0; i < MaxFigCount; i++) {
		FigList[i] = NULL;
	}
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	FigCount = 0;

	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;
		case DRAW_SQU:
			pAct = new AddSquareAction(this);
			break;
		case DRAW_TRI:
			pAct = new AddTriangleAction(this);
			break;
		case DRAW_HEX:
			pAct = new AddHexagonAction(this);
			break;
		case DRAW_CIRC:
			pAct = new AddCircleAction(this);
			break;
		case DEL:
			pAct = new DeleteAction(this);
			break;
		case EXIT:
			///create ExitAction here
			
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//You may need to change this line depending to your implementation
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if (FigCount < MaxFigCount) {
		FigList[FigCount++] = pFig;
		pFig->SetID(FigCount); // set the ID of the figure
	}
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL


	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.

	return NULL;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	for(int i=0; i<FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }


//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }

void ApplicationManager::Delete(CFigure* pFig)
{

	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i] == pFig)
		{
			FigList[i] = FigList[FigCount - 1];

			FigCount--;
			break;
		}
	}
	UpdateInterface();
}

CFigure* ApplicationManager::DeleteLastFigure()
{
	if (FigCount > 0)
	{
		CFigure* DeletedFig = FigList[FigCount - 1];
		FigList[FigCount - 1] = FigList[MaxFigCount - 1];
		FigList[MaxFigCount - 1] = NULL;
		FigCount--;
		pOut->ClearDrawArea();
		UpdateInterface();
		return DeletedFig;
	}
	return nullptr;
}

void ApplicationManager::AddtoUndo(Action* action)
{
	if (action) //if there is  action done 
	{
		if (UndoCount < MaxUndoRedoCount) //if there is less than 5 actions in undoarr
		{
			Undoarr[UndoCount++] = action; //add the last action to the array
		}
		else //else if the UndoCount is max, delete the first action in the array
		{
			for (int i = 0; i < MaxUndoRedoCount - 1; i++)
			{
				Undoarr[i] = Undoarr[i + 1];
			}
			UndoCount = 4;
			Undoarr[UndoCount++] = action;
		}
	}
}

void ApplicationManager::RemovefromUndo()
{
	if (UndoCount > 0) //if there is an action in the array
	{
		UndoCount--;
	}
}


////////////////////////////////////////////////////////////////////////////////////
//Destructor to clean up figures
ApplicationManager::~ApplicationManager()
{
	for (int i = 0; i < FigCount; i++) {
		delete FigList[i];
	}
	delete pIn;
	delete pOut;
	delete Clipboard; //if not NULL
	
}
