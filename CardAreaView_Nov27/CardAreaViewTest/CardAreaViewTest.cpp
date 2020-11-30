
//Driver for the program to showcase the cards in the GUI

// WindowSample.cpp : Defines the entry point for the application.
//

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>
#include <WinUser.h>
// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <time.h>
#include <stdio.h>
#include <string>

#include "CardView.h"

#define ID_2DSLIDER 1
#define ID_QUIT 2

// my stuff
#define MAX_LOADSTRING 100

#define SIDEBAR_WIDTH 150
#define SIDEBAR_LENGTH 150

#define NUM_SUBWINDOWS 2

#define GWL_HINSTANCE (-6)
/*
#define DWLP_MSGRESULT  0
#define DWLP_DLGPROC    DWLP_MSGRESULT + sizeof(LRESULT)
#define DWLP_USER       DWLP_DLGPROC + sizeof(DLGPROC)
*/






//==========================================================================
int imageIndex;
//==========================================================================

// end my stuff

HDC         MainHdc;	//this is the main painting context.  all paint functions will want it
HWND		MainHwnd;   //handle to the main window.  Basically just a reference to it

wchar_t MainWindowText[MAX_LOADSTRING];	//global text array.  all the windows just change this, and the main window paints whatever is in there

//all windows have to have a callback function, it's invoked when ANYTHING happens to the window.
//what you do with the event, or message is your business.  We're usually concerned with mouse clicks, creation, and painting

LRESULT CALLBACK MainWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK SubWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

//static char szSubName[] = "card area";
const wchar_t* szSubName = L"card area";	//static wchar_t* szSubName = L"card area";

//-----------------------------------------------------------CardView is created here -> CardAreView would do this part


CardView* myView;
CardView* myView1;
CardView* myView2;
//CardView* myView3 = new CardView('c', 5);
//CardView* myView4 = new CardView('s', 0);
//CardView* myView5 = new CardView('d', 1);
//CardView* myView6 = new CardView('c', 9);
//CardView* myView7 = new CardView('s', 10);
//CardView* myView8 = new CardView('h', 0);
//CardView* myView9 = new CardView('h', 9);
//CardView* myView10 = new CardView('c', 12);

//------------------------------------------------------------------------------------------------------------------------
std::string* views;

