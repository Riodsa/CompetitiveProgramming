#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+1;
int arr[N][N];
int ans = INT_MIN;
int n;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            cin >> arr[i][j];
            arr[i][j] = max(arr[i][j],arr[i-1][j-1]+arr[i][j]);
            ans = max(ans,arr[i][j]);
        }
    }
    cout << ans;
    return 0;
}