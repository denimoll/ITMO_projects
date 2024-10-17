#include <iostream>
#include <string>

int main() {
    using namespace std;
    setlocale(0, "ru");
    int d=0;
    string s;
    cout<<"Введите строчку: "; cin>>s;
    for(int i=0;i<s.length()-2;i++){
        if (s[i]=='a' and s[i+1]=='b' and s[i+2]=='c'){
            d++;
        }
    }
    cout<<"Комбинация abc повторяется: "<<d<<" раз(a)"<<endl;
    return 0;
}
