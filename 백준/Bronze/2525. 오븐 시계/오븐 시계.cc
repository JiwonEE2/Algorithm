#include<iostream>
using namespace std;
int main(){
    int A,B,C,temp;
    cin>>A>>B;
    cin>>C;
    B+=C;
    if(B>=60){
        temp=B/60;
        B-=(temp*60);
        A+=temp;
    }
    if(A>=24){
        A-=24;
    }
    cout<<A<<" "<<B;
}