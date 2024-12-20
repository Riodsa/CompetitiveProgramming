#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+1;
const int M = 31;
#define ll long long
int hashh[N],pos[N];

int k,m,q;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> k >> m;
    for(int i=1;i<=k;++i)
    {
        string s;
        cin >> s;
        int sum = 0;
        for(int j=0;j<m;++j) sum = (sum<<1) + (s[j]-'0');
        int idx = sum%N;
        while(pos[idx] != 0)
        {
            ++idx;
            if(idx == N) idx = 0;
        }
        pos[idx] = i;
        hashh[idx] = sum;
    }
    cin >> q;
    while(q--)
    {
        bool safe = true;
        int len;
        cin >> len;
        string s;
        cin >> s;
        bool vis[k+1];
        int sum = 0;
        for(int i=0;i<m-1;++i) sum = (sum<<1) + s[i]-'0';
        for(int i=m-1;i<len;++i)
        {
            sum = (sum<<1) + s[i]-'0';
            int idx = sum%N;
            while(pos[idx] != 0)
            {
                if(hashh[pos[idx]] == sum)
                {
                    vis[pos[idx]] = 1;
                    safe = false;
                    break;
                }
                ++idx;
                if(idx == N) idx = 0;
            }
            sum -= (sum&(1<<m-1));
        }
        if(safe)
        {
            cout << "OK" << '\n';
        }
        else
        {
            for(int i=1;i<=k;++i)
            {
                if(vis[i]) cout << i << " ";
            }
            cout << '\n';
        }
    }
    return 0;
}
