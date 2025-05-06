#include "CFigure.h"
#include "..\GUI\Output.h"


CFigure::CFigure()
{
}
//Default status is non-filled.

CFigure::CFigure(GfxInfo FigureGfxInfo) 
{
	FigGfxInfo = FigureGfxInfo;
}

void CFigure::SetID(int id) {
	ID = id;
}

int CFigure::GetID() {
	return ID;
}

void CFigure::SetSelected(bool s)
{
	Selected = s;
	if (s) {
		FigGfxInfo.DrawClr = UI.HighlightColor; //highlight in magenta if selected
	}
	else FigGfxInfo.DrawClr = UI.DrawColor; //default
}

bool CFigure::IsSelected() const
{	return Selected; }

color CFigure::GetDrawClr()
{
	return FigGfxInfo.DrawClr;
}
bool CFigure::IsFilled()
{
	return FigGfxInfo.isFilled;
}
void CFigure::UnFill()
{
	FigGfxInfo.isFilled = false;
}
color CFigure::GetFillClr()
{
	if (IsFilled())
		return FigGfxInfo.FillClr;
	return WHITE;
}

void CFigure::ChngDrawClr(color Dclr)
{
	FigGfxInfo.DrawClr = Dclr;
	if (FigGfxInfo.DrawClr == BLACK)
	{
		DrawColor = "Black";
	}
	else if (FigGfxInfo.DrawClr == BLUE)
	{
		DrawColor = "Blue";
	}
	else if (FigGfxInfo.DrawClr == GREEN)
	{
		DrawColor = "Green";
	}
	else if (FigGfxInfo.DrawClr == YELLOW)
	{
		DrawColor = "Yellow";
	}
	else if (FigGfxInfo.DrawClr == RED)
	{
		DrawColor = "Red";
	}
	else if (FigGfxInfo.DrawClr == ORANGE)
	{
		DrawColor = "Orange";
	}
	else if (FigGfxInfo.DrawClr == NULL)
	{
		DrawColor = "Not_Filled";
	}
}

void CFigure::ChngFillClr(color Fclr)
{
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr;
	if (FigGfxInfo.isFilled) {
		if (FigGfxInfo.FillClr == BLACK)
		{
			FillColor = "Black";
		}
		else if (FigGfxInfo.FillClr == BLUE)
		{
			FillColor = "Blue";
		}
		else if (FigGfxInfo.FillClr == GREEN)
		{
			FillColor = "Green";
		}
		else if (FigGfxInfo.FillClr == YELLOW)
		{
			FillColor = "Yellow";
		}
		else if (FigGfxInfo.FillClr == RED)
		{
			FillColor = "Red";
		}
		else if (FigGfxInfo.FillClr == ORANGE)
		{
			FillColor = "Orange";
		}
	}
	else
	{
		FillColor = "Not_Filled";
	}
}
color CFigure::stringtoclr(string clr)
{
	Output* pout{};

	if (clr == "Black")
		return BLACK;
	else if (clr == "Blue")
		return BLUE;
	else if (clr == "Red")
		return RED;
	else if (clr == "Green")
		return GREEN;
	else if (clr == "Yellow")
		return YELLOW;
	else if (clr == "Orange")
		return ORANGE;
	else if (clr == "Not_Filled")
		return FigGfxInfo.isFilled = false;
	else return NULL;

}