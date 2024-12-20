#include<bits/stdc++.h>
using namespace std;

const int M = 41;
const int T = 101;
int m,n,t;
int road[T][M];
vector<int> path;

void dfs(int time,int lane)
{
    if(time == t)
    {
        for(int x : path)
        {
            cout << x << '\n';
        }
        return ;
    }
    if(time > t) return ;
    if(lane-1 >= 1 && road[time+1][lane-1] == 0)
    {
        path.push_back(1);
        dfs(time+1,lane-1);
        path.pop_back();
    }
    if(lane+1 <= m && road[time+1][lane+1] == 0)
    {
        path.push_back(2);
        dfs(time+1,lane+1);
        path.pop_back();
    }
    if(road[time+1][lane] == 0)
    {
        path.push_back(3);
        dfs(time+1,lane);
        path.pop_back();
    }

}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> m >> n >> t;
    for(int i=1;i<=t;++i)
    {
        for(int j=1;j<=m;++j)
        {
            cin >> road[i][j];
        }
    }
    dfs(0,n);
    return 0;
}
