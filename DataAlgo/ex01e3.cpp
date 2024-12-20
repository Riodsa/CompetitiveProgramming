#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+1;
int n,q;
int num[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    for(int i=1;i<=n;++i) cin >> num[i];
    while(q--)
    {
        int x; cin >> x;
        int l = 1,r = n,mid = (l+r)/2;
        int ans = -1;
        // cout << "x: " << x << '\n';
        while(l <= r)
        {
            mid = (l+r)/2;
            // cout << "l: " << l << " r: " << r << " mid: " << num[mid] << '\n';
            if(num[mid] <= x)
            {
                l = mid+1;
                ans = num[mid];
            }
            else r=mid-1;
        }
        // cout << '\n';
        if(ans>x) cout << "-1\n";
        else cout << ans << '\n';
        // cout << num[mid] << '\n';
    }
    return 0;
}