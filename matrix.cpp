#include "matrix.h"
#include <iostream>
#include "point.h"
#include <time.h>

Matrix::Matrix(int height, int width) {
	this->height = height;
	this->width = width;
	this->arrays = new int*[this->height];
	for (int i = 0; i < this->height; i++) {
		this->arrays[i] = new int[this->width];
	}
}

Matrix::~Matrix() {
	for (int i = 0; i < this->height; i++) {
		delete[] this->arrays[i];
	}
	delete[] this->arrays;
}

void Matrix::initMatrix() {
	for (int i = 0; i < this->height; i++) {
		for (int j = 0; j < this->width; j++) {
			if (i % 2 != 0 && j % 2 != 0) this->arrays[i][j] = EMPTY;
			else this->arrays[i][j] = WALL;
		}
	}
}

void Matrix::outputMatrix() {
	for (int i = 0; i < this->height; i++) {
		if (i) std::cout << "\n";
		for (int j = 0; j < this->width; j++) {
			if (arrays[i][j] == EMPTY || arrays[i][j] == VISITED) printf("%3c", ' ');
			else printf("%3c", '*');
		}
	}
}

void Matrix::outputValueMatrix() {
	for (int i = 0; i < height; i++) {
		if (i) printf("\n");
		for (int j = 0; j < width; j++) {
			printf("%3d", arrays[i][j]);
		}
	}
}

void Matrix::createLabirint(int i, int j) {
//	srand(time(NULL));
	for (int q = 0; q < 3; q++) {
		arrays[i][j] = VISITED;
		Points neighbors = createNeighborsList(i, j);
		if (neighbors.points != nullptr) {
			int direction = rand() % neighbors.count;
			arrays[(neighbors.points[direction].y + i) / 2][(neighbors.points[direction].x + j) / 2] = VISITED;
			createLabirint(neighbors.points[direction].y, neighbors.points[direction].x);
			if (neighbors.count - 1 == 0) { free(neighbors.points); break; }
			free(neighbors.points);
		}
	}
}