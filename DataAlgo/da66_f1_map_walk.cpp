#include<bits/stdc++.h>
using namespace std;

int R,C;
const int N = 11;
bool board[N][N];
bool vis[N][N];

void go(int r,int c,string path)
{
    if(r == R && c == C)
    {
        cout << path << '\n';
        return ;
    }
    vis[r][c] = true;
    if(c < C && !board[r][c+1] && !vis[r][c+1]) go(r,c+1,path+'A');
    if(r < R && !board[r+1][c] && !vis[r+1][c]) go(r+1,c,path+'B');
    if(r > 1 && !board[r-1][c] && !vis[r-1][c]) go(r-1,c,path+'C');
    vis[r][c] = false;
} 

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> R >> C;
    for(int i=1;i<=R;++i)
        for(int j=1;j<=C;++j)
            cin >> board[i][j];
    go(1,1,"");
    cout << "DONE\n";
    return 0;
}
