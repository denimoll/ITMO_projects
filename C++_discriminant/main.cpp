
#include <iostream>
#include <math.h>

float fun(float a,float b,float c){
    float D;
    D = b*b - 4*a*c;
    return D;
}

int main() {
    using namespace std;
    setlocale(0, "ru");
    float a,b,c,x1,x2,x,D;
    cout<<"Введите коэффициент a= "; cin>>a;
    cout<<"Введите коэффициент b= "; cin>>b;
    cout<<"Введите коэффициент c= "; cin>>c;
    cout<<"Уравнение имеет вид: "<<a<<"x^2+"<<b<<"x+"<<c<<" = 0"<<endl;
    D = fun(a,b,c);
    if (D>0){
        x1=(-b+sqrt(D))/(2*a);
        x2=(-b-sqrt(D))/(2*a);
        cout<<"Корень x1= "<<x1<<endl;
        cout<<"Корень x2= "<<x2<<endl;
    }
    else if (D==0){
        x=-b/(2*a);
        cout<<"Корень x= "<<x<<endl;
    }
    else{
        cout<<"Решения нет"<<endl;
    }
    return 0;
}
