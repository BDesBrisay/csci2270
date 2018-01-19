#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

struct Student {
    // ID, Name, Major
    int ID;
    string name;
    string major;
    Student(){};
    Student(int id, string n, string m) {
        ID = id;
        name = n;
        major = m;
    };
};

int main() {
    cout<<"hello world"<<endl;

    Student s;
    s.ID = 5;
    s.name = "Tyson";
    s.major = "Skiing";

    Student s2(3,"bob","swimming");

    cout<<s2.ID<<s2.name<<s2.major<<endl;

    int a[10];

    for (int i = 0; i < 10; i++) {
        a[i] = i; 
        cout<<a[i]<<endl;
    }

    int b[10];

    cout<<"a="<<a<<endl; // address of a

    Student allStudents[10];

    ifstream file("students.txt");
    if (file.is_open()) {
        string line;
        int index = 0;
        while(getline(file, line)) {
            stringstream ss;
            ss << line;

            string value;
            getline(ss, value, ',');
            allStudents[index].ID = stoi(value);
            cout<<allStudents[index].ID<<endl;

            getline(ss, value, ',');
            allStudents[index].name = value;
            cout<<allStudents[index].name<<endl;

            getline(ss, value);
            allStudents[index].major = value;
            cout<<allStudents[index].major<<endl;

            index++;
        }
    } else {
        cout<<"FILE UNABLE TO OPEN"<<endl;
    }

}