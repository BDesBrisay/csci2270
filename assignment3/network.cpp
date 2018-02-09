#include <iostream>

using namespace std;

struct city {
    string name;
    string message;
    city* next;
    city() {}
    city(string n, string m) {
        name = n;
        message = m;
    }
    city(string n, string m, city* ne) {
        name = n;
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
            temp->name = name;
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

void print(city* head) {
    city *place = head;
    cout << "===CURRENT PATH===" << endl;
    while ( place != NULL ) {
        cout << place->name << " -> ";
        place = place->next;
    }
    cout << "NULL" << endl;
    cout << "==================" << endl;
}

city* buildNetwork() {
    string names[] = {"Los Angeles","Phoenix","Denver","Dallas","St. Louis","Chicago","Atlanta","Washington, D.C.","New York","Boston"};
    network a;

    for (int i = 0; i < 10; i++) {
        a.add(names[i]);
    }

    print(a.head);
    return a.head;
}

void displayMenu() {
    int valid = 0;
    string input;
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
                    city* head = buildNetwork();
                } else if (selection == 2) {
                    string newCity;
                    string prevCity;
                    cout << "Enter a city name: " << endl;
                    cin >> newCity;
                    cout << "Enter a previous city name: " << endl;
                    cin >> prevCity;
                    cout << newCity << prevCity << endl;

                } else if (selection == 3) {

                } else if (selection == 4) {

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