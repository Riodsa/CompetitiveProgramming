#include<bits/stdc++.h>
using namespace std;

int mpow(int a,int b)
{
    if(b == 0) return 1;
    int x = mpow(a,b/2) * mpow(a,b/2);
    x = (b%2==1)?x*a:x;
    return x;
}

bool isChild(int x,int par)
{
    while(x != 0 && x != par)
    {
        x = (x-1)/2;
    }
    if(x == par) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> vec;
    for(int i=0;i<n;++i)
    {
        if(i != m && !isChild(i,m)) vec.push_back(i);
    }
    cout << vec.size() << '\n';
    for(int x : vec) cout << x << ' ';
    return 0;
}