#pragma once
#include <vector>
#include <stdexcept>

// Interface for Queue
template<class object>
class Queue{
public:
	Queue(int capacity = 10);
	bool isEmpty() const;
	bool isFull() const;
	const object& getFront() const;
	const object& getBack() const;
	void makeEmpty();
	object dequeue();
	void enqueue(const object &x);
private:
	std::vector<object> theArray;
	int size;
	int currentSize;
	int front;
	int back;
	void increment(int &x);
};

// Constructor
template<class object>
Queue<object>::Queue(int c){
	size = c;
	std::vector<object> theArray;
	makeEmpty();
};

// Make Empty
template<class object>
void Queue<object>::makeEmpty(){
	currentSize = 0;
	front = 0;
	back = -1;
	for (int i = 0; i < size; i++)
	{
		theArray.push_back(NULL);
	}
};

// Enqueue objects
template<class object>
void Queue<object>::enqueue(const object &x){
	if (isFull())
		throw std::overflow_error("Queue Full!");
	increment(back);
	theArray[back] = x;
	currentSize++;
};

// Increment x with wrap around
template<class object>
void Queue<object>::increment(int &x){
	if (++x == theArray.size()) // eval then increment (++x)
		x = 0;
};

//Dequeue
template<class object>
object Queue<object>::dequeue(){
	if (isEmpty())
		throw std::underflow_error("Queue Empty!");
	currentSize--;
	object frontitem = theArray[front];
	increment(front);
	return frontitem;
};

// IsEmpty
template<class object>
bool Queue<object>::isEmpty() const{
	return (currentSize == 0);
};

// IsFull
template<class object>
bool Queue<object>::isFull() const{
	return (currentSize == theArray.size()) ? true : false;
};

// getFront
template<class object>
const object& Queue<object>::getFront() const{
	return theArray[front];
};

// getBack
template<class object>
const object& Queue<object>::getBack() const{
	return theArray[back];
};
