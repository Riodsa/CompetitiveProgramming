#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
const int N = 27;
int n;
vector<pii> g[N];
bool vis[N][N];

void dfs(int u,int cnt,string path)
{
    for(pii v : g[u])
    {
        if(vis[u][v] != 1 && vis[v][u] != 1)
        {
            dfs(v,cnt+1,path)
        }
    }
}

int main()
{
    ios_base::sync_with_stdio();
    cin >> n;
    for(int i=1;i<=n;++i)
    {
        string a;
        cin >> a;
        int u,v;
        u = a[0]-'A'+1, v = a[1]-'A'+1;
        g[u].push_back({v,i});
        g[v].push_back({u,i});
    }
//    for(int i=1;i<=26;++i)
//    {
//        if(g[i].empty()) continue;
//        cout << (char)(i+'A'-1) << " : ";
//        for(pii v : g[i])
//        {
//            cout << (char)(v.first+'A'-1) << " ";
//        }
//        cout << '\n';
//    }
    dfs(1,1,"");
    return 0;
}
