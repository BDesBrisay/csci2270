#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

struct city {
    string cityName;
    string message;
    city* next;
    city() {}
    city(string n, string m) {
        cityName = n;
        message = m;
    }
    city(string n, string m, city* ne) {
        cityName = n;
        message = m;
        next = ne;
    }
};

class network {
    public:
        city *head, *tail;
        int index;

        network() {
            head = NULL;
            tail = NULL;
        }

        void add(string name) {
            city* temp = new city; 
            temp->cityName = name;
            temp->next = NULL;

            if (head == NULL) {
                head = temp;
                tail = temp;
            } else {
                tail->next = temp;
                tail = tail->next;
            }
        }   
};

city* addCity(city* head, city* prev, string newName) {
    city* temp = new city;
    temp->cityName = newName;
    temp->next = NULL;
    city* place = head;
    
    if (head == NULL) {
        head = temp;
    } else if (prev == NULL) {
        temp->next = head;
        head = temp;
    } else {
        while (place != NULL) {
            if (place->cityName == prev->cityName) {
                temp->next = place->next;
                place->next = temp;
                break;
            } else {
                place = place->next;
            }
        }
    }
    
    return head;
}

void transmitMsg(city* head) {
    ifstream file("messageIn.txt");
    string line;
    city* place = head;
    
    if (file.is_open()) {
        while (getline(file, line, ' ')) {
            while (place != NULL) {
                line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
                place->message = line;
                cout << place->cityName << " received " << place->message << endl;
                place = place->next;
            }
            place = head;
        }
    }
}

void printPath(city* head) {
    city *place = head;
    cout << "===CURRENT PATH===" << endl;
    while ( place != NULL ) {
        cout << place->cityName << " -> ";
        place = place->next;
    }
    cout << " NULL" << endl;
    cout << "==================" << endl;
}

city* buildNetwork() {
    string names[] = {"Los Angeles","Phoenix","Denver","Dallas","St. Louis","Chicago","Atlanta","Washington, D.C.","New York","Boston"};
    network a;

    for (int i = 0; i < 10; i++) {
        a.add(names[i]);
    }

    // printPath(a.head);
    return a.head;
}

void displayMenu() {
    int valid = 0;
    string input;
    city* head = buildNetwork();

    while (!valid) {
        cout << "======Main Menu======" << endl;
        cout << "1. Build Network" << endl;	
        cout << "2. Print Network Path" << endl;
        cout << "3. Transmit Message Coast-To-Coast" << endl;
        cout << "4. Add City" << endl;
        cout << "5. Quit" << endl;
        cin >> input;

        try {
            int selection = stoi(input);
            if (selection >= 1 && selection <= 5) {
                if (selection == 1) {
                    city* newhead = buildNetwork();
                    // printPath(newhead);
                } else if (selection == 2) {
                    printPath(head);
                } else if (selection == 3) {
                    transmitMsg(head);
                } else if (selection == 4) {
                    string newCity;
                    string prevCity;
                    cout << "Enter a City name: " << endl;
                    cin >> newCity;
                    cout << "Enter a previous City name: " << endl;
                    cin >> prevCity;
                    
                    city* prev = new city;
                    prev->cityName = prevCity;

                    city* newhead = addCity(head, prev, newCity);
                    // printPath(newhead);
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
    network a;
    string cities[] = {"Los Angeles","Phoenix","Denver","Dallas","St. Louis","Chicago","Atlanta","Washington, D.C.","New York","Boston"};

    displayMenu();

    return 0;
}