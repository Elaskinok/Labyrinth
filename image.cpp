#include "image.h"


Image::Image(const char* existFileName) {

	std::ifstream file(existFileName, std::ios::binary);

	file.read((byte*)&bmfh, sizeof(BITMAPFILEHEADER));
	file.read((byte*)&bmih, sizeof(BITMAPINFOHEADER));

	pixel_count = bmih.biWidth * bmih.biHeight;
	padding = bmih.biWidth % 4;


	raster = new Pixel[pixel_count];

	Pixel* temp = raster;

	for (int row = 0; row < bmih.biHeight; row++)
	{
		file.read((byte*)temp, bmih.biWidth * sizeof(Pixel));

		byte* paddingBuff = new byte[padding];
		file.read(paddingBuff, padding);

		delete[] paddingBuff;
		temp += bmih.biWidth;

	}

	file.close();
}

bool Image::createNewImage(const char* fileName) {
	std::ofstream file(fileName, std::ios::binary);

	file.write((byte*)&bmfh, sizeof(BITMAPFILEHEADER));
	file.write((byte*)&bmih, sizeof(BITMAPINFOHEADER));

	Pixel* temp = raster;

	for (int row = 0; row < bmih.biHeight; row++)
	{
		file.write((byte*)temp, bmih.biWidth * sizeof(Pixel));

		byte* paddingBuff = new byte[padding];
		file.write(paddingBuff, padding);

		delete[] paddingBuff;
		temp += bmih.biWidth;

	}

	file.close();
	return true;
}

Image::Image(int width, int height, int coeff) {
	/*
	std::ifstream file("image.bmp", std::ios::binary);

	file.read((byte*)&bmfh, sizeof(BITMAPFILEHEADER));
	file.read((byte*)&bmih, sizeof(BITMAPINFOHEADER));
	file.close();
*/

	pixel_count = width * height * coeff * coeff;
	padding = (width * coeff) % 4;
	bmfh = {};
	bmih = {};

	bmfh.bfType = 19778;
	bmfh.bfSize = ((width * sizeof(Pixel) + padding) * height) + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
	bmfh.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
	
	bmih.biSize = sizeof(BITMAPINFOHEADER);
	bmih.biWidth = width * coeff;
	bmih.biHeight = height * coeff;
	bmih.biPlanes = 1;
	bmih.biBitCount = 24;
	bmih.biSizeImage = ((width * sizeof(Pixel) + padding) * height);



	raster = new Pixel[pixel_count];
	
	padding = bmih.biWidth % 4;
}

Image::~Image() {
	delete[] raster;
}