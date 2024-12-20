#include<iostream>
#include<vector>
#include<map>
using namespace std;

int n,a,b;
bool can_go = false;
map<int,vector<int>> g;

void go(int u)
{
    if(u == b) can_go = true;
    for(int v : g[u])
    {
        go(v);
    }
}

int main()
{
    cin >> n >> a >> b;
    for(int i=0;i<n;++i)
    {
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    go(a);
    if(can_go) cout << "yes";
    else cout << "no";
    return 0;
}