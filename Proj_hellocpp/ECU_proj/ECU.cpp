#include <iostream>
#include <cmath>
#include "ECU.h"


ECU::ECU() {
	m_bActivatedHydraulicJacks = false;
	m_bActivatedBeltTires = false;
	m_bActivatedIRillumination = false;
	}
ECU::~ECU() {
	std::cout << "Destructor called " << std::endl;
	}

void ECU::handleCommand(char cCommand) {

	switch (cCommand) {

	case 'A':
		actuateHydraulicJacks();
		if (m_bActivatedBeltTires) {
			std::cout << "Belt Tires deactivated" << std::endl;
			numBeltCalls -= 1;
		}
		m_bActivatedBeltTires = false;
		numHydraulicCalls += 1;
		break;
	case 'B':
		actuateBeltTires();
		numBeltCalls += 1;
		break;
	case 'E':
		actuateIRillumination();
		numIRCalls += 1;
		break;
	}
	}

void ECU::actuateHydraulicJacks() {
	if (numHydraulicCalls % 2 == 0) {
		m_bActivatedHydraulicJacks = true;
		std::cout << "Hydraulic Jacks activated" << std::endl;
	}
	else {
		m_bActivatedHydraulicJacks = false;
		std::cout << "Hydraulic Jacks deactivated" << std::endl;
	}
	
}

void ECU::actuateBeltTires() {
	if (numBeltCalls % 2 == 0) {
		m_bActivatedBeltTires = true;
		std::cout << "Belt Tires activated" << std::endl;
	}
	else {
		m_bActivatedBeltTires = false;
		std::cout << "Belt Tires deactivated" << std::endl;
	}
}

void ECU::actuateIRillumination() {
	if (numIRCalls % 2 == 0) {
		m_bActivatedIRillumination = true;
		std::cout << "Infrared Illumination activated" << std::endl;
	}
	else {
		m_bActivatedIRillumination = false;
		std::cout << "Infrared Illumination deactivated" << std::endl;
	}
}