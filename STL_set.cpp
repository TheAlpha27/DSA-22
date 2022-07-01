#include<bits/stdc++.h>
#include<set>
using namespace std;

int main(){
    //Sets can have only unique elements and elements come out in sorted manner
    //Implemented by BST
    //There is unordered set as well
    set<int> s;
    s.insert(5);
    s.insert(5);
    s.insert(5);
    s.insert(5);
    s.insert(2);
    s.insert(1);
    s.insert(4);
    s.insert(8);
    
    for(auto i:s){
        cout<<i<<endl;
    }
    cout<<endl;

    set<int>::iterator it = s.begin(); //we can get iterator this way as well
    it++;
    s.erase(it);
    for(auto i:s){
        cout<<i<<endl;
    }
    cout<<endl;
    cout<<s.count(5)<<endl; //tells if 5 is present or not

    set<int>::iterator itr = s.find(5); //returns iterator of 5
    cout<<"Value present at itr: "<<*itr<<endl;

    cout<<endl;
    for(auto it = itr; it!=s.end(); it++){ 
        //iterates over the set from itr to the end using the iterator it
        cout<<*it<<endl;
    }

    return 0;
}