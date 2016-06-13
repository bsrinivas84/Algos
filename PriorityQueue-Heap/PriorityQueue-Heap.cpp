// PriorityQueue-Heap.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Common.h"
#include<iostream>"
using namespace std;

int main()
{
	MinHeap h(11);
	h.insertKey(3);
	h.insertKey(2);
	h.deleteKey(1);
	h.insertKey(15);
	h.insertKey(5);
	h.insertKey(4);
	h.insertKey(45);
	cout << h.extractMin() << " ";
	cout << h.getMin() << " ";
	h.decreaseKey(2, 1);
	cout << h.getMin();
	getchar();
	return 0;
}

