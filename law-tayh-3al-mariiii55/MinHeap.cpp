#include"MinHeap.h"
MinHeap::MinHeap(int c)
{
	Heap_size = 0;
	capacity = c;
	ptr = new int[c];
}

void MinHeap::InsertKey(int k)
{
	if (Heap_size == capacity)
	{
		cout << " Could not insert a Key" << endl;
		return;
	}
	Heap_size++;
	int i = Heap_size - 1;
	ptr[i] = k;
	while (i != 0 && ptr[parent(i)] > ptr[i])
	{
		swap(&ptr[i], &ptr[parent(i)]);
		i = parent(i);
	}

}

void MinHeap::DecreaseKey(int i, int newValue)
{
	ptr[i] = newValue;
	while (i != 0 && ptr[parent(i)] > ptr[i])
	{
		swap(&ptr[i], &ptr[parent(i)]);
		i = parent(i);
	}
}

int MinHeap::Extract_Min()
{
	if (Heap_size <= 0)
		return INT_MAX;
	if (Heap_size == 1)
	{
		Heap_size--;
		return ptr[0];
	}

	int root = ptr[0];
	ptr[0] = ptr[Heap_size - 1];
	Heap_size--;
	Heapify(0);
	return root;
}

void MinHeap::DeleteKey(int i)
{
	DecreaseKey(i, INT_MIN);
	Extract_Min();
}

void MinHeap::Heapify(int i)
{
	int L = left(i);
	int R = right(i);
	int smallest = i;
	if (L < Heap_size && ptr[L] < ptr[i])
		smallest = L;
	if (R < Heap_size && ptr[R] < ptr[smallest])
		smallest = R;
	if (smallest != i)
	{
		swap(&ptr[i], &ptr[smallest]);
		Heapify(smallest);
	}

}

void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
