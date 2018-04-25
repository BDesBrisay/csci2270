#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <time.h>
#include <vector>

using namespace std;

#define ALPHABET_SIZE 26

struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;
    // Addition to count occurences 
    int wordCount;
};

class Trie {
    public:
        Trie();
        ~Trie();
        void insert(string);
        int search(string);
        struct TrieNode* root;
};

Trie::Trie() {
    root = new TrieNode;
    root->isEndOfWord = false;
    root->wordCount = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        root->children[i] = NULL;
    }
}

Trie::~Trie() {}

void Trie::insert(string word) {

    /* Start from the root  */
    struct TrieNode* pt = root;
 
    /* Iterate over all letters in the word  */
    for (int i = 0; i < word.length(); i++) {
        int index = word[i] - 'a';
        if (word[i] < 'a' || word[i] > 'z') continue;
        if (pt->children[index] == NULL) {
            struct TrieNode* newnode = new TrieNode;
            newnode->isEndOfWord = false;
            for (int i = 0; i < ALPHABET_SIZE; i++) newnode->children[i] = NULL;
            pt->children[index] = newnode; 
        }
    
        pt = pt->children[index];
    }
 
    /* Once we finish iterating over the word,
        we can mark the node of the last letter
        as "end of the word".
      */
    pt->isEndOfWord = true;
    pt->wordCount++;
}

int Trie::search(string word) {
    struct TrieNode* pt = root;
 
    /*
    Starting from the root,
    we iterate over all the letters of this word.
    */
    for (int i = 0; i < word.length(); i++){
        int index = word[i] - 'a';
        if (word[i] < 'a' || word[i] > 'z') continue;
        if (pt->children[index] == NULL) return -1;
        pt = pt->children[index];
    }
 
    /*
    At this point, we finish iterating the word.
    Does that mean we've found this word?
    What additional condition should we check?
    */
 
    if (pt != NULL && pt->isEndOfWord) return pt->wordCount;
    else return -1;

}


void array_insert(string word, vector<string>& vocabulary, vector<int>& counter) {

    for (int i = 0; i < vocabulary.size(); ++i) {
        if (word == vocabulary[i]) {
            counter[i] += 1;
            return;
        }
    }

    vocabulary.push_back(word);
    counter.push_back(1);
    return;
}


int array_search(string word, vector<string>& vocabulary, vector<int>& counter) {

    for (int i = 0; i < vocabulary.size(); ++i) {
        if (word == vocabulary[i]) {
            return counter[i];
        }
    }

    return -1;
}

int main(int argc, char const *argv[]) {
    

    /* Create a trie  */
    Trie the_trie;

    /* Read in file  */
    ifstream handle;
    handle.open(argv[1]);
    string line;
    string word;
    while(getline(handle, line, '\n')) {

        stringstream sp(line);
        while (getline(handle, word, ' ')) {
            the_trie.insert(word);
        }
    }

    handle.close();


    clock_t t1, t2;
    t1 = clock();
    std::cout << "     the: " << the_trie.search("the");
    t2 = clock();
    std::cout << " | Run time: " << ((float)t2-(float)t1) / CLOCKS_PER_SEC << " s" << endl;

    t1 = clock();
    std::cout << "    there: " << the_trie.search("there");
    t2 = clock();
    std::cout << " | Run time: " << ((float)t2-(float)t1) / CLOCKS_PER_SEC << " s" << endl;

    t1 = clock();
    std::cout << "therefore: " << the_trie.search("therefore");
    t2 = clock();
    std::cout << " | Run time: " << ((float)t2-(float)t1) / CLOCKS_PER_SEC << " s" << endl;


    /* Array implementation  */

    handle.open(argv[1]);
    vector<string> vocab;
    vector<int> counter;

    while(getline(handle, line, '\n')) {

        stringstream sp(line);
        while (getline(handle, word, ' ')) {
            if (word[0] == '\n') word = word.substr(1);
            array_insert(word, vocab, counter);
        }
    }

    handle.close();

    t1 = clock();
    std::cout << "      the: " << array_search("the", vocab, counter);
    t2 = clock();
    std::cout << " | Run time: " << ((float)t2-(float)t1) / CLOCKS_PER_SEC << " s" << endl;

    t1 = clock();
    std::cout << "    there: " << array_search("there", vocab, counter);
    t2 = clock();
    std::cout << " | Run time: " << ((float)t2-(float)t1) / CLOCKS_PER_SEC << " s" << endl;

    t1 = clock();
    std::cout << "therefore: " << array_search("therefore", vocab, counter);
    t2 = clock();
    std::cout << " | Run time: " << ((float)t2-(float)t1) / CLOCKS_PER_SEC << " s" << endl;


    return 0;
}