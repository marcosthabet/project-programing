#include "Output.h"
#include "Input.h"
#include "UI_Info.h"

Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;
	
	UI.width = 1250;
	UI.height = 650;
	UI.wx = 5;
	UI.wy =5;

	
	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.LineUnderTBWidth = 2;
	UI.MenuItemWidth = 60;
	
	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames
	

	
	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project - Spring 2025 - Team 31");
	
	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{ 
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);	
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	//shapes images
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\Menu_Rect.jpg";
	MenuItemImages[ITM_SQU] = "images\\MenuItems\\Menu_Squ.jpg";
	MenuItemImages[ITM_TRI] = "images\\MenuItems\\Menu_Tri.jpg";
	MenuItemImages[ITM_CIRC] = "images\\MenuItems\\Menu_Circ.jpg";
	MenuItemImages[ITM_HEX] = "images\\MenuItems\\Menu_Hexa.jpg";
	//Features images
	MenuItemImages[ITM_ROTATE] = "images\\MenuItems\\Menu_Rotate.jpg";
	MenuItemImages[ITM_SWAP] = "images\\MenuItems\\Menu_Swap.jpg";
	MenuItemImages[ITM_DEL] = "images\\MenuItems\\Menu_Delete.jpg";
	MenuItemImages[ITM_MOVE] = "images\\MenuItems\\Menu_Move.jpg";
	MenuItemImages[ITM_COPY] = "images\\MenuItems\\Menu_Copy.jpg";
	MenuItemImages[ITM_CUT] = "images\\MenuItems\\Menu_Cut.jpg";
	MenuItemImages[ITM_PASTE] = "images\\MenuItems\\Menu_Paste.jpg";
	MenuItemImages[ITM_CLRALL] = "images\\MenuItems\\Menu_clear.jpg";
	MenuItemImages[ITM_SELECT] = "images\\MenuItems\\Menu_Select.jpg";
	MenuItemImages[ITM_SAVE] = "images\\MenuItems\\Menu_Save.jpg";
	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\Menu_Load.jpg";
	MenuItemImages[ITM_REDO] = "images\\MenuItems\\Menu_Redo.jpg";
	MenuItemImages[ITM_UNDO] = "images\\MenuItems\\Menu_Undo.jpg";
	MenuItemImages[ITM_TO_PLAY] = "images\\MenuItems\\Menu_Play.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";

	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, UI.LineUnderTBWidth);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;
 pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
	string MenuItemImages[PLAY_ITM_COUNT];

	MenuItemImages[ITM_MISSING] = "images\\MenuItems\\Menu_Missing.jpg";
	MenuItemImages[ITM_MATCH] = "images\\MenuItems\\Menu_Match.jpg";
	MenuItemImages[ITM_TO_DRAW] = "images\\MenuItems\\Menu_Draw.jpg";

	// Draw each item in the Play Mode Toolbar
	for (int i = 0; i < PLAY_ITM_COUNT; i++)
	{
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);
	}

	// Draw a line under the toolbar
	pWind->SetPen(RED, UI.LineUnderTBWidth);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
	
}


//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight + UI.LineUnderTBWidth, UI.width, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drawing color
{	return UI.DrawColor;	}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{	return UI.FillColor;	}
//////////////////////////////////////////////////////////////////////////////////////////
	
int Output::getCrntPenWidth() const		//get current pen width
{	return UI.PenWidth;	}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

//RECTANGLE:
//===========
void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr,1);
	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	
	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
	
}

//SQUARE:
//=========
void Output::DrawSquare(Point center, int length, GfxInfo gfx, bool selected) const
{
	color DrawingClr;

	// Use highlight color if the square is selected
	if (selected)
		DrawingClr = UI.HighlightColor;
	else
		DrawingClr = gfx.DrawClr;

	// Set pen color and width
	pWind->SetPen(DrawingClr, 1);

	drawstyle style;

	// Determine if the square should be filled
	if (gfx.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(gfx.FillClr);
	}
	else
		style = FRAME;

	// Calculate square corners based on center
	int half = length / 2;
	Point topLeft = { center.x - half, center.y - half };
	Point bottomRight = { center.x + half, center.y + half };

	// Draw the square as a rectangle with equal sides
	pWind->DrawRectangle(topLeft.x, topLeft.y, bottomRight.x, bottomRight.y, style);
}


//TRIANGLE:
//=========
void Output::DrawTriangle(Point P1, Point P2, Point P3, GfxInfo TriangleGfxInfo, bool selected) const {
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; 
	else
		DrawingClr = TriangleGfxInfo.DrawClr;
	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (TriangleGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TriangleGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);

}


//CIRCLE:
// =========
void Output::DrawCircle(Point center, int radius, GfxInfo gfx, bool selected) const
{
	color DrawingClr;

	if (selected)
		DrawingClr = UI.HighlightColor;
	else
		DrawingClr = gfx.DrawClr;

	pWind->SetPen(DrawingClr, 1);

	drawstyle style;

	if (gfx.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(gfx.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawCircle(center.x, center.y, radius, style);
}


//HEXAGON:
//=========
void Output::DrawHexagon(Point P1, GfxInfo HexaGfxInfo, bool selected) const
{
	int radius = 130;
	color DrawingClr;

	if (selected)
		DrawingClr = UI.HighlightColor;
	else
		DrawingClr = HexaGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);

	drawstyle style;
	if (HexaGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(HexaGfxInfo.FillClr);
	}
	else
		style = FRAME;

	int dx = radius;
	int dy = (int)(radius * sqrt(3) / 2);

	int HexaX[6] = {
		P1.x - dx,
		P1.x - dx / 2,
		P1.x + dx / 2,
		P1.x + dx,
		P1.x + dx / 2,
		P1.x - dx / 2
	};

	int HexaY[6] = {
		P1.y,
		P1.y - dy,
		P1.y - dy,
		P1.y,
		P1.y + dy,
		P1.y + dy
	};

	pWind->DrawPolygon(HexaX, HexaY, 6, style);
}




//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

