#ifndef INPUT_H
#define INPUT_H
#pragma once
#include <string>
#include "..\DEFS.h"
#include "UI_Info.h" 
#include "..\CMUgraphicsLib\CMUgraphics.h"
using namespace std;

class Output;   // forward declaration

class Input		//The application manager should have a pointer to this class
{
private:
	window *pWind;	//Pointer to the Graphics Window
	static bool selectmode; 

public:
	Input(window *pW);		//Consturctor
	void GetPointClicked(int &x, int &y) const;//Get coordinate where user clicks
	string GetSrting(Output* pO) const ;
	string GetFileName(Output* pOut);
	//Returns a string entered by the user
	char GetChar(Output* pOut);

	color GetUserColor() const;
	bool getSelectmode() const;
	void setSelectmode(bool s);
	ActionType GetUserAction() const; //Read the user click and map to an action

	void ResetSelectMode() { selectmode = false; } //reset select mode to false
	void ResetSelectMode(); //reset select mode to false
	color GetUserColor() const;
	void GetKeyPressed(char& key) const;

	//validation functions
	void Point_Validation(Point& P, Output* pOut);
	void Hexagon_Validation(Point& P, Output* pOut);
	void Circle_Validation(Point& P1, Point& P2, GfxInfo& gfxInfo, Output* pOut);
	void Square_Validation(Point& p1, Output* pOut);
	void Repeatability_Validation(Point& p1, Point& p2, Output* pOut);

	buttonstate GetMouseState(const button btMouse, int& iX, int& iY);


	~Input();
};

#endif