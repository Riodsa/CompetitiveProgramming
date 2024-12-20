#include<bits/stdc++.h>
using namespace std;

int n,a,b;
const int N = 1e6+1;
vector<int> g[N];
int cnt = 0;
set<vector<int>> ans;
void to(vector<int> path,int now)
{
    path.push_back(now);
    if(now == b)
    {
        ans.insert(path);
        ++cnt;
    }
    for(int v : g[now])
    {
        to(path,v);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> a >> b;
    vector<int> room;
    for(int i=0;i<n;++i)
    {
        int u,v;
        cin >> u >> v;
        room.push_back(u);
        g[u].push_back(v);
    }
    // for(int x : room) sort(g[x].begin(),g[x].end());
    vector<int> v;
    to(v,a);
    if(cnt == 0) cout << "no";
    else
    {
        for(auto aa : ans)
        {
            int ss = aa.size();
            for(int i=0;i<ss;++i)
            {
                cout << aa[i];
                if(i != ss-1) cout << " -> ";
            }
            cout << '\n';
        }
    }
    return 0;
}