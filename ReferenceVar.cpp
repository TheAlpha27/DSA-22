#include<bits/stdc++.h>
using namespace std;

int main(){
    int  i =5;
    int &j = i; //j is a reference variable to i, so j and i are same now

    cout<<i<<endl;
    cout<<j<<endl;

    return 0;
}