#include <iostream>
using namespace std;

class Dec{
    const int n = 1000;
    int s[1000];
    int top, bot, i, j;
public:
    void PushFront(int c){
        s[top++]=c;
    }
    void PushBack(int c) {
        for(i=n-1;i>0;i--)
            s[i]=s[i-1];
        s[0]=0;
        top++;
        s[bot]=c;
    }
    
    int PopFront() {
        j=s[top-1];
        s[top-1]=0;
        top--;
        return j;
    }
    
    int PopBack() {
        j=s[bot];
        for(i=0;i<n-1;i++)
            s[i]=s[i+1];
        top--;
        return j;
        
    }
    
    Dec(){
        for(i=0;i<n;i++)
            s[i]=0;
        top=0;
        bot=0;
    }
};

int main() {
    Dec a;
    a.PushBack(1);
    a.PushFront(3);
    a.PushBack(2);
    a.PushFront(4);
    cout<<a.PopFront();
    cout<<a.PopBack();
    a.PushBack(5);
    a.PushFront(6);
    cout<<a.PopFront();
    cout<<a.PopFront();
    cout<<a.PopBack();
    cout<<a.PopBack()<<endl;
    return 0;
}
