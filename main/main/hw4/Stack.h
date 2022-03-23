#pragma once
#include "ListP.h"
typedef ListItemType StackItemType;
class Stack
{
public:
	Stack();
	Stack(const Stack& aStack);
	~Stack();

	bool isEmpty() const;
	bool push(StackItemType newItem);
	bool pop();
	bool pop(StackItemType& stackTop );
	bool getTop(StackItemType& stackTop) const;
private:
	List alist;

};

