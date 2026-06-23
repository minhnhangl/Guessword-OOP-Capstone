#pragma once

#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void printData(T value)
{
    cout << value << endl;
}

template<typename T>
T getMax(T a, T b)
{
    return (a > b) ? a : b;
}