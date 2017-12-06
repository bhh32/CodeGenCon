#include "IntVector.h"
//#include "TVector.h"
#include "IntLinkedList.h"
//#include "TLinkedList.h"
#include "DoublyLinkedList.h"
#include "Algorithms.h"
#include "Stack.h"
#include "Queue.h"
#include <iostream>

using std::cout;
using std::endl;

template<typename T>
bool AssertedEqual(T x, T y)
{
	assert(x == y);
		return true;
}

template<bool T>
bool AssertedBool(bool arg)
{
	assert(arg == T);
		return true;
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

	/*
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
	AssertedEqual<size_t>(vector.Count(12.f), 2);

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
	*/

    /*
	IntLinkedList nums;

	// Test the Empty function
	AssertedBool<true>(nums.Empty());

	// Test the Append Function
	nums.Append(0);
	// Ensure that the lists back is the same as the front since theres' only one element
	AssertedEqual(nums.Back(), nums.Front());

	// Append 3 more elements
	nums.Append(1);
	nums.Append(2);
	nums.Append(3);

	// Ensure the Empty function returns false since there are things in the list
	AssertedBool<false>(nums.Empty());

	// Ensure the Front and Back functions work
	AssertedEqual(nums.Front(), 0);
	AssertedEqual(nums.Back(), 3);

	// Ensure the At function works
	AssertedEqual(nums.At(2), 2);
	AssertedEqual(nums.At(0), 0);

	nums.Insert(12, 1);
	nums.Insert(43, 3);
	AssertedEqual(12, nums.At(1));
	AssertedEqual(43, nums.At(3));

	AssertedEqual(nums.At(4), 2);
	AssertedEqual(nums.At(5), 3);

	nums.~IntLinkedList();

	nums.Clear();
	AssertedBool<true>(nums.Empty());
	*/

    /*
	TLinkedList<float> nums;

	// Test the Empty function
	AssertedBool<true>(nums.Empty());

	// Test the Append Function
	nums.Append(0);
	// Ensure that the lists back is the same as the front since theres' only one element
	AssertedEqual(nums.Back(), nums.Front());

	// Append 3 more elements
	nums.Append(1.f);
	nums.Append(2.f);
	nums.Append(3.f);

	// Ensure the Empty function returns false since there are things in the list
	AssertedBool<false>(nums.Empty());

	// Ensure the Front and Back functions work
	AssertedEqual<float>(nums.Front(), 0.f);
	AssertedEqual<float>(nums.Back(), 3.f);

	// Ensure the At function works
	AssertedEqual<float>(nums.At(2), 2.f);
	AssertedEqual<float>(nums.At(0), 0.f);

	nums.Erase(2);

	//used for debugging
	cout << nums.At(2) << endl;
	//system("pause");
	AssertedEqual<float>(nums.At(2), 3.f);

	// Ensure the Insert function works
	nums.Insert(12, 1);
	nums.Insert(43, 3);
	AssertedEqual<float>(12, nums.At(1));
	AssertedEqual<float>(43, nums.At(3));

	AssertedEqual<float>(nums.At(4), 2);
	AssertedEqual<float>(nums.At(5), 3);

	

	AssertedEqual<size_t>(nums.GetSize(), 4);
	

	nums.Clear();
	AssertedBool<true>(nums.Empty()); */

    /*
	TDoublyLinkedList<float> nums;

	// Test the Empty function
	AssertedBool<true>(nums.Empty());

	// Test the Append Function
	nums.Append(0.f);
	// Ensure that the lists back is the same as the front since theres' only one element
	AssertedEqual(nums.Back(), nums.Front());

	// Append 3 more elements
	nums.Append(1.f);
	nums.Append(2.f);
	nums.Append(3.f);

	// Ensure the Empty function returns false since there are things in the list
	AssertedBool<false>(nums.Empty());

	// Ensure the Front and Back functions work
	AssertedEqual<float>(nums.Front(), 0.f);
	AssertedEqual<float>(nums.Back(), 3.f);

	// Ensure the At function works
	AssertedEqual<float>(nums.At(2), 2.f);
	AssertedEqual<float>(nums.At(0), 0.f);

	// Ensure the Insert function works
	nums.Insert(12.f, 1);
	nums.Insert(43.f, 3);
	AssertedEqual<float>(12.f, nums.At(1));
	AssertedEqual<float>(43.f, nums.At(3));

	AssertedEqual<float>(nums.At(4), 2.f);
	AssertedEqual<float>(nums.At(5), 3.f);

	AssertedEqual<float>(nums.Previous(5), 2.f);

	//nums.Erase(3);

	nums.Clear();
	AssertedBool<true>(nums.Empty());
	*/

	/*
    TVector<int> nums;
	nums.Append(0);
	nums.Append(1);

	auto begin = nums.Begin();
	auto end = nums.End();
	auto total = AddRange(begin, end);
	assert(total == 1);

	TLinkedList<float> linkedList;
	linkedList.Append(10.3f);
	linkedList.Append(12.f);

	auto begin2 = linkedList.Begin();
	auto end2 = linkedList.End();

	auto total2 = AddRange(begin2, end2);

	assert(total2 == 22.3f);

	int arr[] = { 12, 34, 65 };

	auto begin3 = arr;
	auto end3 = arr + 3;

	auto total3 = AddRange(begin3, end3);

	assert(total3 == 111);
	*/

	// STACK TESTS
Stack<int> stack;

// Test Empty function
AssertedBool<true>(stack.Empty());

// Test Push Function
stack.Push(0);
stack.Push(1);
stack.Push(2);

// Test Push worked and Size function
AssertedEqual((int)stack.Size(), 3);

// Test Peek Function
AssertedEqual(stack.Peek(), 2);

// Test Pop function
stack.Pop();
stack.Pop();
stack.Pop();
AssertedBool<true>(stack.Empty());


// QUEUE TESTS
Queue<float> queue;

// Test Empty function
AssertedBool<true>(queue.Empty());

// Test Push Function
queue.Push(9.4f);
queue.Push(12.2f);
queue.Push(5.6f);

// Test Peek Function
AssertedEqual(queue.Peek(), 9.4f);

// Test Pop Function
queue.Pop();
queue.Pop();
queue.Pop();
AssertedBool<true>(queue.Empty());
	
	return 0;
}