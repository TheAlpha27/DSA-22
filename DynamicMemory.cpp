#include <bits/stdc++.h>
using namespace std;

int main()
{
    // we can allocate memory in heap using 'new' keyword
    char *ptr = new char; // new returns address of the block created in heap

    int size;
    cin >> size;

    int *arr = new int[size]; // variable size array //this takes size*4 byte memory in heap and 8 byte in stack (as arr is a pointer)

    if (true)
    {
        int *ptr = new int;
    } // after coming out of the scope of if, ptr is deleted as it is in stack but the memory allocated in heap remains retained.
    int *n = new int;
    delete n;     // deletes memory in heap
    delete[] arr; // deletes the array in heap

    return 0;
}