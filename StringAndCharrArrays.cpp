#include <bits/stdc++.h>
using namespace std;

int getLength(char arr[])
{
    int count = 0;
    for (int i = 0; arr[i] != 0; i++)
    {
        count++;
    }
    return count;
}

char toLowerCase(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || ch >= '0' && ch <= '9')
    {
        return ch;
    }
    else
    {
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

void reverse(char arr[], int n)
{
    int start = 0;
    int end = n - 1; // at index n there will be null character '/0'
    while (start < end)
    {
        swap(arr[start++], arr[end--]);
    }
    cout << "Reversed string: " << arr << endl;
}

char getMaxOccChar(string s)
{
    int arr[26] = {0}; // indexes will represent the characters, a/A is index 0 and z/Z is index 25
    for (int i = 0; i < s.length(); i++)
    {
        int index = 0;
        char ch = s[i];
        if (ch >= 'a' && ch <= 'z')
        { // for lower case
            index = ch - 'a';
        }
        else
        { // for upper case
            index = ch - 'A';
        }
        arr[index]++;
    }

    int max = -1;
    int maxInd = -1;
    for (int i = 0; i < 26; i++)
    {
        if (max < arr[i])
        {
            maxInd = i;
            max = arr[i];
        }
    }

    char ans = 'a' + maxInd;
    return ans;
}

string removeOccurrences (string s, string part){ //wrtite this code without using inbuilt string functions as well!
    while(s.length() !=0 && s.find(part) < s.length()){
        s.erase(s.find(part), part.length());
    }
    return s;
}

int main()
{
    // char arr[20];
    // cin>>arr;
    // cout<<"Length og the string: "<<getLength(arr)<<endl;

    // reverse(arr, getLength(arr));

    string s; // string don't allow you to internally access null character but it stores the data in form of null terminated string.
    cin >> s;
    cout << getMaxOccChar(s);

    // to get input of string with space in char Arrays
    // int length = 20;
    // cin.getline(s, length);

    return 0;
}