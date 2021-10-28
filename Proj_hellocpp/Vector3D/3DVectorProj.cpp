#include "Vector3D.h"
#include <iostream>
#include <cmath>
#include <vector>
#include <string>

// default constructor
Vector3D::Vector3D() {
	m_vector = { 0, 0, 0 };
}
// overloaded constructor
Vector3D::Vector3D(double dX, double dY, double dZ) {
	m_vector = { dX, dY, dZ };
}
// destructor
Vector3D::~Vector3D() {}
// implementation of display function

void Vector3D::display() {
	std::cout << m_vector.at(0) << " x," << m_vector.at(1) << " y," << m_vector.at(2) << " z," << endl;
}
// implementation of dot() function
double Vector3D::dot(Vector3D vec3d) {
	double dDotProduct = 0.0;
	for (unsigned int i = 0; i < this->m_vector.size(); i++) {
		dDotProduct += vec3d.m_vector.at(i) * this->m_vector.at(i);
	}
	return dDotProduct;
}

