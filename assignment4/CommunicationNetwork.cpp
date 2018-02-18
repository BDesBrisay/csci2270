#include <fstream>
#include "./CommunicationNetwork.h"

using namespace std;

CommunicationNetwork::CommunicationNetwork() {
    head = NULL;
    tail = NULL;
}

CommunicationNetwork::~CommunicationNetwork() {
    deleteNetwork();
    head = NULL;
    tail = NULL;
}

void CommunicationNetwork::addCity(string cityNewName, string cityPrevName) {
    City* place = head;
    City* newCity = new City(cityNewName, NULL, NULL, "");

    if (place == NULL) {
        head = newCity;
        head->next = tail;
    } else if (cityPrevName == "First") {
        head->previous = newCity;
        newCity->next = head;
        head = newCity;
    } else if (cityPrevName == "" || tail->cityName == cityPrevName) {
        if (tail == NULL) {
            tail = newCity;
            tail->previous = head;
            head->next = tail;
        } else {
            tail->next = newCity;
            newCity->previous = tail;
            tail = newCity;
        }
    } else {
        /*cout << "Error 14" << endl;
        cout << "Enter a city name: " << endl;
        getline(cin,cityNewName);
        cout << "Enter a previous city name: " << endl;
        getline(cin,cityPrevName);*/

        while (place != NULL) {
            if (place->cityName == cityPrevName) {
                if (place->next != NULL) {
                    place->next->previous = newCity;
                    newCity->next = place->next;
                    place->next = newCity;
                    newCity->previous = place;
                    break;
                } else {
                    place->next = newCity;
                    newCity->previous = place;
                    break;  
                }
            }
            place = place->next;
        }
    }
}

void CommunicationNetwork::buildNetwork() {
    string names[] = {"Los Angeles","Phoenix","Denver","Dallas","St. Louis","Chicago","Atlanta","Washington, D.C.","New York","Boston"};
    // CommunicationNetwork();
    string prevCityName = "";

    for (int i = 0; i < 10; i++) {
        if (i == 0) {
            prevCityName = "First";
        } else {
            prevCityName = "";
        }
        addCity(names[i], prevCityName);
    }
}

void CommunicationNetwork::transmitMsg(char* filename) {
    if (head != NULL) {
        City* place = head;
        ifstream msg(filename);
        string line;
        bool reverse = false;

        if (msg.is_open()) {
            while (getline(msg, line, ' ')) {
                //line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
                
                while (place != NULL) {
                    place->message = line;
                    cout << place->cityName<<" received "<<place->message << endl;
                    
                    if (place->next != NULL && reverse == false) {
                        place = place->next;
                    } else if (place->next == NULL) {
                        place = place->previous;
                        reverse = true;
                    } else if (reverse == true) {
                        place = place->previous;
                    }
                }

                place = head;
                reverse = false;
            }
        }
    } else {
        cout << "Empty list" << endl;
    }
}

void CommunicationNetwork::printNetwork() {
    City* place = head;
    cout << "===CURRENT PATH===" << endl;
    cout <<"NULL <- ";
    while ( place != NULL && place->next != NULL) {
        cout << place->cityName << " <-> ";
        place = place->next;
    }
    if (tail != NULL) cout << tail->cityName << " -> ";
    cout << "NULL" << endl;
    cout << "==================" << endl;
}

void CommunicationNetwork::deleteCity(std::string removeCity) {
    City* place = head;
    bool deleted = false;
    
    while (place != NULL) {
        if (place->cityName == removeCity) {
            if (place->previous == NULL) {
                head = place->next;
                places == NULL;
            } else if (place->next == NULL) {
                tail = place->previous;
                place = NULL;
            } else {
                City* temp = place;
                place = temp->next;
                place->previous = temp->previous;
            }
            deleted = true;
        }
        
        place = place->next;
    }
    
    if (deleted == false) {
        cout << removeCity << " not found" << endl;
    }
}

void CommunicationNetwork::deleteNetwork() {
    City* place = head;

    while (place != NULL) {
        cout<<"deleting "<<place->cityName<<endl;
        City* temp = place;
        deleteCity(temp->cityName);
        place = place->next;
    }
}
