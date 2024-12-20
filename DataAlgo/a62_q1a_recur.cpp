#include<bits/stdc++.h>
using namespace std;

int a,b;
int n;
const int N = (1<<8)+1;
int arr[N][N];

void solve(int a,int b,int r,int c)
{
    if(a == 0)
    {
        arr[r][c] = b;
        return ;
    }
    int g = 1<<(a-1);
    solve(a-1,b,r,c);
    solve(a-1,b-1,r,c+g);
    solve(a-1,b+1,r+g,c);
    solve(a-1,b,r+g,c+g);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> a >> b;
    n = (1<<a);
    solve(a,b,1,1);
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}