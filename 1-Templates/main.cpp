#include <iostream>
#include <assert.h>

using std::cout;
using std::endl;

/** Example Exercise **/
// This should be in a header file
template<typename T>
T Add(T a, T b)
{
	return a + b;
}

/** Closed Exercises **/

// 1. Print Function
template<typename T>
void Print(T arg)
{
	cout << arg << endl;
}

// 2. Common Math Functions

template<typename T>
T Min(T a, T b)
{
	return a < b ? a : b;
}

template<typename T>
T Max(T a, T b)
{
	return a > b ? a : b;
}

template<typename T>
T Clamp(T value, T max, T min)
{
	if (value > max)
		return max;
	else if (value < min)
		return min;
	else
		return value;
}

// 3.) Explicit Print Function Instationation for User-Defined Type(Person)

class Person
{
public:
	char* name = " ";
	int age = 0;
};

template<>
void Print(Person person)
{
	cout << person.name << endl;
	cout << person.age << endl;
}

/** Open Exercises **/

// 1.) Swap

template<typename T>
void Swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

// 2.) Min and Max Instantiation for Char Types
template<>
char Min(char a, char b)
{
	return a < b ? a : b;
}

template<>
char Max(char a, char b)
{
	return a > b ? a : b;
}

// 3.) Templated Assertions

template<bool T>
bool AssertedBool(bool arg)
{
	assert(arg == T);

	return true;
}

template<typename T>
bool AssertedEqual(T x, T y)
{
	assert(x == y);

	return true;
}

template<typename T>
bool AssertedNotEqual(T x, T y)
{
	assert(x != y);
	
	return true;
}

int main()
{
	/** Example Exercise **/

	// Template arg deduced from arguments
	int implInt = Add(5, 5);
	float implFlt = Add(2.1f, 3.2f);

	// Template arg provided
	int explInt = Add<int>(5, 5);

	// Print results
	cout << implInt << endl;
	cout << implFlt << endl;
	cout << explInt << endl;

	cout << endl;
	/** Closed Exercises **/

	// 1. Print Function
	Print<int>(1);
	Print<float>(1.2f);
	Print<bool>(true);

	cout << endl;

	// 2. Common Math Operations

	int minInt = Min<int>(4, 6);
	float minFlt = Min<float>(3.4f, 2.5f);

	cout << minInt << endl;
	cout << minFlt << endl;
	cout << endl;

	int maxInt = Max<int>(4, 6);
	float maxFloat = Max<float>(3.4f, 2.5f);

	cout << maxInt << endl;
	cout << maxFloat << endl;
	cout << endl;

	int clampInt = Clamp<int>(35, 20, 10);
	float clampFloat = Clamp<float>(1.1f, 50.f, 10.f);
	int inRange = Clamp<int>(5, 10, 0);

	cout << clampInt << endl;
	cout << clampFloat << endl;
	cout << inRange << endl;
	cout << endl;

	// 3.) Explicit Print Function Instationation for User-Defined Type(Person)
	Person person;
	person.name = "Bryan";
	person.age = 32;

	Print(person);

	cout << endl;

	/** Open Exercises **/

	// 1.) Swap
	int swapA = 12;
	int swapB = 64;

	cout << "a and b: " << swapA << ", " << swapB << endl;

	Swap<int>(swapA, swapB);

	cout << "a and b swapped: " << swapA << ", " << swapB << endl;

	cout << endl;

	// 2. Min and Max Instantiation for Char Types
	char charA = 'a';
	char charB = 'b';
	 
	cout << "Min char alphabetically: " << Min(charA, charB) << endl;

	charA = 'z';
	charB = 'y';

	cout << "Max char alphabetically: " << Max(charA, charB) << endl;

	cout << endl;

	// 3.) Templated Assertions
	if (AssertedBool<true>(true)) // true
		cout << "The assertion of the bools passed!" << endl;
	//AssertedBool<false>(true); // false
	
	if (AssertedEqual<int>(5, 5)) // pass
		cout << "The assertion that the variables ARE equal passed!" << endl;
	//AssertedEqual<float>(10.3f, 1.3f); // fail

	if (AssertedNotEqual<int>(3, 4)) // pass
		cout << "The assertion that the variables are NOT equal passed!" << endl;
    //AssertedNotEqual<float>(6.2f, 6.2f); // fail

	while (true) {}

	return 0;
}