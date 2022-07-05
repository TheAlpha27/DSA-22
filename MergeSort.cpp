#include <bits/stdc++.h>
using namespace std;

void merge(int *arr, int s, int e)
{
    int mid = (s + e) / 2;
    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *arr1 = new int[len1];
    int *arr2 = new int[len2];

    int mainArrInd = s;

    // Copying the partitioned arrays into two newly created arrays
    for (int i = 0; i < len1; i++)
    {
        arr1[i] = arr[mainArrInd++];
    }
    mainArrInd = mid+1;
    for (int i = 0; i < len2; i++)
    {
        arr2[i] = arr[mainArrInd++];
    }

    // cout << "Arr1: ";
    // for (int i = s; i <= mid; i++)
    // {
    //     cout << arr1[i] << " ";
    // }
    // cout << "Arr2: ";
    // for (int i = mid + 1; i <= e; i++)
    // {
    //     cout << arr1[i] << " ";
    // }

    int ind1 = 0;
    int ind2 = 0;
    mainArrInd = s;
    while (ind1 < len1 && ind2 < len2)
    {
        if (arr1[ind1] < arr2[ind2])
        {
            arr[mainArrInd++] = arr1[ind1++];
        }
        else
        {
            arr[mainArrInd++] = arr2[ind2++];
        }
    }
    while (ind1 < len1)
    {
        arr[mainArrInd++] = arr1[ind1++];
    }
    while (ind2 < len2)
    {
        arr[mainArrInd++] = arr2[ind2++];
    }
    delete []arr1;
    delete []arr2;
    return;
}

void mergeSort(int *arr, int s, int e)
{
    if (s >= e)
    { // base case
        // cout << "Entered base case" << endl;
        return;
    }
    int mid = (s + e) / 2;
    // cout << "Value of s, e, mid: " << s << ", " << e << ", " << mid << endl;

    // left part
    mergeSort(arr, s, mid);
    // Right part
    mergeSort(arr, mid + 1, e);

    merge(arr, s, e);
}

int main()
{
    int arr[] = {8, 2, 10, 7, 6, 11, 5};
    cout << "Before sort:" << endl;
    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl
         << endl;

    mergeSort(arr, 0, 6);

    cout << "After Sort:" << endl;
    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}