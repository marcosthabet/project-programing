
#ifndef DELETE_H  
#define DELETE_H  
#include "Actions/Action.h"  
//#include "Actions/SelectFigureAction.h"   

class DeleteAction : public Action  
{
	// el7a2ona
		CFigure* backup;
		CFigure* ToBeDeleted;
	public:
		DeleteAction(ApplicationManager * pApp);
		virtual void ReadActionParameters();
		virtual void Execute();
		void Undo();
		
	};
#endif

