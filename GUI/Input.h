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

	ActionType GetUserAction() const; //Read the user click and map to an action

	void ResetSelectMode() { selectmode = false; } //reset select mode to false
	color GetUserColor() const;


	~Input();
};

#endif