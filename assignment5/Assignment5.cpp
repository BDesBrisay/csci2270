#include <iostream>
#include "Queue.h"

using namespace std;

void displayMenu() {
    int valid = 0;
    string input;
    string line;
    Queue q(10);

    while (!valid) {
        cout << "======Main Menu=====" << endl;
        cout << "1. Enqueue word" << endl;	
        cout << "2. Dequeue word" << endl;
        cout << "3. Print queue" << endl;
        cout << "4. Enqueue sentence" << endl;
        cout << "5. Quit" << endl;
        cin >> input;

        try {
            int selection = stoi(input);
            if (selection >= 1 && selection <= 5) {
                if (selection == 1) {
                    cout << "word: ";
                    cin >> line;
                    q.enqueue(line);
                } else if (selection == 2) {
                    q.dequeue();
                } else if (selection == 3) {
                    q.printQueue();
                } else if (selection == 4) {
                    string sentence;
                    cout << "sentence: ";
                    cin.ignore(1000, '\n');
                    getline(cin, sentence);
                    q.enqueueSentence(sentence);
                } else if (selection == 5) {
                    cout << "Goodbye!" << endl;
                    valid = 1;
                }
            } else throw invalid_argument("Invalid number");
        } catch(invalid_argument& e) {
            cout << "Please enter a valid number." << endl;
        }
    }
}

int main() {
    displayMenu();

    // Queue q(10);

    // q.enqueueSentence("This sis as s s s dg s");

    return 0;
}