#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

using namespace std;

struct word {
    string word;
    int count;
};

word* resize(word* array, int* size) {
    int newSize = *size * 2;
    word* newArray = new word[newSize];

    for(int i = 0; i < *size; i++) {
        newArray[i] = array[i];
    }

    delete [] array;
    *size = newSize;
    array = newArray;
    return array;
}

void getStopWords(string filename, string ignoreWords[]) {
    ifstream file(filename);
    string line;
    int index = 0;

    if(file.is_open()) {
        while(getline(file, line)) {
            ignoreWords[index] = line;
            index++;
        }
    } else {
        cout << "Ignore words file not open." << endl;
    }
}

bool isStopWord(string word, string ignoreWords[]) {
    for (int i = 0; i < 50; i++) {
        if (ignoreWords[i] == word) return true;
    }
    return false;
}

void printTopN(word wordList[], int topCount) {

}

void arraySort(word wordList[], int length) {

}

/*int getNonStopWordTotal(word wordList[], int length) {

}*/

int main(int argc, char * argv[]) {
    if (argc < 4) return 1;

    int topCount = stoi(argv[1]);
    string filename = argv[2];
    string ignoreFile = argv[3];
    int doublings = 0;
    int uniqueWords = 0;
    int totalWords = 0;
    int size = 100;
    word* words = new word[size];
    string line;
    int index = 0;
    string ignoreWords[50];

    ifstream book(filename);

    getStopWords(ignoreFile, ignoreWords);

    if (book.is_open()) {

        while(getline(book, line, ' ')) {
            if(index == size) {
                words = resize(words, &size);
                doublings++;
            }
            words[index].word = line;
            index++;
        }
    } else {
        cout << "Files did not open correctly." << endl;
    }

    cout << ignoreWords[48] << endl;
    cout << isStopWord("go", ignoreWords) << endl;
    cout << isStopWord("which", ignoreWords) << endl;
    cout << isStopWord("me", ignoreWords) << endl;
    cout << isStopWord("if", ignoreWords) << endl;
    cout << isStopWord("me", ignoreWords) << endl;
}
