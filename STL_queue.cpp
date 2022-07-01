#include<bits/stdc++.h>
#include<queue>
using namespace std;

int main(){
    queue <string> q;
    //follows FIFO
    q.push("Utsav");
    q.push("Soni");
    q.push("DSA");

    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front()<<endl<<q.back()<<endl;
    cout<<q.size()<<endl;

    return 0;
}