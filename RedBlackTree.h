#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include "BinarySearchTree.h"

template <class ElemType>
class RedBlackTree : public BinarySearchTree<ElemType>
{
public:

private:
	void LeftRotate(BinaryTreeNode<ElemType> *x);
	void Parent(BinaryTreeNode<ElemType> *p) const;
};

template <class ElemType>
void RedBlackTree<ElemType>::LeftRotate(BinaryTreeNode<ElemType> *x)
{
	BinaryTreeNode<ElemType> *y = x->rlink;
	x->rlink = y->llink;

	/*if (y->llink != NULL)
		y->llink*/
}

template <class ElemType>
void RedBlackTree<ElemType>::Parent(BinaryTreeNode<ElemType> *p) const
{

}

#endif
