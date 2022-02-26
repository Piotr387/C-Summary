#include <set>
#include <map>
#include "zadanie10_4.cpp"

vector<string> splitv10(const string&s, char delimiter){
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while(getline(tokenStream, token, delimiter)){
        tokens.push_back(token);
    }
    return tokens;
}

void show(set<string> s){
    for(auto i = s.begin(); i != s.end(); i++) {
        cout << *i << endl;
    }
}

void zadanie10_5(){
    string path = "C:\\Users\\Piotr\\Documents\\qt_projects\\summaryCplusplus\\dane.txt";
    unique_ptr<ifstream> file = unique_ptr<ifstream>(new ifstream(path, ios::in));
    string line;
    vector<shared_ptr<kartoteka>> kartotekaTxt;
    while (getline(*file,line))
    {
        auto osoba = splitv10(line,';');
        kartotekaTxt.push_back(shared_ptr<kartoteka>(new kartoteka(osoba[0],osoba[1],stoi(osoba[2]),stoi(osoba[3]), osoba[4])));
    }
    //Domeny: ciag znakow po @ w emailu
    set<string> domeny;
    for_each(kartotekaTxt.begin(),kartotekaTxt.end(),
             [&](shared_ptr<kartoteka> el){
        string nowaDomena = splitv10(el->getEmail(),'@')[1];
        domeny.insert(nowaDomena);
    });
    show(domeny);
    cout << "Parzyste numery telefonow" << endl;
    for_each(kartotekaTxt.begin(),kartotekaTxt.end(),[](shared_ptr<kartoteka> el){if(el->getTel() % 2 == 0) cout << el->getTel() << endl;});
    cout << "Nazwiska laczone:" << endl;
    for_each(kartotekaTxt.begin(),kartotekaTxt.end(),[](shared_ptr<kartoteka> el){if(el->getNazwisko().find("-") != string::npos) cout << el->getNazwisko() << endl;});
    cout << "Statystyka imion: " << endl;
    map<string,int> imiona;
    for_each(kartotekaTxt.begin(),kartotekaTxt.end(),[&](shared_ptr<kartoteka> el){imiona[el->getImie()]++;});
    map<string, int>::iterator it;
    for(it=imiona.begin(); it!=imiona.end(); ++it)
    {
        cout << it->first <<" liczba wystapien: "<<it->second<<endl;
    }
    cout<<endl;
    file->close();
}
