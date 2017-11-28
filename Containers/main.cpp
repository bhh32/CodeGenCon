#include "IntVector.h"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
	IntVector vector;

	// Ensure the the vector is empty
	if (vector.Empty())
		cout << "The Array Is Empty!" << endl;

	cout << endl;

	// Add elements to the vector
	vector.Append(3);
	vector.Append(5);
	
	// Get a reference to the vector
	int* vectorTemp = vector.Data();

	// Print the size, capacity, and front element of the vector
	cout << "Size: " << vector.Size() << endl;
	cout << "Capacity: " << vector.Capacity() << endl;
	cout << "Font Element: " << vector.Front() << endl;
	
	cout << endl;

	// Print all of the elements within the vector
	for (int i = 0; i < vector.Size(); ++i)
		cout << "Element " << i << ": " << vectorTemp[i] << endl;

	cout << endl;

	// Add 3 elements to the vector
	vector.Append(12);
	vector.Append(89);
	vector.Append(14);

	// Print the new size and capacity
	cout << "Size after appending 3 elements to array: " << vector.Size() << endl;
	cout << "Capacity after appending 3 elements to array: " << vector.Capacity() << endl;
	
	cout << endl;

	// Print the added elements
	cout << "Element 2: " << vector.At(2) << endl;
	cout << "Element 3: " << vector.At(3) << endl;
	cout << "Element 4: " << vector.Back() << endl;

	cout << endl;

	// Print all of the elements within the vector
	cout << "All elements: ";
	for (int i = 0; i < vector.Size(); ++i)
	{
		// Check and ensure that the element isn't the last
		if (i < vector.Size() - 1)
			cout << vector.At(i) << ", ";
		else
			// if it is, then print the last element and end the line
			cout << vector.At(i) << endl;
	}

	cout << endl;

	while (true) {}

	return 0;
}