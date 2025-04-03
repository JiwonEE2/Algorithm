#include<iostream>
using namespace std;
int main(){
    int T;
    cin>>T;
    int A[T],B[T];
    for(int i=0;i<T;i++){
        cin>>A[i]>>B[i];
    }
    for(int i=0;i<T;i++){
        cout<<A[i]+B[i]<<"\n";
    }
}