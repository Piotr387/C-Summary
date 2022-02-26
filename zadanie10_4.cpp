#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include <algorithm>
#include <sstream>

using namespace std;

bool returnReg(string s, regex reg) {
    return (regex_match(s.begin(),s.end(),reg)) ? true : false;
}

class kartoteka{
private:
    string imie;
    string nazwisko;
    int wiek;
    int tel;
    string email;
public:
    kartoteka(){
        regex regImie("[A-ZĄĆĘŁŃÓŚŻŹ]{1}[a-ząćęłńóżźś]{1,}");
        do {
            cout << "Podaj imie: "; cin >> this->imie;
        } while(!returnReg(this->imie,regImie));
        regex regNazwisko("[A-ZĄĆĘŁŃÓŚŻŹa-ząćęłńóżźś-]{2,}");
        do {
            cout << "Podaj nazwisko: "; cin >> this->nazwisko;
        } while(!returnReg(this->nazwisko,regNazwisko));
        regex regWiek("^([0-9]?|[1-9][0-9])$");
        string age;
        do {
            cout << "Podaj wiek: "; cin >> age;
        } while(!returnReg(age,regWiek));
        this->wiek = stoi(age);
        string nr;
        regex regTel("^[1-9]\\d{8}$");
        do {
            cout << "Podaj nr tel: "; cin >> nr;
        } while(!returnReg(nr,regTel));
        this->tel = stoi(nr);
        regex regEmail("^[A-Za-z]{1}[A-Za-z0-9_\\-.]{1,}@[A-Za-z0-9]{1,}.[A-Za-z\\d]{1,}$");
        do {
            cout << "Podaj email: "; cin >> this->email;
        } while(!returnReg(this->email,regEmail));
        cout << "Build succes" << endl;
    }
    kartoteka(string imie1, string nazwisko1, int wiek1, int tel1, string email1):
        imie(imie1), nazwisko(nazwisko1), wiek(wiek1), tel(tel1), email(email1){};

    void zapisDoPliku(){
        string path = "C:\\Users\\Piotr\\Documents\\qt_projects\\summaryCplusplus\\dane.txt";
        unique_ptr<fstream> file;
        file = unique_ptr<fstream>(new fstream(path));
        file->open(path, ios::out);
        *file << fflush;
        file->close();
        file->open(path, ios::app);
        string dane = this->imie + ";" +
                this->nazwisko + ";" +
                to_string(this->wiek) + ";" +
                to_string(this->tel) + ";" +
                this->email;
        *file << dane << endl;
        file->flush();
        file->close();
    }
    const string &getEmail() const{
        return email;
    }
    int getTel() const{
        return tel;
    }
    const string &getNazwisko() const{
        return nazwisko;
    }
    const string &getImie() const{
        return imie;
    }

};

void showVec(vector<string> myVec){
    for_each(myVec.begin(),myVec.end(),[](auto el){cout << el << endl;});
}

void zadanie10_4(){
    shared_ptr<kartoteka> k1(new kartoteka("Jan", "Kowalski", 55, 123456788, "mail@to.me"));
    shared_ptr<kartoteka> k2(new kartoteka("Piotr", "Kowa-lski", 40, 123456786, "mail@to.me"));
    shared_ptr<kartoteka> k3(new kartoteka("Sebastian", "Kowalski", 35, 123456784, "mail@to.me"));
    shared_ptr<kartoteka> k4(new kartoteka("Izabela", "Kowa-lski", 25, 123456789, "mail@to.me"));
    shared_ptr<kartoteka> k5(new kartoteka("Mateusz", "Kowalski", 15, 123456789, "mail@to.me"));
    vector<shared_ptr<kartoteka>> myVec;
    myVec.push_back(k1);
    myVec.push_back(k2);
    myVec.push_back(k3);
    myVec.push_back(k4);
    myVec.push_back(k5);
    for_each(myVec.begin(),myVec.end(),[](shared_ptr<kartoteka> el){el->zapisDoPliku();});
}
