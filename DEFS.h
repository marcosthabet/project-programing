#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum FigureType{
	SQUARE,

	RECTANGLE,

	HEXAGON,

	TRIANGLE,

	CIRCLE
};
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_RECT,		//Draw Rectangle
	DRAW_CIRC,		//Draw Circle
	DRAW_TRI,       //Draw Triangle
	DRAW_HEX,       //Draw Hexagon 
	DRAW_SQU,       //Draw Square
	SWAP,           //Swap 2 figures
	DEL,			//Delete a figure
	MOVE,	        //Move a figure 	
	COPY,	        //Copy a figure 	
	CUT,		    //Cut a figure 
	PASTE,		    //Paste a figure 
	SAVE,		    //save 
	UNDO,		    //Undo last action
	REDO,		    //Redo last action
	LOAD,	        //load a saved file
	ROTATE,		    //Rotate a figure
	CLRALL,	        //clear all figures 
	SELECT,		    //Select icon in toolbar
	SELECT_FIGURE,	//Select a figure on the draw area
	EXIT,			//Exit
	TO_DRAW,		//Switch interface to Draw mode
	TO_PLAY,		//Switch interface to Play mode
	MISSING, 
	MATCH,
	EMPTY,			//A click on empty place in the toolbar
	DRAWING_AREA,	//A click on the drawing area
	STATUS,			//A click on the status bar

	//new actions for color and fill
	SELECT_COLOR_BLACK,  // Black color selection
	SELECT_COLOR_YELLOW, // Yellow color selection
	SELECT_COLOR_ORANGE, // Orange color selection
	SELECT_COLOR_RED,    // Red color selection
	SELECT_COLOR_GREEN,  // Green color selection
	SELECT_COLOR_BLUE,   // Blue color selection
	TOGGLE_FILL,         // Toggle fill/unfill
	
	///TODO: Add the other action types of the two modes
};

struct Point	//To be used for figures points
{ int x,y; };

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders
	int CircleRadius; //radius of circle for validation

};

#endif