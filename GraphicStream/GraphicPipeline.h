#pragma once
#include <iostream>
#include <memory> 
#include <vector>
#include <windows.h>

struct pixel {
	unsigned char R;
	unsigned char G;
	unsigned char B;
};


typedef std::vector<pixel> RGBBuffer;

class GraphicPipe{
public:
	GraphicPipe() {};
	GraphicPipe(HDC hdc);
	int SetResolution(unsigned int width, unsigned int height);
protected:
	HDC DrawContextHandler;
	RGBBuffer primaryBuffer;
	RGBBuffer secondaryBuffer;
};