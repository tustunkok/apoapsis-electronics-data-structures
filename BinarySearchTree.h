#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "BinaryTree.h"
#include <iostream>
#include <cassert>

template <class ElemType>
class BinarySearchTree : public BinaryTree<ElemType>
{
public:
	bool Search(const ElemType& searchItem, BinaryTreeNode<ElemType> *foundNode) const;
	void Insert(const ElemType& insertItem);
	void DeleteNode(const ElemType& deleteItem);
private:
	void DeleteFromTree(BinaryTreeNode<ElemType>* &p);
};

template <class ElemType>
bool BinarySearchTree<ElemType>::Search(const ElemType& searchItem, BinaryTreeNode<ElemType> *foundNode) const
{
	BinaryTreeNode<ElemType> *current;
	bool found = false;
	foundNode = NULL;

	if (root == NULL)
		std::cerr << "Cannot search the empty tree." << std::endl;
	else
	{
		current = root;

		while (current != NULL && !found)
		{
			if (current->info == searchItem)
			{
				found = true;
				foundNode = current;
			}
			else if (current->info > searchItem)
				current = current->llink;
			else
				current = current->rlink;
		}
	}

	return found;
}

template <class ElemType>
void BinarySearchTree<ElemType>::Insert(const ElemType& insertItem)
{
	BinaryTreeNode<ElemType> *current;
	BinaryTreeNode<ElemType> *trailCurrent;
	BinaryTreeNode<ElemType> *newNode;

	newNode = new BinaryTreeNode<ElemType>;
	assert(newNode != NULL);
	newNode->info = insertItem;
	newNode->llink = NULL;
	newNode->rlink = NULL;

	if (root == NULL)
		root = newNode;
	else
	{
		current = root;

		while (current != NULL)
		{
			trailCurrent = current;

			if (current->info == insertItem)
			{
				std::cerr << "The insert item is already in the list, duplicates are not allowed." << insertItem << std::endl;
				return;
			}
			else if (current->info > insertItem)
				current = current->llink;
			else
				current = current->rlink;
		}

		if (trailCurrent->info > insertItem)
			trailCurrent->llink = newNode;
		else
			trailCurrent->rlink = newNode;
	}
}

template <class ElemType>
void BinarySearchTree<ElemType>::DeleteFromTree(BinaryTreeNode<ElemType>* &p)
{
	BinaryTreeNode<ElemTree> *current;
	BinaryTreeNode<ElemTree> *trailCurrent;
	BinaryTreeNode <ElemTree> *temp;

	if (p == NULL)
		std::cerr << "Error: The node to be deleted is NULL." << std::endl;
	else if (p->llink == NULL && p->rlink == NULL)
	{
		temp = p;
		p = NULL;
		delete temp;
	}
	else if (p->llink == NULL)
	{
		temp = p;
		p = temp->rlink;
		delete temp;
	}
	else if (p->rlink == NULL)
	{
		temp = p;
		p = temp->llink;
		delete temp;
	}
	else
	{
		current = p->llink;
		trailCurrent = NULL;

		while (current->rlink != NULL)
		{
			trailCurrent = current;
			current = current->rlink;
		}

		p->info = current->info;

		if (trailCurrent == NULL)
			p->llink = current->llink;
		else
			trailCurrent->rlink = current->llink;

		delete current;
	}
}

template <class ElemType>
void BinarySearchTree<ElemType>::DeleteNode(const ElemType& deleteItem)
{
	BinaryTreeNode<ElemType> *current;
	BinaryTreeNode<ElemType> *trailCurrent;
	bool found = false;

	if (root == NULL)
		std::cout << "Cannot delete from the empty tree." << std::endl;
	else
	{
		current = root;
		trailCurrent = root;

		while (current != NULL && !found)
		{
			if (current->info == deleteItem)
				found = true;
			else
			{
				trailCurrent = current;

				if (current->info > deleteItem)
					current = current->llink;
				else
					current = current->rlink;
			}
		}

		if (current == NULL)
			std::cout << "The delete item is not in the tree." << std::endl;
		else if (found)
		{
			if (current == root)
				DeleteFromTree(root);
			else if (trailCurrent->info > deleteItem)
				DeleteFromTree(trailCurrent->llink);
			else
				DeleteFromTree(trailCurrent->rlink);
		}
	}
}

#endif