#include "Stroka.h"
#include <iostream>
using namespace std;


int main(){
    Stroka **s = new Stroka *[6];
    for(int i=0;i<5;i++){
        s[i] = new Stroka ("lol");
        s[i]->show();
    }
}
