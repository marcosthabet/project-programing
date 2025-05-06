#include "ColorFiles.h"

std::string ColorFiles::ColorChoice(color c)
{
	if (c == BLACK)
		return "BLACK";
	else if (c == YELLOW)
		return "YELLOW";
	else if (c == ORANGE)
		return "ORANGE";
	else if (c == RED)
		return "RED";
	else if (c == GREEN)
		return "GREEN";
	else if (c == BLUE)
		return "BLUE";
	else
		return "UNDETERMINED";
}

