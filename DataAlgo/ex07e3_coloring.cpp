#include<bits/stdc++.h>
using namespace std;

const int N = 5e1+1;
vector<int> g[N];
int n,m;

bool coloring(int u,int m,vector<int> &color)
{
    if(u == n) return true;
    for(int i=1;i<=m;++i)
    {
        bool canUse = true;
        for(int v : g[u])
        {
            if(i == color[v])
            {
                canUse = false;
                break;
            }
        }
        if(canUse)
        {
            color[u] = i;
            if(coloring(u+1,m,color)) return true;
            color[u] = 0;
        }
    }
    return false;
}

bool valid(int m)
{
    vector<int> color(n,0);
    return coloring(0,m,color);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<m;++i)
    {
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int l = 1,r = n;
    int ans = n;
    while(l <= r)
    {
        int mid = (l+r)/2;
        if(valid(mid))
        {
            ans = mid;
            r = mid-1;
        }
        else l = mid+1;
    }
    cout << ans;
    return 0;
}