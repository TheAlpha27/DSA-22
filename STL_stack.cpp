#include<bits/stdc++.h>
#include<stack>
using namespace std;

int main(){
    stack<string> s;
    //follows LIFO
    s.push("Utsav");
    s.push("Soni");
    s.push("DSA");

    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    cout<<s.size()<<endl;
    cout<<s.empty()<<endl;

    return 0;
}