#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int i=n;i>=1;--i)
    {
        for(int j=i-1;j>=1;--j)
        {
            cout << ".";
        }
        for(int j=1;j<=n-i+1;++j)
        {
            if(j == 1 || i == 1) cout << "*";
            else cout << ".";
        }
        for(int j=1;j<=n-i;++j)
        {
            if(j == n-i || i == 1) cout << "*";
            else cout << ".";
        }
        cout << '\n';
    }
    return 0;
}