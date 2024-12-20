#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
const int N = 151;
int n,m;
int b[N][N];
int vis1[N][N];
int vis2[N][N];
int dis1[N][N];
int dis2[N][N];
int bomb = 0;
int mindis = 1e9+7;
pii idx[4] = {{-1,0},{0,1},{1,0},{0,-1}};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    pii s,e;
    cin >> s.first >> s.second;
    cin >> e.first >> e.second;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            cin >> b[i][j];
        }
    }
//    cout << "\n\n";
    queue<pii> q;
    dis1[s.first][s.second] = 1;
    dis2[e.first][e.second] = 1;
    vis1[s.first][s.second] = 1;
    vis2[e.first][e.second] = 1;
    q.push({s.first,s.second});
    while(!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for(int i=0;i<4;++i)
        {
            int rr = r+idx[i].first;
            int cc = c+idx[i].second;
            if(rr < 1 || rr > n || cc < 1 || c > m) continue;
            if(vis1[rr][cc] > 0) continue;
            vis1[rr][cc]++;
            dis1[rr][cc] += dis1[r][c] + 1;
            if(b[rr][cc] == 1) q.push({rr,cc});
        }
    }
    q.push({e.first,e.second});
    while(!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for(int i=0;i<4;++i)
        {
            int rr = r+idx[i].first;
            int cc = c+idx[i].second;
            if(rr < 1 || rr > n || cc < 1 || c > m) continue;
            if(vis2[rr][cc] > 0) continue;
            vis2[rr][cc]++;
            dis2[rr][cc] += dis2[r][c] + 1;
            if(b[rr][cc] == 1) q.push({rr,cc});
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            if(vis1[i][j] && vis2[i][j])
            {
                ++bomb;
                mindis = min(mindis,dis1[i][j] + dis2[i][j]-1);
            }
        }
    }
    cout << bomb << '\n' << mindis;
    return 0;
}
