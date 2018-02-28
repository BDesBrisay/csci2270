#include "Queue.h"
#include <iostream>
#include <sstream>

using namespace std;

Queue::Queue(int qs) {
    queueSize = qs;
    arrayQueue = new string[queueSize];
    queueHead = 0;
    queueTail = 0;
    queueCount = 0;
}
Queue::~Queue() {
    delete [] arrayQueue;
    arrayQueue = nullptr;
}

void Queue::enqueue(string item) {
    if (!queueIsFull()) {
        arrayQueue[queueTail] = item;
        queueCount++;

        int tempTail = queueTail + 1;
        if (tempTail == queueSize) {
            tempTail = 0;
        }
        queueTail = tempTail;
        
        if (queueHead == -1) {
            queueHead = 0;
        }

        cout << "E: " << item << endl;
        cout << "H: " << queueHead << endl;
        cout << "T: " << queueTail << endl;
    } else {
        cout << "Queue is full." << endl;
    }
}

void Queue::dequeue() {
    if (!queueIsEmpty()) {
        string word = arrayQueue[queueHead];
        if (queueHead == queueSize - 1) {
            queueHead = -1;
        }
        cout << "H: " << queueHead+1 << endl;
        cout << "T: " << queueTail << endl;
        cout << "word: " << word << endl;
        string item = arrayQueue[queueHead];
        queueCount--;
        queueHead++;
        
        if (queueIsEmpty()) {
            queueHead = queueTail = -1;
        }
    } else {
        cout << "Queue is empty." << endl;
    }
}

void Queue::printQueue() {
    if (queueCount > 0) {
        int i = queueHead;
        do {
            cout << i << ": " << arrayQueue[i] << endl;
            i = (i+1) % queueSize;
        } while (i != queueTail);
    } else {
        cout << "Empty" << endl;
    }
}

void Queue::enqueueSentence(string item) {
    string word;
    stringstream ss;
    ss << item;
    while (getline(ss, word, ' ')) {
        enqueue(word);
    }
}

bool Queue::queueIsFull() {
    if (queueCount == queueSize) return true;
    return false; 
}

bool Queue::queueIsEmpty() {
    if (queueCount == 0 || (queueHead == -1 && queueTail == -1)) return true;
    return false;
}