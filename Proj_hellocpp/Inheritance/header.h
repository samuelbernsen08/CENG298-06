#include <iostream>
#include <string>
#include <cmath>

#if !defined(HEADER_H)
#define HEADER_H


class Shape
{

public:
	Shape(double dHeight, double dWidth);
	virtual ~Shape();
	virtual void scale(double dScaleFactor) = 0;
	virtual double area() = 0;
	virtual double perimeter() = 0;
	virtual void displayProperties();

protected:
	double m_dHeight;
	double m_dWidth;
	std::string m_strType;

};

class Rectangle : public Shape
{
public:
	Rectangle(double dHeight, double dWidth);
	virtual ~Rectangle();
	void scale(double dScaleFactor);
	double area();
	double perimeter();
};

class Circle : public Shape
{
public:
	Circle(double dHeight, double dWidth);
	virtual ~Circle();
	void scale(double dScaleFactor);
	double area();
	double perimeter();
};

#endif