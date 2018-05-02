#include "PQLL.h"

using namespace std;

PQLL::PQLL() {
    head = nullptr;
    tail = nullptr;
    size = 0;
};

PQLL::~PQLL() {
    head = nullptr;
    tail = nullptr;
};

void PQLL::printList() {
    patientNode* place = head;

    while (place != nullptr) {
        cout << place->name << ", " << place->ptime << ", " << place->dtime << endl;
        place = place->next;
    }
};

void PQLL::insertNode(string name, int p, int d) {
    patientNode* newNode = new patientNode(name, p, d);
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = tail->next;
    }
};

patientNode* PQLL::extractMin() {

};
