#pragma once
#include <iostream>
typedef std::string ListItemType;
class List
{
public:
	List();
	List(const List& aList);
	~List();
	bool isEmpty() const;
	int getLength() const;
	bool retrieve(int index, ListItemType & dataItem) const;
	bool insert(int index ,ListItemType newItem);
	bool remove(int index);
private:
	struct ListNode {
		ListItemType item;
		ListNode* next;

	};
	int size;
	ListNode* head;

	ListNode* find(int index) const;
	
};

