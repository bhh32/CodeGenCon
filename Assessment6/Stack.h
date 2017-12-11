#pragma once

#include "TVector.h"

template<typename T>
class Stack
{
private:
	TVector<T> vector;

public:
	// Top = size - 1
	bool Empty()
	{
		return vector.Empty();
	}

	size_t Size()
	{
		return vector.Size();
	}

	auto Pop()
	{
		auto temp = vector.At(vector.Size() - 1);
		vector.Erase(vector.Size() - 1);
		return temp;
	}

	void Push(T value)
	{
		vector.Append(value);
	}

	T Peek()
	{
		return vector[vector.Size() - 1];
	}
};