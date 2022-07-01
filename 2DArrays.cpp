#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    //while passing a 2-d array in a function, we have to specify number of columns in the argument while defining the function
    

    return 0;
}