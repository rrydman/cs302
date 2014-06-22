
void SelectionSort(int *array, int size)
{
	int min;
	int b;
	for (int a = 0; a < size - 1; a++)
	{
		b = a;
		min = array[b];
		for (int j = a + 1; j < size; j++)
		{
			if (array[j] < min)
			{
				b = j;
				min = array[b];
			}
			//switch values
			array[b] = array[a];
			array[a] = min;
		}
	}
};

template <class Comparable>
void InsertionSort(vector<Comparable> &a)
{
	int j;
	for (int p = 1; p < a.size(); p++)
	{
		Comparable temp = a[p];
		for (j = p; j>0 && temp < a[j - 1]; j--)
		{
			a[j] = a[j - 1];
		}
		a[j] = temp;
	}
};

template <class Comparable>
void ShellSort(vector<Comparable> &a)
{
	int j;
	for (int gap = a.size() / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < a.size(); i++)
		{
			Comparable temp = a[i];
			for (j = i; j >= gap && temp < a[j - gap]; j -= gap)
			{
				a[j] = a[j - gap];
			}
			a[j] = temp;
		}
	}
};

/* quick sort */
template <class Comparable>
const Comparable &median(vector<Comparable> &a, int left, int right)
{
	int center = (left + right) / 2;
	if (a[center] < a[left])
	{
		swap(a[left], a[center]);
	}
	if (a[right] < a[left])
	{
		swap(a[left], a[right]);
	}
	if (a[right] < a[center])
	{
		swap(a[center], a[right]);
	}
	// Place pivot at position right
	swap(a[center], a[right]);
	return a[right];
};

template <class Comparable>
void QuickSort(vector<Comparable> &a, int left, int right)
{
	if (left + 10 <= right)
	{
		Comparable pivot = median(a, left, right);
		int i = left; 
		int j = right; // bug? right-1
		for (;;)
		{
			while (a[++i] < pivot){};
			while (pivot < a[--j]){};
			if (i < j) // bug?
			{
				swap(a[i], a[j]); 
			}
			else
			{
				break;
			}
			// restore pivot
			swap(a[i], a[right]); // bug? right-1
			QuickSort(a, left, i - 1);
			QuickSort(a, i + 1, right);
		}
	}
	else
	{
		InsertionSort(a, left, right);
	}
};

/* heap sort */
/* starting at position 0 */

/* return index of left child */
int LeftChild(int i)
{
	return 2 * i + 1;
};

/* delete max and build heap */
/* i is the position to percolate down */
/* n is the size of the heap */
template <class Comparable>
void PercolateDown(vector<Comparable> &a, int i, int n)
{
	int child;
	Comparable temp;
	for (temp = a[i]; LeftChild(i) < n; i = child)
	{
		child = LeftChild(i);
		if (child != n - 1 && a[child] < a[child + 1])
		{
			child++
		}
		if (temp < a[child])
		{
			a[i] = [child];
		}
		else
		{
			break;
		}
	}
	a[i] = temp;
};

/* heapsort */
template <class Comparable>
void HeapSort(vector<Comparable> &a)
{
	/* build the heap */
	for (int i = a.size() / 2; i >= 0; i--)
	{
		PercolateDown(a, i, a.size());
	}
	/* deletemax*/
	for (int j = a.size() - 1; j > 0; j--)
	{
		swap(a[0], a[j]);
		PercolateDown(0, 0, j);
	}
};


