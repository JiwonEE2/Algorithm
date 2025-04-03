#include<iostream>
using namespace std;
int main(){
    int a,b,c,m,h;
    cin>>a>>b>>c;
    if((a!=b)&&(a!=c)&&(b!=c)){
        if(a>b){
            if(a>c){h=a;}
            else{h=c;}
        }
        else{
            if(b>c){h=b;}
            else{h=c;}
        }
        m=h*100;
    }
    else if(a==b&&b==c){m=10000+a*1000;}
    else if(a==b||a==c){m=1000+a*100;}
    else{m=1000+b*100;}
    cout<<m;
}