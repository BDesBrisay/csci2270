#include "MovieTree.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

MovieTree populateTree(string filename) {
    MovieTree tree;
    string line;

    ifstream inFile(filename);
    
    while (getline(inFile, line)) {
        string rank;
        string title;
        string year;
        string quantity;
        stringstream ss;
        ss << line;

        getline(ss, rank, ',');
        getline(ss, title, ',');
        getline(ss, year, ',');
        getline(ss, quantity);

        tree.addMovieNode(stoi(rank), title, stoi(year), stoi(quantity));
    }
    tree.printMovieInventory();

    return tree;
}

void displayMenu(string filename) {
    bool invalid = true;
    string input;
    string line;
    MovieTree tree = populateTree(filename);

    while (invalid) {
        cout << "======Main Menu======" << endl;
        cout << "1. Find a movie" << endl;
        cout << "2. Rent a movie" << endl;
        cout << "3. Print the inventory" << endl;
        cout << "4. Delete a movie" << endl;
        cout << "5. Count the movies" << endl;
        cout << "6. Quit" << endl;
        cin >> input;

        try {
            int selection = stoi(input);
            if (selection >= 1 && selection <= 6) {
                if (selection == 1) {
                    cout << "Enter title:";
                    cin >> line;
                    tree.findMovie(line);
                    cout;
                } else if (selection == 2) {
                    cout << "Enter title:";
                    cin >> line;
                    tree.rentMovie(line);
                    cout;
                } else if (selection == 3) {
                    tree.printMovieInventory();
                } else if (selection == 4) {
                    cout << "Enter title:";
                    cin.get();
                    getline(cin, line);
                    tree.deleteMovieNode(line);
                    cout;
                } else if (selection == 5) {
                    cout << "Tree Contains: " << tree.countMovieNodes() << endl;
                } else if (selection == 6) {
                    cout << "Goodbye!" << endl;
                    invalid = false;
                }
            } else throw invalid_argument("Invalid number");
        } catch(invalid_argument& e) {
            cout << "Please enter a valid number." << endl;
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) return 1;

    string filename = argv[1];
    displayMenu(filename);
}