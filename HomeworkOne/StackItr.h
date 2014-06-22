#pragma once
#include "Stack.h"
#include "StackNode.h"

// StackItr.h - Defines how to iterate over the list

template <class object>
class StackItr{
public:
	StackItr():current(Null) {}		// current position of the Iterator
	bool isPastEnd() const
	{
		return current == NULL;		//return true if at the end of list
	}
	void advance()
	{
		if (!isPastEnd())
			current = current->next;
	}
private:
	StackNode<object> *current;		//current position
	StackItr(StackNode<object> *theNode) :current(theNode){}
	friend class Stack;		
};
