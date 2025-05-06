#include "Copy.h"
#include "../GUI/Output.h"
#include "../ApplicationManager.h"

#include "../Figures/CFigure.h"
#include "../Figures/CCircle.h"
#include "../Figures/CHexagon.h"
#include "../Figures/CRectangle.h"
#include "../Figures/Csquare.h"
#include "../Figures/CTriangle.h"

void Copy::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Selected Fig Copied");
	SelectedFig = *pManager->GetSelectedFigs();
}

void Copy::Execute()
{
	ReadActionParameters();
	CFigure* CopiedFig = SelectedFig->Clone();
	pManager->SetClipboard(CopiedFig);

}
