// Ben Howe
// Lab 01
// COSC 2030, Fall 2018
// 9/17/2018

// Read double numbers from a file and display number count, first number
// second number, next-to-last number, and last number.

#include <fstream>  // ...to read from files.
#include <iostream> // ...to interact with the stream
#include <string>   // ...to allow for input of filename

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
  bool fileTest = false;  // file test
  double currNumber; // current number
  double prevNumber , buffer=0; // previous number
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

      /* Used for debugging
        cout << currNumber << endl; 
      */
      
      counter++;  // Increment counter
      prevNumber = buffer;
      buffer = currNumber;

      /*
      it ws necessary to put a buffer between the current and previous numbers
      because the previous number would get overweritten by the current number
      when the input filestream reads past the end of the file. 
      In essense the last pass through the while loop needs to be ignored.
      */
    }
    else
    {
      break;
    }
  }
  
  cout << "Number Count: " << counter << endl;
  
  if (counter > 0)
  {
    // File contains at least one number
    cout << "First Number: " << firstNumber << endl;

    if (counter > 1)
    {
      // File contains at least a second number
      cout << "Second Number: " << secondNumber << endl;
      cout << "Next-to-last Number: " << prevNumber << endl;
    }

    cout << "Last Number: " << currNumber << endl;
  }
  
  // close file
  inFile.close();

  return 0;
}
