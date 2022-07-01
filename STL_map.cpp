#include<bits/stdc++.h>
#include<map>
using namespace std;

int main(){
    //Stores in key-value pair
    //Same key cannot point to different values
    //There is unordered map as well
    //Ordered map is implemented by red black trees

    map<int, string>m; //Sorted map so gives result in sorted key values

    m[1] = "Utsav";
    m[2] = "Soni";
    m.insert({10, "Hello"});
    m[3] = "DSA";
    
    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }

    cout<<"Is 13 present: "<<m.count(13)<<endl;

    m.erase(3); //O(logN), O(1) for unordered maps
    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }

    auto it = m.find(2);
    for(auto i=it; i!=m.end(); i++){
        cout<<(*i).first<<endl;
    }

    return 0;
}