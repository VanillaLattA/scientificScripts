#include <stdio.h>
#include <iostream>
#include <cmath>
#include <string>
using namespace std;
int main() {
	// Taking in the input of the float
	float input;
	cout << "Please enter a float: ";
	cin >> input;

	//Taking address of the float, and casting to unsigned int*, and dereferencing
	unsigned int floatInt = *((unsigned int*)&input);

	//Extracting 3 fields (the sign, exponent, and the mantissa)
	unsigned int floatSign, floatExponent, floatMantissa;
	floatMantissa = (floatInt >> 0) & 0b11111111111111111111111;
	floatExponent = (floatInt >> 23) & 0b11111111;
	floatSign = (floatInt >> 31) & 0b1;

	//main 
	string output = "";
	if (floatSign == 0 && floatMantissa == 0 && floatExponent == 0) 
		output = "0E0";
	else {
		if (floatExponent != 0)
			floatExponent -= 127;
		if (floatSign == 1)
			output += "-";
		output += "1.";
		int i = 0;
		while (i < 32){
			bool bitIs1 = floatMantissa & (1 << i);
			if (bitIs1) {
				break;
			}
			i++;
		}
		int j = 22;
		while ((j >= i)) {
			if (floatMantissa & (1 << j))
				output += "1";
			else
				output += "0";
			j--;
		}
		//Updating the output to account for the exponent
		output += "E" + to_string(floatExponent);
	}

	//Printing output
	cout << output << endl;
