#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream file("ignoreWords.txt");
    string line;
    string ignoreWords[50];
    int index = 0;

    while(getline(file, line)) {
        ignoreWords[index++] = line;
    }

    for (int i = 0; i < 50; i++) {
        cout << ignoreWords[i] << endl;
    }
}