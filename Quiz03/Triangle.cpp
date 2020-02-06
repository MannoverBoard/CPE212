#include "Triangle.hpp"

Triangle::Triangle(float b, float h, float s) : Shape() {
    base = b;
    height = h;
    side = s;
}

float Triangle::GetBase() {
    return base;
}

float Triangle::GetHeight() {
    return height;
}

float Triangle::GetSide() {
    return side;
}

void Triangle::CalcArea() {
    Shape::SetArea((base*height)/2);
}

void Triangle::CalcPerimeter() {
    Shape::SetPerimeter((side*2)+base);
}