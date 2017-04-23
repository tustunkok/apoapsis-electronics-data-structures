#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>

template <class ElemType>
struct BinaryTreeNode
{
	ElemType info;
	BinaryTreeNode<ElemType> *llink;
	BinaryTreeNode<ElemType> *rlink;
};

template <class ElemType>
class BinaryTree
{
public:
	const BinaryTree<ElemType>& operator=(const BinaryTree<ElemType>&);
	bool IsEmpty() const;
	void InorderTraversal() const;
	void PreorderTraversal() const;
	void PostorderTraversal() const;
	int TreeHeight() const;
	int TreeNodeCount() const;
	int TreeLeavesCount() const;
	void DestroyTree();
	BinaryTree(const BinaryTree<ElemType>& otherTree);
	BinaryTree();
	~BinaryTree();
protected:
	BinaryTreeNode<ElemType> *root;
private:
	void CopyTree(BinaryTreeNode<ElemType>* &copiedTreeRoot, BinaryTreeNode<ElemType>* otherTreeRoot);
	void Destroy(BinaryTreeNode<ElemType>* &p);
	void Inorder(BinaryTreeNode<ElemType> *p) const;
	void Preorder(BinaryTreeNode<ElemType> *p) const;
	void Postorder(BinaryTreeNode<ElemType> *p) const;
	int Height(BinaryTreeNode<ElemType> *p) const;
	int Max(int x, int y) const;
	// int NodeCount(BinaryTreeNode<ElemType> *p) const;
	// int LeavesCount(BinaryTreeNode<ElemType> *p) const;
};

template <class ElemType>
bool BinaryTree<ElemType>::IsEmpty() const
{
	return (root == NULL);
}

template <class ElemType>
BinaryTree<ElemType>::BinaryTree()
{
	root = NULL;
}

template <class ElemType>
void BinaryTree<ElemType>::InorderTraversal() const
{
	Inorder(root);
}

template <class ElemType>
void BinaryTree<ElemType>::PreorderTraversal() const
{
	Preorder(root);
}

template <class ElemType>
void BinaryTree<ElemType>::PostorderTraversal() const
{
	Postorder(root);
}

template <class ElemType>
int BinaryTree<ElemType>::TreeHeight() const
{
	return Height(root);
}

template <class ElemType>
int BinaryTree<ElemType>::TreeNodeCount() const
{
	return NodeCount(root);
}

template <class ElemType>
int BinaryTree<ElemType>::TreeLeavesCount() const
{
	return LeavesCount(root);
}

template <class ElemType>
void BinaryTree<ElemType>::Inorder(BinaryTreeNode<ElemType> *p) const
{
	if (p != NULL)
	{
		Inorder(p->llink);
		std::cout << p->info << " ";
		Inorder(p->rlink);
	}
}

template <class ElemType>
void BinaryTree<ElemType>::Preorder(BinaryTreeNode<ElemType> *p) const
{
	if (p != NULL)
	{
		std::cout << p->info << " ";
		Preorder(p->llink);
		Preorder(p->rlink);
	}
}

template <class ElemType>
void BinaryTree<ElemType>::Postorder(BinaryTreeNode<ElemType> *p) const
{
	if (p != NULL)
	{
		Postorder(p->llink);
		Postorder(p->rlink);
		std::cout << p->info << " ";
	}
}

template <class ElemType>
int BinaryTree<ElemType>::Height(BinaryTreeNode<ElemType> *p) const
{
	if (p == NULL)
		return 0;
	else
		return 1 + Max(Height(p->llink), Height(p->rlink));
}

template <class ElemType>
int BinaryTree<ElemType>::Max(int x, int y) const
{
	if (x >= y)
		return x;
	else
		return y;
}

template <class ElemType>
void BinaryTree<ElemType>::CopyTree(BinaryTreeNode<ElemType>* &copiedTreeRoot, BinaryTreeNode<ElemType>* otherTreeRoot)
{
	if (otherTreeRoot == NULL)
		copiedTreeRoot = NULL;
	else
	{
		copiedTreeRoot = new BinaryTreeNode<ElemType>;
		copiedTreeRoot->info = otherTreeRoot->info;
		CopyTree(copiedTreeRoot->llink, otherTreeRoot->llink);
		CopyTree(copiedTreeRoot->rlink, otherTreeRoot->rlink);
	}
}

template <class ElemType>
void BinaryTree<ElemType>::Destroy(BinaryTreeNode<ElemType>* &p)
{
	if (p != NULL)
	{
		Destroy(p->llink);
		Destroy(p->rlink);
		delete p;
		p = NULL;
	}
}

template <class ElemType>
void BinaryTree<ElemType>::DestroyTree()
{
	Destroy(root);
}

template <class ElemType>
BinaryTree<ElemType>::BinaryTree(const BinaryTree<ElemType>& otherTree)
{
	if (otherTree.root == NULL)
		root = NULL;
	else
		CopyTree(root, otherTree.root);
}

template <class ElemType>
BinaryTree<ElemType>::~BinaryTree()
{
	Destroy(root);
}

template <class ElemType>
const BinaryTree<ElemType>& BinaryTree<ElemType>::operator=(const BinaryTree<ElemType>& otherTree)
{
	if (this != &otherTree)
	{
		if (root != NULL)
			Destroy(root);
		if (otherTree.root == NULL)
			root = NULL;
		else
			CopyTree(root, otherTree.root);
	}
	else
		return *this;
}

#endif