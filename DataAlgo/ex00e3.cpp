#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    set<int> s,a;
    for(int i=1;i<=n;++i) s.insert(i);
    for(int i=0;i<n;++i)
    {
        int x; cin >> x;
        a.insert(x);
    }
    (s == a) ? cout << "YES" : cout << "NO";
    return 0;
}