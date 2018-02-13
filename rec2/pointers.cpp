#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void resize(int* oldArray, int* capacity) {
    int newCapacity = *capacity * 2;
    int* newArray = new int[newCapacity];

    for(int i = 0; i < sizeof(oldArray); i++) {
        newArray[i] = oldArray[i];
    }

    // delete[] oldArray;
    oldArray = newArray;
    *capacity = newCapacity;
}

int main(int argc, char* argv[]) {
    if (argc != 2) return 1;
    
    int capacity = 10;
    string filename = argv[1];
    ifstream file(filename);
    string line;
    int index = 0;
    int* array = new int[capacity];

    if(file.is_open()) {
        while(getline(file, line)) {
            int number = stoi(line);

            if(index == capacity) {
                resize(array, &capacity);
            }

            array[index++] = number;
        }
    } else {
        cout << "File not open" << endl;
    }

    for(int i = 0; i < capacity; i++) {
        cout<<array[i]<<endl;
    }
}