#include <iostream>
#include "Queue.h"

using namespace std;

int main() {
    Queue a(10);

    a.printQueue();
    a.enqueue("Hello");
    a.printQueue();
    a.enqueueSentence(", World! How is it going");
}