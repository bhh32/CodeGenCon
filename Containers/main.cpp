#include "IntVector.h"
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
	// Closed Activities

	IntVector vector;

	AssertedBool<true>(vector.Empty());

	AssertedEqual<size_t>(vector.Capacity(), 2);

	vector.Append(1);
	vector.Append(5);

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
	vector.Insert(78, 2);
	AssertedEqual(vector.At(2), 78);
	vector.Reserve(10);
	AssertedBool<true>(vector.Capacity() >= 10);
	vector.Compact();
	AssertedEqual(vector.Capacity(), vector.Size());
	vector.PrintElements();
	
	system("pause");
	vector.~IntVector();
	return 0;
}