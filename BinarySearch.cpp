#include<bits/stdc++.h>
using namespace std;

int binSearch(int size, int key, int arr[]){
    int low = 0;
    int high = size-1;
    
    while(low<=high){
        // cout<<"Entered while loop"<<endl;

        //high+low can result in integer overflow as high and low each can have MAXINT value at some point in some cases so here either we have to use long long int for mid or we have to convert mid formula to something else

        // int mid = (high+low)/2; //might result in integer overflow

        //int mid = high/2 + low/2; //modified

        int mid = low + (high - low)/2; //another version
        if(arr[mid] == key){
            cout<<key<<" Found at index: "<< mid<<endl;
            return  0;
        }
        if(key > arr[mid]){
            low = mid+1;
        }
        else if(key < arr[mid]){
            high = mid-1;
        }
    }
    cout<<"Key Not Found"<<endl;
    return 0;
}

int main(){
    int arr[] = {2, 5, 10, 12, 15, 29, 40, 43};
    int size = sizeof(arr)/sizeof(int);
    binSearch(size, 43, arr);
    return 0;
}