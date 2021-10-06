// Creator: Samuel Bernsen
// CENG 298 - 06

#include <iostream>
#include <string>
#include <cmath>
#include <cfloat>
#include <iomanip>
using namespace std;

int main() {
    // part 2:

    double pi_over_4 = 0.0;
    double pi;
    
    for (int n = 2; n <= 1048576; n *= 2) { // executing a loop 20 times, storing specific values of n for output
        for (int k = 0; k <= n; k++) { // from part 1
            pi_over_4 += ((pow(-1.0, k)) / ((2.0 * k) + 1));
        }
        cout << setprecision(DBL_DIG) << (pi_over_4 * 4.0); // printing the estimated value of pi to 15 digits
        cout << "; n: " << setw(7) << n << endl;
        pi_over_4 = 0.0; // resets the value of pi_over_4 for a new calculation
    }
    
}