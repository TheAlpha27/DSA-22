#include<bits/stdc++.h>
#include<deque>
using namespace std;

int main(){
    deque<int> d;

    d.push_back(1); //pushes an element from the back
    d.push_front(2); //pushes an element from the front
    d.push_back(3);
    for(int i:d){
        cout<<i<<" ";
    }cout<<endl;

    //Random access
    cout<<d.at(1)<<endl;
    cout<<d[1]<<endl;

    //Front and back
    cout<<d.front()<<endl<<d.back()<<endl;

    d.pop_back(); //pops element from back
    for(int i:d){
        cout<<i<<" ";
    }cout<<endl;

    d.pop_front(); //pops element from front
    for(int i:d){
        cout<<i<<" ";
    }cout<<endl;

    cout<<d.empty()<<endl; //Returns 0 if not empty

    d.push_back(3);
    d.push_back(4);
    d.push_back(5);
    d.push_back(6);
    for(int i:d){
        cout<<i<<" ";
    }cout<<endl;
    cout<<"Before erase size: "<<d.size()<<endl; //size() means the number of elements in the structure

    d.erase(d.begin()+1, d.begin()+3); //.begin() gives the iterator at the first element, inside the .erase we have to give a range so here .begin()+1 means that the iterator is at the index 1 and it will delete elements until the iterator reaches the index 3 => elements at index 1 and 2 will be deleted.

    cout<<"After erase size: "<<d.size()<<endl;
    for(int i:d){
        cout<<i<<" ";
    }cout<<endl;

    return 0;
}