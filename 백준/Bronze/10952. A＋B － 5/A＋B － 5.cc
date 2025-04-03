#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>A,B;
    int a,b;
    do{
        cin>>a>>b;
        if(a==0&&b==0)break;
        A.push_back(a);
        B.push_back(b);
    }while(a!=0||b!=0);
    for(int i=0;i<A.size();i++){
        cout<<A.at(i)+B.at(i)<<"\n";
    }
}