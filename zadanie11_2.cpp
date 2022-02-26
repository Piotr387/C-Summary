#include <iostream>
#include <memory>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

class Warehouse {
private:
    string nazwaTowaru;
    int liczbaSztuk;
public:
    Warehouse(string nazwaTowaru1, int iloscSztuk1):
        nazwaTowaru(nazwaTowaru1), liczbaSztuk(iloscSztuk1){};
    ~Warehouse(){cout << "Destruktor magazynu!" << endl;}
    void info(){
        cout << "Nazwa:" << nazwaTowaru << " szt: " << liczbaSztuk << endl;
    }
    int getLiczbaSztuk() const {
        return liczbaSztuk;
    }
    void setLiczbaSztuk(int newLiczbaSztuk){
        this->liczbaSztuk = newLiczbaSztuk;
    }
    const string &getNazwaTowaru() const {
        return nazwaTowaru;
    }
};

class Shop{
private:
    string nazwaSklepu;
    vector<shared_ptr<Warehouse>> listaMagazyn;
public:
    Shop(string nazwaSklepu1): nazwaSklepu(nazwaSklepu1){};
    ~Shop(){cout << "Destruktor sklepu!" << endl;}
    void addItem(shared_ptr<Warehouse> el){
        listaMagazyn.push_back(el);
    }
    void sellItem(string towar, int ilosc){
        auto warunek = [&](shared_ptr<Warehouse> el){if(el->getNazwaTowaru() == towar && el->getLiczbaSztuk() >= ilosc) return true; else return false;};
        auto result = find_if(listaMagazyn.begin(),listaMagazyn.end(),warunek);
        if(result != listaMagazyn.end()){
            int index = distance(listaMagazyn.begin(),result);
            cout << "Sprzedano: " << towar << " w ilosci " << ilosc << " w sklepie " << nazwaSklepu << endl;
            int sztk = listaMagazyn[index]->getLiczbaSztuk();
            cout << "Stan przed sprzedaniem: " << sztk << endl;
            listaMagazyn[index]->setLiczbaSztuk(sztk-ilosc);
            cout << "Stan po sprzedazy: " << listaMagazyn[index]->getLiczbaSztuk() << endl;
        } else {
            cout << "Nie wystarczajaca ilosc na magazynie! w sklepie " << nazwaSklepu << endl;
        }
    }
    void showMagazyny(){
        for_each(listaMagazyn.begin(),listaMagazyn.end(),[](shared_ptr<Warehouse> el) {cout << el->getNazwaTowaru() << endl;});
    }
    void pokazNazweSklepu(){
        cout << "Wita w  sklepie: " << nazwaSklepu << endl;
    }
};


void zadanie11_2(){
    shared_ptr<Warehouse> m1(new Warehouse("krzesla",10));
    shared_ptr<Warehouse> m2(new Warehouse("biurka",5));
    shared_ptr<Shop> s1(new Shop("Stokrotka"));
    shared_ptr<Shop> s2(new Shop("Biedronka"));
    vector<shared_ptr<Shop>> listaSklepow;
    listaSklepow.push_back(s1);
    listaSklepow.push_back(s2);
    for_each(listaSklepow.begin(),listaSklepow.end(),[&](auto el){el->addItem(m1);el->addItem(m2);});
    s1->sellItem("krzesla",3);
    s1->sellItem("krzesla",3);
    s2->sellItem("krzesla",3);
    s2->sellItem("krzesla",3);
};
