#include "Paste.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"
#include"../ApplicationManager.h"
#include "../Figures/CFigure.h"
#include "../Figures/CCircle.h"
#include "../Figures/CHexagon.h"
#include "../Figures/CRectangle.h"
#include "../Figures/Csquare.h"
#include "../Figures/CTriangle.h"




Paste::Paste(ApplicationManager* pApp) :Action(pApp) {}

void Paste::ReadActionParameter() {  
   Output* pOut = pManager->GetOutput();  
   Input* pIn = pManager->GetInput();  
   if (pManager->GetClipboard() == nullptr) {  
       pOut->PrintMessage("Clipboard is empty. Please copy a figure first.");  
       return;  
   }  
   pOut->PrintMessage("Click paste location");  
   int x, y;  
   pIn->GetPointClicked(x, y);  
   PastePoint.x = x;  
   PastePoint.y = y;  
}

void Paste::Execute() {
	ReadActionParameters();
	CFigure* clipboardFig = pManager->GetClipboard();


if (clipboardFig) {
	CFigure* newFig = clipboardFig->Clone();
	newFig->Move(PastePoint);  
	pManager->AddFigure(newFig);
	pManager->UpdateInterface();
}

