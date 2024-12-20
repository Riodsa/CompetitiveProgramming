#include<iostream>
using namespace std;

int main()
{
    long long num;
    cin >> num;
    for(int i=2;i<=num;++i)
    {
        if(num%i == 0)
        {
            while(num%i == 0)
            {
                cout << i;;
                num /= i;
                if(num != 1) cout << "*";
            }
        }
    }
    return 0;
}