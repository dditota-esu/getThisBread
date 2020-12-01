

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#include <windows.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <time.h>
#include <stdio.h>
#include <string>

//SOFTWARE ENGINEERING INCLUDE FILES
#include "CardAreaView.h"
#include "CardView.h"
#include "ICardList.h"
#include "CardList.h"
#include "IListOfLists.h"

#define ID_2DSLIDER 1
#define ID_QUIT 2

#define MAX_LOADSTRING 100
#define SIDEBAR_WIDTH 150
#define SIDEBAR_LENGTH 150
#define NUM_SUBWINDOWS 2


HDC         MainHdc;	
HWND		MainHwnd;   
wchar_t MainWindowText[MAX_LOADSTRING];	

//all windows have to have a callback function, it's invoked when ANYTHING happens to the window.
//what you do with the event, or message is your business.  We're usually concerned with mouse clicks, creation, and painting

LRESULT CALLBACK MainWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK SubWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
;
const wchar_t* szSubName = L"card area";

//SOFTWARE ENGINEER -- CardAreaView subwindows created here
CardAreaView* cardAreaView;
CardAreaView* cardAreaView1;
CardAreaView* cardAreaView2;
CardAreaView* cardAreaView3;
CardAreaView* cardAreaView4;

std::string* views;
//SUBWINDOWS ARE CREATED HERE
HWND hWnd_subwindow1;
HWND hWnd_subwindow2;
HWND hWnd_subwindow3;
HWND hWnd_subwindow4;
HWND hWnd_subwindow5;

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PSTR szCmdLine, int iCmdShow)
{
	MSG msg;

	//SOFTWARE ENGINEERING -- Creating a CardList Object
	CardList* cardList1 = new CardList();			//vertical stack

	CardList* cardList2 = new CardList();			//deck

	CardList* cardList3 = new CardList();			//horizontal

	RowOfStacks* rows = new RowOfStacks();
	rows->add(cardList1);
	rows->add(cardList3);

	//SOFTWARE ENGINEERING -- Adding cards to the cardlist
	cardList1->addToBeginning(new Card(0, Spades));
	cardList1->addToBeginning(new Card(1, Spades));
	cardList1->addToBeginning(new Card(2, Spades));

	Card* one = new Card(1, Diamonds);
	Card* two = new Card(10, Diamonds);
	cardList2->addToBeginning(one);
	cardList2->addToBeginning(two);

	cardList3->addToBeginning(new Card(3, Spades));
	cardList3->addToBeginning(new Card(4, Spades));
	cardList3->addToBeginning(new Card(5, Spades));
	cardList3->addToBeginning(new Card(6, Spades));



	//SOFTWARE ENGINEERING -- Creating Subwindow sizes
	int areaWidth = 72;
	int areaHeight = 100;

	//Created card area view
	cardAreaView1 = new CardAreaView(0, 0, areaWidth, areaHeight, cardList1, 0); // vertical stack
	cardAreaView2 = new CardAreaView(0, 0, 72, 100, cardList2, 0);
	cardAreaView3 = new CardAreaView(0, 0, 400, 100, cardList3, 0);

	cardAreaView4 = new CardAreaView(0, 0, 500, 300, rows, 0);
	//cardAreaView2 = new CardAreaView(50, 50, areaWidth, areaHeight, 0, cardList2); // vertical stack
	//cardAreaView3 = new CardAreaView(50, 50, areaWidth, areaHeight, 0, cardList3); // vertical stack
	//cardAreaView4 = new CardAreaView(50, 50, areaWidth, areaHeight, 0, cardList4); // vertical stack


	// set characteristics of MainWndClass and SubWndClass
	//static char szAppName[] = "Dialog";
	const wchar_t* szAppName = L"Dialog";//static wchar_t* szAppName = L"Dialog";
	WNDCLASS MainWndClass, SubWndClass;

	MainWndClass.style = CS_HREDRAW | CS_VREDRAW;
	MainWndClass.lpfnWndProc = MainWndProc; // name of the callback for main window
	MainWndClass.cbClsExtra = 0;  // No extra class bytes
	MainWndClass.cbWndExtra = 0;  // No extra window bytes
	MainWndClass.hInstance = hInstance;
	MainWndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	MainWndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	MainWndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	MainWndClass.lpszMenuName = NULL;
	MainWndClass.lpszClassName = szAppName; // name of class that handles main window events
	RegisterClass(&MainWndClass);

	SubWndClass.style = CS_HREDRAW | CS_VREDRAW;
	SubWndClass.lpfnWndProc = SubWndProc; // name of the callback for subwindows
	SubWndClass.cbClsExtra = 0;  // No extra class bytes
	SubWndClass.cbWndExtra = 12;  // extra bytes to store pointer
	SubWndClass.hInstance = hInstance;
	SubWndClass.hIcon = NULL;
	SubWndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	SubWndClass.hbrBackground = NULL;
	SubWndClass.lpszMenuName = NULL;
	SubWndClass.lpszClassName = szSubName; // name of class that handles subwindow events
	RegisterClass(&SubWndClass);

	// create the main window and display it
	HWND hWnd;
	hWnd = CreateWindow(szAppName,           // name of class that handles main window events
		L".... PROGRAM ", // window caption
		WS_OVERLAPPEDWINDOW, // window style
		CW_USEDEFAULT,       // init x pos
		CW_USEDEFAULT,       // init y pos
		1000,                 // init x size
		730,                 // init y size
		NULL,                // parent window
		NULL,                // window menu
		hInstance,           // program instance
		NULL);               // create params.
	MainHwnd = hWnd;  /* store away the handle for global use */

	ShowWindow(hWnd, iCmdShow); // display it
	UpdateWindow(hWnd);

	// loop "forever"
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg); // translate key codes
		DispatchMessage(&msg);  // call window procedure
	}

	return (int)msg.wParam;
}

