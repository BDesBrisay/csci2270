#include "MinHeap.h"
#include <iostream>

using namespace std;
 
int main() {
    MinHeap h(10); 
    
    for (int i = 0; i < 10; i++) {
        patient* newP = new patient("Sally",i,1+10);
        h.insertNode(*newP);
    }

    for (int i = 3; i < 8; i++) {
        h.deleteNode(i);
    }

    for (int i = 10; i < 20; i++) {
        patient* newP = new patient("Sally",i,1+10);
        h.insertNode(*newP);
    }

    h.printHeap();
    h.extractMin();
    h.printHeap();
    return 0;
}