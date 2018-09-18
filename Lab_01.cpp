#include <fstream>
#include <iostream>
#include <string>

using std::ifstream;
using std::iostream;

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;

int main()
{
	ifstream inFile; // input file
	string inFileName; // input filename
	bool fileTest=false;  // file test
	double currNumber; // current number
	double prevNumber=0,x; // previous number
	double firstNumber, secondNumber; // first and second numbers
	int counter = 0;
	
	// Get a file
	while (fileTest == false)
	{
		// prompt for a file
		cout << "Please input a filename: ";
		cin >> inFileName;

		// open file
		inFile.open(inFileName);
		if (inFile)
		{
			fileTest = true;
		}
		else
		{
			cerr << "\nCould not open file." << endl;
			inFile.clear();
		}

	}
	
	// Read from file
	//inFile >> currNumber;
	while (true)
	{
		inFile >> currNumber;
		if (!inFile.fail())
		{

			if (counter == 0)
				firstNumber = currNumber;

			if (counter == 1)
				secondNumber = currNumber;

			cout << currNumber << endl;
			counter++;

			x = prevNumber;
			prevNumber = currNumber;

		}
		else
		{
			break;
		}
	} 
	cout << "Number Count: " << counter << endl;
	if (counter > 0)
	{
		cout << "First Number: " << firstNumber << endl;
		cout << "Second Number: " << secondNumber << endl;
		cout << "Next-to-last Number: " << x << endl;
		cout << "Last Number: " << currNumber << endl;
	}
	else
	{

	}

	// close file
	inFile.close();

	system("pause");
	return 0;
}
