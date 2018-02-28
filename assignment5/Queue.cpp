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
    int count = queueCount;

    if (count >= 0 && count < queueSize) {
        arrayQueue[count] = item;
        queueCount++;
        queueTail = queueCount;
        cout << "E: " << arrayQueue[count] << endl;
        cout << "H: " << queueHead << endl;
        cout << "T: " << queueTail << endl;
    } else if (count == queueSize) {
        cout << "Queue Full" << endl;
    }
}

void Queue::dequeue() {
    int place = queueHead;

    if (place == queueTail - 1) {
        cout << "Queue Empty" << endl;
    } else if (queueCount > 0) {
        queueHead++;
        queueSize++;
        cout << "H: " << queueHead << endl;
        cout << "T: " << queueTail << endl;
        cout << "word: " << arrayQueue[place] << endl;
    }
}

void Queue::printQueue() {
    int count = queueCount;

    if (count > 0) {
        for (int i = queueHead; i < count; i++) {
            cout<<i+1<<": "<<arrayQueue[i]<<endl;
        }
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

}

bool Queue::queueIsEmpty() {

}