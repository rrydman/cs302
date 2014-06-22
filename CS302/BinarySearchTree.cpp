#include "BinaryTree.cpp"

/* template */
template <class Comparable>
class BinarySearchTree{
public:
	BinarySearchTree();
	BinarySearchTree(const BinarySearchTree &rhs);
	~BinarySearchTree();
	/* Public member function will call the private recursive function */

	const Comparable &find(const Comparable &x) const; // last const means cant change members of class - first means cant change the tree
	const Comparable &findMax() const;
	const Comparable &findMin() const;
	bool isEmpty() const;
	void printTree() const;
	void makeEmpty();
	void insert(const Comparable &x);
	void remove(const Comparable &x);
	void print_inorder(BinaryNode<Comparable> *P);
	void print_postorder(BinaryNode<Comparable> *P);
private:
	BinaryNode<Comparable> *root;
	const Comparable ITEM - NOT - FOUND;
	const Comparable &elementAt(BinaryNode<Comparable> *t) const;
	void insert(const Comparable &x, BinaryNode<Comparable> *&t);
	void remove(const Comparable &x, BinaryNode<Comparable> *&t);
	BinaryNode<Comparable> *find(const Comparable &x, BinaryNode<Comparable> *t) const; // make note
	BinaryNode<Comparable> *findMax(BinaryNode<Comparable> *t);
	BinaryNode<Comparable> *findMin(BinaryNode<Comparable> *t);
};

/* find item x in the tree */
/* public to get element in node t */
template<class Comparable>
const Comparable &BinarySearchTree<Comparable>::find(const Comparable &x) const{
	return elementAt(find(x, root));
};

template<class Comparable>
const Comparable &BinarySearchTree<Comparable>::elementAt(BinaryNode<Comparable> *t) const{
	return t == NULL ? ITEM - NOT - FOUND : t->element;
};

/* private Find */
/* t represents current node (root on first recursive call) */
template <class Comparable>
Comparable BinaryNode<Comparable>::find(const Comparable &x, BinaryNode<Comparable> *t) const{
	if (t == NULL) return NULL;
	else if (x < t->element)
		return find(x, t->left);
	else if (x > t->element)
		return find(x, t->right);
	else
		return t;
};

/* private findMin */
template <class Comparable>
Comparable BinaryNode<Comparable>::findMin(BinaryNode<Comparable> *t) const{
	if (t == NULL)
		return NULL;
	if (t->left == NULL)
		return t;
	return findMin(t->left);
};

/* private findMax */
template <class Comparable>
Comparable BinaryNode<Comparable>::findMax(BinaryNode<Comparable> *t) const{
	if (t == NULL)
		return NULL;
	if (t->right == NULL)
		return t;
	return findMax(t->right);
};

/* private insert
	x is the element
	t is the node that roots the tree */
/* implementation depends on how you handle duplicates - if not allowed then do not insert once found */
template <class Comparable>
void BinarySearchTree<Comparable>::insert(const Comparable &x, BinaryNode<Comparable> *&t){
	if (t = NULL)
		t = new BinaryNode<Comparable>(x, NULL, NULL);
	else if (x < t->element) insert(x, t->left);
	else if (x > t->element) insert(x, t->right);
	else; // duplicate , do nothing
};

/* ----------------------------------- */
/* delete -- three cases
	only a leaf - easy just change parent ptr to null and delete leaf
	one child - easy just change parent ptr to point to child then delete node
	two children - go into sub tree, find smallest element, swap with parent , recursively delete
	*/

/* remove x from the tree rooted at t */
template <class Comparable>
void BinarySearchTree<Comparable>::remove(Const Comparable &x, BinaryNode<Comparable> *&t)
{
	if (t == NULL) return; // Item not found in tree
	if (x < t->element)
	{
		remove(x, t->left); // recursively searches for x
	}
	else if (x>t->element)
	{
		remove(x, t->right); // recursively searches for x
	}
	else if (t->left != NULL && t->right != NULL) // case 3: node has two children
	{
		t->element = findMin(t->right)->element; // find smallest element
		remove(t->element, t->right); // remove element from t->right
	}
	else // case 1/2: node has only one child
	{	
		BinaryNode<Comparable> *oldNode = t; // new pointer named oldNode
		t = (t->left != NULL) ? t->left : t->right;
		delete oldNode;
	}
};

/* print tree - prints as an ascending sorted list (L,N,R) */
template <class Comparable>
void print_inorder(BinaryNode<Comparable> *P)
{
	if (P != NULL)
	{
		print_inorder(P->left); // print leftsubtree
		cout << P->element << endl; // print this node
		print_inorder(P->right); // print right subtree
	}
};

/* print tree - prints as post order (L,R,N) */
/* prints all leafs of a node before printing the parent node */
/* prints in same order as postfix notation */
template <class Comparable>
void print_postorder(BinaryNode<Comparable> *P)
{
	if (P != NULL)
	{
		print_postorder(P->left); // print leftsubtree
		print_postorder(P->right); // print right subtree
		cout << P->element << endl; // print this node
	}
};
