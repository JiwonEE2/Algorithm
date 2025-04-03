#include<iostream>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    int c=a*(b%10),d=a*(b%100/10),e=a*(b/100),f=c+d*10+e*100;
    cout<<c<<endl<<d<<endl<<e<<endl<<f;
}