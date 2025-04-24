#include <iostream>
#include "Arr.h"

using namespace std;


int main()
{
    test();
    DynArr<int> arr;
    DynArr<int> arr2(5);

    for (size_t i = 0; i < 6; i++)
    {
        arr.pushBack(i);
    }
    cout << "\n";
    for (size_t i = 0; i < arr.length(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    DynArr<int> arr3(arr);
    for (size_t i = 0; i < arr3.length(); i++)
    {
        cout << arr3[i] << " ";
    }
    cout << "\n";
    for (size_t i = 0; i < arr.length(); i++)
    {
        arr[i] = 5;
    }
    cout << "\n";
    for (size_t i = 0; i < arr.length(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}