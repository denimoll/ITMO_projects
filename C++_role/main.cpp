#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
using namespace std;


int main() {
    int role[100], r=0,b=0,w=0;
    int x, money, up, up1, i, n, max;
    srand(time(NULL));
    
    for(i=1;i<=100;i++) role[i]=0;
    cout<<"введите начальную сумму: "; cin>>money;
    max=money;
    cout<<"введите количество раундов: ";cin>>n;
    cout<<"введите ставку: ";cin>>up;
    cout<<endl;
    up1=up;
    while(n>0 and money>0){
        money-=up1;
        x=rand() % 100 + 1;
        role[x]++;
        if (x<=45) {
            money+=up1*2;
            up1=up;
        }
        else up1*=2;
        if(money>max) max=money;
        n--;
        }
    for(i=1;i<=45;i++) r+=role[i];
    for(i=46;i<=90;i++) b+=role[i];
    for(i=91;i<=100;i++) w+=role[i];
    cout<<"Денег стало: "<<money<<endl<<"Максимальное количество: "<<max<<endl<<endl;
    cout<<"красное: "<<r<<endl;
    cout<<"черное: "<<b<<endl;
    cout<<"белое: "<<w<<endl<<endl;
    cout<<"всего раундов: "<<r+b+w<<endl<<endl;
    return 0;
}