//HWND * hwndarray;// get rid of it
//----------------------------------------------------------------SUBWINDOWS ARE CREATED HERE
HWND hWnd_subwindow1;
HWND hWnd_subwindow2;
HWND hWnd_subwindow3;
HWND hWnd_subwindow4;
HWND hWnd_subwindow5;
HWND hWnd_subwindow6;
HWND hWnd_subwindow7;
HWND hWnd_subwindow8;
HWND hWnd_subwindow9;
HWND hWnd_subwindow10;
//-----------------------------------------------------------------------------------------------

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PSTR szCmdLine, int iCmdShow)
{

	myView1 = new CardView('d', 0);
	myView2 = new CardView('h', 10);
	MSG msg;

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
		L"BULL.... PROGRAM ", // window caption
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
		//Create subwindows here to display image ------------------------------------------------------------------------------------
		// create the first subwindow
		hWnd_subwindow1 = CreateWindow(szSubName,   // name of class that handles subwindow events
			NULL, // window caption
			WS_CHILD | WS_VISIBLE, // window style
			20,       // init x pos
			50,       // init y pos
			100,       // init x size
			100,                 // init y size
			hWnd,                // parent window
			(HMENU)ID_2DSLIDER,                // window menu
			(HINSTANCE)GetWindowLong(hWnd, GWLP_HINSTANCE),           // program instance
			NULL);               // create params.
		SetWindowLong(hWnd_subwindow1, DWLP_USER, (long)(myView1)); // associate a view object with this window


		// create the second subwindow
		hWnd_subwindow2 = CreateWindow(szSubName,    // name of class that handles subwindow events
			NULL, // window caption
			WS_CHILD | WS_VISIBLE, // window style
			20,       // init x pos
			80,       // init y pos
			72,       // init x size
			100,                 // init y size
			hWnd,                // parent window
			(HMENU)ID_2DSLIDER,                // window menu
			(HINSTANCE)GetWindowLong(hWnd, GWLP_HINSTANCE),           // program instance
			NULL);               // create params.
		SetWindowLong(hWnd_subwindow2, DWLP_USER, (long)(myView2)); // associate a view object with this window

		//hWnd_subwindow3 = CreateWindow(szSubName,    // name of class that handles subwindow events
		//	NULL, // window caption
		//	WS_CHILD | WS_VISIBLE, // window style
		//	20,       // init x pos
		//	110,       // init y pos
		//	72,       // init x size
		//	100,                 // init y size
		//	hWnd,                // parent window
		//	(HMENU)ID_2DSLIDER,                // window menu
		//	(HINSTANCE)GetWindowLong(hWnd, GWLP_HINSTANCE),           // program instance
		//	NULL);               // create params.
		//SetWindowLong(hWnd_subwindow3, DWLP_USER, (long)(myView3));

		//hWnd_subwindow4 = CreateWindow(szSubName,    // name of class that handles subwindow events
		//	NULL, // window caption
		//	WS_CHILD | WS_VISIBLE, // window style
		//	20,       // init x pos
		//	140,       // init y pos
		//	72,       // init x size
		//	100,                 // init y size
		//	hWnd,                // parent window
		//	(HMENU)ID_2DSLIDER,                // window menu
		//	(HINSTANCE)GetWindowLong(hWnd, GWLP_HINSTANCE),           // program instance
		//	NULL);               // create params.
		//SetWindowLong(hWnd_subwindow4, DWLP_USER, (long)(myView4));

		//hWnd_subwindow5 = CreateWindow(szSubName,    // name of class that handles subwindow events
		//		 NULL, // window caption
		//		 WS_CHILD | WS_VISIBLE, // window style
		//		 20,       // init x pos
		//		 170,       // init y pos
		//		 72,       // init x size
		//		 100,                 // init y size
		//		 hWnd,                // parent window
		//		 (HMENU)ID_2DSLIDER,                // window menu
		//		 (HINSTANCE)GetWindowLong(hWnd, GWLP_HINSTANCE),           // program instance
		//		 NULL);               // create params.
		//SetWindowLong(hWnd_subwindow5, DWLP_USER, (long)(myView5));

		//hWnd_subwindow6 = CreateWindow(szSubName,    // name of class that handles subwindow events
		//		 NULL, // window caption
		//		 WS_CHILD | WS_VISIBLE, // window style
		//		 20,       // init x pos
		//		 200,       // init y pos
		//		 72,       // init x size
		//		 100,                 // init y size
		//		 hWnd,                // parent window
		//		 (HMENU)ID_2DSLIDER,                // window menu
		//		 (HINSTANCE)GetWindowLong(hWnd, GWLP_HINSTANCE),           // program instance
		//		 NULL);               // create params.
		//SetWindowLong(hWnd_subwindow6, DWLP_USER, (long)(myView6));

		//hWnd_subwindow7 = CreateWindow(szSubName,    // name of class that handles subwindow events
		//		 NULL, // window caption
		//		 WS_CHILD | WS_VISIBLE, // window style
		//		 20,       // init x pos
		//		 230,       // init y pos
		//		 72,       // init x size
		//		 100,                 // init y size
		//		 hWnd,                // parent window
		//		 (HMENU)ID_2DSLIDER,                // window menu
		//		 (HINSTANCE)GetWindowLong(hWnd, GWLP_HINSTANCE),           // program instance
		//		 NULL);               // create params.
		//SetWindowLong(hWnd_subwindow7, DWLP_USER, (long)(myView7));

		//hWnd_subwindow8 = CreateWindow(szSubName,    // name of class that handles subwindow events
		//		 NULL, // window caption
		//		 WS_CHILD | WS_VISIBLE, // window style
		//		 20,       // init x pos
		//		 260,       // init y pos
		//		 72,       // init x size
		//		 100,                 // init y size
		//		 hWnd,                // parent window
		//		 (HMENU)ID_2DSLIDER,                // window menu
		//		 (HINSTANCE)GetWindowLong(hWnd, GWLP_HINSTANCE),           // program instance
		//		 NULL);               // create params.
		//SetWindowLong(hWnd_subwindow8, DWLP_USER, (long)(myView8));

		//hWnd_subwindow9 = CreateWindow(szSubName,    // name of class that handles subwindow events
		//		 NULL, // window caption
		//		 WS_CHILD | WS_VISIBLE, // window style
		//		 120,       // init x pos
		//		 50,       // init y pos
		//		 72,       // init x size
		//		 100,                 // init y size
		//		 hWnd,                // parent window
		//		 (HMENU)ID_2DSLIDER,                // window menu
		//		 (HINSTANCE)GetWindowLong(hWnd, GWLP_HINSTANCE),           // program instance
		//		 NULL);               // create params.
		//SetWindowLong(hWnd_subwindow9, DWLP_USER, (long)(myView9));

		//hWnd_subwindow10 = CreateWindow(szSubName,    // name of class that handles subwindow events
		//		 NULL, // window caption
		//		 WS_CHILD | WS_VISIBLE, // window style
		//		 220,       // init x pos
		//		 50,       // init y pos
		//		 72,       // init x size
		//		 100,                 // init y size
		//		 hWnd,                // parent window
		//		 (HMENU)ID_2DSLIDER,                // window menu
		//		 (HINSTANCE)GetWindowLong(hWnd, GWLP_HINSTANCE),           // program instance
		//		 NULL);               // create params.
		//SetWindowLong(hWnd_subwindow10, DWLP_USER, (long)(myView10));

		//--------------------------------------------------------------------------------------------------------------------------


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
		myView = (CardView*)GetWindowLong(hWnd, DWLP_USER); 
		myView->display(0, 0, false, false, &hdc);						

		/*myView2 = (CardView*)GetWindowLong(hWnd, DWLP_USER); 
		myView2->display(0, 0, true, true, &hdc);*/

		//myView3 = (CardView*)GetWindowLong(hWnd, DWLP_USER); // get the associated view
		//myView4 = (CardView*)GetWindowLong(hWnd, DWLP_USER);
		//myView5 = (CardView*)GetWindowLong(hWnd, DWLP_USER);
		//myView6 = (CardView*)GetWindowLong(hWnd, DWLP_USER);
		//myView7 = (CardView*)GetWindowLong(hWnd, DWLP_USER);
		//myView8 = (CardView*)GetWindowLong(hWnd, DWLP_USER);

		//------------------------------------------------------------------------------------------------
		

		EndPaint(hWnd, &ps);
		break;

	case WM_LBUTTONUP: // left mouse button released (up)

		GetClientRect(MainHwnd, &rect);
		swprintf_s(MainWindowText, MAX_LOADSTRING, L"Clicked in subwindow; cursor position (%d,%d)", LOWORD(lParam), HIWORD(lParam));
		InvalidateRect(MainHwnd, &rect, FALSE);

		GetClientRect(MainHwnd, &rect);
		InvalidateRect(MainHwnd, &rect, FALSE);
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