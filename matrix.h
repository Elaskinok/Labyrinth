#pragma once
#include "point.h"

#define EMPTY 0
#define WALL 1
#define VISITED -1


class Matrix {
public:
	Matrix(int height, int width);

	void initMatrix();
	void outputMatrix();
	void outputValueMatrix();
	void createLabirint(int i, int j);
	Points createNeighborsList(int y, int x);


	friend void drawlabirint(Matrix& lab, int width, int height, const char*);
	friend bool passageLabyrinth(Matrix& labyrinth, int, int);

	friend int middleCoord(Matrix& matrix);
	~Matrix();
private:
	int** arrays;
	int height;
	int width;
};