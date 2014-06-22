template <class Comparable>
class BinaryHeap{
public:
	BinaryHeap(int capacity = 100);
	bool isEmpty() const;
	const Comparable &findMin() const;
	void insert(const Comparable &x);
	void deleteMin(Comparable &minItem);
	void makeEmpty();
private:
	int currentsize;
	vector<Comparable> array; //heap
	void buildHeap();
	void percolateDown(int hole);
};

/* insert */
template <class Comparable>
void BinaryHeap<Comparable>::insert(const Comparable &x)
{
	if (isFull())
		throw overflow();
	// percolate up - creates new leaf node and trades places with parent(s) if parent(s) are larger
	int hole = ++currentsize;
	for (; hole > 1 && x < array[hole / 2]; hole /= 2)
		array[hole] = array[hole / 2];
	array[hole] = x;
};

