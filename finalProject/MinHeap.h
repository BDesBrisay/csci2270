#ifndef MINHEAP_H
#define MINHEAP_H
#include <iostream>
#include <climits>

using namespace std;

struct patient {
    string name;
    int ptime;
    int dtime;
    patient () {
    };
    patient(string n, int p, int d) {
        name = n;
        ptime = p;
        dtime = d;
    }
};

class MinHeap {
    public:
        MinHeap();
        MinHeap(int);
        void MinHeapify(int);
        patient extractMin();
        void deleteNode(int);
        void insertNode(string, int, int);

        // Helper functions
        void printHeap();
        void swap(patient *a, patient *b);
        patient getMin() { return harr[0]; };
        int parent(int i) { return (i-1)/2; };
        int left(int i) { return (2*i + 1); };
        int right(int i) { return (2*i + 2); };
    private:
        patient* harr;
        int capacity;
        int heap_size;
};

#endif // MINHEAP_H