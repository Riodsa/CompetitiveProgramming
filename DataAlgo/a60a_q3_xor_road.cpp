#include<bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define pui pair<ull,int>
const int N = 2e3+1;
const int INF = 1e9+7;
priority_queue<pui> pq;
ull node[N];
ull cost[N];
ull mst = 0;
bool taken[N];
int n;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=0;i<n;++i)
    {
        cin >> node[i];
        taken[i] = false;
        cost[i] = 1;
    }
    cost[0] = 0;
    pq.push({cost[0],0});
    while(!pq.empty())
    {
        auto [w,u] = pq.top();
        pq.pop();
        // cout << "start: " << u << ' ' << w << '\n';
        taken[u] = true;
        for(int j=0;j<n;++j)
        {
            if(u != j && !taken[j])
            {
                int c = node[u]^node[j];
                // cout << u << ' ' << node[j] << " : " << c << '\n';
                // cout << "c: " << c << " cost[j]: " << cost[j] << '\n';
                if(c > cost[j])
                {
                    // cout << "FOUND";
                    cost[j] = c;
                    pq.push({cost[j],j});
                }
            }
        }
    }
    for(int i=0;i<n;++i) mst += cost[i];
    cout << mst << '\n';
    return 0;
}