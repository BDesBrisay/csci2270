#include "MinHeap.h"
#include <iostream>
#include <climits>

using namespace std;

MinHeap::MinHeap(int cap) {
    heap_size = 0;
    capacity = cap;
    harr = new patient[cap];
}
 
void MinHeap::swap(patient *a, patient *b) {
    patient temp = *a;
    *a = *b;
    *b = temp;
}

void MinHeap::printHeap() {
    cout << endl;
    for (int i = 0; i < heap_size; i++) {
        cout << harr[i].ptime << " ";
    }
    cout << endl;
}

// A recursive method to heapify a subtree with root at given index
// This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l].ptime < harr[i].ptime) smallest = l;
    if (r < heap_size && harr[r].ptime < harr[smallest].ptime) smallest = r;
    if (smallest != i) {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}

// Method to remove minimum element (or root) from min heap
patient MinHeap::extractMin() {

    if (heap_size <= 0) return patient("x", 30,40);
    if (heap_size == 1) {
        heap_size--;
        return harr[0];
    }
 
    // Store the minimum value, and remove it from heap
    patient root = harr[0];
    harr[0] = harr[heap_size-1];
    heap_size--;
    MinHeapify(0);
 
    return root;
}
 
// This function deletes key at index i. It first reduced value to minus
// infinite, then calls extractMin()
void MinHeap::deleteNode(int i) {
    harr[i].ptime = INT_MIN;
    while (i != 0 && harr[parent(i)].ptime > harr[i].ptime) {
       swap(&harr[i], &harr[parent(i)]);
       i = parent(i);
    }
    extractMin();
}
 
// Inserts a new value
void MinHeap::insertNode(patient newP) {
    if (heap_size == capacity) {
        cout << "The heap is full" << endl;
        return;
    }
 
    int i = heap_size;
    heap_size++;
    harr[i] = newP;
 
    while (i != 0 && harr[parent(i)].ptime > harr[i].ptime) {
       swap(&harr[i], &harr[parent(i)]);
       i = parent(i);
    }
}
