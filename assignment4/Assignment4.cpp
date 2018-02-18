#include <iostream>
#include <fstream>
#include <algorithm>
#include "./CommunicationNetwork.h"

using namespace std;

void displayMenu(char* filename) {
    int valid = 0;
    string input;
    CommunicationNetwork a;

    while (!valid) {
        cout << "======Main Menu======" << endl;
        cout << "1. Build Network" << endl;	
        cout << "2. Print Network Path" << endl;
        cout << "3. Transmit Message Coast-To-Coast-To-Coast" << endl;
        cout << "4. Add City" << endl;
        cout << "5. Delete City" << endl;
        cout << "6. Clear Network" << endl;
        cout << "7. Quit" << endl;
        cin >> input;

        try {
            int selection = stoi(input);
            if (selection >= 1 && selection <= 7) {
                if (selection == 1) {
                    a.buildNetwork();
                    a.printNetwork();
                } else if (selection == 2) {
                    a.printNetwork();
                } else if (selection == 3) {
                    a.transmitMsg(filename);
                } else if (selection == 4) {
                    string newCity;
                    string prevCity;
                    cout << "Enter a City name: " << endl;
                    cin >> newCity;
                    cout << "Enter a previous City name: " << endl;
                    cin >> prevCity;

                    a.addCity(newCity, prevCity);
                } else if (selection == 5) {
                    string delCity;
                    cout << "Enter a City name: " << endl;
                    cin >> delCity;

                    a.deleteCity(delCity);
                } else if (selection == 6) {
                    a.deleteNetwork();
                } else if (selection == 7) {
                    cout << "Goodbye!" << endl;
                    valid = 1;
                }
            } else throw invalid_argument("Invalid number");
        } catch(invalid_argument& e) {
            cout << "Please enter a valid number." << endl;
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) return 1;

    char* filename = argv[1];
    CommunicationNetwork a;

    displayMenu(filename);
}