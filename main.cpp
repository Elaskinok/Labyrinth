#include <iostream>
#include "matrix.h"
#include "point.h"
#include <ctime>
#include "secEnter.h"
#include "image.h"

#define TEMPWAY 2
#define TRUEWAY 3

int coefficientOfScale(int width) { //коэффициент масштаба
//	int result = width / 2;
//	return result / 5;
	return 12;
}

void drawlabirint(Matrix& lab, int width, int height, const char* fileName) {
	//	int coeff = coefficientOfScale(width);
	int coeff = 10;
	Image labyrinth(width, height, coeff);



	int index = 0;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < coeff; j++) {
			for (int q = 0; q < width; q++) {
				for (int w = 0; w < coeff; w++, index++) {
					if (lab.arrays[height - i - 1][q] == EMPTY || lab.arrays[height - i - 1][q] == VISITED) {
						labyrinth.raster[index].r = 255;
						labyrinth.raster[index].g = 255;
						labyrinth.raster[index].b = 255;
					}
					if (lab.arrays[height - i - 1][q] == WALL) {
						labyrinth.raster[index].r = 0;
						labyrinth.raster[index].g = 0;
						labyrinth.raster[index].b = 0;
					}
					if (lab.arrays[height - i - 1][q] == TRUEWAY) {
						labyrinth.raster[index].r = 0;
						labyrinth.raster[index].g = 255;
						labyrinth.raster[index].b = 0;
					}
				}
			}
		}
	}
	labyrinth.createNewImage(fileName);
}

bool passageLabyrinth(Matrix& labyrinth, int i, int j) {
	if (i != labyrinth.height - 2 || j != labyrinth.width - 2)
		for (auto q = 0; q < 4; q++) {
			labyrinth.arrays[i][j] = TEMPWAY;
			if (labyrinth.arrays[i][j - 1] == VISITED) {
				if (passageLabyrinth(labyrinth, i, j - 1)) break;
			}
			if (labyrinth.arrays[i][j + 1] == VISITED) {
				if (passageLabyrinth(labyrinth, i, j + 1)) break;
			}
			if (labyrinth.arrays[i - 1][j] == VISITED) {
				if (passageLabyrinth(labyrinth, i - 1, j)) break;
			}
			if (labyrinth.arrays[i + 1][j] == VISITED) {
				if (passageLabyrinth(labyrinth, i + 1, j)) break;
			}
			labyrinth.arrays[i][j] = EMPTY;
			return false;
		}
	labyrinth.arrays[i][j] = TRUEWAY;
	return true;
}

int middleCoord(Matrix& matrix) {
	if (matrix.arrays[matrix.height / 2][matrix.width / 2] == VISITED) return matrix.height / 2;
	if (matrix.arrays[matrix.height / 2 - 1][matrix.width / 2 + 1] == VISITED || matrix.arrays[matrix.height / 2 - 1][matrix.width / 2 - 1] == EMPTY) return matrix.height / 2 - 1;
}

int main() {
	srand(time(NULL));

	std::cout << "Enter size of labyrinth.(size must be odd (for correcting work), otherwise size will become correcting!)\n";


	//std::cout << "Width: " << std::endl;
	//int width = securitedEnter(3, 20000);
	//if (width % 2 == 0) width++;
	//std::cout << "Height: " << std::endl;
	//int height = securitedEnter(3, 20000);
	//if (height % 2 == 0) height++;

		std::cout << "Size: " << std::endl;
	int height = securitedEnter(3, 9999999);
	if (height % 2 == 0) height++;
	int width = height;

	Matrix matrix(height, width);
	
	matrix.initMatrix();
//	matrix.outputMatrix();
//	puts("\n\n\n");

	
	int coord = middleCoord(matrix);
	matrix.createLabirint(1, coord);
	
	drawlabirint(matrix, width, height, "Labyrinth.bmp");
	//matrix.outputValueMatrix();
	//puts("\n\n\n\n");
	passageLabyrinth(matrix, 1, 1);
//	matrix.outputValueMatrix();
//	matrix.outputMatrix();
	drawlabirint(matrix, width, height, "solutedLabyrinth.bmp");

//	std::cin.get();
	return 0;
}