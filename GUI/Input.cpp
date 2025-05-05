#include "Input.h"
#include "Output.h"
#include "UI_Info.h"

bool Input::selectmode = false; //initialize select mode to false

Input::Input(window* pW) 
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int &x, int &y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output *pO) const 
{
	string Label;
	char Key;
	while(1)
	{
		pWind->FlushMouseQueue();	//Flush the mouse queue to avoid any pending clicks
		pWind->FlushKeyQueue();	//Flush the keyboard queue to avoid any pending key presses

		pWind->WaitKeyPress(Key);
		if(Key == 27 )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if(Key == 13 )	//ENTER key is pressed
			return Label;
		if((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() -1 );			
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}

void Input::ResetSelectMode()
{
	selectmode = false;
}

color Input::GetUserColor() const {
	int x, y;
	pWind->WaitMouseClick(x, y);

	if (y >= 0 && y < UI.ToolBarHeight) {

		int ClickedItemOrder = (x / UI.MenuItemWidth);
		switch (ClickedItemOrder)
		{
		case 5: return BLACK;  
		case 6: return YELLOW;
		case 7: return ORANGE;
		case 8: return RED;
		case 9: return GREEN;
		case 10: return BLUE;

		default: return BLUE; 
		}
	}
	return BLUE; //default if no click on toolbar
}


//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{
	selectmode = false; //to check if were in select mode or not

	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check which Menu item was clicked
			//assuming that menu items are lined up horizontally
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
				//shapes cases 
			case ITM_RECT: return DRAW_RECT;
			case ITM_CIRC: return DRAW_CIRC;
			case ITM_TRI: return DRAW_TRI;
			case ITM_HEX: return DRAW_HEX;
			case ITM_SQU:  return DRAW_SQU;

				//features cases
			case ITM_CLRALL: return CLRALL; 	//Clear all figures
			case ITM_SWAP: return SWAP;	//Swap 2 figures
			case ITM_MOVE: return MOVE;	//Move a figure
			case ITM_UNDO: return UNDO; //Undo last action
			case ITM_REDO: return REDO; //Redo last action
			case ITM_COPY: return COPY;	//Copy a figure
			case ITM_CUT: return CUT;	//Cut a figure
			case ITM_PASTE: return PASTE;	//Paste a figure
			case ITM_LOAD: return LOAD;//Load a saved file
			case ITM_ROTATE: return ROTATE;	//Rotate a figure 
			case ITM_SAVE: return SAVE;	//Save the file
			case ITM_DEL: return DEL;	//Delete a figure
			case ITM_TO_PLAY: return TO_PLAY;	//Switch to Play mode

			case ITM_SELECT:
				selectmode = true; 
				return SELECT;	//returning select action activates selectfigureaction

				//color selection cases
			case ITM_BLACK: return SELECT_COLOR_BLACK;
			case ITM_YELLOW: return SELECT_COLOR_YELLOW;
			case ITM_ORANGE: return SELECT_COLOR_ORANGE;
			case ITM_RED: return SELECT_COLOR_RED;
			case ITM_GREEN: return SELECT_COLOR_GREEN;
			case ITM_BLUE: return SELECT_COLOR_BLUE;
			case ITM_FILL: return TOGGLE_FILL;
			case ITM_FILL_COLOR: return SELECT_FILL_COLOR;


			case ITM_EXIT: return EXIT;


			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			//if select mode is on, we need to check if the click is on a figure
			if (selectmode)
			{
				return SELECT_FIGURE; //we'll be in select mode
			}
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//GUI is in PLAY mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			int ClickedItemOrder = x / (UI.MenuItemWidth + UI.wx);
			///TODO: //perform checks similar to Draw mode checks above and return the correspoding action
			switch (ClickedItemOrder)
			{

			case ITM_MATCH: return MATCH;	//Match shape in game
			case ITM_MISSING: return MISSING;	//Missing shape in game
			case ITM_TO_DRAW: return TO_DRAW;	//Switch to Draw mode return 		

			default: return EMPTY;	//A click on empty place in desgin toolbar
			}

			//[2] User clicks on the drawing area
			if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
			{
				return DRAWING_AREA;
			}

			//[3] User clicks on the status bar
			return STATUS;
		}

	}
}
/////////////////////////////////
	
	Input::~Input(){
	}
