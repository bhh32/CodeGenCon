#include <iostream>
#include <conio.h>
#include <cassert>
#include <vector>
#include "Dictionary.h"
#include <map>

int main()
{
	Dictionary<float> intMap;

	assert(intMap.Empty());
	intMap.Put("zero", 0.25f);
	intMap.Put("one", 1.14f);
	intMap.Put("two", 2.36f);

	assert(intMap.ContainsKey("zero"));
	assert(intMap.ContainsKey("one"));
	assert(intMap.ContainsKey("two"));
	//assert(!intMap.ContainsKey("three")); // Fails as expected

	assert(intMap.Get("zero") == 0.25f);
	assert(intMap.Get("one") == 1.14f);
	assert(intMap.Get("two") == 2.36f);
	assert(intMap["zero"] == 0.25f);
	assert(intMap["one"] == 1.14f);
	assert(intMap["two"] == 2.36f);

	vector<string> returnedVec = intMap.Keys();
	assert(returnedVec[0] == "zero");
	assert(returnedVec[1] == "one");
	assert(returnedVec[2] == "two");

	assert(intMap.Size() == 3);

	intMap.Remove("two");
	assert(!intMap.ContainsKey("two"));

	assert(intMap.Size() == 2);

	string checker = intMap.ToString("zero");
	std::cout << checker << std::endl;

	vector<float> mapValueVec = intMap.Values();
	assert(mapValueVec[0] == 0.25f);
	assert(mapValueVec[1] == 1.14f);

	Dictionary<float> map2;
	map2.Put("zero", 0.25f);
	map2.Put("one", 1.14f);

	assert(intMap.Equals(map2)); // Checks to ensure Equals() works
	assert(intMap == map2); // Checks to ensure the == operator evaluates properly
	//assert(!(intMap == map2)); // Fails as expected
	assert(!(intMap != map2)); // Check to ensure the != operator evaluates to false
	//assert(intMap != map2); // Fails as expected

	while (true)
	{
		char keyUp = _getch();
		if (keyUp)
			break;
	}

	return 0;
}