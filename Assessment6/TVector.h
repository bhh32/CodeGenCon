#pragma once

#include <cassert>
#include <cstdlib>
#include <cstring>
#include "Iterator.h"
#include <iostream>

template<typename T>
class TVector
{
private:
	// Pointer to dynamically allocated array
	T* data;

	// Total capacity of the array
	size_t capacity;

	// Total number of elements stored within the array
	size_t size;

	

public:
	const T& operator[](size_t idx);
	const T operator[](const size_t index) const;

	TVector();

	~TVector();

	Iterator<TVector<T>> Begin()
	{
		return Iterator<TVector<T>>(*this, 0);
	}

	Iterator<TVector<T>> End()
	{
		return Iterator<TVector<T>>(*this, size);
	}

	T& At(size_t idx);

	T &Append(T val);

	T* C_Ptr() const;

	// Grow the capacity size of the array
	bool Grow(size_t minSize);	

	size_t Capacity() const;

	size_t Size() const;

	bool Empty() const;

	T Front() const;

	T Back() const;

	void Clear();

	void Erase(int idx);

	size_t Count(T value);

	void Insert(T value, size_t idx);

	void Reserve(size_t elements);

	void Compact();

	void Pop();

	void EraseRange(size_t minIdx, size_t maxIdx);
};

template<typename T>
TVector<T>::TVector()
{
	capacity = 2;
	data = new T[capacity];
	size = 0;
}

template<typename T>
TVector<T>::~TVector()
{
	delete[] data;
}

template<typename T>
const T& TVector<T>::operator[](size_t idx)
{
	assert(idx < size);
	return data[idx];
}

template<typename T>
const T TVector<T>::operator[](const size_t idx) const
{
	assert(idx < size)

	return data[idx];
}

template<typename T>
T &TVector<T>::At(size_t idx)
{
	assert(idx >= 0 && idx < size && "The index was out of range!");

	return data[idx];
}

template<typename T>
T &TVector<T>::Append(T val)
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

template<typename T>
T* TVector<T>::C_Ptr() const
{
	return data;
}

template<typename T>
bool TVector<T>::Grow(size_t minSize)
{
	assert(minSize <= sizeof(T));

	// Check to see if we even need to grow the array
	if (minSize <= capacity)
		return true;

	// Grows the capacity until it's over the minSize
	while (capacity < minSize)
	{
		capacity *= 2;
	}

	T* newData = new T[capacity];

	// Copy the old array into the new array
	memcpy(newData, data, sizeof(T) * size);

	// Delete the old array
	delete[] data;

	// Point to the newData array using the data pointer
	data = newData;

	return true;
}

template<typename T>
size_t TVector<T>::Capacity() const
{
	return capacity;
}

template<typename T>
size_t TVector<T>::Size() const
{
	return size;
}

template<typename T>
bool TVector<T>::Empty() const
{
	return size == 0 ? true : false;
}

template<typename T>
T TVector<T>::Front() const
{
	assert (size > 0);
	return data[0];
}

template<typename T>
T TVector<T>::Back() const
{
	assert(size > 0);
	return data[size - 1];
}

template<typename T>
void TVector<T>::Clear()
{
	size = 0;
}

template<typename T>
void TVector<T>::Erase(int idx)
{
	assert (size > 0);

	T* temp = data;

	for (int i = 0; i < size; ++i)
	{
		if (i < idx)
			data[i] = temp[i];
		else
			data[i] = temp[i + 1];
	}

	size--;
}

template<typename T>
size_t TVector<T>::Count(T value)
{
	size_t counter = 0;

	for (size_t i = 0; i < size; ++i)
	{
		if (data[i] == value)
			counter++;
	}

	return counter;
}

template<typename T>
void TVector<T>::Insert(T value, size_t idx)
{
	assert(idx >= 0);
	assert(idx <= size);

	Append(value);

	for (size_t i = size - 1; i >= idx; i--)
	{
		T temp = data[i];
		data[i] = data[i - 1];
		data[i - 1] = temp;
	}
}

template<typename T>
void TVector<T>::Reserve(size_t elements)
{
	if (elements >= capacity)
	{
		T* newData = new T[elements];
		memcpy(newData, data, sizeof(T) * size);

		delete[] data;

		data = newData;

		capacity = elements;
	}
}

template<typename T>
void TVector<T>::Compact()
{
	if (capacity > size)
	{
		T* newData = new T[size];
		memcpy(newData, data, sizeof(T) * size);
		capacity = size;
		delete[] data;
		data = newData;
	}
}

template<typename T>
void TVector<T>::Pop()
{
	Erase(size - 1);
}

template<typename T>
void TVector<T>::EraseRange(size_t minIdx, size_t maxIdx)
{
	assert(minIdx >= 0 && minIdx < maxIdx, "Your min range was out of scope!");
	assert(maxIdx <= size - 1 && maxIdx > minIdx, "Your max range was out of scope!");

	for (int i = minIdx; i < maxIdx + 1; ++i)
	{
		Erase(i);
	}
}