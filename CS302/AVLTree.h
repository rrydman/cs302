// AVL Node has 4 pieces to it

template <class Comparable>
class AVLTree
{};

template <class Comparable>
class AVLNode
{
	Comparable element;
	int height;
	AVLNode *left;
	AVLNode *eight;
	AVLNode(const Comparable &theElement, int h = 0, AVLNode *lt, AVLNode *rt){};
	friend class AVLTree<Comparable>; // bug? might need to be something other than Comparable
};

/* return height of node t, or -1 if Null */
template <class Comparable>
int AVLTree<Comparable>::height(AVLNode<Comparable> *t) const
{
	return t == NULL ? -1 : t->height;
};

// LL
template <class Comparable>
void AVLTree<Comparable>::rotateWithLeft(AVLNode<Comparable> *&k2)
{
	AVLNode<Comparable> *k1 = k2->left;
	k2->left = k1->right;
	k1->right = k2;
	k2->height = max(height(k2), height(K2->right)) + 1;
	k1->height = max(height(k1->left), k2->height) + 1;
	k2 = k1;
};

// RR - may be wrong
template <class Comparable>
void AVLTree<Comparable>::rotateWithRight(AVLNode<Comparable> *&k2)
{
	AVLNode<Comparable> *k1 = k2->right;
	k2->right = k1->left;
	k1->left = k2;
	k2->height = max(height(k2), height(K2->left)) + 1;
	k1->height = max(height(k1->right), k2->height) + 1;
	k2 = k1;
};

/* double rotation - LR */
template <class Comparable>
void AVLTree<Comparable>::doubleWithLeftChild(AVLNode<Comparable> *&k3)
{
	rotateWithRight(k3->left);
	rotateWithLeft(k3);
};

/* double rotation - RL */
template <class Comparable>
void AVLTree<Comparable>::doubleWithRightChild(AVLNode<Comparable> *&k3)
{
	rotateWithLeft(k3->right); // may need to swap these two func parameters
	rotateWithRight(k3);
};

/* insert */
template <class Comparable>
void AVLTree<Comparable>::insert(const Comparable &x, AVLNode<Comparable> *&t)
{
	if (t == NULL)
	{
		t = new AVLNode<Comparable>(x, 0, NULL, NULL);
	}
	else if (x < t->element)
	{
		insert(x, t->left);
		if (height(t->left) - height(t->right) == 2)
		{
			if (x < t->left->element)
			{
				rotateWithLeft(t); // LL
			}
			else
			{
				doubleWithLeftChild(t); // LR
			}
		}
	}
	else if (x > t->element)
	{
		insert(x, t->right);
		if (height(t->right) - height(t->left) == 2)
		{
			if (t->right->element < x)
			{
				rotateWithRight(t); // RR
			}
			else
			{
				doubleWithRightChild(t); // RL
			}
		}
	}
	else; // Duplicate
	t->height = max(height(t->left), height(t->right)) + 1;
};