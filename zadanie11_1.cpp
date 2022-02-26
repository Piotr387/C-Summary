#include <iostream>
#include <memory>
#include <vector>
#include <fstream>

using namespace std;

//Deklaracja klasy Buffer.
class Buffer
{
public:
   Buffer(){std::cout << "Kontruktor Buffer" << std::endl;};
   virtual void add(int a) = 0;
   virtual void write() = 0;
   virtual ~Buffer(){std::cout << "Destruktor buffer" << std::endl;};
};

//Deklaracja klasy BufferArr
class BufferArr : public Buffer
{
private:
   unique_ptr<int[]> tab;
   int free = 0;
   int n = 0;
public:
   BufferArr(int n): Buffer(){
       cout << "Kontruktor BufferArr" << endl;
       tab = unique_ptr<int[]>(new int[n]);
       this->n = n;
   };

   ~BufferArr(){
       cout << "Destruktor BufferArr" << endl;
   };

   virtual void add(int a) override{
       if(free < n) {
           tab[free] = a;
           free++;
       } else {
           cout << "Nie ma miejsca" << endl;
       }
   }

   virtual void write() override {
       cout << endl;
       for(int i=0;i<free;i++)
           cout << tab[i] << " ";
       cout << endl;
   }
};

class BufferFile: public Buffer {
private:
   string path;
   unique_ptr<fstream> file;
public:
   BufferFile(string path): Buffer(){
       file = unique_ptr<fstream>(new fstream(path));
       this->path = path;
       file->open(path, ios::out);
       *file << fflush;
       file->close();
       file->open(path, ios::out | ios::in);
       cout << "Kontruktor BufferFile" << endl;
   }

   virtual ~BufferFile() {
       file->close();
       cout << "Destruktor BufferFile" << endl;
   }

   virtual void add(int a) override {
       *file << a << endl;
       file->flush();
   }

   virtual void write() override {
       file->clear();
       file->seekg(0);
       while(!file->eof()){
           string line;
           getline(*file,line);
           cout << line << " ";
       }
       cout << endl;
   }
};

class BufferFile2: public Buffer {
private:
   string path;
public:
   BufferFile2(string path): Buffer(){
       unique_ptr<ofstream> file = unique_ptr<ofstream>(new ofstream(path, ios::out));
       this->path = path;
       cout << "Kontruktor BufferFile2" << endl;
   }

   ~BufferFile2(){
       cout << "Destruktor BufferFile2" << endl;
   }

   virtual void add(int a) override {
       unique_ptr<ofstream> file = unique_ptr<ofstream>(new ofstream(path, ios::app));
       *file << a << endl;
   }

   virtual void write() override {
       unique_ptr<ifstream> file = unique_ptr<ifstream>(new ifstream(path, ios::in));
       while (!file->eof())
       {
           string line;
           getline(*file, line);
           cout << line << " ";
       }
       cout << endl;
   }

};

void zadanie11_1(){
   shared_ptr<Buffer> a(new BufferArr(5));
   a->add(1);
   a->add(2);
   a->add(3);
   a->add(4);
   a->add(5);
   a->add(6);

   a->write();

   shared_ptr<Buffer> b(new BufferFile("C:\\Users\\Piotr\\Documents\\qt_projects\\summaryCplusplus\\plik.txt"));
   b->add(1);
   b->add(2);
   b->add(3);
   b->add(4);
   b->add(5);
   b->add(6);

   b->write();


   vector<shared_ptr<Buffer>> v;
   v.push_back(a);
   v.push_back(b);

   for (shared_ptr<Buffer> i : v) {
       i->write();
   }

   shared_ptr<Buffer> c = shared_ptr<Buffer>(new BufferFile2("C:\\Users\\Piotr\\Documents\\qt_projects\\summaryCplusplus\\plik2.txt"));
   c->add(1);
   c->add(2);
   c->add(3);

   c->write();
}
