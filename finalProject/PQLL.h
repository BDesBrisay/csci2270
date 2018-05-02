#ifndef PQLL_H
#define PQLL_H
#include <iostream>

using namespace std;

struct patientNode {
    string name;
    int ptime;
    int dtime;
    patientNode* next;
    patientNode () {
    };
    patientNode(string n, int p, int d) {
        name = n;
        ptime = p;
        dtime = d;
    }
};

class PQLL {
    public: 
        PQLL();
        ~PQLL();
        void insertNode(string, int, int);
        patientNode* extractMin();
        void printList();

    private:
        patientNode* head;
        patientNode* tail;
        int size;
};

#endif // PQLL_H 