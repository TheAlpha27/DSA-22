#include<bits/stdc++.h>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    vector<int> v;
    v.push_back(3);
    v.push_back(1);
    v.push_back(4);
    v.push_back(14);
    v.push_back(9);
    v.push_back(6);

    cout<<binary_search(v.begin(), v.end(), 4)<<endl;

    for(auto i:v){
        cout<<i<<" ";
    }cout<<endl;

    rotate(v.begin(), v.begin()+3, v.end()); //rotates the vector until the second parameter iterator comes at the begin position

    for(auto i:v){
        cout<<i<<" ";
    }cout<<endl;

    //Lower bound and upper bound works only on sorted arrays/vectors.
    sort(v.begin(), v.end());
    cout<<"sorted vector:"<<endl;
    for(auto i:v){
        cout<<i<<" ";
    }cout<<endl;
    cout<<"Lower bound of 6: "<<*lower_bound(v.begin(), v.end(), 6)<<endl; //returns the iterator of the element equal to the key given if found, else returns least greatest element than the key.
    cout<<"Upper bound of 1: "<<*upper_bound(v.begin(), v.end(), 1)<<endl; //always returns the iterator of the least greatest element than the key even if the key exists in the array/vector.
    //if key is greater than the last element in the sorted vector then it returns v.end() iterator.

    //Other functions are like max(a,b), swap(a,b), reverser(s.begin(), s.end()), sort(v.begin(), v.end()) based on intro sort.

    return 0;
}