#include <iostream>
#include <string>
#include <cmath>
#include "header.h"

Shape::Shape(double dWidth, double dHeight) : m_dWidth(dWidth), m_dHeight(dHeight), m_strType("Shape")
{

}

Shape::~Shape() {
	std::cout << "Shape destructor called" << std::endl;
}

void Shape::displayProperties()
{
	std::cout << "Shape: " << this->m_strType << ", Width: " << this->m_dWidth << ", Height: " << this->m_dHeight << std::endl;
	return;
}




Rectangle::Rectangle(double dWidth, double dHeight) : Shape(dWidth, dHeight)
{
	this->m_strType = "Rectangle";
}

Rectangle::~Rectangle() {
	std::cout << "Rectangle destructor called" << std::endl;
}

void Rectangle::scale(double dScaleFactor) {
	this->m_dHeight *= dScaleFactor;
	this->m_dWidth *= dScaleFactor;
}

double Rectangle::area() {
	return (this->m_dHeight * this->m_dWidth);
}

double Rectangle::perimeter() {
	return ((2 * this->m_dHeight) + (2 * this->m_dWidth));
}




Circle::Circle(double dWidth, double dHeight) : Shape(dWidth, dHeight)
{
	this->m_strType = "Circle";
}

Circle::~Circle() {
	std::cout << "Circle destructor called" << std::endl;
}

void Circle::scale(double dScaleFactor) {
	this->m_dHeight *= dScaleFactor;
	this->m_dWidth *= dScaleFactor;
}

double Circle::area() {
	return (0.25 * 3.14159 * this->m_dHeight * this->m_dWidth);
}

double Circle::perimeter() {
	return (3.14159265358979 * this->m_dHeight);
}