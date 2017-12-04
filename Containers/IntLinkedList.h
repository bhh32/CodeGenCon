#pragma once

class IntLinkedList
{
public:
	struct IntLinkedListNode 
	{
		int value;
		IntLinkedListNode* next;
	};

	IntLinkedList();
	~IntLinkedList();

	void Append(int value);
	int At(int index);
	size_t GetSize() const;
	bool Empty() const;
	int &Front() const;
	int &Back() const;
	void Clear();
	size_t Count(int value);
	void Insert(int value, size_t index);

private:
	IntLinkedListNode* head;
	IntLinkedListNode* tail;
	size_t size;


};
