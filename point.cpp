#include "point.h"
#include <malloc.h>
#include "matrix.h"

void copyPoints(Point* dest, Points source) {
	for (int i = 0; i < source.count; i++) {
		dest[i].x = source.points->x;
		dest[i].y = source.points->y;
	}
}

void pointsReallocPlus1(Points& points) {
	Point* new_points;
	new_points = new Point[points.count + 1];
	copyPoints(new_points, points);
	free(points.points);
	points.points = new_points;
}

void addElem(Points& points, int x, int y) {
	points.count++;
	if (points.points == nullptr) {
		points.points = new Point;
		points.points->x = x;
		points.points->y = y;
	}
	else {
		pointsReallocPlus1(points);
		points.points[points.count - 1].x = x;
		points.points[points.count - 1].y = y;
	}
}

Points Matrix::createNeighborsList(int y, int x) {
	Points neighbors; neighbors.points = nullptr; neighbors.count = 0;
	if (y - 2 > 0 && arrays[y - 2][x] != VISITED) addElem(neighbors, x, y - 2);
	if (y + 2 < height && arrays[y + 2][x] != VISITED) addElem(neighbors, x, y + 2);
	if(x - 2 > 0 && arrays[y][x - 2] != VISITED)  addElem(neighbors, x - 2, y);
	if(x + 2 < width && arrays[y][x + 2] != VISITED)  addElem(neighbors, x + 2, y);
	return neighbors;
}
