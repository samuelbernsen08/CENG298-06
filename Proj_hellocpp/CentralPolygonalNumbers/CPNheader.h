// Samuel Bernsen
// Class: CENG 298 - 06
// Midterm Programming Project: Central Polygonal Numbers

#include <string>

class CentralPolygonalNumbers
{
public:
	CentralPolygonalNumbers();
	CentralPolygonalNumbers(int nMax);
	~CentralPolygonalNumbers();
	void display();
	void save(std::string strFilename);

private:
	int m_nMax;
	int* mp_iNumbers;
};
