#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H


#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"
#include "Actions\Action.h"
#include"Figures/CRectangle.h"
#include"Figures/CCircle.h"
#include"Figures/CHexagon.h"
#include"Figures/CSquare.h"
#include"Figures/CTriangle.h"

#include "Figures/CFigure.h"
#include "GUI/Input.h"
#include "GUI/Output.h"
#include "Actions/AddRectAction.h"
#include "Actions/AddSquareAction.h"
#include "Actions/AddTriangleAction.h"
#include "Actions/AddHexagonAction.h"
#include "Actions/AddCircleAction.h"
#include "Actions/DeleteAction.h"
#include "Actions/SelectFigureAction.h"
#include "Actions/Action.h"
#include "Actions/UndoAction.h"
#include "Actions/LoadAction.h"
#include "Actions/Copy.h"


//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures
	enum { MaxUndoRedoCount = 5 }; //Max no to undo/redo actions
	enum { MaxSelectedCount = 50 };//max no of selected figures


private:
	int FigCount;		//Actual number of figures
	int UndoCount;
	int RedoCount;
	bool RedoStatus;  //checks that redo is only done after redo/undo actions

	int SelectedRects, SelectedSqrs, SelectedHexes, SelectedTris, SelectedCircs;//Number of selected figures of each type
	int NumOfRect, NumOfSqr, NumOfHex, NumOfTri, NumOfCirc;//Number of Figures of each type
	int SelectedFigCount;//Number of Selected Figures

	CFigure* DeletedFiguresArr[5];  //list of all deleted figures to undo
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	CFigure* LastSelectedFig; //Pointer to the selected figure
	CFigure* SelectedFigure; //Pointer to the selected figure

	CFigure* SelectedFigsArr[MaxSelectedCount]; //array of selected figures
	int SelectedCount;


	Action* Undoarr[5]; //list of all actions to undo
	Action* Redoarr[5]; //list of all actions to redo
	Action* LastAction; //pointer to the last action done

	CFigure* GetClipboard(); //returns pointer to figure in clipboard

	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;

	CFigure* Clipboard;  //Pointer to copied/cut figure

public:	
	ApplicationManager(); 
	~ApplicationManager();
	
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList

	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure

	void Delete(CFigure* pFig);             //Deletes the selected -if any- firure

	CFigure* DeleteLastFigure();                //deletes last figure from figlist 

	CFigure* GetFigureByID(int)const; //Search for a figure given its ID

	int GetCutFigureID();	   //returns ID of Cut Figure in clipboard

	int CutFigureID; //ID of the figure in clipboard if it was cut

	void UpdateFigureData();//Updates all Data in Application Manager

	void SetCutFigureID(int);   //Setter for the figure's ID in clipboard
	// Select figure stuff
	CFigure** GetSelectedFigs() const; // Get the array of selected figures
	int GetSelectedCount() const; // Get the number of selected figures
	void AddSelectedFig(CFigure* pFig); // Add a figure to the selected list
	void RemoveSelectedFig(CFigure* pFig); // Remove a figure from the selected list
	void UnSelect(); // Clear all selected figures
	void PrintTotalInfo() const; // Print total info (e.g., figure count)
	void PrintSelectedInfo() const; // Print info about selected figures
	

	int Get_FigCount() const;               //Returns the number of figures

	// -- SAVE functions
	void SaveAll(ofstream& File); // Saves all figures to a file
	int GetFigCount() const; // Returns the number of figures
	CFigure* GetFigure(int index) const; // Returns a figure at a specific index

	// -- CLRALL functions
	void ClearAll();                        //deletes all the drawn figures from the array
	// -- Clipboard functions
	void ClearClipboard();//Clears any figures in clipboard
	void SetClipboard(CFigure*);  //Adds a figure to the clipboard
	CFigure* GetClipboard();	 //returns pointer to figure in clipboard





	// -- UNDO functions
	void AddtoUndo(Action* action);         //adds action to undoarr
	void RemovefromUndo();                  //removes action from undoarr 
	Action* GetLastActiontoUndo();          //returns last action in redoarr

	// -- REDO functions
	void AddtoRedo(Action* action);         //adds action to redoarr
	void RemovefromRedo();                  //removes action from redoarr
	Action* GetLastActiontoRedo();          //returns last action in redoarr

	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	

	// -- Clipboard
	void SetClipboard(CFigure* fig);
	CFigure* GetClipboard() const;


};

#endif