#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <map>

using namespace std;

//zadanie_1
void ex1(vector <string> &myVec){
    string path = "C:\\Users\\Piotr\\Documents\\qt_projects\\summaryCplusplus\\tekst.txt";
    ifstream fileOf;
    fileOf.open(path);
    if(fileOf.is_open())
    {
        cout<<"Plik otworzyl sie poprawnie"<<endl;
        string linia;
        while (getline(fileOf, linia)){
            myVec.push_back(linia);
        }
        fileOf.close();
        sort(myVec.begin(),myVec.end(),[](string a, string b){return a[0] < b[0];});
        cout<<endl;
        for_each(myVec.begin(),myVec.end(),[](string el){cout<<el<<endl;});
    }
    else
        cerr<<"Blad przy otwieraniu pliku!"<<endl;
    fileOf.close();

};

//zadanie_2
vector<string> split(const string &s, char delim){
    vector<string> result;
    stringstream ss(s);
    string item;
    while (getline(ss,item,delim)){
        result.push_back(item);
    }
    return result;
};

void ex2(vector<string> const& myVec, vector <string> &slowa) {
    for_each(myVec.begin(),myVec.end(),[&](string el){
        auto result = split(el,' ');
        slowa.insert(slowa.end(),result.begin(),result.end());
    });
    auto it = max_element(slowa.begin(),slowa.end(),[](string a, string b){ return a.size() < b.size();});
    cout << "Max: " << *it << endl;
};


void ex2m(vector<string> const& myVec, vector <string> &slowa) {
    for_each(myVec.begin(),myVec.end(),[&](string el){
        auto result = split(el,' ');
        slowa.insert(slowa.end(),result.begin(),result.end());
    });
   for_each(slowa.begin(),slowa.end(),[&](string a){if(a[0] == 'm') cout << a << endl;});
};

void ex3(vector <string> const& slowa, map<int,int> mapaSlow){
    for_each(slowa.begin(),slowa.end(),[&](string slowo){mapaSlow[slowo.size()]++;});
    map<int,int>::iterator it;
    for(it=mapaSlow.begin(); it!=mapaSlow.end(); ++it)
    {
        cout << "Slowa o dlugosci: " << it->first << " wystepuja: " << it->second << " razy" << endl;
    }
};

void kolokwium2()
{
    cout << "Zadanie 1" << endl;
    vector<string> linia;
    ex1(linia);

    cout << "Zadanie 2" << endl;
    vector<string> slowa;
    ex2(linia,slowa);

    cout << "Zadanie 2 z M" << endl;
    ex2m(linia,slowa);

    cout << "Zadanie 3" << endl;
    map<int,int> mapaSlow;
    ex3(slowa,mapaSlow);
};
