#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,v;
    cin >> n >> k >> v;
    list<int> l;
    for(int i=0;i<n;++i)
    {
        int x; cin >> x;
        l.push_back(x);
    }
    
    list<int>::iterator it = l.insert(next(l.begin(),k),v);
    if((it != l.begin() || *prev(it) == v) && (next(it) == l.end() || *next(it) != v)) it--;
    if((it == l.begin() || *prev(it) != v) && (next(it) == l.end() || *next(it) == v)) it++;

    while(it != l.end())
    {
        v = *it;
        if(it != l.begin() && *prev(it) == v && next(it) != l.end() && *next(it) == v)
        {
            while(it != l.begin() && *prev(it) == v) l.erase(prev(it));
            while(next(it) != l.end() && *next(it) == v) l.erase(next(it));
            it = l.erase(it);
        }
        else break;
    }
    for(int a : l) cout << a << ' ';
    return 0;
}