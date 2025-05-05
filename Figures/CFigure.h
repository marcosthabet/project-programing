#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"

//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	string Type;  //Type of the figure
	string DrawColor;
	string FillColor;
	/// Add more parameters if needed.

public:
	CFigure(GfxInfo FigureGfxInfo);
	CFigure();
	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected
	void SetID(int id); //set the ID of the figure

	virtual void Draw(Output* pOut) const = 0;		//Draw the figure
	color stringtoclr(string);

	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color

	//SELECT FIGURE STUFF
	virtual bool IsPointInside(int x, int y) const = 0; //check if a point is inside the figure
	virtual void PrintInfo(Output* pOut) const = 0;     //print all figure info on the status bar
	virtual string GetFigureInfo() const = 0;           //getting figure info back as a string
	virtual CFigure* Clone() const = 0;                 //Clone the figure


	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	


	//virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file

	//virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
};
#endif
