// Samuel Bernsen
// bernsen@chapman.edu
// CENG 298-06
// Instructor: Jim Bonang

#include <iostream>
#include <stdexcept>
#include <cmath>
#include <string>

unsigned long sigma(unsigned long n)
{
	unsigned long sum = 0;

	try
	{
		if (n < 1) {
			std::string strMessage = "Precondition n>=1 violated, invalid value for n: " + std::to_string(n) +
				" (Loc: " + __FILE__ + " " + std::to_string(__LINE__) + ")";
			throw std::runtime_error(strMessage);
		}

		for (int i = 1; i <= n; i++) {
			sum += i;
		}

		if (sum != ((n * (n + 1)) / 2)) {
			std::string strMessage = "Postcondition sum == n(n+1)/2 violated, sum: " + std::to_string(sum) +
				" (Loc: " + __FILE__ + " " + std::to_string(__LINE__) + ")";
			throw std::runtime_error(strMessage);
		}
	}
	catch (std::runtime_error& ex)
	{
		std::cout << "Exception: " << ex.what() << std::endl;
		std::cout << "Cannot compute sum; returning 0" << std::endl;
		sum = 0;
	}

	return sum;
}

int main()
{
	int sum = sigma(5);
	std::cout << "sigma(5) = " << sum << std::endl;
	sum = sigma(0);
	std::cout << "sigma(0) = " << sum << std::endl;

	return 0;
}