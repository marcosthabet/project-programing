#include "ApplicationManager.h"
#include "Figures/CFigure.h"
#include "GUI/Input.h"
#include "GUI/Output.h"
#include "Actions/Action.h"
#include "Actions/AddRectAction.h"
#include "Actions/AddSquareAction.h"
#include "Actions/AddTriangleAction.h"
#include "Actions/AddHexagonAction.h"
#include "Actions/AddCircleAction.h"
#include "Actions/DeleteAction.h"
#include "Actions/LoadAction.h"
#include "Actions/RotateAction.h"
#include "Actions/SelectFigureAction.h"
#include "Actions/SwapAction.h"
#include "Actions/UndoAction.h"
#include "Actions/SaveAction.h"
#include "Actions/ExitAction.h"
#include "Actions/SwitchToPlayAction.h"
#include "Actions/SwitchToDrawAction.h"
#include "Actions/RedoAction.h"
#include "Actions/ClearAction.h"

#include <Windows.h>
#include "MMSystem.h"

//Constructor
ApplicationManager::ApplicationManager() :
	FigCount(0), SelectedCount(0),LastSelectedFig(NULL), Clipboard(NULL), pIn(NULL), pOut(NULL),UndoCount(0), RedoCount(0), RedoStatus(true)
{

//Create an array of figure pointers and set them to NULL		
	for (int i = 0; i < MaxFigCount; i++) {
		FigList[i] = NULL;
	}
	for (int i = 0; i < MaxSelectedCount; i++) {
		SelectedFigsArr[i] = NULL;
	}

	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	FigCount = 0;
	LastAction = NULL;
	UndoCount = 0;
	RedoCount = 0;


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
		case LOAD:
			pAct = new LoadAction(this);
			break;
		case UNDO:
			pAct = new UndoAction(this);
			break;
		case CLRALL:
			pAct = new ClearAction(this);
			pOut->PrintMessage("All figures deleted");
			break;
		case SELECT:
			pAct = new SelectFigureAction(this);
			break;
			//colours
		case SELECT_COLOR_BLACK:
			UI.DrawColor = BLACK;
			pOut->setCrntDrawColor(BLACK);
			pOut->PrintMessage("Draw color set to Black");
			break;
		case SELECT_COLOR_YELLOW:
			UI.DrawColor = YELLOW;
			pOut->setCrntDrawColor(YELLOW);
			pOut->PrintMessage("Draw color set to Yellow");
			break;
		case SELECT_COLOR_ORANGE:
			UI.DrawColor = ORANGE;
			pOut->setCrntDrawColor(ORANGE);
			pOut->PrintMessage("Draw color set to Orange");
			break;
		case SELECT_COLOR_RED:
			UI.DrawColor = RED;
			pOut->setCrntDrawColor(RED);
			pOut->PrintMessage("Draw color set to Red");
			break;
		case SELECT_COLOR_GREEN:
			UI.DrawColor = GREEN;
			pOut->setCrntDrawColor(GREEN);
			pOut->PrintMessage("Draw color set to Green");
			break;
		case SELECT_COLOR_BLUE:
			UI.DrawColor = BLUE;
			pOut->setCrntDrawColor(BLUE);
			pOut->PrintMessage("Draw color set to Blue");
			break;
		case TOGGLE_FILL:
			UI.IsFilled = !UI.IsFilled;
			pOut->PrintMessage(UI.IsFilled ? "Figures will be filled" : "Figures will not be filled");
			break;
		//case SELECT_FILL_COLOR:
		//	pOut->PrintMessage("Select a fill color from the toolbar (Black, Yellow, Orange, Red, Green, Blue)");
		//	UI.FillColor = pIn->GetUserColor();
		//	pOut->PrintMessage("Fill color set");
		//	return;
		case SWAP:
			pAct = new SwapAction(this);
			break;
		case ROTATE:
			pAct = new RotateAction(this);
			break;
		case SAVE:
			pAct = new SaveAction(this);
			break;
		case TO_PLAY:
			pAct = new SwitchToPlayAction(this);
			break;
		case REDO:
			pAct = new RedoAction(this);
			break;
		case TO_DRAW:
			pAct = new SwitchToDrawAction(this);
			break;


		case EXIT:
			pAct = new ExitAction(this);
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			break;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		//delete pAct;	//You may need to change this line depending to your implementation
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
	for (int i = FigCount - 1; i >= 0; i--)
	{
		if (FigList[i] && FigList[i]->IsPointInside(x, y))
		{
			return FigList[i];
		}
	}

	return NULL;
}

//SELECT FIGURE STUFF
CFigure** ApplicationManager::GetSelectedFigs() const
{
	return (CFigure**)SelectedFigsArr; //returns address of array
}

int ApplicationManager::GetSelectedCount() const
{
	return SelectedCount;
}

void ApplicationManager::AddSelectedFig(CFigure* pFig)  
{
	if (SelectedCount < MaxSelectedCount && pFig != NULL) {
		for (int i = 0; i < SelectedCount; i++) {
			if (SelectedFigsArr[i] == pFig) {
				return; //fig already selected
			}
		}
		SelectedFigsArr[SelectedCount++] = pFig;
		pFig->SetSelected(true);
	}
}

void ApplicationManager::RemoveSelectedFig(CFigure* pFig)
{
	for (int i = 0; i < SelectedCount; i++) {
		if (SelectedFigsArr[i] == pFig) {
			SelectedFigsArr[i] = SelectedFigsArr[SelectedCount - 1];
			SelectedFigsArr[SelectedCount - 1] = NULL;
			SelectedCount--;
			pFig->SetSelected(false);
			break;
		}
	}
}

