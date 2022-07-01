#include<bits/stdc++.h>
#include<vector>
using namespace std;

int main(){
    vector<int> v;
    cout<<"Capacity: "<<v.capacity()<<endl; //capacity will be 0

    v.push_back(1);
    cout<<"Capacity: "<<v.capacity()<<endl; //capacity will be 1

    v.push_back(4);
    cout<<"Capacity: "<<v.capacity()<<endl; //capacity will be 2
    
    v.push_back(2);
    cout<<"Capacity: "<<v.capacity()<<endl; //capacity will be 4
    cout<<"Size: "<<v.size()<<endl; //size will be 3

    v.push_back(5);
    cout<<"Capacity: "<<v.capacity()<<endl; //capacity will be 4

    //Random Access:
    cout<<v.at(2)<<endl;
    cout<<v[1]<<endl;
    
    //Other funcs:
    cout<<v.front()<<endl<<v.back()<<endl; //prints 1st and last element of vector array

    cout<<"Before pop:"<<endl;
    for(int i:v){ //Can be used to iterate over vector array
        cout<<i<<" ";
    }
    cout<<endl;

    v.pop_back();

    cout<<"After pop:"<<endl;
    for(int i:v){
        cout<<i<<" ";
    }
    cout<<endl;

    cout<<"Size before clear: "<<v.size()<<endl<<"Capacity before clear: "<<v.capacity()<<endl;
    v.clear();
    cout<<"Size after clear: "<<v.size()<<endl<<"Capacity after clear: "<<v.capacity()<<endl; //Capacity remains same even after clearing the vector

    //Other ways to initialize the vector: 
    vector <int> a(5,1); //5 is the size and every slot is initialized with value 1
    for(int i:a){
        cout<<i<<" ";
    }
    cout<<endl;

    vector <int> c(a); //creates a vector c which is a copy of a
    for(int i:c){
        cout<<i<<" ";
    }
    cout<<endl;

    //We can use begin function to get the iterator of the vector

    return 0;
}