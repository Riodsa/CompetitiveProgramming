#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
const int N = 5e2+1;
int m,n;

void solve()
{
    cin >> n >> m;
    int tree;
    cin >> tree;
    set<pii> pos;
    for(int i=0;i<tree;++i)
    {
        int x,y;
        cin >> x >> y;
        pos.insert({x,y});
    }

}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 2;
    while(t--)
    {
        solve();
    }
    return 0;
}
