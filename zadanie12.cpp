#include <iostream>
#include <vector>
#include <algorithm>
#include <car.h>
#include <map>

using namespace std;

template<typename T>
void show(const T &arr){
    for_each(arr.begin(),arr.end(),[](auto el) -> void {cout << el << "|";});
    cout << endl;
}

template<typename T>
void avg(const T &arr){
    double suma;
    for_each(arr.begin(),arr.end(),[&suma](auto el) -> void {suma+=el;});
    cout << "Srednia: "<< suma/arr.size() << endl;
}

template<typename T>
void even(const T &arr){
    int counter = count_if(arr.begin(),arr.end(),[](int x) -> bool { return x % 2 == 0; });
    cout << "Parzyste: " << counter << endl;
}

template<typename T>
void noNegative(T &arr){
    arr.erase(
                remove_if(
                    arr.begin(),
                    arr.end(),
                    [](auto x) -> bool { return x < 0;}),
                arr.end());
    show(arr);
}

template<typename T>
void sorted(T &arr){
    partition(arr.begin(),arr.end(),[](auto el) -> bool {return el % 2 == 0;});
    show(arr);
}


template<typename T>
void reverse(T &arr){
    for_each(arr.begin(),arr.end(),[](int &el) -> void { el = -el;});
}

template<typename T,typename T2>
void lessThan(T &arr,T2 arg){
    int counter = count_if(arr.begin(),arr.end(),[&arg](auto el) -> bool {return el < arg;});
    cout << "Liczb mniejszych od " << arg << " jest: " << counter << endl;
}

void ex12_1(){
    vector<int> myVec = {-2,3,5,2,2,2,2,2,3};
    show(myVec);
    avg(myVec);
    even(myVec);
    noNegative(myVec);
    sorted(myVec);
    reverse(myVec);
    show(myVec);
    reverse(myVec);
    show(myVec);
    lessThan(myVec,3);
}

void ex12_2(){
    vector<Car> cars;
    vector<pair<int,Car>> katalog;
    cars.push_back(Car("Audi", "A3",1999,"1.8T"));
    cars.push_back(Car("Audi", "A4",2000,"1.9TDI"));
    cars.push_back(Car("Audi", "A8",2008,"1.8"));
    cars.push_back(Car("Audi", "A6",2004,"1.6"));
    int counter=1;
    for(auto x: cars){
        katalog.push_back(make_pair(counter,x));
        counter++;
    }

    auto showCars = [](auto a) -> void{
        cout << a.first << " - ";
        a.second.show();
    };

    auto rokProdukcji = [](auto a,auto b) -> bool {
        return a.second.getYear() < b.second.getYear();
    };

    sort(katalog.begin(),katalog.end(),rokProdukcji);
    for_each(katalog.begin(),katalog.end(),showCars);
}

#include <tuple>
tuple<int, float, string> zadanie(vector<string> v) {
    int sum = 0;
    for_each(v.begin(), v.end(), [&sum](string x) { sum += x.length(); });

    vector<string>::iterator najk = min_element(v.begin(), v.end(),
                                                 [](string a, string b) { return a.length() < b.length(); });
    auto najd = max_element(v.begin(), v.end(),
                        [](string a, string b) { return a.length() < b.length(); });


    return make_tuple((*najk).length(), sum / (float)v.size(), (*najd));
}

void ex12_3()
{
    vector<string> v = { "ala", "ma", "kota", "a" };

    auto w = zadanie(v);

    cout << "Dlugosc najkrotszego: " << get<0>(w) << endl;
    cout << "Srednia dlugosc: " << get<1>(w) << endl;
    cout << "Najdluzszy napis: " << get<2>(w) << endl;
}
