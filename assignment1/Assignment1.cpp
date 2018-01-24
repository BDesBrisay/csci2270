// CSCI 2270 - Data Structures
// Author: Bryce DesBrisay
// Assignment 1
// Instructor: Hoenigman

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// made struct
struct Item {
    string type;
    bool status;
    int price;

    Item() {}
    Item(string t, bool s, int p) {
        type = t;
        status = s;
        price = p;
    }
};

// finds first empty item in array and returns index
int findEmpty(Item array[]) {
    int index;
    for(int i = 0; i < 100; i++) {
        if(array[i].type == "") {
            index = i;
            break;
        }
    }
    return index;
}

// finds a match for an item in the board through multiple conditionals
int search(Item array[], Item key) {
    int index = -1;
    for(int i = 0; i < 100; i++) {
        if(array[i].type == key.type && (array[i].status != key.status)) {
            if(key.status == 0 && key.price <= array[i].price) {
                index = i;
                break;
            } else if(key.status == 1 && key.price >= array[i].price) {
                index = i;
                break;
            }
        }
    }
    return index;
} 

// reads lines of file and processes them accordingly
void readLines(string filename, Item array[]) {
    ifstream file(filename);
    string line;
    int sold;

    if(file.is_open()) {
        while(getline(file, line)) {
            stringstream ss;
            ss << line;

            // extracts values out of each line into variable
            Item value;
            string tempStatus;
            string tempPrice;
            getline(ss, value.type, ',');
            getline(ss, tempStatus, ',');
            getline(ss, tempPrice);

            // converts string price to int
            value.price = stoi(tempPrice);

            // converts text status to bool
            if(tempStatus == " wanted") {
                value.status = 1;
            } else {
                value.status = 0;
            };

            // condtional if match is found
            int arrayIndex = search(array, value);
            if(arrayIndex != -1) {
                Item soldItem = array[arrayIndex];
                int soldPrice;

                // gets price that item is sold at
                if(value.status == 0) {
                    soldPrice = value.price;
                } else {
                    soldPrice = array[arrayIndex].price;
                }

                // removes sold/bought item from array by shifting every item after what was removed
                for(int i = arrayIndex; i < 99; i++) {
                    array[i] = array[i + 1];
                }

                cout<<soldItem.type<<" "<<soldPrice<<endl;
            } else {
                // finds first empty solt and populates it
                int emptyIndex = findEmpty(array);
                array[emptyIndex] = value;
            }
        }
    } else {
        cout<<"File did not open"<<endl;
    }
}

int main(int argc, char* argv[]) {
    Item board[100];

    // Reads file lines and prints out sold items
    readLines(argv[1], board);
    cout<<"#"<<endl;
    
    // Prints remaining items on message board
    for(int i = 0; i < 100; i++) {
        if(board[i].type != "") {
            if(board[i].status == 1) {
                cout<<board[i].type<<", wanted, "<<board[i].price<<endl;
            } else {
                cout<<board[i].type<<", for sale, "<<board[i].price<<endl;
            }
        }
    }
    cout<<"#"<<endl;
};