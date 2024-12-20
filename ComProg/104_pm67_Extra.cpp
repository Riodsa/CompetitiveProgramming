#include<bits/stdc++.h>
using namespace std;

int k,n,m;
const int N = 1e5+1;
int num[N];
int moving[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> k >> n >> m;
    for(int i=0;i<m;++i)
    {
        int d,x; cin >> d >> x;
        num[d] = x;
    }
    // for(int i=1;i<=n;++i) cout << num[i] << ' ';
    // cout << '\n';
    for(int i=1;i<=n;++i)
    {
        // cout << num[i] << " : ";
        map<int,int> cnt;
        bool found = false;
        for(int j=max(1,i-k);j<=min(n,i+k);++j)
        {
            // cout << num[j] << ' ';
            if(num[j] != 0)
            {
                cnt[num[j]]++;
                found = true;
            }
        }
        if(!found) moving[i] = -1;
        else
        {
            int maxcnt = -1;
            int mov;
            for(auto it=cnt.begin();it!=cnt.end();++it)
            {
                int c = it->second;
                if(maxcnt < c)
                {
                    maxcnt = c;
                    mov = it->first;
                }
            }
            moving[i] = mov;
        }
        // cout << '\n';
    }
    for(int i=1;i<=n;++i)
    {
        if(moving[i] != -1) cout << moving[i] << ' ';
        else cout << "X ";
    }
    return 0;
}