#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

using namespace std;

struct word {
    string word;
    int count;
};

void resize(word* array, int* size) {
    size_t newSize = *size * 2;
    word* newArray = new word[newSize];

    for(int i = 0; i < sizeof(array); i++) {
        newArray[i] = array[i];
    }

    *size = newSize;
    delete[] array;
    array = newArray;
}

int main(int argc, char * argv[]) {
    if (argc < 4) return 1;

    int topCount = stoi(argv[1]);
    string filename = argv[2];
    string ignoreFile = argv[3];
    int size = 100;
    word* words = new word[100];
    string line;
    int index = 0;

    ifstream book(filename);
    ifstream ignore(ignoreFile);

    if (book.is_open() && ignore.is_open()) {
        while(getline(book, line)) {
            if(index == size) {
                resize(words, &size);
            }
            if(index < 100) {
                words[index++].word = line;
            }
        }
    } else {
        cout << "Files did not open correctly." << endl;
    }

    /*for(int i = 0; i < size; i++) {
        cout << words[i].word << endl;
    }*/
}
