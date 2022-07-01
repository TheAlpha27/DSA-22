#include <bits/stdc++.h>
using namespace std;

void update(int *p)
{
    // p = p + 1;                              // we cannot update the address of the pointer outside the function
    cout << "Inside update: " << p << endl; // here the value is shown updated but the same do not appears in the main function.
    *p = *p + 1;                            // we can update the value of the variable at the p is pointing to!
}

// function(int arr[])
// function(int *arr)
// both the above definitions are same, i.e array when passed as an argument, the pointer is passed.

int main()
{
    int arr[10] = {23, 122, 41, 67};
    cout << "Address of 1st block of arr: " << arr << endl;
    cout << "Address of 1st block of arr: " << &arr[0] << endl;
    cout << "Value at index 0: " << *arr << endl;
    cout << "Value at index 1: " << *(arr + 1) << endl;
    cout << "Value at index 0 + 1: " << *arr + 1 << endl;

    // arr[i] = *(arr + i);
    //=> i[arr] = *(i + arr);
    cout << "Value at index 1: " << arr[1] << endl;
    cout << "Value at index 1: " << 1 [arr] << endl;

    char ch[6] = "abcde";
    cout << ch << endl; // prints the whole strings instead of address of first block.
    char *ptr = &ch[0];
    cout << ptr << endl; // this also prints the entire string.

    char temp = 'z';
    char *p = &temp;
    cout << p << endl; // this prints the character first and keeps going on along the contagious memory until it finds a null character

    int a = 10;
    int *ptr1 = &a;

    // int *ptr and int* ptr both are same

    cout << "Before update: " << ptr1 << endl;
    cout << "Before update the value is : " << *ptr1 << endl;
    update(ptr1);
    cout << "After update: " << ptr1 << endl;               // same as before!!
    cout << "After update the value is: " << *ptr1 << endl; // the value gets updated

    int **p1 = &ptr1; //p1 is pointer to ptr1 i.e pointer to pointer.

    return 0;
}