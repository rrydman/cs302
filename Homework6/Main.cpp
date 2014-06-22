// Ross Rydman
// Assignment # 6 for CS 302-1001
// Professor Taghva
// Fall 2013

// ----------------------
// USAGE: Execute program and then input full path to txt file.
// ----------------------

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <cctype>
#include <vector>

using namespace std;

void check(int row, int col, vector< vector<char> > &vec, int &currSize)
{
	if (vec[row][col] == '1')
	{
		// Set to 2 so as not to record it again
		vec[row][col] = '2';
		currSize++;
		// Check right
		check(row, (col + 1), vec, currSize);
		// Check down
		check((row + 1), col, vec, currSize);
		// Check left
		check(row, (col - 1), vec, currSize);
		// Check up
		check((row - 1), col, vec, currSize);

	}
	return;
}

int main()
{
	// Variables
	string file;					// File name input by user
	string fileLine;				// Current string
	int strLen;						// Len of current string
	ifstream fileStream;
	int lineNumber = 0;
	int inputRows = 0;
	int inputCols = 0;
	int currRow = 0;
	int currCol = 0;
	int currSize = 0;

	// Set outputRows to be max grouping size
	int outputRows = 100;

	vector< vector<char> > inputVec;
	vector<int> outputVec(outputRows, NULL);

	// Prompt user for input file name
	cout << "Please input a file name to read from: ";
	cin >> file;

	fileStream.open(file.c_str()); // Attempt to open file

	if (fileStream.is_open())
	{
		cout << "Input: " << endl << endl;
		getline(fileStream, fileLine);

		while (fileStream)
		{
			strLen = fileLine.length();
			if (lineNumber == 0)
			{
				if (!(istringstream(fileLine) >> inputRows)) inputRows = 0;
				cout << inputRows ;
			}
			else if (lineNumber == 1)
			{
				if (!(istringstream(fileLine) >> inputCols)) inputCols = 0;
				cout << inputCols ;
			}
			else
			{
				// Add row to input vector
				inputVec.push_back(vector<char>());
				// Print Input and add to vector
				for (int i = 0; i < strLen; i++)
				{
					// Print char
					cout << fileLine[i];
					// Add char to array
					inputVec[currRow].push_back( fileLine[i] );
					currCol++;
				}
				currRow++;
			}
			cout << endl;
			lineNumber++;
			getline(fileStream, fileLine);
		}
		// Process checks
		for (int i = 0; i < inputRows; i++)
		{
			for (int j = 0; j < inputCols; j++)
			{
				currSize = 0;
				check(i, j, inputVec, currSize);
				if (currSize != 0)
				{
					// Record result
					if (outputVec[currSize] == NULL)
					{
						outputVec[currSize] = 1;
					}
					else
					{
						outputVec[currSize] += 1;
					}
				}
			}
		}

	}
	else
	{
		cout << "Error reading file! Please double check file name. Make sure to include full path." << endl;
	}

	// Print input vector
	/*cout << "Printing input vector" << endl << endl;
	for (int i = 0; i < inputRows; i++)
	{
		for (int j = 0; j < inputCols; j++)
			cout  << inputVec[i][j] << ' ';
		cout << '\n';
	}*/

	// Print output vector
	cout << endl << "Group Size | Number of Groups" << endl;
	for (int i = 0; i < outputRows; i++)
	{		
		if (outputVec[i] != NULL)
		{
			cout << i << "         |         " << outputVec[i] << endl;
		}
	}

	return 0;
};
