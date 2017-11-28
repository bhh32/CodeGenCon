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
	
	const float operator[](const int index) const;

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

	// Clears the vector array
	void Clear();

	// Deletes the element at the specified index
	void Erase(int idx);

	// Returns the total number of occurrences of a given element in the vector
	int Count(int value);

	// Inserts an element at a given index
	void Insert(int value, int idx);

	// The vector resizes the underlying array to be able to store a given number of elements
	void Reserve(int elements);

	// The vector resizes the underlying array to fit EXACTLY the number of elements that it currently contains
	void Compact();
};