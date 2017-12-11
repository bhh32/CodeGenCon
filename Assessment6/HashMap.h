#pragma once

#define TOSTRING(key)) #key

#include <cassert>
#include <string>
#include <vector>
#include "Iterator.h"

using std::string;
using std::vector;

template<typename T>
class HashMap
{
public:
	struct MapElement
	{
		T value;
		string key;
		MapElement* next;
	};

	const T& operator[](string key);
	const T operator[](const string key) const;

	HashMap();
	~HashMap();

	void Clear();
	bool ContainsKey(string key);
	/*bool Equals(HashMap map);*/
	T Get(string key);
	bool Empty();
	vector<string> Keys();
	void Put(string key, T value);
	void Remove(string key);
	size_t Size();
	string ToString(string key);
	vector<T> Values();

private:
	size_t size;
	MapElement* head;
};

template<typename T>
const T &HashMap<T>::operator[](string key)
{
	assert(ContainsKey(key));

	// Get the beginning element
	MapElement* currentElement = head;

	// iterate through each key
	while (currentElement->key != key)
	{
		// make sure the next element exists
		if (currentElement->next != nullptr)
			currentElement = currentElement->next;
		else
			break;
	}

	return currentElement->value;
}

template<typename T>
const T HashMap<T>::operator[](const string key) const
{
	assert(ContainsKey(key));

	// Get the beginning element
	MapElement* currentElement = head;

	// iterate through each key
	while (currentElement->key != key)
	{
		// make sure the next element exists
		if (currentElement->next != nullptr)
			currentElement = currentElement->next;
		else
			break;
	}

	return currentElement->value;
}

template<typename T>
HashMap<T>::HashMap() : head(nullptr), size(0)
{}

template<typename T>
HashMap<T>::~HashMap()
{
	Clear();
}

template<typename T>
void HashMap<T>::Clear()
{
	MapElement* iter = head;

	while (iter != nullptr)
	{
		MapElement* next = iter->next;
		delete iter;
		iter = next;
	}
}

template<typename T>
bool HashMap<T>::ContainsKey(string key)
{
	// Ensure there is at least one element within the hashmap
	assert(head != nullptr);

	// Get the beginning element
	MapElement* currentElement = head;

	// iterate through each key
	while (currentElement->key != key)
	{
		// make sure the next element exists
		if (currentElement->next != nullptr)
			currentElement = currentElement->next;
		else
			break;
	}

	// Ensure the current key is the same as the requested key
	if (currentElement->key == key)
		return true;

	// otherwise return false
	return false;
}

//template<typename T>
//bool HashMap<T>::Equals(HashMap map)
//{
//	return false;
//}

template<typename T>
T HashMap<T>::Get(string key)
{
	MapElement* currentElement = head;

	return currentElement[key];
}

template<typename T>
bool HashMap<T>::Empty()
{
	if (head == nullptr)
		return true;

	return false;
}

template<typename T>
vector<string> HashMap<T>::Keys()
{
	vector<string> keyVec; // creates a vector to hold the keys
	keyVec.resize(Size()); // Sets the size of the vector to the same size of the hashmap
	MapElement* currentElement = head;
	size_t index = 0; // Sets the index of the vector

	while (currentElement != nullptr)
	{
		keyVec[index] = currentElement->key;
		currentElement = currentElement->next;
		index++;
	}
	return keyVec;
}

template<typename T>
void HashMap<T>::Put(string key, T value)
{
	// Ensures no key is a duplicate
	if(head != nullptr)
		assert(!ContainsKey(key));

	MapElement* newElement = new MapElement;
	newElement->key = key;
	newElement->value = value;
	newElement->next = nullptr;

	if (head == nullptr)
	{
		head = newElement;
		size++;
	}
	else
	{
		MapElement* iter = head;

		while (iter->next != nullptr)
		{
			iter = iter->next;
		}

		iter->next = newElement;
		size++;
	}
}

template<typename T>
void HashMap<T>::Remove(string key)
{
	assert(ContainsKey(key));

	MapElement* currentElement = head;
	MapElement* previousElement = head;

	while (currentElement->key != key)
	{
		if (currentElement->next->key == key)
			previousElement = currentElement;

		currentElement = currentElement->next;
	}

	previousElement->next = currentElement->next;

	if (currentElement == head)
		head = currentElement->next;

	delete currentElement;

	size--;

}

template<typename T>
size_t HashMap<T>::Size()
{
	return size;
}

template<typename T>
string HashMap<T>::ToString(string key)
{
	assert(ContainsKey(key));
	
	MapElement* currentElement = head;

	while (currentElement->key != key)
	{
		currentElement = currentElement->next;
	}
	
	string converter = std::to_string(currentElement->value);

	return converter;
}

template<typename T>
vector<T> HashMap<T>::Values()
{
	vector<T> valueVec; // creates a vector to hold the values
	valueVec.resize(Size()); // Sets the size of the vector to the same size of the hashmap
	MapElement* currentElement = head;
	size_t index = 0; // Sets the index of the vector

	while (currentElement != nullptr)
	{
		valueVec[index] = currentElement->value;
		currentElement = currentElement->next;
		index++;
	}

	return valueVec;
}
