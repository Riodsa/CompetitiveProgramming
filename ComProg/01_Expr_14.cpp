#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int year_budda;
    cin >> year_budda;
    int year_chris = year_budda-543;
    int y = year_chris%100;
    cout << (y + (int)floor(y/4) + 11)%7;
    return 0;
}