#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_PLAY	//Playing mode
};

enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are **(ordered)** here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_RECT,		//Recangle item in menu
	ITM_CIRC,		//Circle item in menu
	ITM_TRI,		//Triangle item in menu
	ITM_HEX,		//Hexagon item in menu
	ITM_SQU,		//Square item in menu

	ITM_UNDO,		//Undo item in menu
	ITM_REDO,		//Redo item in menu
	ITM_ROTATE,		//Rotate item in menu
	ITM_SWAP,       //Swap 2 itms places
	ITM_DEL,		//Delete item in menu
	ITM_MOVE,		//Move item in menu
	ITM_COPY,		//Copy item in menu
	ITM_CUT,		//Cut item in menu
	ITM_PASTE,		//Paste item in menu
	ITM_SAVE,		//Save item in menu
	ITM_LOAD,		//Load item in menu
	ITM_CLRALL,		//Clear all item in menu
	ITM_SELECT,		//Select item in menu
	ITM_TO_PLAY,	//Switch to Play mode item

	//new color and fill items
	ITM_BLACK,      // Black color selection
	ITM_YELLOW,     // Yellow color selection
	ITM_ORANGE,     // Orange color selection
	ITM_RED,        // Red color selection
	ITM_GREEN,      // Green color selection
	ITM_BLUE,       // Blue color selection
	ITM_FILL,       // Toggle fill/unfill
	

	//TODO: Add more items names here

	ITM_EXIT,		//Exit item
	
	DRAW_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};

enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	//Note: Items are **(ordered)** here as they appear in menu
	//If you want to change the menu items order, change the order here
	
	//TODO: Add more items names here
	ITM_MATCH,	//Match shape in game
	ITM_MISSING,	//Missing shape in game
	ITM_TO_DRAW,	//Switch to Draw mode item
	PLAY_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};





__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;
	
	int	width, height,	    //Window width and height
		wx , wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		LineUnderTBWidth,	//line Under the Toolbar Pen Width
		MenuItemWidth;		//Width of each item in toolbar menu
	

	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	bool IsFilled;		//is the shape filled?
	int PenWidth;			//width of the pen that draws shapes

	/// Add more members if needed
	
}UI;	//create a global object UI

#endif