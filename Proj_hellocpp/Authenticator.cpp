// authenticator.cpp: A program that authenticates the message inputted by the user

#include <iostream>
#include <string>
using namespace std;

int main()
{
	// part 1:

	const char Char1 = 'E';
	const char Char2 = 'C';
	const char Char3 = 'A';

	const int Valid_checksum = 5;
	int user_checksum;

	char input1;
	char input2;
	char input3;

	int ascii_input1;
	int ascii_input2;
	int ascii_input3;

	string user_input_string;
	string authenticator_code;
	string empty_string; // to concatenate character, we need to add them to a string
	string empty_string2; // need an empty string to concatenate the const chars

	cout << "First character of the message: " << endl;
	cin >> input1;
	while (isalpha(input1) == false) {
		cout << "This must be an integer. Re-enter your character: ";
		cin >> input1;
	}

	cout << "Second character of the message: " << endl;
	cin >> input2;
	while (isalpha(input2) == false) {
		cout << "This must be an integer. Re-enter your character: ";
		cin >> input2;
	}

	cout << "Third character of the message: " << endl;
	cin >> input3;
	while (isalpha(input3) == false) {
		cout << "This must be an integer. Re-enter your character: ";
		cin >> input3;
	}

	cout << endl; // for clarity of output

	user_input_string = empty_string + input1 + input2 + input3;

	authenticator_code = empty_string2 + Char1 + Char2 + Char3;

	cout << "Message Code: " << user_input_string << endl;
	cout << "Authenticator Code: " << authenticator_code << endl;
	cout << endl; // for clarity of output
	
	// part 2:

	if ((input1 == Char1) && (input2 == Char2) && (input3 == Char3)) {
		cout << "Message is authentic." << endl;

	}

	else {
		cout << "Message is invalid." << endl;
	}

	// part 3:

	if (user_input_string == authenticator_code) {
		cout << "Concurrence: message is authentic." << endl;

	}

	else {
		cout << "Concurrence: message is invalid." << endl;
	}

	// part 4

	cout << "Characterization of message code" << endl;
	cout << "------------------------------" << endl;

	ascii_input1 = int(input1);
	ascii_input2 = int(input2);
	ascii_input3 = int(input3);

	user_checksum = (ascii_input1 + ascii_input2 + ascii_input3) % 7;

	if (user_checksum == Valid_checksum) {
		cout << "Message Code Checksum is valid: 5" << endl;

	}
	
	else {
		cout << "Message Code Checksum is invalid: " << user_checksum << ";" << " expected: " << Valid_checksum << endl;
	}

	cout << "ASCII Values of Message Code Characters: " << ascii_input1 << ", " << ascii_input2 << ", " << ascii_input3 << endl;
	cout << "Sum of ASCII values for Message Code Characters: 208" << endl;

	if (input1 != Char1) {
		cout << "First characters do not match: Message: " << input1 << " ; " << "Authenticator: " << Char1 << endl;
	}

	if (input2 != Char2) {
		cout << "Second characters do not match: Message: " << input2 << " ; " << "Authenticator: " << Char2 << endl;

	}
	if (input3 != Char3) {
		cout << "Third characters do not match: Message: " << input3 << " ; " << "Authenticator: " << Char3 << endl;
	}

	if ((input1 != Char1) || (input2 != Char2) || (input3 != Char3)) {
		if (user_input_string < authenticator_code) {
			cout << "Message code (" << user_input_string << ") is lexicographically less than Authenticator code (" << authenticator_code << ")" << endl;
		}

		if (user_input_string > authenticator_code) {
			cout << "Message code (" << user_input_string << ") is lexicographically greater than Authenticator code (" << authenticator_code << ")" << endl;
		}
	}

}
