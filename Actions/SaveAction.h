#pragma once
#include "Action.h"
#include <string>
#include <fstream>

class SaveAction : public Action
{
private:
	std::string FileName; // The name of the file to save to

public:
	SaveAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	void Undo();
	void Redo();
};

