#include <iostream>

using namespace std;

void oczko(int &sum){
   int a;
   cout << "Podaj liczbe: ";
   cin >> a;
   sum += a;
   if(sum > 21){
       throw "Podane liczby sa wieksze od liczby 21!";
   }
}

void zadanie9_2(){
   int ileProb = 0;
   int suma = 0;
   cout << "Zadanie 9_2 Gra w oczko do 21" << endl;
   try {
       do {
           ileProb++;
           oczko(suma);
       } while (suma < 21);
       cout << "Osiagnieto sume 21 po: " << ileProb << " probach!" << endl;
   }  catch (char const* a) {
       cout << "Przekroczono liczbe 21 o " << suma - 21 << "!" << endl;
       cout << "Po " << ileProb << " probach!" << endl;
   }
}
