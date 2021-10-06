// Creator: Samuel Bernsen
// CENG 298 - 06

#include <iostream>
#include <string>
#include <cmath>
#include <cfloat>
#include <iomanip> // seems to be needed for setprecision() function
using namespace std;

int main()
{
    // part 1:
    int n; // upper bound of summation
    double pi_over_4 = 0.0;
    double pi;


    cout << "Upper bound for pi approximation (must be a natural number): ";
    cin >> n; // getting upper bound from user and storing in it n


    for (int k = 0; k <= n; k++) { // calculation of pi / 4
        pi_over_4 += ((pow(-1.0, k)) / ((2.0 * k) + 1));
    }
    pi = pi_over_4 * 4;

    // printing output to terminal
    cout << "Approximate value of pi: " << setprecision(DBL_DIG) << pi;
    cout << "; n: " << setw(7) << n << endl;
    cout << "Actual value of pi: " << "3.141592653589793" << endl;
    cout << "Decimal digits of precision: " << DBL_DIG << endl;
    cout << "Number of base 2 mantissa digits of double precision floating point value: " << DBL_MANT_DIG << endl;
    cout << "Next representable number from 3.141592653589793: " << nextafter(3.141592653589793, 3.14) << endl;




}
