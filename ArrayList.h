#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <iostream>

template <class Type>
class ArrayList
{
public:
	ArrayList();
	~ArrayList();
	void Add(const Type& element);
	Type operator[](int index) const;
	Type Get(int index) const;
	void Delete(int index);
	void Print() const;
	int Search(const Type& element) const;
	int GetLength() const;
private:
	Type *ar;
	int length;
	void CopyArray(Type *otherArray);
};

template <class Type>
ArrayList<Type>::ArrayList()
{
	ar = NULL;
	length = 0;
}

template <class Type>
ArrayList<Type>::~ArrayList()
{
	delete[] ar;
}

template <class Type>
void ArrayList<Type>::Add(const Type& element)
{
	int afterAddLength = length + 1;
	Type *candidateArray = new Type[afterAddLength];

	CopyArray(candidateArray);
	candidateArray[afterAddLength - 1] = element;
	length++;

	delete[] ar;

	ar = candidateArray;
	candidateArray = NULL;
}

template <class Type>
Type ArrayList<Type>::operator[](int index) const
{
	if (index < length && index >= 0)
	{
		return ar[index];
	}

	std::cout << "Array index out of bounds. Returning first index." << std::endl;
	return ar[0];
}

template <class Type>
Type ArrayList<Type>::Get(int index) const
{
	return (*this)[index];
}

template <class Type>
void ArrayList<Type>::Delete(int index)
{
	if (index >= 0 && index < length)
	{
		Type *candidateArray = new Type[length - 1];
		for (int i = 0, j = 0; i < length; i++)
		{
			if (i == index) continue;
			candidateArray[j++] = ar[i];
		}
		length--;

		delete[] ar;

		ar = candidateArray;
		candidateArray = NULL;
	}
	else
	{
		std::cout << "Array index out of bounds." << std::endl;
	}
}

template <class Type>
int ArrayList<Type>::Search(const Type& element) const
{
	for (int i = 0; i < length; i++)
	{
		if (ar[i] == element) return i;
	}

	return -1;
}

template <class Type>
void ArrayList<Type>::Print() const
{
	for (int i = 0; i < length; i++)
	{
		std::cout << ar[i] << std::endl;
	}
}

template <class Type>
int ArrayList<Type>::GetLength() const
{
	return length;
}

template <class Type>
void ArrayList<Type>::CopyArray(Type *otherArray)
{
	for (int i = 0; i < length; i++)
	{
		otherArray[i] = ar[i];
	}
}

#endif