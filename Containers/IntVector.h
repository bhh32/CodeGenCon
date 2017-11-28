#pragma once

class IntVector
{
private:
	// Pointer to dynamically allocated array
	int* data;

	// Total capacity of the array
	unsigned int capacity;
	
	// Total number of elements stored within the array
	unsigned int size;

	// Grow the capacity size of the array
	bool Grow(size_t minSize);

public:

	IntVector();
	~IntVector();

	// Return the element at the specified index
	int &At(size_t indx);

	// Add elements to the array
	int &Append(int val);

	// Return a pointer to the underlying data array
	int* Data() const;

	// Returns the current total capacity
	size_t Capacity() const;

	// Return the current number of elements in the array
	size_t Size() const;

	// Returns true if the vector has no elements in it, otherwise returns false
	bool Empty() const;

	// Returns the first element in the vector
	int Front() const;

	// Returns the last element in the vector
	int Back() const;
};