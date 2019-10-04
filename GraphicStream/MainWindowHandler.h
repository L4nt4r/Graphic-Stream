#pragma once

#include <iostream>
#include <windows.h>
#include <math.h>

# define M_PI           3.14159265358979323846  /* pi */
using namespace std;

class WindowHandler {
public:
	long __stdcall WindowProcedure(HWND window, unsigned int msg, WPARAM wp, LPARAM lp);
protected:
#define RedrawWindow(window) SendMessage(window, WM_PAINT, NULL, NULL)
	bool isDrawingable;
	int width;
	int height;

	void InitPipeline();
	void InitWorld();
	void DrawScene(HWND window);
	void DestroyPipeline();
	void DestroyWorld();
	void ChangeResolution(LPARAM lp);
};