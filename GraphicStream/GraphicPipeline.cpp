#include "GraphicPipeline.h"


GraphicPipe::GraphicPipe(HDC hdc ) {

	DrawContextHandler = hdc;
}

int GraphicPipe::SetResolution(unsigned int width, unsigned int height) {
	int result = 1;
	try {
		primaryBuffer.resize(width*height);
		secondaryBuffer.resize(width*height);
	}
	catch (...) {
		result = 0;
	}
	return result;
}