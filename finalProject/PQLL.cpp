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
    // Check if head ptime is greater than new ptime
    else if (head->ptime >= p) {
        // Check if head ptime is equal to new ptime so you can compare dtime
        if (head->ptime == p) {
            // Comparing dtimes for elements with equal ptimes
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
        // Find node next to position of new node
        while (place->next != nullptr && place->next->ptime < p) {
            place = place->next;
        }

        if (place->next != nullptr) {
            if (place->next->ptime == p) {
                // Comparing dtimes for elements with equal ptimes
                if (place->next->dtime > d) {
                    newNode->next = place->next;
                    place->next = newNode;
                }
                else {
                    while (place->next != nullptr && place->next->ptime == p && place->next->dtime < d) {
                        place = place->next;
                    }
                    newNode->next = place->next;
                    place->next = newNode;
                }
            }
            else {
                newNode->next = place->next;
                place->next = newNode;
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
    patientNode* min = head;
    head = head->next;
    return min;
};
