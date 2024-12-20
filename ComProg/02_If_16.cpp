#include<iostream>
using namespace std;

int main()
{
    int x;
    cin >> x;
    if(x == 0) cout << "zero";
    else if(x > 0) cout << "positive";
    else cout << "negative";
    cout << '\n';
    if(abs(x)%2 == 1) cout << "odd";
    else cout << "even";
    return 0;
}