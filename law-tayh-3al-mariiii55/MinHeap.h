#pragma once
#include <iostream>
#include <climits>
using namespace std;
void swap(int* x, int* y);
class MinHeap
{
	int* ptr;
	int capacity;
	int Heap_size;
public:
	MinHeap(int capacity);
	void Heapify(int);
	int parent(int i) { return (i - 1) / 2; }
	int left(int i) { return (2 * i + 1); }
	int right(int i) { return (2 * i + 2); }
	int Extract_Min();
	void DecreaseKey(int i, int newValue);
	int Get_Min() { return ptr[0]; }
	void DeleteKey(int i);
	void InsertKey(int key);
};
