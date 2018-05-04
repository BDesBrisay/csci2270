#include "MinHeap.h"
#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

MinHeap::MinHeap(int cap) {
    heap_size = 0;
    capacity = cap;
    harr = new patient[cap];
}
 
/*void MinHeap::swap(patient *a, patient *b) {
    patient temp = *a;
    *a = *b;
    *b = temp;
}*/

void MinHeap::printHeap() {
    cout << endl;
    for (int i = 0; i < heap_size; i++) {
        cout << harr[i].name << ", " << harr[i].ptime << ", " << harr[i].dtime << endl;
    }
    cout << endl;
}

// A recursive method to heapify a subtree with root at given index
// This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;
    // Check if left or right nodes have higher priority than current node
    if (l < heap_size && harr[l].ptime <= harr[i].ptime) {
        if (harr[l].ptime == harr[i].ptime) {
            if (harr[l].dtime < harr[i].dtime) smallest = l;
        }
        else  {
            smallest = l;
        }
    }
    if (r < heap_size && harr[r].ptime <= harr[smallest].ptime) {
        if (harr[r].ptime == harr[smallest].ptime) {
            if (harr[r].dtime < harr[smallest].dtime) smallest = r;
        }
        else {
            smallest = r;
        } 
    }
    // If left or right nodes are higher priority than current node, switch the two and check again
    if (smallest != i) {
        swap(harr[i], harr[smallest]);
        // Recursive function to correct tree after a change
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
       swap(harr[i], harr[parent(i)]);
       i = parent(i);
    }
    extractMin();
}
 
// Inserts a new value
void MinHeap::insertNode(string name, int p, int d) {
    if (heap_size == capacity) {
        cout << "The heap is full" << endl;
        return;
    }
 
    int i = heap_size;
    patient* newP = new patient(name, p, d);
    harr[i] = *newP;
 
    while (i != 0 && harr[parent(i)].ptime >= harr[i].ptime) {
        if (harr[parent(i)].ptime == harr[i].ptime) {
            if (harr[parent(i)].dtime > harr[i].dtime) {
                swap(harr[i], harr[parent(i)]);
                i = parent(i);
            }
            else {
                i = 0;
            }
        }
        else {
            swap(harr[i], harr[parent(i)]);
            i = parent(i);
        }
    }

    heap_size++;
}
