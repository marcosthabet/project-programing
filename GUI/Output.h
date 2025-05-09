#ifndef OUPTUT_H
#define OUPTUT_H
#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:	
	window* pWind;	//Pointer to the Graphics Window
public:
	Output();		

	window* CreateWind(int, int, int , int) const; //creates the application window
	void CreateDrawToolBar() const;	//creates Draw mode toolbar & menu
	void CreatePlayToolBar() const;	//creates Play mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar

	Input* CreateInput() const; //creates a pointer to the Input object	
	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area
	
	// -- Figures Drawing functions
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected = false) const;  //Draw a rectangle
	void DrawSquare(Point center, int length, GfxInfo gfx, bool selected = false) const;
	void DrawTriangle(Point P1, Point P2, Point P3, GfxInfo gfx, bool selected = false) const;
	void DrawHexagon(Point P1, GfxInfo HexaGfxInfo, bool selected = false) const;
	void DrawCircle(Point center, int radius, GfxInfo gfxInfo, bool selected = false) const;
	
	
	void PrintMessage(string msg) const;	//Print a message on Status bar

	color getCrntDrawColor() const;	//get current drawing color
	void setCrntDrawColor(color newcolor); //sets the Draw color
	color getCrntFillColor() const;	//get current filling color
	void setCrntFillColor(color newcolor); //sets the Fill color
	int getCrntPenWidth() const;		//get current pen width
	void SetFilled(bool f);
	
	~Output();
};

#endif