// the callback for the main window (invoked via DispatchMessage())
LRESULT CALLBACK MainWndProc(HWND hWnd, // handle to the window
	UINT msg, WPARAM wParam, LPARAM lParam) // describes the event
{

	//-------------------------------------------------------------------------
	HWND* buttonarray;
	//--------------------------------------------------------------------------

	LRESULT		retVal = 0;
	static int  cxChar, cyChar;
	RECT        rect;
	HDC         hdc;
	PAINTSTRUCT ps;
	HPEN        hOldPen;
	HBRUSH      hOldBrush;

	//-----------------------------------------------------------------------------
	buttonarray = new HWND[2];
	int			button_x = 0;
	const wchar_t* labels[2];
	labels[0] = L"Quit";
	labels[1] = L"Do Nothing";
	//------------------------------------------------------------------------------

	switch (msg)
	{
	case WM_CREATE:  // for initialization that happens when window is created
		/*this runs only once, as soon as the main window is created.
		use this opportunity to create the children */

		MainHdc = BeginPaint(hWnd, &ps);
		EndPaint(hWnd, &ps);
		cxChar = LOWORD(GetDialogBaseUnits());
		cyChar = HIWORD(GetDialogBaseUnits());

		GetClientRect(hWnd, &rect);
//Create subwindows here to display image===============================================================================
		// create the first subwindow
		
		hWnd_subwindow1 = CreateWindow(szSubName,   // name of class that handles subwindow events
			NULL, // window caption
			WS_CHILD | WS_VISIBLE, // window style
			20,       // init x pos
			50,       // init y pos
			72,       // init x size
			100,                 // init y size
			hWnd,                // parent window
			(HMENU)ID_2DSLIDER,                // window menu
			(HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),           // program instance
			NULL);               // create params.
		SetWindowLong(hWnd_subwindow1, DWL_USER, (long)(cardAreaView2)); // associate a view object with this window


		//// create the second subwindow
		hWnd_subwindow2 = CreateWindow(szSubName,    // name of class that handles subwindow events
			NULL, // window caption
			WS_CHILD | WS_VISIBLE, // window style
			102,       // init x pos
			50,       // init y pos
			72,       // init x size
			100,                 // init y size
			hWnd,                // parent window
			(HMENU)ID_2DSLIDER,                // window menu
			(HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),           // program instance
			NULL);               // create params.
		SetWindowLong(hWnd_subwindow2, DWL_USER, (long)(cardAreaView1)); // associate a view object with this window

		hWnd_subwindow3 = CreateWindow(szSubName,    // name of class that handles subwindow events
			NULL, // window caption
			WS_CHILD | WS_VISIBLE, // window style
			672,       // init x pos
			50,       // init y pos
			318,       // init x size
			100,                 // init y size
			hWnd,                // parent window
			(HMENU)ID_2DSLIDER,                // window menu
			(HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),           // program instance
			NULL);               // create params.
		SetWindowLong(hWnd_subwindow3, DWL_USER, (long)(cardAreaView3));
		
		hWnd_subwindow5 = CreateWindow(szSubName,    // name of class that handles subwindow events
			NULL, // window caption
			WS_CHILD | WS_VISIBLE, // window style
			20,       // init x pos
			200,       // init y pos
			500,       // init x size
			400,                 // init y size
			hWnd,                // parent window
			(HMENU)ID_2DSLIDER,                // window menu
			(HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),           // program instance
			NULL);               // create params.
		SetWindowLong(hWnd_subwindow5, DWL_USER, (long)(cardAreaView4));

		//hWnd_subwindow4 = CreateWindow(szSubName,    // name of class that handles subwindow events
		//	NULL, // window caption
		//	WS_CHILD | WS_VISIBLE, // window style
		//	450,       // init x pos
		//	50,       // init y pos
		//	72,       // init x size
		//	500,                 // init y size
		//	hWnd,                // parent window
		//	(HMENU)ID_2DSLIDER,                // window menu
		//	(HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),           // program instance
		//	NULL);               // create params.
		//SetWindowLong(hWnd_subwindow4, DWL_USER, (long)(cardAreaView4));
//============================================================================================================

	case WM_PAINT:		// paint event-- window should display itself

		hdc = BeginPaint(hWnd, &ps);   //read up ob brushes and such.  it's basically the color you paint with
		GetClientRect(hWnd, &rect);

		hOldPen = (HPEN)SelectObject(hdc, GetStockObject(BLACK_PEN));
		hOldBrush = (HBRUSH)SelectObject(hdc, GetStockObject(WHITE_BRUSH));

		Rectangle(hdc, 0, 0, rect.right, rect.bottom);
		TextOut(hdc, 25, 450, MainWindowText, (int)wcslen(MainWindowText));  // display whatever is in MainWindowText

		SelectObject(hdc, hOldBrush);  // put the brush and pen back to the color they were before you used them
		SelectObject(hdc, hOldPen);

		EndPaint(hWnd, &ps);
		break;


	case WM_COMMAND: // an event tied to a GUI component

		if (HIWORD(wParam) == BN_CLICKED) { // a GUI button was clicked

			swprintf_s(MainWindowText, MAX_LOADSTRING, L"Clicked button %s", labels[LOWORD(wParam)]);

			GetClientRect(MainHwnd, &rect);
			InvalidateRect(MainHwnd, &rect, FALSE);

			if (labels[LOWORD(wParam)] == L"Quit") { // Quit button was clicked
				PostQuitMessage(0); // terminate the application
			}
			else if (labels[LOWORD(wParam)] == L"Do Nothing") // Do Nothing button was clicked
			{
				// in the future, do something to the application when this button is clicked!
			}
		}
		break;

	case WM_DESTROY: // to terminate the application
		PostQuitMessage(0);
		break;

	default:
		retVal = DefWindowProc(hWnd, msg, wParam, lParam);
	}

	return retVal;
}

