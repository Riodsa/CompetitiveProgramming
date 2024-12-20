#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    int num[n+1];
    int cnt[4];
    int x[4][4];
    for(int i=1;i<=3;++i) cnt[i] = 0;
    for(int i=1;i<=3;++i)
        for(int j=1;j<=3;++j)
            x[i][j] = 0;
    for(int i=1;i<=n;++i)
    {
        cin >> num[i];
        cnt[num[i]]++;
    }
    for(int i=1;i<=cnt[1];++i) x[1][num[i]]++;
    for(int i=cnt[1]+1;i<=cnt[1]+cnt[2];++i) x[2][num[i]]++;
    for(int i=cnt[1]+cnt[2]+1;i<=n;++i) x[3][num[i]]++;
    int ans_1 = x[1][2] + x[1][3] + x[2][3];
    int ans_2 = x[3][1] + x[3][2] + x[2][1];
    if(x[1][2] >= x[2][1]) cout << ans_1;
    else cout << ans_2;
    return 0;
}