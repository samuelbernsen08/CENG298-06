#include <vector>
#include <string>
#if !defined(VECTOR_3D_H)
using namespace std;

class Vector3D
{
public:
	Vector3D();
	Vector3D(double dX, double dY, double dZ);
	~Vector3D();
	double dot(Vector3D vec3d);
	void display();

private:
	vector<double> m_vector = { 0, 0, 0 };

};
#endif