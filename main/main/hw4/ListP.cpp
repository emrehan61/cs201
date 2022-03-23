#include "ListP.h"
#include <cstddef>

List::List() : size(0), head(NULL) {}

List::List(const List& aList) : size(aList.size) {
	if (aList.head == NULL) {
		head = NULL;
	}
	else {
		head = new ListNode;
		head->item = aList.head->item;
		ListNode* newPtr = head;
		for (ListNode* orgptr = aList.head->next; orgptr != NULL; orgptr = orgptr->next) {
		
			newPtr->next = new ListNode;
			newPtr = newPtr->next;
			newPtr->item = orgptr->item;
			
		}
		newPtr->next = NULL;
	}

}
List::~List() {

	while (!isEmpty()) {
		remove(1);
	}
}
bool List::isEmpty() const {
	
	return size == 0;
}

int List::getLength() const {

	return size;
}
List::ListNode* List::find(int index) const {

	if ((index < 1) || (index > getLength())) return NULL;

	else {
		ListNode* cur = head;
		for (int skip = 1; skip < index; ++skip) {
			cur = cur->next;
		}
		return cur;
		
	}
}
bool List::retrieve(int index, ListItemType& dataItem) const {
	
	if ((index < 1) || (index > getLength())) return false;

	ListNode* cur = find(index);
	dataItem = cur->item;
	return true;
}

bool List::insert(int index, ListItemType newItem) {
	int newLength = getLength() + 1;
	if ((index < 1) || (index > newLength)) return false;

	ListNode* newPtr = new ListNode;
	size = newLength;
	newPtr->item = newItem;
	if (index == 1) {
		newPtr->next = head;
		head = newPtr;
	}
	else {
		ListNode* prev = find(index - 1);
		newPtr->next = prev->next;
		prev->next =  newPtr;
	}
	return true;
}

bool List::remove(int index) {

	ListNode* cur;
	if ((index < 1) || (index > getLength())) return false;
	--size;
	if (index == 1) {
		cur = head;
		head = head->next;
	}
	else {
		ListNode* prev = find(index - 1);
		cur = prev->next;
		prev->next = cur->next;
	
	}
	cur->next = NULL;
	delete cur;
	cur = NULL;
	return true;

}