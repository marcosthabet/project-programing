#include "Copy.h"
#include "..\GUI\Output.cpp"
#include "..\GUI\Input.cpp"
#include "..\ApplicationManager.h"


Copy::Copy(ApplicationManager* pApp) :Action(pApp) {}

void Copy::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Selected Fig Copied");
	SelectedFig = *pManager->GetSelectedFigs();
}

void Copy::Execute()
{
	ReadActionParameters();
	CFigure* CopiedFig = NULL;
	switch (SelectedFig->GetFigType()) {
	case HEXAGON: CopiedFig = new CHexagon((CHexagon*)SelectedFig); break;
	case CIRCLE: CopiedFig = new CCircle((CCircle*)SelectedFig); break;
	case TRIANGLE: CopiedFig = new CTriangle((CTriangle*)SelectedFig); break;
	case SQUARE: CopiedFig = new Csquare((Csquare*)SelectedFig); break;
	case RECTANGLE: CopiedFig = new CRectangle((CRectangle*)SelectedFig); break;

	}
	 
	pManager->ClearClipboard();
	pManager->SetClipboard(CopiedFig);
}