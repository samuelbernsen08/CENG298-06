#include <iostream>
#include <string>
#include "ECU.h"

int main() {
	
	char userOpt;

	std::cout << "Press X to turn off ignition or enter a steering wheel button (A, B, or E)" << std::endl;
	std::cout << "     (A)     " << std::endl;
	std::cout << " (F) (G) (B) " << std::endl;
	std::cout << " (E)     (C) " << std::endl;
	std::cout << "     (D)     " << std::endl;

	std::cin >> userOpt;

	ECU vehicle;

	while (userOpt != 'X') {

		vehicle.handleCommand(userOpt);

		std::cout << "     (A)     " << std::endl;
		std::cout << " (F) (G) (B) " << std::endl;
		std::cout << " (E)     (C) " << std::endl;
		std::cout << "     (D)     " << std::endl;

		std::cin >> userOpt;
		}
	}