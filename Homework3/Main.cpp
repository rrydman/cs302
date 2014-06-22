// Ross Rydman
// Assignment # 3 for CS 302-1001
// Professor Taghva
// Fall 2013

// Infix to Postfix

// This program takes an expression (assumed to be valid and assumed to contain operands of only one char long)
// and converts that expression to Postfix notation. Only Postfix will both be output to the terminal.

// ----------------------
// USAGE: Execute program and then input full path to txt file.
// ----------------------

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <cctype>

#include "Stack.h"

using namespace std;

bool isOperator(char currentChar)
{
	switch (currentChar) {
	case '+':
	case '-':
	case '*':
	case '/':
	case '^':
	case '%':
		return true;
	default:
		return false;
	}
}

bool precedence(char leftOperator, char rightOperator)
{
	if (leftOperator == '*' || leftOperator == '/') {
		return true;
	}
	else if (rightOperator == '*' || rightOperator == '/') {
		return false;
	}
	return true;
}

int main()
{
	// Variables
	string file;					// File name input by user
	string fileLine;				// Current string
	int strLen;						// Len of current line
	ifstream fileStream;
	Stack<char> operandStack;		// Stack to store operands
	Stack<char> postFixStack;		// Stack to store postfix
	char x;							// current char from line
	char rightOp;
	char leftOp;

	// Prompt user for input file name
	cout << "Please input a file name to read from: ";
	cin >> file;

	fileStream.open(file.c_str()); // Attempt to open file

	// If file opened successfully, do conversion
	if (fileStream.is_open())
	{
		cout << "Postfix Output: " << endl << endl;
		getline(fileStream, fileLine);

		while (fileStream)
		{
			strLen = fileLine.length();

			// Initialize stack
			postFixStack.push('(');

			for (int i = 0; i < strLen; i++) // loop over all chars in string
			{
				x = fileLine[i];

				if (x == ' ') {}	// ignore spaces
				else if (x == '(')
				{
					postFixStack.push(x);
				}
				else if (isOperator(x))
				{
					char rightOp = x;
					while (!postFixStack.isEmpty() && isOperator(postFixStack.top()) && precedence(postFixStack.top(), rightOp))
					{
						cout << postFixStack.topAndPop() << ' ';
					}
					postFixStack.push(rightOp);
				}
				else if (x == ')')
				{
					while (!postFixStack.isEmpty() && postFixStack.top() != '(')
					{
						cout << postFixStack.topAndPop() << ' ';
					}
					postFixStack.pop();
				}
				else if (!isOperator(x))
					cout << x << ' ';
			}

			while (!postFixStack.isEmpty() && postFixStack.top() != '(')
				cout << postFixStack.topAndPop() << ' ';

			postFixStack.pop();

			cout << endl << endl;
			getline(fileStream, fileLine);
		}
	}
	else
	{
		cout << "Error reading file! Please double check file name. Make sure to include full path." << endl;
	}

	cout << endl << endl << "Done!" << endl;

	system("pause");
};