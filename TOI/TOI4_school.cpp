#include<bits/stdc++.h>
using namespace std;

const int N = 65;
int n,m;
char b[N][N];

int main()
{
    cin >> n >> m;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            cin >> b[i][j];
        }
    }
    return 0;
}
