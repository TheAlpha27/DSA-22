#include<bits/stdc++.h>
#include<list>
using namespace std;

int main(){
    //List in STL is created using doubly linked list
    list <int> l;

    list <int> l1(l);
    list <int> l2(5, 100);

    l.push_back(1);
    l.push_front(2);
    for(int i:l){
        cout<<i<<" ";
    }cout<<endl;

    //Here direct access is not possible so delete and other similar functions TC will be O(n).

    cout<<"After erasing the 1st element from front"<<endl;
    l.erase(l.begin()); //deletes the element the iterator is pointing to
    for(int i:l){
        cout<<i<<" ";
    }cout<<endl;
    
    //Other functions like size also exists

    return 0;
}