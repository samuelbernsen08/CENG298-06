#include <iostream>
#include <string>
#include "header.h"


int main() {

	Rectangle* p_shapeRectangle = new Rectangle(2.0, 3.0);
	Circle* p_shapeCircle = new Circle(2.0, 2.0);

	Shape* p_shapes[2];

	p_shapes[0] = p_shapeCircle;
	p_shapes[1] = p_shapeRectangle;

	for (int i = 0; i <= 1; i++) {

		p_shapes[i]->displayProperties();
		double dArea = p_shapes[i]->area();
		std::cout << "Area: " << dArea << ", ";
		double perimeter = p_shapes[i]->perimeter();
		std::cout << "Perimeter: " << perimeter << " " << std::endl;;

		p_shapes[i]->scale(2.0);

		p_shapes[i]->displayProperties();
		dArea = p_shapes[i]->area();
		std::cout << "Area: " << dArea << ", ";
		perimeter = p_shapes[i]->perimeter();
		std::cout << "Perimeter: " << perimeter << " " << std::endl;


	}

	delete p_shapeRectangle;
	delete p_shapeCircle;

	return 0;

}