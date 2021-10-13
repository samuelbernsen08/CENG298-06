
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	double ref_freq = 16.35;
	int speed_of_sound = 345; // m/s
	const int k_n_octaves = 8;
	const int k_n_half_tones = 11;

	string a_strNotes[9][12] = { "C0", "C#0", "D0","D#0", "E0", "F0","F#0", "G0", "G#0", "A0", "A#0", "B0",   // must declare rows and columns to access elements in the array
							"C1", "C#1", "D1","D#1", "E1", "F1", "F#1", "G1", "G#1", "A1", "A#1", "B1",
							"C2", "C#2", "D2","D#2", "E2", "F2", "F#2", "G2", "G#2", "A2", "A#2", "B2",
							"C3", "C#3", "D3","D#3", "E3", "F3", "F#3", "G3", "G#3", "A3", "A#3", "B3",
							"C4", "C#4", "D4","D#4", "E4", "F4", "F#4", "G4", "G#4", "A4", "A#4", "B4",
							"C5", "C#5", "D5","D#5", "E5", "F5", "F#5", "G5", "G#5","A5", "A#5", "B5",
							"C6", "C#6", "D6","D#6", "E6", "F6", "F#6", "G6", "G#6","A6", "A#6", "B6",
							"C7", "C#7", "D7","D#7", "E7", "F7", "F#7", "G7", "G#7","A7", "A#7", "B7",
							"C8", "C#8", "D8","D#8", "E8", "F8", "F#8", "G8", "G#8","A8", "A#8", "B8",
	};

	for (int nu = 0; nu < k_n_octaves; nu++) { // outer for loop iterates 8 times
		for (int k = 0; k < k_n_half_tones; k++) { // inner for loop iterates 11 times

			// total of 88 iterations from both for loops

			double final_note_freq = ref_freq * (pow(2.0, (nu + (k / 12.0))));

			double wavelength_cm = 100 * (speed_of_sound / final_note_freq); // multiplying by 100 since speed_of_sound is in m/s, we want cm/s * s)

			cout << "Note: " << a_strNotes[nu][k] << "; nu: " << nu << "; k: " << k; // accessing the array at *nu* row and *k* column
			cout << ": frequency: " << final_note_freq << " Hz; wavelength: " << wavelength_cm << " cm" << endl;
		}

	}
}

