#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
using namespace std;

class Stroka{
    
protected:
    int i,pIn;
    size_t len, j;
    char *pCh;
    
public:
    Stroka(size_t = 0);
    Stroka(char);
    Stroka(const char*);
    Stroka(const Stroka&);
    virtual ~Stroka();
    
    void Cleaner();
    void setStr(int);
    friend Stroka operator + (const Stroka&, const Stroka&);
    friend Stroka operator + (const Stroka&, const char *);
    friend Stroka operator + (const char *, const Stroka&);
    Stroka & operator = (const Stroka &);
    //void Plus(char*);
    void show();
};

void Stroka::setStr(int c){
    pIn=c;
}

//КОНСТРУКТОР
Stroka::Stroka(size_t c){
    cout<<"Stroka::Stroka()"<<endl;
    
    if (c==0) this->Cleaner();
    len=c;
    pCh = new char[len + 1];
}

//СТРОКА, ПРИНИМАЮЩАЯ СИМВОЛ
Stroka::Stroka(char c){
    cout<<"Stroka::Stroka(char)"<<endl;
    
    pCh = new char [2];
    pCh[0] = c;
    pCh[1] = '\0';
    len=1;
}

//КОНСТРУКТОР, ПРИНИМАЮЩИЙ СТРОКУ
Stroka::Stroka(const char* c){
    cout<<"Stroka::Stroka(const char*)"<<endl;
    
    len=strlen(c);
    pCh= new char[len+1];
    strcpy(pCh, c);
}

//КОНСТРУКТОР КОПИРОВАНИЯ
Stroka::Stroka(const Stroka& c){
    cout<<"Stroka::&Stroka(const Stroka&)"<<endl;
    
    len=strlen(c.pCh);
    pCh = new char [c.len+1];
    strcpy(pCh,c.pCh);
}

//ДЕСТРУКТОР
Stroka::~Stroka(){
    cout<<"Stroka::~Stroka()"<<endl;
    
    if(pCh) {
        delete [] pCh;
        len=0;
    }
}

//СОЗДАНИЕ ПУСТОЙ СТРОКИ
void Stroka::Cleaner(){
    cout<<"Stroka::Cleaner()"<<endl;
    pCh=new char[1];
    pCh[0]='\0';
}

Stroka & Stroka:: operator=(const Stroka & c)
{
    cout<<"Stroka & Stroka::operator=(const Stroka&)"<<endl;
    if(&c != this)
    { delete[]pCh;
        len=strlen(c.pCh);
        pCh= new char[len+1];
        strcpy(pCh,c.pCh);
    }
    return *this;
}

//ВЫВОД СТРОКИ И ДЛИНЫ НА ЭКРАН
void Stroka::show(){
    cout<<"void Stroka::show()"<<endl;
    cout <<"pCh="<<pCh<<endl;
    cout <<"len=" <<len <<endl;
}

Stroka operator+(const Stroka & c, const Stroka & x){
    cout<<"Stroka operator+(const Stroka & c, const Stroka & x)"<<endl;
    size_t l=c.len+x.len;
    Stroka pCh1(l+1);
    strcpy(pCh1.pCh,c.pCh);
    strcat(pCh1.pCh,x.pCh);
    return pCh1.pCh;
}

Stroka operator+(const Stroka& x, const char *c){
    cout<<"Stroka operator+(const Stroka& x, const char *c)"<<endl;
    Stroka pCh1(x.len+strlen(c)+1);
    strcpy(pCh1.pCh,x.pCh);
    strcat(pCh1.pCh,c);
    return pCh1.pCh;
}

Stroka operator+(const char *c, const Stroka& x){
    cout<<"Stroka operator+(const char *c, const Stroka& x)"<<endl;
    Stroka pCh1(x.len+strlen(c)+1);
    strcpy(pCh1.pCh,c);
    strcat(pCh1.pCh,x.pCh);
    return pCh1.pCh;
}








class Stroka_id: public Stroka{
    
    
public:
    Stroka_id();
    Stroka_id(const char*);
    ~Stroka_id();
    
    int Search(char);
    bool check(const char*);
    bool Less(const Stroka_id &, int);
};

