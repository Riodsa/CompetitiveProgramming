#include<bits/stdc++.h>
using namespace std;

#define iii tuple<int,int,int>

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int r,c;
    cin >> r >> c;
    pair<int,int> idx[4] = {{0,1},{-1,0},{0,-1},{1,0}};
    vector<vector<int>> block(r+1,vector<int>(c+1,0));
    vector<vector<int>> dist(r+1,vector<int>(c+1,1e9+7));
    for(int i=0;i<r;++i)
        for(int j=0;j<c;++j)
            cin >> block[i][j];
    priority_queue<iii,vector<iii>,greater<>> pq;
    dist[0][0] = 0;
    pq.push({dist[0][0],0,0});
    while(!pq.empty())
    {
        auto [d,x,y] = pq.top();
        pq.pop();
        if(d > dist[x][y]) continue;
        for(int i=0;i<4;++i)
        {
            auto [tx,ty] = make_pair(x+idx[i].first,y+idx[i].second);
            if(tx < 0 || tx >= r) continue;
            if(ty < 0 || ty >= c) continue;
            if(dist[tx][ty] > d + block[tx][ty])
            {
                dist[tx][ty] = d + block[tx][ty];
                // cout << "dist[" << tx << "][" << ty << "]: " << dist[tx][ty] << " = dist[" << x << "][" << y << "]: " << dist[x][y] << " + " << block[tx][ty] << '\n';
                pq.push({dist[tx][ty],tx,ty});
            }
        }
    }
    for(int i=0;i<r;++i)
    {
        for(int j=0;j<c;++j)
            cout << dist[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}