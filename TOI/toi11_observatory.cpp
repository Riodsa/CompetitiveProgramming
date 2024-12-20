#include<bits/stdc++.h>
using namespace std;

const int N = 2e3+1;
int n,m;
int arr[N][N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            cin >> arr[i][j];
        }
    }
    return 0;
}
