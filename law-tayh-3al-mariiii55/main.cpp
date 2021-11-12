#include<iostream>
#include "MinHeap.h"
using namespace std;
int main()
{
	MinHeap h(11);
	h.InsertKey(3);
	h.InsertKey(2);
	h.DeleteKey(1);
	h.InsertKey(15);
	h.InsertKey(5);
	h.InsertKey(4);
	h.InsertKey(45);
	cout << h.Extract_Min() << " ";
	cout << h.Get_Min() << " ";
	h.DecreaseKey(2, 1);
	cout << h.Get_Min();
	return 0;
}