#include "MainWindowHandler.h"

# define M_PI           3.14159265358979323846  /* pi */

WindowHandler MainWndHandler;

long __stdcall WindowProcedure(HWND window, unsigned int msg, WPARAM wp, LPARAM lp){
	auto result = MainWndHandler.WindowProcedure(window, msg, wp, lp);
	switch (msg)
	{
	case WM_DESTROY:
		std::cout << "\ndestroying window\n";
		PostQuitMessage(0);
		return 0L;
	default:
		break;
	}
	return result;
}

int main(){
	std::cout << "hello world!\n";

	const char* const myclass = "myclass";
	WNDCLASSEX wndclass = { 
		sizeof(WNDCLASSEX), 
		CS_DBLCLKS, 
		WindowProcedure, 
		0, 
		0, 
		GetModuleHandle(0), 
		LoadIcon(0, IDI_APPLICATION), 
		LoadCursor(0, IDC_ARROW), 
		HBRUSH(COLOR_WINDOW + 1),
		0, 
		myclass, 
		LoadIcon(0, IDI_APPLICATION)
	};

	if (RegisterClassEx(&wndclass)){
		HWND window = CreateWindowEx(0, 
			myclass, 
			"title", 
			WS_OVERLAPPEDWINDOW, 
			CW_USEDEFAULT, 
			CW_USEDEFAULT, 
			CW_USEDEFAULT, 
			CW_USEDEFAULT, 
			0, 
			0, 
			GetModuleHandle(0), 
			0
		);
		if (window){
			ShowWindow(window, SW_SHOWDEFAULT);
			MSG msg;
			while (GetMessage(&msg, 0, 0, 0)) DispatchMessage(&msg);

		}
	}
}