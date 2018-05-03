#include "MinHeap.h"
#include "PQLL.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <time.h>
#include <queue>

using namespace std;

struct compare {
    bool operator() (const patient l, const patient r) {
        // Check if p times are equal
        if (l.ptime == r.ptime) {
            // Compare d times
            return l.dtime > r.dtime;
        }
        else {
            return l.ptime > r.ptime;
        }
    }
};
 
int main() {
    priority_queue <patient, vector<patient>, compare > stlPq;
    MinHeap h(901); 
    PQLL ll;
    ifstream patientData("patientData2270.csv");
    ofstream runtime("runtime.csv");
    ofstream deletion("deletion.csv");
    ofstream heapOut("heapOut.txt");
    ofstream llOut("llOut.txt");
    ofstream stlOut("stlOut.txt");
    int i = 0;
    string line;
    clock_t t1, t2;
    // Read the header so it doesnt disrupt real data
    patientData >> line;
    // Insert header line into csv file
    runtime << "Index,  Heap Add,  LL Add,    STL Add\n";
    deletion << "Index, Heap Del,  LL Del,    STL Del\n";
    heapOut << "Rank\tpatient,  Priority,  Treatment\n";
    llOut << "Rank\tpatient,  Priority,  Treatment\n";
    stlOut << "Rank\tpatient,  Priority,  Treatment\n";


    // Run through line by line to extract data from file
    while (i <= 880) {
        stringstream ss;
        patientData >> line;
        ss << line;
        
        string name;
        string p;
        string d;
        getline(ss, name, ',');
        getline(ss, p, ',');
        getline(ss, d);

        t1 = clock();
        h.insertNode(name, stoi(p), stoi(d));
        t2 = clock();
        float heapTime = ((float)t2-(float)t1) / CLOCKS_PER_SEC;

        t1 = clock();
        ll.insertNode(name, stoi(p), stoi(d));
        t2 = clock();
        float llTime = ((float)t2-(float)t1) / CLOCKS_PER_SEC;

        t1 = clock();
        patient* newPatient = new patient(name, stoi(p), stoi(d));
        stlPq.push(*newPatient);
        t2 = clock();
        float stlTime = ((float)t2-(float)t1) / CLOCKS_PER_SEC;

        runtime << to_string(i + 1) + ',';
        runtime << to_string(heapTime) + ',';
        runtime << to_string(llTime) + ',';
        runtime << to_string(stlTime)+ '\n';

        i++;
    }

    h.printHeap();

    for (int i = 0; i < 880; i++) {
        t1 = clock();
        patient heapMin = h.extractMin();
        t2 = clock();
        float heapDel = ((float)t2-(float)t1) / CLOCKS_PER_SEC;

        t1 = clock();
        patientNode* llMin = ll.extractMin();
        t2 = clock();
        float llDel = ((float)t2-(float)t1) / CLOCKS_PER_SEC;

        patient stlMin = stlPq.top();        
        t1 = clock();
        stlPq.pop();
        t2 = clock();
        float stlDel = ((float)t2-(float)t1) / CLOCKS_PER_SEC;

        deletion << to_string(i + 1) << ',';
        deletion << to_string(heapDel) + ',';
        deletion << to_string(llDel) + ',';
        deletion << to_string(stlDel) + '\n';

        heapOut << to_string(i + 1) << ":\t" << heapMin.name << ",  " << heapMin.ptime << ",  " << heapMin.dtime << '\n';
        llOut << to_string(i + 1) << ":\t" << llMin->name << ",  " << llMin->ptime << ",  " << llMin->dtime << '\n';
        stlOut << to_string(i + 1) << ":\t" << stlMin.name << ",  " << stlMin.ptime << ",  " << stlMin.dtime << '\n';
    }

    /*
    ll.printList();

    while (!stlPq.empty()) {
        patient top = stlPq.top();
        cout << top.name << ", " << top.ptime << ", " << top.dtime << endl;
        stlPq.pop();
    }
    */

    return 0;
}