#include <iostream>
#include <windows.h>

long __stdcall WindowProcedure(HWND window, unsigned int msg, WPARAM wp, LPARAM lp){
	int a;
	switch (msg)
	{
	case WM_CREATE:
		a = 0;
		break;
	case WM_DESTROY:
		std::cout << "\ndestroying window\n";
		PostQuitMessage(0);
		return 0L;
	case WM_PAINT:
		a = 1;
		break;
	case WM_LBUTTONDOWN:
		std::cout << "\nmouse left button down at (" << LOWORD(lp) << ',' << HIWORD(lp) << ")\n";
		break;
	default:
		break;
	}
	return DefWindowProc(window, msg, wp, lp);
}

int main(){
	std::cout << "hello world!\n";

	const char* const myclass = "myclass";
	WNDCLASSEX wndclass = { sizeof(WNDCLASSEX), CS_DBLCLKS, WindowProcedure, 0, 0, GetModuleHandle(0), LoadIcon(0, IDI_APPLICATION), LoadCursor(0, IDC_ARROW), HBRUSH(COLOR_WINDOW + 1),
	0, myclass, LoadIcon(0, IDI_APPLICATION) };

	if (RegisterClassEx(&wndclass)){
		HWND window = CreateWindowEx(0, myclass, "title", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, 0, 0, GetModuleHandle(0), 0);
		if (window){
			ShowWindow(window, SW_SHOWDEFAULT);
			MSG msg;
			while (GetMessage(&msg, 0, 0, 0)) DispatchMessage(&msg);

		}
	}
}