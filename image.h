#pragma once
#include "bmpHeaders.h"
#include <fstream>
#include "matrix.h"

class Handler;

class Image {
private:
	Pixel* raster;

	BITMAPFILEHEADER bmfh;
	BITMAPINFOHEADER bmih;

	size_t pixel_count;
	size_t padding;

public:
	Image(int, int, int);
	Image(const char* existFileName);

	friend Handler;


	friend void drawlabirint(Matrix& lab, int width, int height);

	bool createNewImage(const char* fileName);

	~Image();
};