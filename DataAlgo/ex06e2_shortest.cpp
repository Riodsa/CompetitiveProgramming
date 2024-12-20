#include<bits/stdc++.h>
using namespace std;

#define iii tuple<int,int,int>
const int N = 1e2+1;
const int INF = 1e9+7;
int n,m,s;
vector<iii> edges;
int dist[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> s;
    fill(dist,dist+n+1,INF);
    for(int i=0;i<m;++i)
    {
        int u,v,w;
        cin >> u >> v >> w;
        edges.push_back({u,v,w});
    }
    dist[s] = 0;
    for(int i=0;i<n-1;++i)
    {
        for(auto [u,v,w] : edges)
        {
            if(dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
            }
        }
    }
    bool hasNegLoop = false;
    for(auto [u,v,w] : edges)
    {
        if(dist[v] > dist[u] + w)
        {
            hasNegLoop = true; 
            break;
        }
    }
    if(!hasNegLoop)
    {
        for(int i=0;i<n;++i) cout << dist[i] << ' ';
    }
    else cout << "-1";
    return 0;
}