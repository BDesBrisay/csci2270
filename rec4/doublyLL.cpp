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
    Node* place = head;

    while (place != nullptr) {
        if (place->key == a && place->next != nullptr && place->prev != nullptr) {
            place->prev->next = place->next;
            place->next->prev = place->prev;
            place = place->next;
        } else if (place->key == a && place->next == nullptr) {
            place->prev->next = nullptr;
            tail = place->prev;
            place = nullptr;
        } else if (place->key == a && place->prev == nullptr) {
            place->next->prev = nullptr;
            place = place->next;
            head = place;
        } else {
            place = place->next;
        }
    }
}

void doublyLL::printList() {
    Node* place = head;

    cout << "Head and Tail: " << head->key << ", " << tail->key << endl;

    while (place != nullptr) {
        cout << place->key << endl;
        place = place->next;
    }
}

doublyLL::doublyLL() {
    head = nullptr;
    tail = nullptr;
}

doublyLL::doublyLL(int a) {
    Node* temp = new Node;
    temp->key = a;
    temp->prev = nullptr;
    temp->next = nullptr;
    head = temp;
}

doublyLL::~doublyLL() {

}
