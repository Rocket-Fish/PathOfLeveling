#include "stdafx.h"
#include "ButtonFunctions.h"


WNDPROC  charButtonProc;
WNDPROC  gearButtonProc;
WNDPROC  treeButtonProc;
LRESULT CALLBACK CharButtonProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
{
	switch (msg) {
	case WM_LBUTTONUP:
// TODO: do something
		return 0;
	}
	return CallWindowProc(charButtonProc, hwnd, msg, wp, lp);
}

LRESULT CALLBACK GearButtonProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
{
	switch (msg) {
	case WM_LBUTTONUP:
		// TODO: do something
		return 0;
	}
	return CallWindowProc(gearButtonProc, hwnd, msg, wp, lp);
}

LRESULT CALLBACK TreeButtonProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
{
	switch (msg) {
	case WM_LBUTTONUP:
		// TODO: do something
		return 0;
	}
	return CallWindowProc(treeButtonProc, hwnd, msg, wp, lp);
}


void MakeTheButtons(HWND hWnd_parent) {
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
