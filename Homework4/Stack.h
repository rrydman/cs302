#pragma once
#include "StackItr.h"
#include "StackNode.h"
#include <stdexcept>

// Stack.h - defines how to create a Stack

// Simple implementation of linked Stack. Does NOT include deep copy.

template <class object>
class Stack{
public:
	Stack();
	Stack(const Stack<object> &rhs);		//constructor
	~Stack();								//destructor
	bool isEmpty() const;
	void makeEmpty();
	void push(const object &x);
	void pop();
	object topAndPop();
	object top();
private:
	StackNode<object> *TopOfStack;
	int stackSize;
};

// Constructor
template <class object>
Stack<object>::Stack(){
	TopOfStack = NULL;
	stackSize = 0;
};

// Destructor
template <class object>
Stack<object>::~Stack(){
	makeEmpty();
	delete TopOfStack;
};

// makeEmpty
template <class object>
void Stack<object>::makeEmpty(){
	if (TopOfStack != NULL)
	{
		while (TopOfStack != NULL)
		{
			StackNode<object> *oldNode = TopOfStack;
			TopOfStack = TopOfStack->next;
			delete oldNode;
		}
		stackSize = 0;
	}
};

//	Push - Constructs the Stack (using linked list)
template<class object>
void Stack<object>::push(const object &x){
	TopOfStack = new StackNode<object>(x, TopOfStack);
	stackSize++;
};

// IsEmpty
template <class object>
bool Stack<object>::isEmpty() const{
	return stackSize == 0;
};

// Top and Pop (remove)
template<class object>
object Stack<object>::topAndPop(){
	object element = TopOfStack->element;
	if (stackSize == 1)
	{
		delete TopOfStack;
		TopOfStack = NULL;
		stackSize = 0;
		return element;
	}
	else
	{
		StackNode<object> *OldTop = TopOfStack;
		TopOfStack = TopOfStack->next;
		delete OldTop;
		stackSize--;
		return element;
	}

};

// Pop (remove)
template<class object>
void Stack<object>::pop(){
	object element = TopOfStack->element;
	if (stackSize == 1)
	{
		delete TopOfStack;
		TopOfStack = NULL;
		stackSize = 0;
	}
	else
	{
		StackNode<object> *OldTop = TopOfStack;
		TopOfStack = TopOfStack->next;
		delete OldTop;
		stackSize--;
	}

};
// Top 
template<class object>
object Stack<object>::top(){
	if (isEmpty()) throw std::underflow_error("Stack Empty!");
	object element = TopOfStack->element;
	return element;
};
