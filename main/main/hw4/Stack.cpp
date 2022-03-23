#include "Stack.h"
Stack::Stack() {}

Stack::Stack(const Stack& aStack) :alist(aStack.alist) {}
Stack::~Stack(){}

bool Stack::isEmpty() const {

	return alist.isEmpty();
}
bool Stack::getTop(StackItemType& stackTop) const {

	return alist.retrieve(1, stackTop);
}
bool Stack::push(StackItemType newItem) {

	return alist.insert(1, newItem);
}
bool Stack::pop(StackItemType& stackTop) {

	if (alist.retrieve(1, stackTop)) return alist.remove(1);
	else return false;
}

bool Stack::pop() {

	return alist.remove(1);
}
