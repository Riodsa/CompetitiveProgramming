#include<bits/stdc++.h>
using namespace std;
int n;
int minans1 = INT_MAX,minans2 = INT_MAX;
int maxans1 = INT_MIN,maxans2 = INT_MIN;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    int x1,x2;
    for(int i=1;i<=n;++i)
    {
        cin >> x1 >> x2;
        if(i%2 == 0)
        {
            minans1 = min(minans1,x2);
            maxans1 = max(maxans1,x1);
            minans2 = min(minans2,x1);
            maxans2 = max(maxans2,x2);
        }
        else
        {
            minans2 = min(minans2,x2);
            maxans2 = max(maxans2,x1);
            minans1 = min(minans1,x1);
            maxans1 = max(maxans1,x2);
        }
    }
    string s;
    cin >> s;
    if(s == "Zig-Zag") cout << minans1 << ' ' << maxans1;
    else cout << minans2 << ' ' << maxans2;
    return 0;
}