void ApplicationManager::UnSelect()
{
	for (int i = 0; i < SelectedCount; i++) {
		if (SelectedFigsArr[i]) {
			SelectedFigsArr[i]->SetSelected(false);
			SelectedFigsArr[i] = NULL;
		}
	}
	SelectedCount = 0;
}

void ApplicationManager::PrintTotalInfo() const
{
	string info = "Total Figures: " + to_string(FigCount);
	pOut->PrintMessage(info);
}

void ApplicationManager::PrintSelectedInfo() const
{
	if (SelectedCount == 0) {
		pOut->PrintMessage("No figures selected");
	}
	else if (SelectedCount == 1) {
		// For single selection, print detailed info
		pOut->PrintMessage(SelectedFigsArr[0]->GetFigureInfo());
	}
	else {
		// For multiple selections, just print the count until GetType is added
		string info = "Selected Figures: " + to_string(SelectedCount);
		pOut->PrintMessage(info);
	}
}

//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	for (int i = 0; i < FigCount; i++)
		if (FigList[i]) FigList[i]->Draw(pOut); //call draw function
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

int ApplicationManager::Get_FigCount() const
{
	return FigCount;
}

void ApplicationManager::ClearAll()
{
	for (int i = 0; i < FigCount; i++)
	{
		delete FigList[i];
		FigList[i] = NULL;
	}
	FigCount = 0;
	

	//default draw/color mode for the shapes
	pOut->setCrntDrawColor(BLUE);
	pOut->setCrntFillColor(UI.BkGrndColor);
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
		RedoStatus = false;
	}
}

void ApplicationManager::RemovefromUndo()
{
	if (UndoCount > 0) //if there is an action in the array
	{
		UndoCount--;
	}
	else
		UndoCount = 0;
	RedoStatus = true;
}

Action* ApplicationManager::GetLastActiontoUndo()
{
	if (UndoCount > 0)  // Last action is the Undo 
	{
		LastAction = Undoarr[UndoCount - 1];
		return LastAction;
	}
	return NULL;
}

void ApplicationManager::AddtoRedo(Action* action)
{
	if (action) //if there is  action to redo 
	{
		if (RedoCount >= MaxUndoRedoCount) //if there is less than 5 actions in redoarr
		{
			for (int i = 0; i < MaxUndoRedoCount - 1; i++)
			{
				Redoarr[i] = Redoarr[i + 1];
			}
			RedoCount = 4;
		}
		Redoarr[RedoCount++] = action; //add the last action to the array
	}
}

void ApplicationManager::RemovefromRedo()
{
	if (RedoCount > 0)
	{
		RedoCount--;
	}
	else
		RedoCount = 0;
	RedoStatus = true;
}

Action* ApplicationManager::GetLastActiontoRedo()
{

	if (RedoCount > 0 && RedoStatus)
	{
		return Redoarr[RedoCount - 1];
	}
	return NULL;
}

CFigure* ApplicationManager::GetClipboard() const {
	return Clipboard;
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

void ApplicationManager::SaveAll(ofstream& File)
{
}

int ApplicationManager::GetFigCount() const
{
	return FigCount;
}

CFigure* ApplicationManager::GetFigure(int index) const
{
	if (index >= 0 && index < FigCount)
	{
		return FigList[index];
	}
	return nullptr;
}
CFigure* ApplicationManager::GetFigureByID(int ID)const
{
	for (int i = FigCount - 1; i >= 0; i--)
	{
		if (FigList[i]->GetID() == ID)
			return FigList[i];
	}
	return NULL;
}

int ApplicationManager::GetCutFigureID() {
	return CutFigureID;
}

void ApplicationManager::SetCutFigureID(int i) {
	CutFigureID = i;
}

void ApplicationManager::UpdateFigureData()
{
	SelectedRects = 0, SelectedSqrs = 0, SelectedHexes = 0, SelectedTris = 0, SelectedCircs = 0;
	NumOfRect = 0, NumOfSqr = 0, NumOfHex = 0, NumOfTri = 0, NumOfCirc = 0; SelectedFigCount = 0;
	SelectedFigure = NULL;

	//Reset all figure numbers and count them again

	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i] != NULL)
		{
			switch (FigList[i]->GetFigType())
			{
			case HEXAGON:
				NumOfHex++;
				if (FigList[i]->IsSelected())
				{
					SelectedFigCount++;
					SelectedHexes++;
					SelectedFigure = FigList[i];
				}
				break;
			case CIRCLE:
				NumOfCirc++;
				if (FigList[i]->IsSelected())
				{
					SelectedFigCount++;
					SelectedCircs++;
					SelectedFigure = FigList[i];
				}
				break;
			case TRIANGLE:
				NumOfTri++;
				if (FigList[i]->IsSelected())
				{
					SelectedFigCount++;
					SelectedTris++;
					SelectedFigure = FigList[i];
				}
				break;
			case SQUARE:
				NumOfSqr++;
				if (FigList[i]->IsSelected())
				{
					SelectedFigCount++;
					SelectedSqrs++;
					SelectedFigure = FigList[i];
				}
				break;
			case RECTANGLE:
				NumOfRect++;
				if (FigList[i]->IsSelected())
				{
					SelectedFigCount++;
					SelectedRects++;
					SelectedFigure = FigList[i];
				}
				break;
			}
		}
	}
}

// Clipboard functions
void ApplicationManager::SetClipboard(CFigure* CF) {
	Clipboard = CF;
}

void ApplicationManager::ClearClipboard() 
{
	delete Clipboard;
	Clipboard = NULL;
	CutFigureID = -1;//sets cutfigure ID by a value that cannot equal any ID
}

CFigure* ApplicationManager::GetClipboard() {
	return Clipboard;
}