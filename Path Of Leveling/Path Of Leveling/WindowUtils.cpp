#include "stdafx.h"
#include "WindowUtils.h"

void MakeTransparent(HWND hWnd, double transparencyPercentage) {
	// Window Transparent
	// Enable WS_EX_LAYERED window extended style.
	LONG ExtendedStyle = GetWindowLong(hWnd,
		GWL_EXSTYLE);
	SetWindowLong(hWnd,
		GWL_EXSTYLE,
		ExtendedStyle | WS_EX_LAYERED);

	// Set the alpha for transparency.
	// 0 is transparent and 255 is opaque.
	double fAlpha = transparencyPercentage * (255.0 / 100);
	BYTE byAlpha = static_cast<BYTE>(fAlpha);
	SetLayeredWindowAttributes(hWnd,
		0,
		byAlpha,
		LWA_ALPHA);
}

// 
// Create Button Function  
//

HWND CreateButton(HWND parent_hwnd, LPCTSTR text, int pos_x, int pos_y) {
	return CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		text,      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		pos_x,         // x position 
		pos_y,         // y position 
		150,        // Button width
		50,        // Button height
		parent_hwnd,     // Parent window
		NULL,       // No menu.
		(HINSTANCE)GetWindowLong(parent_hwnd, GWL_HINSTANCE),
		NULL);      // Pointer not needed.
}

