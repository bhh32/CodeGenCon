#include <iostream>
#include <cassert>
#include <vector>
#include "HashMap.h"

int main()
{
	HashMap<float> intMap;
	
	assert(intMap.Empty() == true);
	intMap.Put("zero", 0.25f);
	intMap.Put("one", 1.14f);
	intMap.Put("two", 2.36f);

	assert(intMap.ContainsKey("zero"));
	assert(intMap.ContainsKey("one"));
	assert(intMap.ContainsKey("two"));
	assert(!intMap.ContainsKey("three")); // Makes sure returns false

	assert(intMap.Get("zero") == 0.25f);
	assert(intMap.Get("one") == 1.14f);
	assert(intMap.Get("two") == 2.36f);

	vector<std::string> returnedVec = intMap.Keys();
	assert(returnedVec[0] == "zero");
	assert(returnedVec[1] == "one");
	assert(returnedVec[2] == "two");

	assert(intMap.Size() == 3);

	intMap.Remove("two");
	assert(!intMap.ContainsKey("two"));

	assert(intMap.Size() == 2);

	string checker = intMap.ToString("zero");
	std::cout << checker << std::endl;
	system("pause");

	vector<float> mapValueVec = intMap.Values();
	assert(mapValueVec[0] == 0.25f);
	assert(mapValueVec[1] == 1.14f);
}