#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

vector<string> splitv2(const string &s, char delim){
    vector<string> result;
    stringstream ss(s);
    string item;
    while (getline(ss,item,delim)){
        result.push_back(item);
    }
    return result;
}

void zadanie9_3(){
    //tutaj tylko jak sie odczytuje z srednikami
    string path = "C:\\Users\\Piotr\\Documents\\qt_projects\\summaryCplusplus\\dane.csv";
    ifstream fileOf;
    fileOf.open(path);
    if(fileOf.is_open())
    {
        cout<<"Plik otworzyl sie poprawnie"<<endl;
        string linia;
        while (getline(fileOf, linia)){
            auto vec = splitv2(linia,';');
            for (auto i : vec) {
                cout << left << setw(11) << i;
            }
            cout << endl;
        }
        fileOf.close();
    }
    else
        cerr<<"Blad przy otwieraniu pliku!"<<endl;
}
