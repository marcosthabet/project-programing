#include "Paste.h"
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"


Paste::Paste(ApplicationManager* pApp) :Action(pApp)
{
	ClipboardFigure = pManager->GetClipboard();
}

void Paste::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if (ClipboardFigure == NULL)
	{
		pOut->PrintMessage("No Figures in Clipboard");
		return;
	}
	pOut->PrintMessage("Click anywhere to paste!");
	pIn->GetPointClicked(Clicked.x, Clicked.y);
	pOut->ClearStatusBar();
}

void Paste::Execute()
{
	ReadActionParameters();
	if (ClipboardFigure == NULL)
	{
		return;
	}
	CFigure* PastedFig = NULL;
	switch (ClipboardFigure->GetFigType()) {
	case HEXAGON: PastedFig = new CHexagon((CHexagon*)ClipboardFigure); break;
	case CIRCLE: PastedFig = new CCircle((CCircle*)ClipboardFigure); break;
	case TRIANGLE: PastedFig = new CTriangle((CTriangle*)ClipboardFigure); break;
	case SQUARE: PastedFig = new Csquare((Csquare*)ClipboardFigure); break;
	case RECTANGLE: PastedFig = new CRectangle((CRectangle*)ClipboardFigure); break;
	}
	PastedFig->MoveFigure(Clicked.x, Clicked.y);
	pManager->AddFigure(PastedFig);
	if (pManager->GetCutFigureID() != -1)
	{
		pManager->DeleteLastFigure(pManager->GetCutFigureID());
		pManager->SetCutFigureID(-1);
	}
}