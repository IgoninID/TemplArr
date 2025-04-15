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
    for (size_t i = 0; i < arr.length(); i++)
    {
        cout << arr[i] << " ";
    }
    for (size_t i = 0; i < arr.length(); i++)
    {
        arr[i] = 5;
    }
    for (size_t i = 0; i < arr.length(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}