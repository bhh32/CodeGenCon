#include "IntLinkedList.h"
#include <cassert>

IntLinkedList::IntLinkedList() : head(nullptr), tail(head), size(0)
{

}

IntLinkedList::~IntLinkedList()
{
	IntLinkedListNode* iter = head;

	while (iter != nullptr)
	{
		IntLinkedListNode* next = iter->next;
		delete iter;
		iter = next;
	}
}

void IntLinkedList::Append(int value)
{
	IntLinkedListNode* newNode = new IntLinkedListNode;
	newNode->value = value;
	newNode->next = nullptr;

	if (head == nullptr)
	{
		head = newNode;
		tail = head;
	}
	else
	{
		IntLinkedListNode* iter = head;
		
		while (iter->next != nullptr)
		{
			iter = iter->next;
		}

		iter->next = newNode;
		tail = newNode;
		size++;
	}
}

int IntLinkedList::At(int index)
{
	assert(index <= size);
	
	int counter = 0;

	IntLinkedListNode* currentNode = head;

	while (counter < index && currentNode != nullptr)
	{
		currentNode = currentNode->next;
		counter++;
	}

	return currentNode->value;
}

size_t IntLinkedList::GetSize() const
{
	return size;
}

bool IntLinkedList::Empty() const
{
	return head == nullptr;
}

int &IntLinkedList::Front() const
{
	assert(!Empty());

	return head->value;
}

int &IntLinkedList::Back() const
{
	assert(!Empty());

	return tail->value;
}

void IntLinkedList::Clear()
{
	IntLinkedListNode* iter = head;

	while (head != nullptr)
	{
		if (iter != nullptr)
		{
			IntLinkedListNode* next = iter->next;
			delete iter;
			iter = next;
		}

		head = nullptr;
		tail = head;
	}
}

size_t IntLinkedList::Count(int value)
{
	size_t counter = 0;

	IntLinkedListNode* currentNode = head;

	while (currentNode != nullptr)
	{
		if(currentNode->value == value)
			counter++;
	}

	return counter;
}

void IntLinkedList::Insert(int value, size_t index)
{
	assert(index <= size);

	IntLinkedListNode* newNode = new IntLinkedListNode;
	newNode->value = value;

	IntLinkedListNode* currentNode = head;

	IntLinkedListNode* previousNode = new IntLinkedListNode;

	int counter = 0;

	// Gets the the node that is currently at the index as well as the node before it
	while (counter < index)
	{
		if (counter == index - 1)
			previousNode = currentNode;

		currentNode = currentNode->next;		

		counter++;
	}

	// The current node at the specified idx is saved in the temp variable
	IntLinkedListNode* temp = currentNode;

	// The current node is set to the new node
	currentNode = newNode;

	// The pointer to the next node is set to the temp variable that holds the original node
	currentNode->next = temp;

	// The pointer of the previous node is set to the new current node
	previousNode->next = currentNode;

	// Increase the size by one
	size++;
}
