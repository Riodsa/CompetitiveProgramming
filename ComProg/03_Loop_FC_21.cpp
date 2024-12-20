#include<iostream>
using namespace std;

int main()
{
    double x;
    cin >> x;
    double k=1,t=1;
    t = t*(365-(k-1))/365;
    while(1-t < x)
    {
        k++;
        t = t*(365-(k-1))/365;
    }
    cout << k; 
    return 0;
}