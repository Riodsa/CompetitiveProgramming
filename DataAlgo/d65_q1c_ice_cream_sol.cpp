#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+1;
int n,m,start;
unordered_map<int,int> mp;
vector<int> total(N);

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> start;
    int sum = 0;
    for(int i=0;i<n;++i)
    {
        int a,s;
        cin >> a >> s;
        mp[a] = s;
    }
    total[0] = start;
    for(int i=1;i<=1e5;++i)
    {
        if(mp.find(i) != mp.end()) start = mp[i];
        total[i] = total[i-1] + start;
    }
    // for(int i=1;i<=100;++i) cout << total[i] << ' ';
    while(m--)
    {
        int p,x;
        cin >> p >> x;
        cout << (total[x]>=p ? lower_bound(total.begin(),total.begin()+x+1,p)-total.begin() : lower_bound(total.begin()+x,total.end(),p+total[x])-total.begin()) << ' ';
    }
    return 0;
}