#include "MainWindowHandler.h"

long __stdcall WindowHandler::WindowProcedure(HWND window, unsigned int msg, WPARAM wp, LPARAM lp) {
	switch (msg)
	{
	case WM_CREATE:
		isDrawingable = true;
		cout << "\nInitialization";
		InitPipeline();
		InitWorld();
		break;
	case WM_DESTROY:
		DestroyPipeline();
		DestroyWorld();
	case WM_PAINT:
		if (isDrawingable);
		DrawScene(window);
		break;
	case WM_LBUTTONDOWN:
		cout << "\nmouse left button down at (" << LOWORD(lp) << ',' << HIWORD(lp) << ")\n";
		break;
	case WM_SIZE:
		ChangeResolution(lp);
		isDrawingable = true;
		RedrawWindow(window);
		break;
	case WM_SIZING:
		isDrawingable = false;
		break;
	default:
		break;
	}
	return DefWindowProc(window, msg, wp, lp);
}

void WindowHandler::DrawScene(HWND window) {
	std::cout << "\ndrawing in window\n";
	HDC myDC = GetDC(window);
	int pixel = 0;
	//Choose any color
	COLORREF COLOR = RGB(255, 0, 0);
	for (double i = 0; i < M_PI * 4; i += 0.05)
	{
		SetPixel(myDC, pixel, (int)(50 + 25 * cos(i)), COLOR);
		pixel += 1;
	}

	ReleaseDC(window, myDC);
}


void WindowHandler::InitPipeline() {

}
void WindowHandler::InitWorld() {}
void WindowHandler::DestroyPipeline() {}
void WindowHandler::DestroyWorld() {}
void WindowHandler::ChangeResolution(LPARAM lp) {}