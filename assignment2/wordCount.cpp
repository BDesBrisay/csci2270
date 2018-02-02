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

/*
I could not get this function to properly work. It would populate the array but the
isStopWord function was never able to properly compare a string to a string. In order to get
around this I hard coded the ignoreWords array

void getStopWords(string filename, string ignore[]) {
    ifstream infile(filename);
    string line;
    int index = 0;

    if (infile.is_open()) {
        while(getline(infile, line)) {
            ignore[index] = line;
            index++;
        }
    }

    infile.close();
}
*/

bool isStopWord(string word, string ignoreWords[]) {
    for (int i = 0; i < 50; i++) {
        if (strcmp(word.c_str(), ignoreWords[i].c_str()) == 0) return true;
    }
    return false;
}

void printTopN(word wordList[], int topCount) {
    for (int i = 0; i < topCount; i++) {
        cout << wordList[i].count << " - " << wordList[i].word << endl;
    }
}

void arraySort(word wordList[], int length) {
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length - 1; j++) {
            if (wordList[i].count < wordList[i + 1].count) {
                word tempWord = wordList[i];
                wordList[i] = wordList[i + 1];
                wordList[i + 1] = tempWord;
            }
        }
    }
}

int getNonStopWordTotal(word wordList[], int length) {
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (wordList[i].word != "") {
            count++;
        }
    }
    return count;
}

void addWord(word wordList[], string word, int length, int* unique) {
    for (int i = 0; i < length; i++) {
        if(wordList[i].word == word) {
            wordList[i].count++;
        } else if (wordList[i].word == "") {
            wordList[i].word = word;
            wordList[i].count = 1;
            *unique++;
            break;
        }
    }
}

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
    string ignoreWords[] = {"the","be","to","of","and","a","in","that","have","i","it","for","not","on","with","he","as","you","do","at","this","but","his","by","from","they","we","say","her","she","or","an","will","my","one","all","would","there","their","what","so","up","out","if","about","who","get","which","go", "me"};

    ifstream book(filename);

    // getStopWords(ignoreFile, ignoreWords);

    if (book.is_open()) {
        while(getline(book, line, ' ')) {
            if(index == size) {
                words = resize(words, &size);
                doublings++;
            }
            if(!isStopWord(line, ignoreWords) && (line != " ")) {
                addWord(words, line, size, &uniqueWords);
                totalWords++;
            }
        }
    } else {
        cout << "Files did not open correctly." << endl;
    }

    printTopN(words, topCount);
    cout << "#" << endl;
    cout << "Array Doubled: " << doublings << endl;
    cout << "#" << endl;
    cout << "Unique non-common words: " << uniqueWords << endl;
    cout << "#" << endl;
    cout << "Total non-common words: " << totalWords << endl;
}
