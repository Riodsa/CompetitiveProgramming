#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
const int A = 101;
int a,b;
char p[A][A];
bool vis[A][A];

int main()
{
    cin >> a >> b;
    for(int i=1; i<=a; i++)
    {
        for(int j=1; j<=b; j++)
        {
            cin >> p[i][j];
            vis[i][j] = 0;
        }
    }
    queue<pair<ll,pii>> q;
    q.push({1,{1,1}});
    while(!q.empty())
    {
        int d = q.front().first;
        int r = q.front().second.first;
        int c = q.front().second.second;
        q.pop();
        if(r<1 || r>a || c<1 || c>b) continue;
        if(vis[r][c])
        {
            cout << d << '\n';
            cout << r << " " << c;
            return 0;
        }
        else
        {
            vis[r][c] = true;
            if(p[r][c] == 'R' && c+1 <= b && !vis[r][c+1]) q.push({d+1,{r,c+1}});
            else if(p[r][c] == 'D' && r+1 <= a && !vis[r+1][c]) q.push({d+1,{r+1,c}});
            else if(p[r][c] == 'B')
            {
                if(r+1<=a && !vis[r+1][c]) q.push({d+1,{r+1,c}});
                if(c+1<=b && !vis[r][c+1]) q.push({d+1,{r,c+1}});
            }
            if(r-1>0 && p[r-1][c] == 'D' && !vis[r-1][c]) q.push({d+1,{r-1,c}});
            if(r-1>0 && p[r-1][c] == 'B' && !vis[r-1][c]) q.push({d+1,{r-1,c}});
            if(c-1>0 && p[r][c-1] == 'R' && !vis[r][c-1]) q.push({d+1,{r,c-1}});
            if(c-1>0 && p[r][c-1] == 'B' && !vis[r][c-1]) q.push({d+1,{r,c-1}});
        }
    }
    return 0;
}

