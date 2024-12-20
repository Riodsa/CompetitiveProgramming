#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+1;
const int K = 1e4+1;
int n,k,t;
int lvl[N];
int degree[N];
struct tech
{
    int id,lvl;

    bool operator<(const tech &x)const{
        return lvl < x.lvl;
    }
};
set<tech> lvll[K];
vector<tech> nextdo[N];
vector<tech> need[N];
queue<tech> q;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k >> t;
    for(int i=1;i<=n;++i)
    {
        int l,p;
        cin >> l >> p;
        degree[i] += p;
        lvll[l].insert({i,l});
        for(int j=0;j<p;++j)
        {
            int v; cin >> v;
            nextdo[v].push_back({i,l});
        }
        if(p == 0)
        {
            q.push({i,l});
        }
    }
//    for(int i=1;i<=n;++i)
//    {
//        cout << "nextdo[" << i << "] : ";
//        for(tech v : nextdo[i])
//        {
//            cout << v.id << " ";
//        }
//        cout << '\n';
//    }
    while(!q.empty())
    {
        tech u = q.front();
//        cout << u.id << " ";
        q.pop();
        t--;
        lvll[u.lvl].erase({u.id,u.lvl});
        for(int i=1;i<=k;++i)
        {
            if(lvll[i].empty()) continue;
            else
            {
                for(auto v : lvll[i])
                {
                    q.push(v);
                }
                break;
            }
        }
        if(t == 0) break;
        for(auto v : nextdo[u.id])
        {
            degree[v.id]--;
            if(degree[v.id] == 0)
            {
                q.push(v);
            }
        }
    }
//    cout << '\n';
    int ans = -1;
    for(int i=1;i<=k;++i)
    {
//        cout << lvl[i] << " ";
        if(lvll[i].empty()) ans = i;
        else break;
    }
    cout << ans;
    return 0;
}
