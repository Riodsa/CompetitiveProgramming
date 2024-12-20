#include <bits/stdc++.h>
using namespace std;

int n, m;
const int N = 1e6 + 1;
map<string, vector<string>> g;
map<string, string> grndpa;
set<string> ppl;

void dfs(string s, string u, int cnt)
{
    if (cnt == 2)
    {
        grndpa[s] = u;
        return;
    }
    if (!g[u].empty())
    {
        for (string v : g[u])
        {
            dfs(s, v, cnt + 1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        string f, s;
        cin >> f >> s;
        g[s].push_back(f);
        ppl.insert(f);
        ppl.insert(s);
    }
    for(string x : ppl)
    {
        dfs(x,x,0);
    }
    // cout << '\n';
    // for(string x : ppl)
    // {
    //     cout << x << " = " << grndpa[x] << '\n';
    // }
    // cout << '\n';
    for(int i=0;i<m;++i)
    {
        string a,b;
        cin >> a >> b;
        (a!=b && (grndpa[a] != "" || grndpa[b] != "") && grndpa[a] == grndpa[b]) ? cout << "YES\n" : cout << "NO\n";
    }
    return 0;
}