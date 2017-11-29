#include "IntVector.h"
#include "TVector.h"
#include <iostream>

using std::cout;
using std::endl;

template<typename T>
bool AssertedEqual(T x, T y)
{
	if (x == y)
		return true;
	abort();
}

template<bool T>
bool AssertedBool(bool arg)
{
	if (arg == T)
		return true;

	abort();
}

int main()
{
	/*
	// Closed Activities

	IntVector vector;

	AssertedBool<true>(vector.Empty());

	AssertedEqual<size_t>(vector.Capacity(), 2);

	vector.Append(1);
	vector.Append(5);

	AssertedEqual<size_t>(vector.Capacity(), 2);

	AssertedEqual(vector.At(0), 1);
	AssertedEqual(vector.At(1), 5);

	vector.Append(33);

	AssertedEqual(vector.At(0), 1);
	AssertedEqual(vector.At(1), 5);
	AssertedEqual(vector.At(2), 33);
	AssertedEqual<size_t>(vector.Capacity(), 4);
	AssertedEqual<size_t>(vector.Size(), 3);
	AssertedEqual(vector.Front(), 1);
	AssertedEqual(vector.Back(), 33);
	AssertedEqual(vector.Data(), &vector.At(0));

	// Open Activities

	AssertedEqual<size_t>(vector[0], 1);
	vector.Clear();
	AssertedBool<true>(vector.Size() == 0);
	AssertedBool<true>(vector.Capacity() == 2);
	AssertedBool<true>(vector.Empty());

	vector.Append(12);
	vector.Append(45);
	vector.Append(12);

	AssertedEqual<size_t>(vector.Size(), 3);
	AssertedEqual(vector.Count(12), 2);
	
	vector.Erase(0);
	AssertedEqual(vector.Front(), 45);
	vector.Append(89);
	vector.Insert(78, 3);
	AssertedEqual<size_t>(vector[2], 78);

	vector.PrintElements();

	vector.Clear();
	vector.Reserve(10);
	AssertedBool<true>(vector.Capacity() >= 10);
	vector.Append(56);
	vector.Append(90);
	vector.Append(34);
	vector.Compact();
	AssertedEqual(vector.Capacity(), vector.Size());
	*/

	TVector<float>vector;

	AssertedBool<true>(vector.Empty());

	AssertedEqual<size_t>(vector.Capacity(), 2);

	vector.Append(1);
	vector.Append(5);

	AssertedEqual<size_t>(vector.Capacity(), 2);

	AssertedEqual<float>(vector.At(0), 1.f);
	AssertedEqual<float>(vector.At(1), 5.f);

	vector.Append(33.f);

	AssertedEqual<float>(vector.At(0), 1.f);
	AssertedEqual<float>(vector.At(1), 5.f);
	AssertedEqual<float>(vector.At(2), 33.f);
	AssertedEqual<size_t>(vector.Capacity(), 4);
	AssertedEqual<size_t>(vector.Size(), 3);
	AssertedEqual<float>(vector.Front(), 1.f);
	AssertedEqual<float>(vector.Back(), 33.f);
	AssertedEqual(vector.C_Ptr(), &vector.At(0));

	AssertedEqual<float>(vector[0], 1.f);
	vector.Clear();
	AssertedBool<true>(vector.Size() == 0);
	AssertedBool<true>(vector.Capacity() == 2);
	AssertedBool<true>(vector.Empty());

	vector.Append(12.f);
	vector.Append(45.f);
	vector.Append(12.f);

	AssertedEqual<size_t>(vector.Size(), 3);
	AssertedEqual(vector.Count(12.f), 2);

	vector.Erase(0);
	AssertedEqual<float>(vector.Front(), 45.f);
	vector.Append(89.f);
	vector.Insert(78.f, 3);
	AssertedEqual<size_t>(vector[2], 78.f);

	vector.Clear();
	vector.Reserve(10);
	AssertedBool<true>(vector.Capacity() >= 10);
	vector.Append(56.f);
	vector.Append(90.f);
	vector.Append(34.f);
	vector.Compact();
	AssertedEqual(vector.Capacity(), vector.Size());
	vector.Pop();
	AssertedEqual<float>(vector.Back(), 90.f);
	vector.Append(12.f);
	vector.Append(78.2f);
	vector.Append(32.f);
	vector.EraseRange(1, 3);
	AssertedEqual<float>(vector.Size(), 2);

	return 0;
}