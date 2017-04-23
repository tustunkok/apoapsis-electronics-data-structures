#ifndef FIXEDSTACK_H
#define FIXEDSTACK_H

#include <iostream>
#include <cassert>

template <class Type>
class FixedStack
{
public:
	const FixedStack<Type>& operator=(const FixedStack<Type>&);
	bool IsEmptyStack() const;
	bool IsFullStack() const;
	void Push(const Type& newItem);
	Type Top() const;
	Type Pop();
	FixedStack(int stackSize = 100);
	FixedStack(const FixedStack<Type>& otherStack);
	~FixedStack();
private:
	int maxStackSize;
	int top;
	Type *list;
	void CopyStack(const FixedStack& otherStack);
};

template <class Type>
FixedStack<Type>::FixedStack(int stackSize)
{
	if (stackSize <= 0)
	{
		std::cout << "Size of the array to hold the stack must be positive." << std::endl;
		std::cout << "Creating an array of size 100." << std::endl;
		maxStackSize = 100;
	}
	else
	{
		maxStackSize = stackSize;
	}

	top = 0;
	list = new Type[maxStackSize];
}

template <class Type>
FixedStack<Type>::FixedStack(const FixedStack<Type>& otherStack)
{
	list = NULL;
	CopyStack(otherStack);
}

template <class Type>
FixedStack<Type>::~FixedStack()
{
	delete[] list;
}

template <class Type>
const FixedStack<Type>& FixedStack<Type>::operator=(const FixedStack<Type>& otherStack)
{
	if (this != &otherStack)
		CopyStack(otherStack);
	return *this;
}

template <class Type>
bool FixedStack<Type>::IsEmptyStack() const
{
	return (top == 0);
}

template <class Type>
bool FixedStack<Type>::IsFullStack() const
{
	return (top == maxStackSize);
}

template <class Type>
void FixedStack<Type>::Push(const Type& newItem)
{
	if (!IsFullStack())
	{
		list[top++] = newItem;
	}
	else
	{
		std::cerr << "Cannot add to a full stack." << std::endl;
	}
}

template <class Type>
Type FixedStack<Type>::Top() const
{
	assert(top != 0);
	return list[top - 1];
}

template <class Type>
Type FixedStack<Type>::Pop()
{
	if (!IsEmptyStack())
	{
		return list[--top];
	}
	else
	{
		std::cerr << "Cannot remove from an empty stack." << std::endl;
		assert(top != 0);
	}
}

template <class Type>
void FixedStack<Type>::CopyStack(const FixedStack<Type>& otherStack)
{
	delete[] list;
	maxStackSize = otherStack.maxStackSize;
	top = otherStack.top;
	list = new Type[maxStackSize];

	for (int i = 0; i < top; i++)
	{
		list[i] = otherStack.list[i];
	}
}

#endif