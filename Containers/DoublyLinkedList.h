#pragma once

#include <cassert>

template<typename T>
class TDoublyLinkedList
{
public:
	struct TDoublyLinkedListNode
	{
		T value;
		TDoublyLinkedListNode* next;
	};

	TDoublyLinkedList();
	~TDoublyLinkedList();

	void Append(T value);
	T &At(size_t index);
	size_t GetSize() const;
	bool Empty() const;
	T &Front() const;
	T &Back() const;
	T &Previous(size_t index);
	void Clear();
	size_t Count(T value);
	void Insert(T value, size_t index);
	
private:
	TDoublyLinkedListNode* head;
	TDoublyLinkedListNode* tail;
	TDoublyLinkedListNode* previous;
	size_t size;
};

template<typename T>
TDoublyLinkedList<T>::TDoublyLinkedList() : head(nullptr), tail(head), size(0)
{}

template<typename T>
TDoublyLinkedList<T>::~TDoublyLinkedList()
{
	TDoublyLinkedListNode* iter = head;

	while (iter != nullptr)
	{
		TDoublyLinkedListNode* next = iter->next;
		delete iter;
		iter = next;
	}
}

template<typename T>
void TDoublyLinkedList<T>::Append(T value)
{
	// Allocate new memory for the new node and set its value, and, since it's at the end,
	// it will have a nullptr
	TDoublyLinkedListNode* newNode = new TDoublyLinkedListNode;
	newNode->value = value;
	newNode->next = nullptr;

	// If this is the first element being added to the list...
	if (head == nullptr)
	{
		// ... set the head to the new node...
		head = newNode;

		// ... and set the tail to the head
		tail = head;
	}
	// If this is not the first element being added...
	else
	{
		// Create an iterator and set it to head...
		TDoublyLinkedListNode* iter = head;

		// ... and set the previous node to tail
		previous = tail;

		// Set the newNode as the tail
		tail = newNode;

		// Set the previous (old tail) next to the new tail
		previous->next = tail;

		// Increase the size
		size++;
	}
}

template<typename T>
T &TDoublyLinkedList<T>::At(size_t index)
{
	assert(index <= size);

	size_t counter = 0;

	TDoublyLinkedListNode* currentNode = head;

	while (counter < index && currentNode != nullptr)
	{
		currentNode = currentNode->next;
		counter++;
	}

	return currentNode->value;
}

template<typename T>
size_t TDoublyLinkedList<T>::GetSize() const
{
	return size;
}

template<typename T>
bool TDoublyLinkedList<T>::Empty() const
{
	return head == nullptr;
}

template<typename T>
T &TDoublyLinkedList<T>::Front() const
{
	assert(!Empty());

	return head->value;
}

template<typename T>
T &TDoublyLinkedList<T>::Back() const
{
	assert(!Empty());

	return tail->value;
}

template<typename T>
T &TDoublyLinkedList<T>::Previous(size_t index)
{
	assert(index <= size);

	previous->value = At(index - 1);

	return previous->value;
}

template<typename T>
void TDoublyLinkedList<T>::Clear()
{
	TDoublyLinkedListNode* iter = head;

	while (head != nullptr)
	{
		if (iter != nullptr)
		{
			TDoublyLinkedListNode* next = iter->next;

			delete iter;

			iter = next;
		}

		if (iter == nullptr)
		{
			head = nullptr;
			previous = nullptr;
		}
	}
}

template<typename T>
size_t TDoublyLinkedList<T>::Count(T value)
{
	size_t counter = 0;

	TDoublyLinkedListNode* currentNode = head;

	while (currentNode != nullptr)
	{
		if (currentNode->value == value)
			counter++;
	}

	return counter;
}

template<typename T>
void TDoublyLinkedList<T>::Insert(T value, size_t index)
{
	assert(index <= size);

	// Allocate the memory for the new node and set it's value to the specified value
	TDoublyLinkedListNode* newNode = new TDoublyLinkedListNode;
	newNode->value = value;

	// Create and set the currentNode to head
	TDoublyLinkedListNode* currentNode = head;

	size_t counter = 0;

	// Gets the node that is currently at the index as well as the node before it
	while (counter < index)
	{
		if (counter == index - 1)
			previous = currentNode;

		currentNode = currentNode->next;

		counter++;
	}

	// The current node at the specified idx is saved in the temp variable
	TDoublyLinkedListNode* temp = currentNode;

	// The current node is set to the new node
	currentNode = newNode;

	// The pointer to the next node is set to the temp variable that holds the original node
	currentNode->next = temp;

	// The pointer of the previous node is set to the new current node
	previous->next = currentNode;

	// Increase the size
	size++;
}