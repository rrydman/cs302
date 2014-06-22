#pragma once
#include "StackItr.h"
#include "Stack.h"

// StackNode.h -  Defines how a node looks

template <class object>
class StackNode{
	StackNode(const object &theElement = object(), StackNode *n = NULL) :
		element(theElement), next(n){}
	object element;
	StackNode *next;
	template <class o> friend class StackItr;
	template <class o> friend class Stack;
};

