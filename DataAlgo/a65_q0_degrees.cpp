#include<bits/stdc++.h>
using namespace std;

const int N = 5e3+1;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    map<int,int> cnt_deg;
    int max_deg = 0;
    for(int i=0;i<n;++i)
    {
        int cnt = 0;
        for(int j=0;j<n;++j)
        {
            bool x; cin >> x;
            if(x) cnt++;
        }
        // cout << "cnt[" << i << "]: " << cnt << '\n';
        cnt_deg[cnt]++;
        max_deg = max(max_deg,cnt);
    }
    // cout << "max_deg: " << max_deg << '\n';
    for(int i=0;i<=max_deg;++i) cout << cnt_deg[i] << ' ';
    
    return 0;
}