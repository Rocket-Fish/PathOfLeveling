#include "stdafx.h"
#include "ButtonFunctions.h"
#include "NetworkRequests.h"
#include <cstdlib>

	WNDPROC  charButtonProc;
	WNDPROC  gearButtonProc;
	WNDPROC  treeButtonProc;
	HINSTANCE hInstanceForButton;
	HWND hWnd_parent_forButton;
	void setHInstForOutput(HINSTANCE hInstt) {
		hInstanceForButton = hInstt;

	}

	LPWSTR convertToLString(const char* cs) {
	size_t wn = mbsrtowcs(NULL, &cs, 0, NULL);
	// error if wn == size_t(-1)
	wchar_t * buf = new wchar_t[wn + 1]();  // value-initialize to 0 (see below)
	wn = mbsrtowcs(buf, &cs, wn + 1, NULL);
	// error if wn == size_t(-1)
	//			assert(cs == NULL); // successful conversion
	// result now in buf, return e.g. as std::wstring
	return buf;
	}


	LRESULT CALLBACK CharButtonProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
	{
		switch (msg) {
		case WM_LBUTTONUP:
			char * cs = ReadCharFrom("https://www.pathofexile.com/character-window/get-characters?accountName=RockyFish");
			CreateWindow(L"STATIC", convertToLString(cs), WS_VISIBLE | WS_CHILD | SS_LEFT, 10, 60, 450, 100, hWnd_parent_forButton, NULL, hInstanceForButton, NULL);
			break;
		}
		return CallWindowProc(charButtonProc, hwnd, msg, wp, lp);
	}

	LRESULT CALLBACK GearButtonProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
	{
		switch (msg) {
		case WM_LBUTTONUP:
			char * cs = ReadCharFrom("https://www.pathofexile.com/character-window/get-items?character=AWanderingFish&accountName=RockyFish");
			CreateWindow(L"STATIC", convertToLString(cs), WS_VISIBLE | WS_CHILD | SS_LEFT, 10, 60, 450, 100, hWnd_parent_forButton, NULL, hInstanceForButton, NULL);
			break;
		}
		return CallWindowProc(gearButtonProc, hwnd, msg, wp, lp);
	}

	LRESULT CALLBACK TreeButtonProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
	{
		switch (msg) {
		case WM_LBUTTONUP:
			char * cs = ReadCharFrom("https://www.pathofexile.com/character-window/get-passive-skills?reqData=false&character=AWanderingFish&accountName=RockyFish");
			CreateWindow(L"STATIC", convertToLString(cs), WS_VISIBLE | WS_CHILD | SS_LEFT, 10, 60, 450, 100, hWnd_parent_forButton, NULL, hInstanceForButton, NULL);
			break;
		}
		return CallWindowProc(treeButtonProc, hwnd, msg, wp, lp);
	}


	void MakeTheButtons(HWND hWnd_parent) {
		hWnd_parent_forButton = hWnd_parent;

		HWND charButton = CreateButton(hWnd_parent, L"Get Char List", 10, 10);
		HWND gearButton = CreateButton(hWnd_parent, L"Get Gear", 160, 10);
		HWND treeButton = CreateButton(hWnd_parent, L"Get Tree", 310, 10);
		charButtonProc = (WNDPROC)
			SetWindowLong(charButton, GWL_WNDPROC, (LONG)CharButtonProc);
		gearButtonProc = (WNDPROC)
			SetWindowLong(gearButton, GWL_WNDPROC, (LONG)GearButtonProc);
		treeButtonProc = (WNDPROC)
			SetWindowLong(treeButton, GWL_WNDPROC, (LONG)TreeButtonProc);
	}
