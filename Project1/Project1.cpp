// Project1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cassert>
#include <cstdlib>
using namespace std;
//declare constants
const int ZERO = 0;
const int ONE = 1;

//declare function prototypes
int fileSize(string ifile);
int fib_Summation(int n);
int fib_Recursion(int n);


int _tmain(int argc, _TCHAR* argv[])
{
	//variable declarations and iostream
	string file_name;
	int output;
	ifstream iFile;
	
	//ask for user input (file name) and call FileSize function to determine number of items within file
	cout << "Enter File Name (including file extension e.g. 'numbers.txt'): ";
	cin >> file_name;
	cout <<"\n"<<fileSize(file_name)<<" items in file" << endl;

	//attempt reading from file, if successful continue otherwise display error
	iFile.open(file_name);
	if (iFile.is_open())
	{
		cout << "\nFile Opened!" << endl;	
		cout << "\n1.) Recursion\n" << endl;
		
		//begin looping through file displaying the item in file, while calling Fib_Recursion function with passed in argument
		while (!iFile.eof())
		{
			iFile >> output;
			cout << "Fib" << "(" << output << ")" << " is: " << fib_Recursion(output) <<endl;
		}
		
		//reset reader position to 0 to begin second run through numbers using Fib_Summation function
		iFile.clear();
		iFile.seekg(0, std::ios::beg);

		//formatting purposes only
		cout << "\n---------------------------------------------------------------------" << endl;
		cout << "\n2.) Non-Cursion\n" << endl;
		
		//begin looping through file displaying the item in file, while calling Fib_Summation function with passed in argument
		while (!iFile.eof())
		{
			//read item, and call function
			iFile >> output;
			cout << "Fib" << "(" << output << ")" << " is: " << fib_Summation(output) << endl;
		}
		
		//close file
		iFile.close();
		cout << "\nFile Closed!" << endl;
	
	}
	else
	{
		cout << "File could not be opened!" << endl;
	}
		
	cout << "\nPress any key to exit!" << endl;
	
	//pause system
	cin.clear();
	cin.ignore();
	std::cin.get();
	return 0;
}

// Function Name:	fib_Recursion 
// Purpose:	   Method to calculate Nth sequence of Fibonacci numbers
// After base-case checking, call function recursively passing argument into n-1, n-2 and adding the returned values together
// Parameters:	integer passed by value
// Returns:	   integer
// Pre-conditions:	none
// Post-conditions:none	 

int fib_Recursion(int n)
{


	if (n <= ZERO)
		return ZERO;
	else if (n == ONE)
		return ONE;
	else if (n > ONE)
		return fib_Recursion(n - 2) + fib_Recursion(n - 1);

}

// Function Name:	fib_Summation 
// Purpose:	Method to calculate Nth sequence of Fibonacci numbers
// After base-case checking, begin looping through sequence n-1 times, performing summation of fibonnaci sequence non recursively
// continue loop for n-1 times then return
// Parameters:	integer passed by value
// Returns:	   integer
// Pre-conditions:	none
// Post-conditions:none	 
int fib_Summation(int n)
{
	//declare variable to hold fibonacci sequence
	int fib = 0;
	//declare variables for base case
	int num_1 = 0;
	int num_2 = 1;

	if (n <= ZERO)
		return ZERO;
	else if (n == ONE)
		return ONE;
	else if (n > ONE)
	for (int i = 0; i < n - 1; i++)
	{
		//first add base cases
		fib = num_1 + num_2;
		//now move number sequenctially by setting num_1 = num_2 and then num_2 = fib
		num_1 = num_2;
		num_2 = fib;

	}
	return fib;
}
/// fileSize: method to calculate number of items in file
/// gets each line and increments counter until no more lines
/// then returns counter
/// Parameters: (int ifile)
/// returns: int
int fileSize(string ifile)
{

	int numLines = 0;
	ifstream in(ifile);
	std::string unused;
	while (std::getline(in, unused))
		++numLines;
	return numLines;
}