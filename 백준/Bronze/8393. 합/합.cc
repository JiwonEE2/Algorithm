#include<iostream>
using namespace std;
int main(){
    int n;
    int s=0;
    cin>>n;
    for(int i=0;i<=n;i++){
        s+=i;
    }
    cout<<s;
}