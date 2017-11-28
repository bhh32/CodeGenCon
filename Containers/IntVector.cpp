#include "IntVector.h"
#include <cassert>
#include <cstring>

IntVector::IntVector()
{
	capacity = 2;
	data = new int[capacity];
	size = 0;
}

IntVector::~IntVector()
{
	delete[] data;
}

int &IntVector::At(size_t idx)
{
	assert(idx >= 0 && idx < size && "The index was out of range!");
	
	return data[idx];
}

int &IntVector::Append(int val)
{
	if (size == capacity)
	{
		bool didGrow = Grow(size + 1);
		assert(didGrow);
	}
	
	data[size] = val;
	++size;

	return val;
}

bool IntVector::Grow(size_t minSize)
{
	assert(minSize <= 64000);

	// Check to see if we even need to grow the array
	if (minSize <= capacity)
		return true;

	// Grows the capacity until it's over the minSize
	while (capacity < minSize)
	{
		capacity *= 2;
	}
	
	int* newData = new int[capacity];

	// Copy the old array into the new array
	memcpy(newData, data, sizeof(int) * size);

	// Delete the old array
	delete[] data;

	// Point to the newData array using the data pointer
	data = newData;

	return true;
}

int* IntVector::Data() const
{
	int* temp = data;
	return temp;
}

size_t IntVector::Capacity() const
{
	return capacity;
}

size_t IntVector::Size() const
{
	return size;
}

bool IntVector::Empty() const
{
	return size == 0 ? true : false;
}

int IntVector::Front() const
{
	return data[0];
}

int IntVector::Back() const
{
	return data[size - 1];
}
