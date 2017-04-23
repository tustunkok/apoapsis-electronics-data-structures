#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <cassert>

template <class Type>
struct node_t
{
	Type info;
	node_t<Type> *link;
};

template <class Type>
class LinkedList
{
public:
	const LinkedList<Type>& operator=(const LinkedList<Type>&);
	void InitializeList();
	bool IsEmptyList() const;
	void Print() const;
	int Length() const;
	void DestroyList();
	const node_t<Type>* Front() const;
	const node_t<Type>* Back() const;
	const node_t<Type>* Search(const Type& searchItem) const;
	void InsertFirst(const Type& newItem);
	void DeleteNode(const Type& deleteItem);
	LinkedList();
	LinkedList(const LinkedList<Type>& otherLinkedList);
	~LinkedList();
protected:
	int count;
	node_t<Type> *first;
	node_t<Type> *last;
private:
	void CopyList(const LinkedList<Type>& otherList);
};

template <class Type>
const node_t<Type>* LinkedList<Type>::Search(const Type& searchItemp) const
{
	node_t<Type> *temp = first;

	for (int i = 0; i < count; i++)
	{
		if (temp->info == searchItemp)
			return temp;
		temp = temp->link;
	}
	return NULL;
}

template <class Type>
void LinkedList<Type>::InsertFirst(const Type& newItem)
{
	node_t<Type> *newNode = new node_t<Type>;
	newNode->info = newItem;
	newNode->link = first;
	first = newNode;

	if (last == NULL)
		last = first;

	count++;
}

template <class Type>
void LinkedList<Type>::DeleteNode(const Type& deleteItem)
{
	node_t<Type> *current, *trailCurrent;
	bool found;

	if (first == NULL)
		cout << "Cannot delete from empty list." << endl;
	else
	{
		if (first->info == deleteItem)
		{
			current = first;
			first = first->link;
			count--;
			if (first == NULL)
				last = NULL;
			delete current;
		}
		else
		{
			found = false;
			trailCurrent = first;
			current = first->link;

			while (current != NULL && !found)
			{
				if (current->info != deleteItem)
				{
					trailCurrent = current;
					current = current->link;
				}
				else
				{
					found = true;
				}
			}
			if (found)
			{
				trailCurrent->link = current->link;
				count--;
				if (last == current)
					last = trailCurrent;
				delete current;
			}
			else
			{
				cout << "Item to be deleted is not in the list." << endl;
			}
		}
	}
}

template <class Type>
bool LinkedList<Type>::IsEmptyList() const
{
	return (first == NULL);
}

template <class Type>
LinkedList<Type>::LinkedList()
{
	first = NULL;
	last = NULL;
	count = 0;
}

template <class Type>
void LinkedList<Type>::DestroyList()
{
	node_t<Type> *temp;

	while (first != NULL)
	{
		temp = first;
		first = first->link;
		delete temp;
	}

	last = NULL;
	count = 0;
}

template <class Type>
void LinkedList<Type>::InitializeList()
{
	DestroyList();
}

template <class Type>
void LinkedList<Type>::Print() const
{
	node_t<Type> *current;

	current = first;
	while (current != NULL)
	{
		cout << current->info << " ";
		current = current->link;
	}
}

template <class Type>
int LinkedList<Type>::Length() const
{
	return count;
}

template <class Type>
const node_t<Type>* LinkedList<Type>::Front() const
{
	assert(first != NULL);
	return first;
}

template <class Type>
const node_t<Type>* LinkedList<Type>::Back() const
{
	assert(last != NULL);
	return *last;
}

template <class Type>
void LinkedList<Type>::CopyList(const LinkedList<Type>& otherList)
{
	node_t<Type> *newNode;
	node_t<Type> *current;

	if (first != NULL)
		DestroyList();

	if (otherList.first == NULL)
	{
		first = NULL;
		last = NULL;
		count = 0;
	}
	else
	{
		current = otherList.first;
		count = otherList.count;

		first = new node_t<Type>;
		first->info = current->info;
		first->link = NULL;
		last = first;
		current = current->link;

		while (current != NULL)
		{
			newNode = new node_t<Type>;
			newNode->info = current->info;
			newNode->link = NULL;
			last->link = newNode;
			last = newNode;

			current = current->link;
		}
	}
}

template <class Type>
LinkedList<Type>::~LinkedList()
{
	DestroyList();
}

template <class Type>
LinkedList<Type>::LinkedList(const LinkedList<Type>& otherList)
{
	first = NULL;
	CopyList(otherList);
}

template <class Type>
const LinkedList<Type>& LinkedList<Type>::operator=(const LinkedList<Type>& otherList)
{
	if (this != &otherList)
	{
		CopyList(otherList);
	}
	return *this;
}
#endif
