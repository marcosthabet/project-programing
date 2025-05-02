#include "GUI\Input.h"
#include "GUI\Output.h"

//This is a test code to test the Input and Output classes

int main()
{
	int x, y;
	Point P1, P2, P3;
	GfxInfo gfxInfo;

	

	//Create Input and Output objects to test
	Output *pOut = new Output();
	Input *pIn = pOut->CreateInput();

	//Starting the test
	pOut->PrintMessage("This demo is to test input and output classes, Click anywhere to start the test");
	pIn->GetPointClicked(x,y);	//Wait for any click


	///////////////////////////////////////////////////////////////////////////////////
	// TEST 1:	
	//			Create The FULL Tool bar, the drawing area and the status bar	
	//			This has already been done through the constrcutor of class Output
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMessage("TEST1: Drawing Tool bar and Status bar, Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	
	///////////////////////////////////////////////////////////////////////////////////
	// TEST 2:	
	//			Drawing all the Figures with all possible states: 
	//			Non-filled, Filled, and highlighted in both cases			
	///////////////////////////////////////////////////////////////////////////////////


	/// 2.1 - Rectangle Test ///
// ========================
	pOut->PrintMessage("Drawing a Rectangle, filled/non-filled and highlighted versions. Click to continue.");
	pIn->GetPointClicked(x, y); // Wait for any click

	// 2.1.1 - Drawing non-filled rectangle
	pOut->PrintMessage("Rectangle ==> non-filled, Click two points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);

	gfxInfo.BorderWdth = 5;
	gfxInfo.DrawClr = BLACK;
	gfxInfo.isFilled = false;
	pOut->DrawRect(P1, P2, gfxInfo, false);

	// 2.1.2 - Drawing highlighted non-filled rectangle
	pOut->PrintMessage("Rectangle ==> highlighted non-filled, Click to highlight");
	pIn->GetPointClicked(x, y);
	pOut->DrawRect(P1, P2, gfxInfo, true);

	// 2.1.3 - Drawing a filled rectangle
	pOut->PrintMessage("Rectangle ==> filled, Click two points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);

	// Ask user for fill color
	pOut->PrintMessage("Click anywhere, then choose a fill color: 1.Red 2.Green 3.Blue 4.Yellow 5.Black");
	pIn->GetPointClicked(x, y); // Just wait
	string colorChoice = pIn->GetSrting(pOut);

	// Set border and default draw color
	gfxInfo.BorderWdth = 6;
	gfxInfo.DrawClr = BLACK;

	// Determine fill color based on user input
	if (colorChoice == "1") {
		gfxInfo.FillClr = RED;
		gfxInfo.isFilled = true;
	}
	else if (colorChoice == "2") {
		gfxInfo.FillClr = GREEN;
		gfxInfo.isFilled = true;
	}
	else if (colorChoice == "3") {
		gfxInfo.FillClr = BLUE;
		gfxInfo.isFilled = true;
	}
	else if (colorChoice == "4") {
		gfxInfo.FillClr = YELLOW;
		gfxInfo.isFilled = true;
	}
	else if (colorChoice == "5") {
		gfxInfo.FillClr = BLACK;
		gfxInfo.isFilled = true;
	}
	else {
		pOut->PrintMessage("Invalid color input. Rectangle will NOT be filled.");
		gfxInfo.isFilled = false;
	}

	// Draw filled (or unfilled) rectangle
	pOut->DrawRect(P1, P2, gfxInfo, false);

	// 2.1.4 - Drawing highlighted filled rectangle
	pOut->PrintMessage("Rectangle ==> highlighted filled, Click to highlight");
	pIn->GetPointClicked(x, y);
	pOut->DrawRect(P1, P2, gfxInfo, true);

	// Done
	pOut->PrintMessage("Rectangle Test ? Complete! Click anywhere to continue.");
	pIn->GetPointClicked(x, y);
	pOut->ClearDrawArea();


	/// 2.2 - Square Test
//======================
	pOut->PrintMessage("Drawing a Square: filled/non-filled and Highlighted versions, Click to continue");
	pIn->GetPointClicked(x, y);

	// 2.2.1 - Non-filled Square
	pOut->PrintMessage("Square ==> non-filled, Click center");
	pIn->GetPointClicked(P1.x, P1.y);

	gfxInfo.BorderWdth = 5;
	gfxInfo.DrawClr = BLACK;
	gfxInfo.isFilled = false;
	pOut->DrawSquare(P1, 100, gfxInfo, false);

	// 2.2.2 - Highlighted non-filled Square
	pOut->PrintMessage("Square ==> highlighted non-filled, Click to highlight");
	pIn->GetPointClicked(x, y);
	pOut->DrawSquare(P1, 100, gfxInfo, true);

	// 2.2.3 - Filled Square
	pOut->PrintMessage("Square ==> filled, Click center");
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("Click anywhere then choose fill color: 1.Red 2.Green 3.Blue 4.Yellow 5.Black");
	pIn->GetPointClicked(x, y);
	string squareColor = pIn->GetSrting(pOut);
	if (squareColor == "1") gfxInfo.FillClr = RED;
	else if (squareColor == "2") gfxInfo.FillClr = GREEN;
	else if (squareColor == "3") gfxInfo.FillClr = BLUE;
	else if (squareColor == "4") gfxInfo.FillClr = YELLOW;
	else if (squareColor == "5") gfxInfo.FillClr = BLACK;
	else gfxInfo.isFilled = false;

	gfxInfo.BorderWdth = 6;
	gfxInfo.DrawClr = BLACK;
	gfxInfo.isFilled = true;
	pOut->DrawSquare(P1, 100, gfxInfo, false);

	// 2.2.4 - Highlighted filled Square
	pOut->PrintMessage("Square ==> highlighted filled, Click to highlight");
	pIn->GetPointClicked(x, y);
	pOut->DrawSquare(P1, 100, gfxInfo, true);

	pOut->PrintMessage("Square test complete! Click anywhere to continue.");
	pIn->GetPointClicked(x, y);
	pOut->ClearDrawArea();

	/// 2.3 - Triangle Test 
	//=======================
	pOut->PrintMessage("Drawing a Triangle: filled/non-filled and Highlighted versions, Click to continue");
	pIn->GetPointClicked(x, y);

	// 2.3.1 - Non-filled Triangle
	pOut->PrintMessage("Triangle ==> non-filled, Click 3 points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);
	pIn->GetPointClicked(P3.x, P3.y);

	gfxInfo.BorderWdth = 5;
	gfxInfo.DrawClr = BLACK;
	gfxInfo.isFilled = false;
	pOut->DrawTriangle(P1, P2, P3, gfxInfo, false);

	// 2.3.2 - Highlighted non-filled
	pOut->PrintMessage("Triangle ==> highlighted non-filled");
	pIn->GetPointClicked(x, y);
	pOut->DrawTriangle(P1, P2, P3, gfxInfo, true);

	// 2.3.3 - Filled Triangle
	pOut->PrintMessage("Triangle ==> filled, Click 3 points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);
	pIn->GetPointClicked(P3.x, P3.y);

	pOut->PrintMessage("Click anywhere then choose fill color: 1.Red 2.Green 3.Blue 4.Yellow 5.Black");
	pIn->GetPointClicked(x, y);
	string triColor = pIn->GetSrting(pOut);
	if (triColor == "1") gfxInfo.FillClr = RED;
	else if (triColor == "2") gfxInfo.FillClr = GREEN;
	else if (triColor == "3") gfxInfo.FillClr = BLUE;
	else if (triColor == "4") gfxInfo.FillClr = YELLOW;
	else if (triColor == "5") gfxInfo.FillClr = BLACK;
	else gfxInfo.isFilled = false;

	gfxInfo.BorderWdth = 6;
	gfxInfo.DrawClr = BLACK;
	gfxInfo.isFilled = true;
	pOut->DrawTriangle(P1, P2, P3, gfxInfo, false);

	// 2.3.4 - Highlighted filled
	pOut->PrintMessage("Triangle ==> highlighted filled");
	pIn->GetPointClicked(x, y);
	pOut->DrawTriangle(P1, P2, P3, gfxInfo, true);

	pOut->PrintMessage("Triangle test complete! Click anywhere to continue.");
	pIn->GetPointClicked(x, y);
	pOut->ClearDrawArea();


	
	/// 2.4 - Hexagon Test 
	//======================
	pOut->PrintMessage("Drawing a Hexagon: filled/non-filled and Highlighted versions, Click to continue");
	pIn->GetPointClicked(x, y);

	// 2.4.1 - Non-filled
	pOut->PrintMessage("Hexagon ==> non-filled, Click center");
	pIn->GetPointClicked(P1.x, P1.y);

	gfxInfo.BorderWdth = 5;
	gfxInfo.DrawClr = BLACK;
	gfxInfo.isFilled = false;
	pOut->DrawHexagon(P1, gfxInfo, false);

	// 2.4.2 - Highlighted non-filled
	pOut->PrintMessage("Hexagon ==> highlighted non-filled");
	pIn->GetPointClicked(x, y);
	pOut->DrawHexagon(P1, gfxInfo, true);

	// 2.4.3 - Filled
	pOut->PrintMessage("Hexagon ==> filled, Click center");
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("Click anywhere then choose fill color: 1.Red 2.Green 3.Blue 4.Yellow 5.Black");
	pIn->GetPointClicked(x, y);
	string hexColor = pIn->GetSrting(pOut);
	if (hexColor == "1") gfxInfo.FillClr = RED;
	else if (hexColor == "2") gfxInfo.FillClr = GREEN;
	else if (hexColor == "3") gfxInfo.FillClr = BLUE;
	else if (hexColor == "4") gfxInfo.FillClr = YELLOW;
	else if (hexColor == "5") gfxInfo.FillClr = BLACK;
	else gfxInfo.isFilled = false;

	gfxInfo.BorderWdth = 6;
	gfxInfo.DrawClr = BLACK;
	gfxInfo.isFilled = true;
	pOut->DrawHexagon(P1, gfxInfo, false);

	// 2.4.4 - Highlighted filled
	pOut->PrintMessage("Hexagon ==> highlighted filled");
	pIn->GetPointClicked(x, y);
	pOut->DrawHexagon(P1, gfxInfo, true);

	pOut->PrintMessage("Hexagon test complete! Click anywhere to continue.");
	pIn->GetPointClicked(x, y);
	pOut->ClearDrawArea();


	
	/// 2.5 - Circle Test
	//=====================
	
	pOut->PrintMessage("Drawing a Circle: variable radius, filled/non-filled and highlighted versions. Click to continue.");
	pIn->GetPointClicked(x, y);

	// 2.5.1 - Non-filled Circle
	pOut->PrintMessage("Circle ==> non-filled, Click center");
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("Now click on the edge to set the size");
	Point edge;
	pIn->GetPointClicked(edge.x, edge.y);

	// Calculate radius using distance formula
	int dx = P1.x - edge.x;
	int dy = P1.y - edge.y;
	int radius = (int)sqrt(dx * dx + dy * dy);

	gfxInfo.BorderWdth = 5;
	gfxInfo.DrawClr = BLACK;
	gfxInfo.isFilled = false;
	pOut->DrawCircle(P1, radius, gfxInfo, false);

	// 2.5.2 - Highlighted non-filled
	pOut->PrintMessage("Circle ==> highlighted non-filled. Click to highlight.");
	pIn->GetPointClicked(x, y);
	pOut->DrawCircle(P1, radius, gfxInfo, true);

	// 2.5.3 - Filled Circle
	pOut->PrintMessage("Circle ==> filled, Click new center");
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("Click new edge to set radius");
	pIn->GetPointClicked(edge.x, edge.y);
	dx = P1.x - edge.x;
	dy = P1.y - edge.y;
	radius = (int)sqrt(dx * dx + dy * dy);

	pOut->PrintMessage("Click anywhere, then choose fill color: 1.Red 2.Green 3.Blue 4.Yellow 5.Black");
	pIn->GetPointClicked(x, y);
	string fillColor = pIn->GetSrting(pOut);

	gfxInfo.BorderWdth = 6;
	gfxInfo.DrawClr = BLACK;

	if (fillColor == "1") {
		gfxInfo.FillClr = RED;
		gfxInfo.isFilled = true;
	}
	else if (fillColor == "2") {
		gfxInfo.FillClr = GREEN;
		gfxInfo.isFilled = true;
	}
	else if (fillColor == "3") {
		gfxInfo.FillClr = BLUE;
		gfxInfo.isFilled = true;
	}
	else if (fillColor == "4") {
		gfxInfo.FillClr = YELLOW;
		gfxInfo.isFilled = true;
	}
	else if (fillColor == "5") {
		gfxInfo.FillClr = BLACK;
		gfxInfo.isFilled = true;
	}
	else {
		pOut->PrintMessage("Invalid color input. Circle will NOT be filled.");
		gfxInfo.isFilled = false;
	}

	pOut->DrawCircle(P1, radius, gfxInfo, false);

	// 2.5.4 - Highlighted filled Circle
	pOut->PrintMessage("Circle ==> highlighted filled. Click to highlight.");
	pIn->GetPointClicked(x, y);
	pOut->DrawCircle(P1, radius, gfxInfo, true);

	// Done!
	pOut->PrintMessage("Circle test ? complete! Click anywhere to continue.");
	pIn->GetPointClicked(x, y);
	pOut->ClearDrawArea();




	///////////////////////////////////////////////////////////////////////////////////
	// TEST 3: 
	//			Input Class: Read strings from the user
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMessage("TEST3: Now Time to test class Input, Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	
	pOut->PrintMessage("Testing Input ability to read strings");

	///TODO: Add code here to 
	// 1- Read a string from the user on the status bar
	// 2- After reading the string clear the status bar
	// 3- print on the status bar "You Entered" then print the string

	string input = pIn->GetSrting(pOut);
	pOut->PrintMessage("You Entered: " + input);
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->ClearDrawArea();

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 4: 
	//			Input Class : Check for the user action
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMessage("TEST4: Testing Input ability to detect User Action, click anywhere");

	ActionType ActType;
	
	///TODO:  
	//You must add a case for each action (both Draw mode and Play mode actions)
	//Add cases for the missing actions below
	do
	{
		ActType = pIn->GetUserAction();

		switch (ActType)
		{
		case DRAW_RECT:
			pOut->PrintMessage("Action: Draw a Rectangle, Click anywhere");
			break;

		case DRAW_CIRC:
			pOut->PrintMessage("Action: Draw a Circle, Click anywhere");
			break;

		case DRAW_TRI:
			pOut->PrintMessage("Action: Draw a Triangle, Click anywhere");
			break;

		case DRAW_HEX:
			pOut->PrintMessage("Action: Draw a Hexagon, Click anywhere");
			break;

		case DRAW_SQU:
			pOut->PrintMessage("Action: Draw a Square, Click anywhere");
			break;

		case SWAP:
			pOut->PrintMessage("Action: Swap two figures, Click anywhere");
			break;

		case DEL:
			pOut->PrintMessage("Action: Delete a figure, Click anywhere");
			break;

		case MOVE:
			pOut->PrintMessage("Action: Move a figure, Click anywhere");
			break;

		case COPY:
			pOut->PrintMessage("Action: Copy a figure, Click anywhere");
			break;

		case CUT:
			pOut->PrintMessage("Action: Cut a figure, Click anywhere");
			break;

		case PASTE:
			pOut->PrintMessage("Action: Paste a figure, Click anywhere");
			break;

		case SAVE:
			pOut->PrintMessage("Action: Save current drawing, Click anywhere");
			break;

		case LOAD:
			pOut->PrintMessage("Action: Load a saved drawing, Click anywhere");
			break;

		case UNDO:
			pOut->PrintMessage("Action: Undo last action, Click anywhere");
			break;

		case REDO:
			pOut->PrintMessage("Action: Redo last undone action, Click anywhere");
			break;

		case ROTATE:
			pOut->PrintMessage("Action: Rotate a figure, Click anywhere");
			break;

		case CLRALL:
			pOut->PrintMessage("Action: Clear all figures, Click anywhere");
			break;

		case SELECT:
			pOut->PrintMessage("Action: Select a figure, Click anywhere");
			break;

		case TO_DRAW:
			pOut->PrintMessage("Action: Switch to Draw Mode, creating Draw toolbar");
			pOut->CreateDrawToolBar();
			break;

		case TO_PLAY:
			pOut->PrintMessage("Action: Switch to Play Mode, creating Play toolbar");
			pOut->CreatePlayToolBar();
			break;

		case MISSING:
			pOut->PrintMessage("Action: Not implemented yet, Click anywhere");
			break;

		case MATCH:
			pOut->PrintMessage("Action: Match mode activated, Click anywhere");
			break;

		case EMPTY:
			pOut->PrintMessage("Action: A click on an empty area in the Toolbar, Click anywhere");
			break;

		case DRAWING_AREA:
			pOut->PrintMessage("Action: A click in the Drawing Area, Click anywhere");
			break;

		case STATUS:
			pOut->PrintMessage("Action: A click on the Status Bar, Click anywhere");
			break;

		case EXIT:
			pOut->PrintMessage("Action: EXIT, test is finished, Click anywhere to exit");
			break;

		default:
			pOut->PrintMessage("Unknown action");
			break;
		}

	}while(ActType != EXIT);


	/// Exiting
	pOut->PrintMessage("Action: EXIT, test is finished, click anywhere to exit");
	pIn->GetPointClicked(x,y);


	delete pIn;
	delete pOut;	
	return 0;
}


