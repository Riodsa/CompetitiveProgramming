#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q;
    cin >> n >> q;
    set<int> num;
    unordered_map<int,int> dup;
    unordered_map<int,int> ans;
    for(int i=0;i<n;++i)
    {
        int n,d;
        cin >> n >> d;
        num.insert(n);
        dup[n]+=d;
    }
    vector<int> pos;
    int sum = 0;
    for(int x : num)
    {
        sum += dup[x];
        pos.push_back(sum);
        ans[sum] = x;
    }
    while(q--)
    {
        int x; cin >> x;
        auto idx = lower_bound(pos.begin(),pos.end(),x)-pos.begin();
        cout << ans[pos[idx]] << '\n';
    }
    return 0;
}