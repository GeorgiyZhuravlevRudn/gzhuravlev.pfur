#include<iostream>
using namespace std;

void Moreless(const int &n);

void Input(){

int n;

cout<<"give a number:"; cin>>n;

Moreless(n);

}

void Moreless(const int &n){

n>0? exit(0) : n==0? exit(1) : exit(2);

}

int main(){

Input();

return(3);

}
