#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<ll> publish;
    while(n--)
    {
        ll year,month;
        cin >> year >> month;
        ll total = 12*year + month;
        publish.push_back(total);
    }
    sort(publish.begin(),publish.end());
    vector<ll> q;
    while(m--)
    {
        ll year,month;
        cin >> year >> month;
        ll total = 12*year + month;
        q.push_back(total);
    }
    for(ll x : q)
    {
        ll total = x;
        int idx = lower_bound(publish.begin(),publish.end(),total)-publish.begin();
        if(publish[idx] == total) cout << "0 0 ";
        else if(idx > 0)
        {
            idx--;
            if(publish[idx]%12==0)
            {
                cout << publish[idx]/12-1 << " 12 ";
            }
            else cout << publish[idx]/12 << ' ' << publish[idx]%12 << ' ';
        }
        else if(idx == 0) cout << "-1 -1 ";
        // cout << '\n';
    }
    return 0;
}