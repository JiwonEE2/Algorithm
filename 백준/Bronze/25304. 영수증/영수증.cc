#include<iostream>
using namespace std;
int main(){
    int X,N;
    int s=0;
    cin>>X>>N;
    int a[N],b[N];
    for(int i=0;i<N;i++){
        cin>>a[i]>>b[i];
        s+=a[i]*b[i];
    }
    if(s==X){cout<<"Yes";}
    else{cout<<"No";}
}