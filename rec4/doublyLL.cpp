#include "doublyLL.h"

using namespace std;

bool doublyLL::insertNodeAtEnd(int a) {
    Node* temp = new Node;
    temp->key = a;
    temp->prev = nullptr;
    temp->next = nullptr;

    if (head == nullptr) {
        head = temp;
        tail = temp;
    } else {
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }
}

bool doublyLL::deleteNode(int a) {

}

void doublyLL::printList() {
    Node* place = head;

    while (place != nullptr) {
        cout << place->key << endl;
        place = place->next;
    }
}

doublyLL::doublyLL() {

}

doublyLL::doublyLL(int) {
 
}

doublyLL::~doublyLL() {

}
