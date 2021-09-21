
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	//calculating different values of certain musical notes
	cout << "Reference frequency is = Fr = 16.35 Hz" << endl;
	cout << " " << endl; //for better visual output
	double twelf_root_two = 1.059463094359;
	//cout << twelf_root_two << endl;
	int speed_of_sound = 345;
	long two_raised_to_power_zero = 1;
	//long two_raised_to_power_one = 2;
	//long two_raised_to_power_two = 4;
	long two_raised_to_power_three = 8;
	long two_raised_to_power_four = 16;
	long two_raised_to_power_seven = 128;
	long two_raised_to_power_eight = 256;

	double ref_freq = 16.35;
	// notes: C#0, D0, D3, C4, D#7, C8
	
	// necessary info: Note, nu, k, frequency, wavelength

	// desired frequency = reference frequency ( 16.35 Hz ) * (2 ^ nu ) * ((2 ^ (1 / 12 )) ^ k)

	double C_sharp_zero_freq = ref_freq * (two_raised_to_power_zero) * (pow(twelf_root_two, 1.0));
	double D_zero_freq = ref_freq * (two_raised_to_power_zero) * (pow(twelf_root_two, 2.0));
	double D_three_freq = ref_freq * (two_raised_to_power_three) * (pow(twelf_root_two, 2.0));
	double C_four_freq = ref_freq * (two_raised_to_power_four) * (pow(twelf_root_two, 0.0));
	double D_sharp_seven_freq = ref_freq * (two_raised_to_power_seven) * (pow(twelf_root_two, 3.0));
	double C_eight_freq = ref_freq * (two_raised_to_power_eight) * (pow(twelf_root_two, 0.0));

	cout << "Speed of Sound: " << speed_of_sound << " m/s" << endl;
	//cout << Note: C0, nu: 
	cout << " " << endl; //for better visual output


	cout << "Note: C#0 " << "nu = 0 " << "k = 1 " << "frequency: " << "Hz " << C_sharp_zero_freq << " " << "Wavelength: " << (speed_of_sound / C_sharp_zero_freq) << " m" << endl;
	
	cout << "Note: D0 " << "nu = 0 " << "k = 2 " << "frequency: " << "Hz " << D_zero_freq << " " << "Wavelength: " << (speed_of_sound / D_zero_freq) << " m" << endl;

	cout << "Note: D3 " << "nu = 3 " << "k = 2 " << "frequency: " << "Hz " << D_three_freq << " " << "Wavelength: " << (speed_of_sound / D_three_freq) << " m" << endl;

	cout << "Note: C4 " << "nu = 4 " << "k = 0 " << "frequency: " << "Hz " << C_four_freq << " " << "Wavelength: " << (speed_of_sound / C_four_freq) << " m" << endl;

	cout << "Note: D#7 " << "nu = 7 " << "k = 3 " << "frequency: " << "Hz " << D_sharp_seven_freq << " " << "Wavelength: " << (speed_of_sound / D_sharp_seven_freq) << " m" << endl;

	cout << "Note: C8 " << "nu = 8 " << "k = 0 " << "frequency: " << "Hz " << C_eight_freq << " " << "Wavelength: " << (speed_of_sound / C_eight_freq) << " m" << endl;
}
