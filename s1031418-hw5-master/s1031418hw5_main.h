#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

static enum ShapeType{
	Shape = 0, Triangle, Quadrilateral, Pentagon, Parallelogram, Square,
	Trapezium, Isosceles_triangle, Regular_triangle, Right_triangle, Polygon
};
static char *ShapeName[] = {
	"Shape", "Triangle", "Quadrilateral", "Pentagon", "Parallelogram", "Square",
	"Trapezium", "Isosceles_triangle", "Regular_triangle", "Right_triangle", "Polygon"
};
static char *outputName[] = {
	"Shape", "Triangle", "Quadrilateral", "Pentagon", "Quadrilateral-Parallelogarm", "Quadrilateral-Parallelogarm-Square",
	"Quadrilateral-Trapezium", "Triangle-Isosceles_triangle", "Triangle-Isosceles_Triangle-Regular_triangle", "Triangle-Right_triangle", "Polygon"
};