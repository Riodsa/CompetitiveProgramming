#include <iostream>
using namespace std;

string h[17] = {"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};

string dec2hex(int d) 
{
    if (d < 16) return h[d];
    return dec2hex(d/16) + dec2hex(d%16);
}

int main() 
{
    int d;
    while (cin >> d) 
    {
        cout << d << " -> " << dec2hex(d) << '\n';
    }
    return 0;
}