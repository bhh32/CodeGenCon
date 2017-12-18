#pragma once

#include <cassert>
#include <string>
#include <vector>
#include "Iterator.h"

using std::string;
using std::vector;

template<typename T>
class Dictionary
{
public:
	struct DictionaryElement
	{
		T value;
		string key;
		DictionaryElement* next;
	};

	T &operator[](string &&key);
	T &operator[](const string &key);
	bool operator==(const Dictionary<T> &rhs);
	bool operator!=(const Dictionary<T> &rhs);

	Dictionary();
	~Dictionary();

	void Clear();
	bool ContainsKey( string key);
	bool Equals(const Dictionary<T> &map);
	T Get(string key);
	bool Empty();
	vector<string> Keys();
	void Put(string key, T value);
	void Remove(string key);
	size_t Size() const;
	string ToString(string key);
	vector<T> Values();

private:
	size_t size;
	DictionaryElement* head;
};


template<typename T>
T &Dictionary<T>::operator[](string &&key)
{
	assert(ContainsKey(key));

	// Get the beginning element
	DictionaryElement* currentElement = head;

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
T &Dictionary<T>::operator[](const string &key)
{
	assert(ContainsKey(key));

	// Get the beginning element
	DictionaryElement* currentElement = head;

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
bool Dictionary<T>::operator==(const Dictionary<T> &rhs)
{
	if (this->size == rhs.size)
	{
		int counter = 0;
		DictionaryElement* lhsElement = head;
		DictionaryElement* rhsElement = rhs.head;

		while (counter < Size())
		{
			if (lhsElement->value == rhsElement->value)
			{
					lhsElement = lhsElement->next;
					rhsElement = rhsElement->next;
					counter++;				
			}
			else
				return false;
		}
		return true;
	}

	return false;
}

template<typename T>
bool Dictionary<T>::operator!=(const Dictionary<T> &rhs)
{
	if (this->size == rhs.size)
	{
		int counter = 0;
		DictionaryElement* lhsElement = this->head;
		DictionaryElement* rhsElement = rhs.head;

		while (counter < size)
		{
			if (lhsElement->value != rhsElement->value)
				return true;
			else
			{
				lhsElement = lhsElement->next;
				rhsElement = rhsElement->next;
				counter++;
				
			}
		}

		return false;
	}

	return true;
}

template<typename T>
Dictionary<T>::Dictionary() : head(nullptr), size(0)
{}

template<typename T>
Dictionary<T>::~Dictionary()
{
	Clear();
}

template<typename T>
void Dictionary<T>::Clear()
{
	DictionaryElement* iter = head;

	while (iter != nullptr)
	{
		DictionaryElement* next = iter->next;
		delete iter;
		iter = next;
	}
}

template<typename T>
bool Dictionary<T>::ContainsKey(string key)
{
	// Ensure there is at least one element within the Dictionary
	assert(head != nullptr);

	// Get the beginning element
	DictionaryElement* currentElement = head;

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

template<typename T>
bool Dictionary<T>::Equals(const Dictionary<T> &map)
{
	return *this == map ? true : false;
}

template<typename T>
T Dictionary<T>::Get(string key)
{
	assert(ContainsKey(key) == true);

	return (*this)[key];
}

template<typename T>
bool Dictionary<T>::Empty()
{
	if (head == nullptr)
		return true;

	return false;
}

template<typename T>
vector<string> Dictionary<T>::Keys()
{
	vector<string> keyVec; // creates a vector to hold the keys
	keyVec.resize(Size()); // Sets the size of the vector to the same size of the Dictionary
	DictionaryElement* currentElement = head;
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
void Dictionary<T>::Put(string key, T value)
{
	// Ensures no key is a duplicate
	if(head != nullptr)
		assert(!ContainsKey(key));

	DictionaryElement* newElement = new DictionaryElement;
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
		DictionaryElement* iter = head;

		while (iter->next != nullptr)
		{
			iter = iter->next;
		}

		iter->next = newElement;
		size++;
	}
}

template<typename T>
void Dictionary<T>::Remove(string key)
{
	assert(ContainsKey(key));

	DictionaryElement* currentElement = head;
	DictionaryElement* previousElement = head;

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
size_t Dictionary<T>::Size() const
{
	return size;
}

template<typename T>
 string Dictionary<T>::ToString(string key)
{
	assert(ContainsKey(key));
	
	DictionaryElement* currentElement = head;

	while (currentElement->key != key)
	{
		currentElement = currentElement->next;
	}
	
	// Converts the value to a string
	 string converter = std::to_string(currentElement->value);

	return converter;
}

template<typename T>
vector<T> Dictionary<T>::Values()
{
	vector<T> valueVec; // creates a vector to hold the values
	valueVec.resize(Size()); // Sets the size of the vector to the same size of the Dictionary
	DictionaryElement* currentElement = head;
	size_t index = 0; // Sets the index of the vector

	while (currentElement != nullptr)
	{
		valueVec[index] = currentElement->value;
		currentElement = currentElement->next;
		index++;
	}

	return valueVec;
}
