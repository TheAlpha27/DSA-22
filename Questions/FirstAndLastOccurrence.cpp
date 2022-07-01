#include<bits/stdc++.h>
using namespace std;


int firstOccur(int arr[], int size, int key, int high, int low){
    int mid = low + (high - low)/2;
    while(low<=high){
        mid = low + (high - low)/2;
        // cout<<"Entered FO"<<endl;
        // cout<<"Low: "<<low<<" High: "<<high<<endl;
        if(arr[mid]==key && arr[mid-1] != key){
            return mid;
        }
        else if(arr[mid] == key){
            high = mid-1;
        }
        if(key>arr[mid]){
            low = mid+1;
        }
        if(key<arr[mid]){
            high = mid-1;
        }
    }
}

int lastOccur(int arr[], int size, int key, int low, int high){
    int mid = low + (high - low)/2;
    while(low<=high){
        mid = low + (high - low)/2;
        // cout<<"Entered LO"<<endl;
        // cout<<"Low: "<<low<<" High: "<<high<<endl;
        if(arr[mid]==key && arr[mid+1] != key){
            return mid;
        }
        else if(arr[mid] == key){
            low = mid+1;
        }
        if(key>arr[mid]){
            low = mid+1;
        }
        if(key<arr[mid]){
            high = mid-1;
        }
    }
}

void result(int arr[], int size, int key){
    int high = size-1;
    int low = 0;
    int first, last;
    int mid = low + (high-low)/2;
    int check = 0;
    while(low<=high){
        mid = low + (high-low)/2;
        // cout<<"Entered BS"<<endl;
        // cout<<"Low: "<<low<<" High: "<<high<<" Mid: "<<mid<<endl;
        if(arr[mid]==key){
            cout<<"Key Found"<<endl;
            if(arr[mid-1]==key){
                first = firstOccur(arr, size, key, mid, low);
                cout<<"First Occurrence of "<<key<<" is at index: "<<first<<endl;
                check = 1;
            }
            if(arr[mid-1]!=key){
                first = mid;
                cout<<"First Occurrence of "<<key<<" is at index: "<<first<<endl;
            }
            if(arr[mid+1] ==key){
                last = lastOccur(arr, size, key, mid, high);
                cout<<"Last Occurrence of "<<key<<" is at index: "<<last<<endl;
            }
            if(arr[mid+1] != key){
                last = mid;
                cout<<"Last Occurrence of "<<key<<" is at index: "<<last<<endl;
            }
            return;
        }
        if(key>arr[mid]){
            low = mid+1;
        }
        if(key<arr[mid]){
            high = mid-1;
        }
    }
    if(check != 1){
        cout<<"Key not found"<<endl;
    }
    return;
}

int main(){
    int arr[] = {0, 1, 1, 2, 3, 3, 3, 3, 3, 5, 5, 5, 6, 6};
    int size = sizeof(arr)/sizeof(int);
    result (arr, size, 8);
    return 0;
}