// the callback for any of the subwindows (invoked via DipatchMessage())
LRESULT CALLBACK SubWndProc(HWND hWnd, // handle to the window
	UINT msg, WPARAM wParam, LPARAM lParam) // describes the event
{
	LRESULT		retVal = 0;
	HDC         hdc;
	PAINTSTRUCT ps;
	RECT Rect;
	RECT rect;

	GetClientRect(hWnd, &Rect);

	static int  cxChar, cyChar;
	CardAreaView* cardAreaView=(CardAreaView*)GetWindowLong(hWnd, DWL_USER);
	switch (msg)
	{
	case WM_CREATE: // for initialization that happens when the window is created
		cxChar = LOWORD(GetDialogBaseUnits());
		cyChar = HIWORD(GetDialogBaseUnits());
		break;

	case WM_PAINT: // paint event-- window should display itself
		hdc = BeginPaint(hWnd, &ps);

		//Display using CardView----------------------------------------------------------------------
		//The x and y values shows were to position the card in the subwindow 
		//cardAreaView = (CardAreaView*)GetWindowLong(hWnd, DWL_USER);
		cardAreaView->cardViewDisplay(&hdc);
		//------------------------------------------------------------------------------------------------


		EndPaint(hWnd, &ps);
		break;

	case WM_LBUTTONUP: // left mouse button released (up)
	{
		GetClientRect(MainHwnd, &rect);
		CardIdentity* tempIdent = new CardIdentity;
		tempIdent=cardAreaView->click(LOWORD(lParam), HIWORD(lParam));
		swprintf_s(MainWindowText, MAX_LOADSTRING, L"Clicked in subwindow; cursor position (%d,%d); index: (%d)", LOWORD(lParam), HIWORD(lParam), tempIdent->cardIndex);
		InvalidateRect(MainHwnd, &rect, FALSE);

		cardAreaView = (CardAreaView*)GetWindowLong(hWnd, DWL_USER); // get the associated view
		/*CardIdentity* tempIdent=cardAreaView->click(LOWORD(lParam), HIWORD(lParam)); // give the view the cursor position
		std::string indexMsg = "Card area view index :" + std::to_string(tempIdent->cardIndex);
		std::wstring wMsg = std::wstring(indexMsg.begin(), indexMsg.end());
		const wchar_t* outMsg = wMsg.c_str();
		swprintf_s(MainWindowText, MAX_LOADSTRING,outMsg);*/



		GetClientRect(MainHwnd, &rect);
		InvalidateRect(MainHwnd, &rect, FALSE);
	}	
		break;

	case WM_ERASEBKGND:
		retVal = (LONG)TRUE;
		break;

	case WM_DESTROY: // to terminate the application
		PostQuitMessage(0);
		break;

	default:
		retVal = DefWindowProc(hWnd, msg, wParam, lParam);
	}
	//delete i;
	return retVal;

}