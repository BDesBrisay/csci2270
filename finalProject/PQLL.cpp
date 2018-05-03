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
    patientNode* place = head;
    patientNode* newNode = new patientNode(name, p, d);
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } 
    else if (head->ptime >= p) {
        if (head->ptime == p) {
            if (head->dtime > d) {
                newNode->next = head;
                head = newNode;
            }
            else {
                newNode->next = head->next;
                head->next = newNode;
            }
        } 
        else {
            newNode->next = head;
            head = newNode;
        }
    } 
    else {
        while (place->next != nullptr && place->next->ptime < p) {
            place = place->next;
        }

        if (place->next != nullptr && place->next->ptime == p) {
            if (place->next->dtime > d) {
                newNode->next = place->next;
                place->next = newNode;
            }
            else {
                newNode->next = place->next->next;
                place->next->next = newNode;
            }
        } 
        else {
            newNode->next = place->next;
            place->next = newNode;
        }
    }

    size++;
};

patientNode* PQLL::extractMin() {

};
