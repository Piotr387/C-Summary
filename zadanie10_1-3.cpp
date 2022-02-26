#include <iostream>
#include <regex>
#include <iomanip>

using namespace std;

void returnReg1_3(string s, regex reg) {
    cout << s << " -- ";
    if(regex_match(s.begin(),s.end(),reg)){
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
}

void ex10_1(string s){
    regex regPattern("[\\+|-]?\\d+.\\d+");
    cout << s << "\t";
    if(regex_match(s.begin(),s.end(),regPattern)){
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
}

void ex10_2(string s){
    regex regPattern("^([0-1]\\d|[2][0-3]):[0-5]\\d(:[0-5]\\d)?");
    cout << left << setw(11) << s;
    if(regex_match(s.begin(),s.end(),regPattern)){
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
}

void ex10_3(string s0,string s1,string s2) {
    regex regPatternStreet("([A-Za-z]+ )*[A-Za-z]+");
    regex regPatternPostCode("^[0-9]{2}-[0-9]{3}$");
    regex regPatternHouseNumber("^\\d+(A-Z)?");
    regex regPatternFlatNumber("(\\d+)?");
    returnReg1_3(s0,regPatternStreet);
    returnReg1_3(s1,regPatternPostCode);
    returnReg1_3(s2,regPatternHouseNumber);
}

void zadanie10_1_3(){
    cout << "Zadanie 1" << endl;
    ex10_1("6.789");
    ex10_1("7.567");
    cout << "Zadnie 2" << endl;
    ex10_2("00:00:00");
    ex10_2("01:01:01");
    ex10_2("00:00");
    ex10_2("34:35:45");
    ex10_2("23:34:56");
    ex10_2("24:00");
    ex10_2("23:04");
    cout << "Zadanie 3" << endl;
    ex10_3("Wajdeloty","20-400","29B");
    ex10_3("Wajdeloty Jakiegos","20400","29");
    ex10_3("Wajdeloty-Cos","as-400","abc");
}
