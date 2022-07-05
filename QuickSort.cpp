#include <bits/stdc++.h>
using namespace std;

int partition(int *arr, int s, int e)
{
    int pivot = arr[s];
    int count = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= arr[s])
        {
            count++;
        }
    }
    swap(arr[s], arr[s + count]);
    int pivotInd = s + count;

    int i = s;
    int j = e;

    while (i < pivotInd && j > pivotInd)
    {
        if (arr[i] < pivot)
        {
            i++;
        }
        if (arr[j] > pivot)
        {
            j--;
        }
        if (arr[i] > pivot && arr[j] < pivot)
        {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotInd;
}

void quickSort(int *arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int pivotInd = partition(arr, s, e);
    // handling partition of left
    quickSort(arr, s, pivotInd - 1);
    // handling partition of right
    quickSort(arr, pivotInd + 1, e);

    // partition(arr, s, e);
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

    quickSort(arr, 0, 6);

    cout << "After Sort:" << endl;
    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}