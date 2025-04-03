#include<iostream>
int main(){
    int num1,num2;
    std::cin>>num1;
    std::cin>>num2;
    std::cout.precision(10);
    double re=num1/(double)num2;
    std::cout<<re;
}