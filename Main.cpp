#include "mat.hpp"

#include <iostream>
#include <stdexcept>
using namespace std;
using namespace ariel;

int main() {
	int cols, rows;
	char ch1, ch2;

	cout<< "Enter number of cols:"<<endl;
	cin>> cols;

	cout<< "Enter number of rows:"<<endl;
	cin>> rows;

	cout<< "Enter char 1:"<<endl;
	cin>> ch1;

	cout<< "Enter char 2:"<<endl;
	cin>> ch2;

	try {
		cout << mat(cols, rows, ch1, ch2) << endl; // Exception - not a valid code
	} catch (exception& ex) {
	 	cout << "   caught exception: " << ex.what() << endl;
	}





}