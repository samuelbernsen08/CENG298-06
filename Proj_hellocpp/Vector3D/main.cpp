#include "Vector3D.h"
#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

int main() {
	double const PI = 3.14159265;

	double Fx = 10.0 * cos(45 * PI / 180.0); //Newtons
	double Fy = 10.0 * sin(45 * PI / 180.0); //Newtons
	double Fz = 0;

	double Dx = 10.0; // Newtons
	double Dy = 0.0; // Meters
	double Dz = 0.0; // Meters

	Vector3D vec3dForce(Fx, Fy, Fz);
	Vector3D vec3dDisplacement(Dx, Dy, Dz);

	vec3dForce.display();
	vec3dDisplacement.display();

	double dWork = vec3dForce.dot(vec3dDisplacement); // Joules (= 1 N*m)
	cout << "Work: " << dWork << endl;

	return 0;
}