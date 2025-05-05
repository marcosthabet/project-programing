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

	CFigure* DeletedFiguresArr[5];  //list of all deleted figures to undo
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	CFigure* LastSelectedFig; //Pointer to the selected figure

	CFigure* SelectedFig; //Pointer to the selected figure

	Action* Undoarr[5];
=======
	Action* Undoarr[5]; //list of all actions to undo
	Action* Redoarr[5]; //list of all actions to redo
	Action* LastAction; //pointer to the last action done
>>>>>>> 210a51b88af9d663c4903ff12d4df8035e2b16dd
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
	
	// -- CLRALL functions
	void ClearAll();                        //deletes all the drawn figures from the array
	
	// -- UNDO functions
	void AddtoUndo(Action* action);         //adds action to undoarr
	void RemovefromUndo();                  //removes action from undoarr 
<<<<<<< HEAD
	Action* GetLastActiontoUndo();          //returns last action in redoarr
	void ClearUndoList();
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	
};

#endif