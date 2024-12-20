#include<iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n12,sum=0;
    int p = 13;
    for(int i=0;i<12;++i)
    {
        sum += p*(s[i]-'0');
        p--;
    }
    sum %= 11;
    n12 = (11-sum)%10;
    for(int i=0;i<12;++i)
    {
        cout << s[i];
        if(i == 0 || i == 4 || i == 9 || i == 11) cout << "-";
    }
    cout << n12;
    return 0;
}