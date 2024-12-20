#include <bits/stdc++.h>
using namespace std;

#define iii tuple<int, int, int>
const int N = 1e3 + 1;
int n;
int par[N];
int si[N];
int mst = 0;

vector<iii> edges;

int root(int u)
{
    if (par[u] == u)
        return u;
    par[u] = root(par[u]);
    return par[u];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        par[i] = i;
        si[i] = 1;
    }
    int u = 0, v = 1;
    for (int j = n - 1; j >= 0; --j)
    {
        for (int i = 0; i < j; ++i)
        {
            int w;
            cin >> w;
            edges.push_back({w, u, v + i});
        }
        u++;
        v++;
    }
    sort(edges.begin(), edges.end());
    for (auto [w, u, v] : edges)
    {
        int pu = root(u);
        int pv = root(v);
        if (pu == pv)
            continue;

        if (si[pu] <= si[pv])
        {
            si[pv] += si[pu];
            par[pu] = pv;
        }
        else
        {
            si[pu] += si[pv];
            par[pv] = pu;
        }
        mst += w;
    }
    cout << mst;
    return 0;
}