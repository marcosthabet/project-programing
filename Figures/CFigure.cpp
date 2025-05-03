#include "CFigure.h"
#include "..\GUI\Output.h"

CFigure::CFigure(GfxInfo FigureGfxInfo):
	FigGfxInfo(FigureGfxInfo), ID(0),Selected(false)
	{}//Default status is non-filled.


void CFigure::SetID(int id) {
	ID = id;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}

