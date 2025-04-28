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
        arr[i] = i;
    }
    cout << "\n";
    for (size_t i = 0; i < arr.length(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    //arr.pushAt(1, 0);
    //arr.popAt(0);
    for (size_t i = 0; i < arr.length(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";

    DynArr<int> arr_popind(8);
    for (size_t i = 0; i < arr_popind.length(); i++)
    {
        arr_popind[i] = i;
    }
    for (size_t i = 0; i < arr_popind.length(); i++)
    {
        cout << arr_popind[i] << " ";
    }
    cout << endl;
    arr_popind.popAt(2) == 2; // память не удаляется
    for (size_t i = 0; i < arr_popind.length(); i++)
    {
        cout << arr_popind[i] << " ";
    }
    cout << endl;
    arr_popind.popAt(0) == 0; // из начала
    for (size_t i = 0; i < arr_popind.length(); i++)
    {
        cout << arr_popind[i] << " ";
    }
    cout << endl;
    arr_popind.popAt(6) == 7; // из конца
    for (size_t i = 0; i < arr_popind.length(); i++)
    {
        cout << arr_popind[i] << " ";
    }
    cout << endl;
    arr_popind.popAt(2) == 4;
    for (size_t i = 0; i < arr_popind.length(); i++)
    {
        cout << arr_popind[i] << " ";
    }
    cout << endl;
    arr_popind.popAt(2) == 5;
    for (size_t i = 0; i < arr_popind.length(); i++)
    {
        cout << arr_popind[i] << " ";
    }
    cout << endl;
    arr_popind.popAt(2) == 6;
    for (size_t i = 0; i < arr_popind.length(); i++)
    {
        cout << arr_popind[i] << " ";
    }
    cout << endl;
    return 0;
}