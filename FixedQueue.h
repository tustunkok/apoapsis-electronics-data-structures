#ifndef FIXEDQUEUE_H
#define FIXEDQUEUE_H

#include <iostream>
#include <cassert>

template <class Type>
class FixedQueue
{
public:
	const FixedQueue<Type>& operator=(const FixedQueue<Type>&);
	bool IsEmptyQueue() const;
	bool IsFullQueue() const;
	void InitializeQueue();
	Type Front() const;
	Type Back() const;
	void AddQueue(const Type& queueElement);
	Type DeleteQueue();
	FixedQueue(int queueSize = 100);
	FixedQueue(const FixedQueue<Type>& otherQueue);
	~FixedQueue();
private:
	int maxQueueSize;
	int count;
	int queueFront;
	int queueRear;
	Type *list;
	void CopyQueue(const FixedQueue<Type>& otherQueue);
};

template <class Type>
FixedQueue<Type>::FixedQueue(int queueSize)
{
	if (queueSize <= 0)
	{
		std::cout << "Size of the array to hold the queue must be positive." << std::endl;
		std::cout << "Creating an array of size 100." << std::endl;
		maxQueueSize = 100;
	}
	else
		maxQueueSize = queueSize;

	queueFront = 0;
	queueRear = maxQueueSize - 1;
	count = 0;
	list = new Type[maxQueueSize];
}

template <class Type>
FixedQueue<Type>::FixedQueue(const FixedQueue<Type>& otherQueue)
{
	list = NULL;
	CopyQueue(otherQueue);
}

template <class Type>
FixedQueue<Type>::~FixedQueue()
{
	delete[] list;
}

template <class Type>
const FixedQueue<Type>& FixedQueue<Type>::operator=(const FixedQueue<Type>& otherQueue)
{
	if (this != &otherQueue)
		CopyStack(otherQueue);
	return *this;
}

template <class Type>
bool FixedQueue<Type>::IsEmptyQueue() const
{
	return (count == 0);
}

template <class Type>
bool FixedQueue<Type>::IsFullQueue() const
{
	return (count == maxQueueSize);
}

template <class Type>
void FixedQueue<Type>::InitializeQueue()
{
	queueFront = 0;
	queueRear = maxQueueSize - 1;
	count = 0;
}

template <class Type>
Type FixedQueue<Type>::Front() const
{
	assert(!IsEmptyQueue());
	return list[queueFront];
}

template <class Type>
Type FixedQueue<Type>::Back() const
{
	assert(!IsEmptyQueue());
	return list[queueRear];
}

template <class Type>
void FixedQueue<Type>::AddQueue(const Type& newElement)
{
	if (!IsFullQueue())
	{
		queueRear = (queueRear + 1) % maxQueueSize;
		count++;
		list[queueRear] = newElement;
	}
	else
		std::cout << "Cannot add to a full queue." << std::endl;
}

template <class Type>
Type FixedQueue<Type>::DeleteQueue()
{
	assert(!IsEmptyQueue());

	Type ret = list[queueFront];
	count--;
	queueFront = (queueFront + 1) % maxQueueSize;
	return ret;
}

template <class Type>
void FixedQueue<Type>::CopyQueue(const FixedQueue<Type>& otherQueue)
{
	delete[] list;

	maxQueueSize = otherQueue.maxQueueSize;
	queueFront = otherQueue.queueFront;
	queueRear = otherQueue.queueRear;
	count = otherQueue.count;
	list = new Type[maxQueueSize];

	for (int i = 0; i < maxQueueSize; i++)
	{
		list[i] = otherQueue.list[i];
	}
}

#endif