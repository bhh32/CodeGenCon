#include "IntVector.h"
#include <cassert>
#include <cstdlib>
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

	return data[size - 1];
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

const float IntVector::operator[](const int index) const
{
	if (index >= size)
		abort();

	return data[index];
}

int* IntVector::Data() const
{
	return data;
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

void IntVector::Clear()
{
	int* newData = new int[capacity];
	delete[] data;
	data = newData;
}

void IntVector::Erase(int idx)
{
	int* temp = data;

	for (int i = 0; i < size; ++i)
	{
		if (i < idx)
			data[i] = temp[i];
		else
			data[i] = temp[i + 1];
	}

	size--;
}

int IntVector::Count(int value)
{
	int counter = 0;

	for (int i = 0; i < size; ++i)
	{
		if (data[i] == value)
			counter++;
	}

	return counter;
}

void IntVector::Insert(int value, int idx)
{
	int* temp = data;

	if (idx < 0)
		abort();
	else if (idx > size)
		Grow(size + 1);
	else
	{
		for (int i = 0; i < size; ++i)
		{
			if (i < idx)
				data[i] = temp[i];
			else if (i == idx)
				data[i] = value;
			else
				data[i] = temp[i + 1];
		}
	}
}

void IntVector::Reserve(int elements)
{
	if (elements < size)
	{
		for (int i = elements + 1; i < size; ++i)
		{
			Erase(i);
		}

		capacity = sizeof(int) * size;
	}
	else if (elements >= size)
	{
		Grow(elements + 1);
	}
}

void IntVector::Compact()
{
	int* temp = data;
	int* newData = new int[size - 1];
	delete[] data;
	memcpy(data, newData, sizeof(int) * (size - 1));
}
