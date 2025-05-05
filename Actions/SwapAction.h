#pragma once  
#include "Action.h"  
#include "..\Figures/CFigure.h"
#include "..\ApplicationManager.h"
#include "..\GUI/Input.h"
#include "..\GUI/Output.h"

class SwapAction :  
public Action  
{  
public:
   SwapAction(ApplicationManager* pApp);
   virtual void ReadActionParameters() ; 
   virtual void Execute() ;             
   virtual void Undo() ;                
   virtual void Redo() ;                
};