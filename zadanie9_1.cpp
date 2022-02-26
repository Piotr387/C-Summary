#include <iostream>
#include <fstream>
using namespace std;

void zadanie9_1(){
    string path = "C:\\Users\\Piotr\\Documents\\qt_projects\\summaryCplusplus\\kod.txt";
    ifstream fileOf;
    fileOf.open(path);
    if(fileOf.is_open())
    {
        cout<<"Plik otworzyl sie poprawnie"<<endl;
        string linia;
        while (getline(fileOf, linia)){
            string::size_type n = linia.find("//");
            if (n != string::npos)
                linia.erase(n);
            cout << linia << endl;
        }
        fileOf.close();
    }
    else
        cerr<<"Blad przy otwieraniu pliku!"<<endl;
}
