#pragma once

//#include <windows.h>

#define byte char

#pragma pack(push,1)

struct BITMAPFILEHEADER
{
	unsigned short bfType;
	unsigned int bfSize;
	unsigned short bfReserved1;
	unsigned short bfReserved2;
	unsigned int bfOffBits;
};

struct BITMAPINFOHEADER
{
	unsigned int  biSize;
	long   biWidth;
	long   biHeight;
	unsigned short   biPlanes;
	unsigned short   biBitCount;
	unsigned int  biCompression;
	unsigned int  biSizeImage;
	long   biXPelsPerMeter;
	long   biYPelsPerMeter;
	unsigned int  biClrUsed;
	unsigned int  biClrImportant;
};

struct Pixel
{
	byte b;
	byte g;
	byte r;
};

#pragma pack(pop)