Stroka_id::Stroka_id(){
    cout<<"Stroka_id::Stroka_id()"<<endl;
}

Stroka_id::Stroka_id(const char* c){
    cout<<"Stroka_id::Stroka_id(const char*)"<<endl;
    if(check(c)){
        for(i=0;c[i]!='\0';i++){
            len++;
        }
        pCh = new char [len+1];
        for(i=0;c[i]!='\0';i++){
            pCh[i]=c[i];
        }
        pCh[len]='\0';
    }
    else this->Cleaner();
}

Stroka_id::~Stroka_id(){
    cout<<"Stroka_id::~Stroka_id()"<<endl;
}

int Stroka_id::Search(char c){
    cout<<"int Stroka_id::Search(char)"<<endl;
    for(i=0;i<len;i++)
        if(pCh[i]==c) return (i+1);
    return 0;
}

bool Stroka_id::check(const char *c){
    cout<<"bool Stroka_id::Check(const char*)"<<endl;
    int k=0;
    if(!(c[0]>='0' && c[0]<='9') || c[0]!=' ')
        for(i=1;c[i]!='\0';i++){
            if(c[i]!=' ' && ((c[i]>='a' && c[i] <='z') || (c[i]>='A' && c[i] <='Z') || (c[i]>='0' && c[i]<='9') || c[i]=='_'))
                k++;
        }
    return (k==(i-1) && k!=0);
}

bool Stroka_id::Less(const Stroka_id & c, int x){
    cout<<"bool Stroka_id::Less(const Stroka_id&, int)"<<endl;
    return (pCh[x]<c.pCh[x]);
}







class Stroka_int: public Stroka{
    
public:
    Stroka_int();
    Stroka_int(const char*);
    ~Stroka_int();
    
    bool check(const char*);
    bool less(const Stroka_int &);
    Stroka_int operator+(const Stroka_int &);
    Stroka_int operator*(const Stroka_int &);
    Stroka_int & operator = (const Stroka_int &);
    void show();
};

Stroka_int::Stroka_int(){
    cout<<"Stroka_int::Stroka_int()"<<endl;
}

Stroka_int::Stroka_int(const char* c){
   cout<<"Stroka_int::Stroka_int(const char*)"<<endl;
    pCh=new char[len];
    if (this->check(c)){
        if(c[0]=='-' || c[0]=='+'){
            for(i=1;c[i]!='\0';i++)
                pCh[i-1]=c[i];
            pIn=atoi(pCh);
            if(c[0]=='-')
                pIn=-pIn;
        }
        else pIn=atoi(c);
    }
}

Stroka_int::~Stroka_int(){
    cout<<"Stroka_int::~Stroka_int()"<<endl;
}


bool Stroka_int::check(const char *c){
    cout<<"bool Stroka_int::check(const char*)"<<endl;
    int k=0;
    if(c[0]=='+' || c[0]=='-' || (c[0]>'0' && c[0]<'9'))
        for(i=1;c[i]!='\0';i++){
            if((c[i] >'0' && c[i] < '9'))
                k++;
        }
    return (k==(i-1));
}

/*void Stroka_int::plus(int c){
    cout<<"Plus_int"<<endl;
    if (pIn!=0)
        pIn=pIn+c;
}*/

Stroka_int Stroka_int::operator + (const Stroka_int & c){
    cout<<"Stroka_int Stroka_int::operator + (const Stroka_int &)"<<endl;
    pIn+=c.pIn;
    return *this;
}

Stroka_int Stroka_int::operator * (const Stroka_int & c){
    cout<<"Stroka_int Stroka_int::operator * (const Stroka_int &)"<<endl;
    pIn*=c.pIn;
    return *this;
}

Stroka_int & Stroka_int::operator=(const Stroka_int & c){
    cout<<"Stroka_int & Stroka_int::operator = (const Stroka_int &)"<<endl;
    if(&c!=this)
        pIn=c.pIn;
    return *this;
}

bool Stroka_int::less(const Stroka_int & c){
    cout<<"bool Stroka_int::less (const Stroka_int &)"<<endl;
    return (pIn<c.pIn);
}

void Stroka_int::show(){
    cout<<"void Stroka_int::show()"<<endl;
    cout<<"pIn="<<pIn<<endl;
}
