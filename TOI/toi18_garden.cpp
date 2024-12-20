#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+1;
int n,q;
int tree[N],ans1[N],ans2[N];
vector<int> lisL,lisR;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    for(int i=0;i<n;++i)
    {
        cin >> tree[i];
        auto idx = lower_bound(lisL.begin(),lisL.end(),tree[i])-lisL.begin();
        if(idx == lisL.size())
        {
            lisL.push_back(tree[i]);
        }
        else lisL[idx] = tree[i];
        ans1[i] = idx;
    }
    for(int i=n-1;i>=0;--i)
    {
        int idx = lower_bound(lisR.begin(),lisR.end(),tree[i])-lisR.begin();
        if(idx == lisR.size())
        {
            lisR.push_back(tree[i]);
        }
        else lisR[idx] = tree[i];
        ans2[i] = idx;
    }
    while(q--)
    {
        int x;
        cin >> x;
        cout << min(ans1[x],ans2[x]) << '\n';
    }
    return 0;
}
