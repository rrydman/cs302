// Ross Rydman
// Assignment # 5 for CS 302-1001
// Professor Taghva
// Fall 2013

// Sorting Analysis

// Sorts a randomly generated set of integers using either Selection Sort or Quicksort - which ever the user selects at runtime.

// ----------------------
// USAGE: programname -s [q/s] -n [integer]
// -s switch is for sorting algo (q for quicksort or s for selectionsort)
// -n switch is for size of randomly generated data to use
// ----------------------


#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include <ctime> 
#include <vector>

using namespace std;

// Generate random number array
vector<int> generateRands(int size)
{
	srand((unsigned)time(0));
	vector<int> ret(size);
	for (int i = 0; i < size; i++)
	{
		ret[i] = rand();
	}
	return ret;
};

// Print vector (for testing)
void printVector(vector<int> vec) {
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << endl;
};


// Selection Sort Functions
int minLocation(vector<int> &list, int first, int last)
{
	int loc, minIndex;
	minIndex = first;
	for (loc = first + 1; loc <= last; loc++)
	if (list[loc] < list[minIndex])
		minIndex = loc;
	return minIndex;
}
void swap(vector<int> &list, int first, int second)
{
	int temp;
	temp = list[first];
	list[first] = list[second];
	list[second] = temp;
}
void selectionSort(vector<int> &list)
{
	int loc, minIndex;
	for (loc = 0; loc < list.size(); loc++)
	{
		minIndex = minLocation(list, loc, list.size() - 1);
		swap(list, loc, minIndex);
	}
}

// Quick Sort
int partition(vector<int> &list, int first, int last)
{
	int pivot;
	int index, smallIndex;
	swap(list, first, (first + last) / 2);
	pivot = list[first];
	smallIndex = first;
	for (index = first + 1; index <= last; index++)
	if (list[index] < pivot)
	{
		smallIndex++;
		swap(list, smallIndex, index);
	}
	swap(list, first, smallIndex);
	return smallIndex;
}
void recQuickSort(vector<int> &list, int first, int last)
{
	int pivotLocation;
	if (first < last)
	{
		pivotLocation = partition(list, first, last);
		recQuickSort(list, first, pivotLocation - 1);
		recQuickSort(list, pivotLocation + 1, last);
	}
}
void quickSort(vector<int> &list)
{
	recQuickSort(list, 0, list.size() - 1);
}

int main(int argc, char *argv[])
{
	// Variables
	vector<int> data;

	if (argc != 5)
	{
		cout << "Incorrect arguments!" << endl;
		cout << "Usage: " << argv[0] << " -s <q or s> -n <value>" << endl;
		cout << "-s switch is for sorting algo (q for quicksort or s for selectionsort)" << endl;
		cout << "-n switch is for size of randomly generated data to use" << endl;
	}
	else
	{
		cout << "Running!" << endl;
		// Do sorts here
		switch (*argv[2])
			{
			case 'q':
				cout << "You have selected Quicksort. Good choice! Proceeding to sort..." << endl;
				// Generate random data
				cout << *argv[4] << endl;
				data = generateRands(atoi(argv[4]));
				//printVector(data);
				// Sort using method selected
				quickSort(data);
				//printVector(data);
				break;
			case 's':
				cout << "You have selected Selection Sort. Not the best but proceeding to sort anyway..." << endl;
				// Generate random data
				data = generateRands(atoi(argv[4]));
				//printVector(data);
				// Sort using method selected
				selectionSort(data);
				//printVector(data);
				break;
			}
	}

	cout << "Done!" << endl;
	//system("pause");
};
