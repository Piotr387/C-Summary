#include "car.h"

const string &Car::getModel() const
{
    return model;
}

void Car::setModel(const string &newModel)
{
    model = newModel;
}

int Car::getYear() const
{
    return year;
}

void Car::setYear(int newYear)
{
    year = newYear;
}

const string &Car::getPojemnoscSilnika() const
{
    return pojemnoscSilnika;
}

void Car::setPojemnoscSilnika(const string &newPojemnoscSilnika)
{
    pojemnoscSilnika = newPojemnoscSilnika;
}

void Car::show()
{
    cout << "Marka: " << marka
         << " Model: " << model
         << " Rok: " << year
         << " Silnik: " << pojemnoscSilnika << endl;
}

const string &Car::getMarka() const
{
    return marka;
}

void Car::setMarka(const string &newMarka)
{
    marka = newMarka;
}
