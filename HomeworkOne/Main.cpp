// Ross Rydman
// Assignment # 2 for CS 302-1001
// Professor Taghva
// Fall 2013

// Program reads a user-specified text file line by line
// Searches for and returns if a line is a palindrome or not
// Error checking is basic. The data structures will throw overflow/underflow
// and the main will print an error if the file fails to open successfully.

// Note: This is literally my first C++ Program!
// Transfered from another school where I learned Python
// and I had a little C# background also.
// Thank you to the book "Accelerated C++"!!!!

// ----------------------
// USAGE: Execute program and then input full path to txt file.
// ----------------------

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <cctype>

#include "Queue.h"
#include "Stack.h"

using namespace std;

int main()
{
	// Variables
	string file;					// File name input by user
	string fileLine;				// Current string
	int strLen;						// Len of current string
	bool isPalindrome;
	ifstream fileStream;
	Queue<char> charQueue(10000);	// Queue to store characters 
									// assuming 10,000 chars will be enough for the max line size
									// using teacher's implementation of fixed size queue
	Stack<char> charStack;			// Stack to store characters

	// Prompt user for input file name
	cout << "Please input a file name to read from: ";
	cin >> file;

	fileStream.open(file.c_str()); // Attempt to open file

	// If file opened successfully, do comparison on strings
	if (fileStream.is_open())
	{
		cout << "Palindrome Output: " << endl << endl;
		getline(fileStream, fileLine);

		while (fileStream)
		{
			strLen = fileLine.length();
			isPalindrome = true; // Assume it is a palindrome and check later

			for (int i = 0; i < strLen / 2; i++)
				charQueue.enqueue(tolower(fileLine[i]));	// add chars to queue
			if (strLen % 2 == 0)
			{
				for (int i = strLen / 2; i < strLen; i++)
					charStack.push(tolower(fileLine[i]));  // add chars to stack
			}
			else
			{
				for (int i = strLen / 2 + 1; i < strLen; i++)
					charStack.push(tolower(fileLine[i]));  // add chars to stack
			}
			for (int i = 0; i < strLen / 2; i++)
			{
				if (charQueue.dequeue() != charStack.topAndPop())
					isPalindrome = false;
			}
			if (isPalindrome)
				cout << fileLine << endl << "Is a palindrome." << endl << endl;
			else
				cout << fileLine << endl << "Is NOT a palindrome." << endl << endl;
			getline(fileStream, fileLine);
		}
	}
	else
	{
		cout << "Error reading file! Please double check file name. Make sure to include full path." << endl;
	}

	cout << endl << endl << "My work here is done!" << endl;


	return 0;
};