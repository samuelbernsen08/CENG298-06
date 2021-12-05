// Samuel Bernsen
// Class: CENG 298 - 06
// Midterm Programming Project: Central Polygonal Numbers

#include <iostream>
#include <cmath>
#include <fstream>
#include "CPNheader.h"

CentralPolygonalNumbers::CentralPolygonalNumbers() {
	
	mp_iNumbers = 0;
	m_nMax = 0;
}



CentralPolygonalNumbers::CentralPolygonalNumbers(int nMax) {
	
	m_nMax = nMax;

	mp_iNumbers = new int[nMax];

	for (int i = 0; i < nMax; i++) {

		int p = pow(i, 2) + i + 2;

		p /= 2;

		this->mp_iNumbers[i] = p;
	}
}




CentralPolygonalNumbers::~CentralPolygonalNumbers() {
	
	delete[] mp_iNumbers;

	std::cout << "~CentralPolygonalNumbers called" << std::endl;
}


void CentralPolygonalNumbers::display() {

	for (int k = 0; k <= m_nMax; k++) {

		std::cout << this->mp_iNumbers[k] << std::endl;

	}
}



void CentralPolygonalNumbers::save(std::string strFilename) {

	std::ofstream ofsNumbers;

	ofsNumbers.open(strFilename);


	for (int j = 0; j <= m_nMax; j++) {

		ofsNumbers << this->mp_iNumbers[j] << std::endl;

	}

	ofsNumbers.close();
}



