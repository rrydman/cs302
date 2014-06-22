// Ross Rydman
// Assignment # 4 for CS 302-1001
// Professor Taghva
// Fall 2013

// Postfix to Infix w/ Expression Tree

// This program takes an expression (assumed to be valid and assumed to contain operands of only one char long)
// and converts that expression to Infix notation.

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

struct BinaryNode
{
	char element;
	BinaryNode *left, *right;
	bool isOp;
};

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
};

void print_inorder(BinaryNode *P)
{
	if (P != NULL)
	{
		if (P->isOp = true && P->left != NULL) cout << "( ";
		print_inorder(P->left); // print left subtree
		cout << P->element << " "; // print this node
		print_inorder(P->right); // print right subtree
		if (P->isOp = true && P->right != NULL) cout << ") ";
	}
};

int main()
{
	// Variables
	string file;							// File name input by user
	string fileLine;						// Current string
	int strLen;								// Len of current line
	ifstream fileStream;
	Stack<BinaryNode *> treeStack;			// Stack to store tree node pointers
	char x;									// current char from line
	BinaryNode *one, *two, *finaltree;


	// Prompt user for input file name
	cout << "Please input a file name to read from: ";
	cin >> file;

	fileStream.open(file.c_str()); // Attempt to open file

	// If file opened successfully, go on
	if (fileStream.is_open())
	{
		getline(fileStream, fileLine);

		while (fileStream)
		{
			strLen = fileLine.length();

			for (int i = 0; i < strLen; i++)	// loop over all chars in input string
			{
				// Read one char at a time from input
				x = fileLine[i];

				BinaryNode *temp;
				temp = new BinaryNode;
				temp->element = x;

				if (x == ' ') {}				// ignore spaces
				else if (!isOperator(x))		// If read operand
				{
					// Create one node tree
					temp->left = NULL;
					temp->right = NULL;
					temp->isOp = false;
					// Push pointer to tree to stack
					treeStack.push(temp);
				}
				else if (isOperator(x))			// If read operator
				{
					temp->isOp = true;
					// Create two node tree
					// Pop two symbols from stack into nodes on tree
					two = treeStack.topAndPop();
					one = treeStack.topAndPop();
					temp->left = one;
					temp->right = two;
					// Push pointer to tree to stack
					treeStack.push(temp);
				}
			}
			cout << "Infix Output: " << endl << endl;
			// Print out expression tree
			finaltree = treeStack.topAndPop();
			print_inorder(finaltree);
			cout << endl << endl;
			// Clear expression tree for next line iteration
			getline(fileStream, fileLine);
		}
		
	}
	else
	{
		cout << "Error reading file! Please double check file name. Make sure to include full path." << endl;
	}

	cout << endl << endl << "Done!" << endl << endl;

	//system("pause");
};