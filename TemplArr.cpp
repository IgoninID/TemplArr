#include <iostream>
#include "Arr.cpp"

using namespace std;


int main()
{
    DynArr<int> arr;
    for (size_t i = 0; i < 6; i++)
    {
        arr.pushBack(i);
    }
    for (size_t i = 0; i < arr.length(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}