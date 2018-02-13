#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct Car {
    string model;
    string make;
    string year;
    Car() {};
    Car(string mo, string ma, string y) {
        model = mo;
        make = ma;
        year = y;
    };
};

int main(int argc, char* argv[]) {
    Car cars[stoi(argv[2])];
    ifstream inFile(argv[1]);
    ofstream outFile(argv[3]);
    string line;
    int index = 0;

    if(inFile.is_open()) {
        while(getline(inFile, line)) {
            stringstream ss;
            ss << line;

            string model;
            string make;
            string year;
            getline(ss, model, ' ');
            getline(ss, make, ' ');
            getline(ss, year, ' ');

            Car tempCar(model, make, year);
            cout<<tempCar.model<<tempCar.make<<tempCar.year<<endl;

            cars[index] = tempCar;
            index++;
        }
    } else {
        cout<<"File did not open!"<<endl;
    }

    if(outFile.is_open()) {
        for(int i = 0; i < stoi(argv[2]); i++) {
            outFile<<cars[i].model<<"\t"<<cars[i].make<<"\t"<<cars[i].year<<endl;
        }
    } else {
        cout<<"Out file did not open"<<endl;
    }
}