#ifndef CAR_H
#define CAR_H
#include <iostream>

using namespace std;

class Car
{
private:
    string marka;
    string model;
    int year;
    string pojemnoscSilnika;
public:
    Car(string marka1,string model1,int year1,string pojemnosc1):
        marka(marka1), model(model1), year(year1), pojemnoscSilnika(pojemnosc1){};
    const string &getMarka() const;
    void setMarka(const string &newMarka);
    const string &getModel() const;
    void setModel(const string &newModel);
    int getYear() const;
    void setYear(int newYear);
    const string &getPojemnoscSilnika() const;
    void setPojemnoscSilnika(const string &newPojemnoscSilnika);
    void show();
};

#endif // CAR_H
