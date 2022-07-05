#include<bits/stdc++.h>
using namespace std;

void update1(int i){
    i++;
}
void update2(int &i){
    i++; //this updates the value of n in main function as it is a reference variable
}

int main(){
    int  i =5;
    int &j = i; //j is a reference variable to i, so j and i are same now

    cout<<i<<endl;
    cout<<j<<endl;

    

    return 0;
}