#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> team1,team2;
    for(int i=0;i<n;++i)
    {
        int x; cin >> x;
        team1.push_back(x);
    }
    for(int i=0;i<n;++i)
    {
        int x; cin >> x;
        team2.push_back(x);
    }
    sort(team1.begin(),team1.end());
    sort(team2.begin(),team2.end());
    int ans = 0;
    for(int i=0;i<n;++i)
    {
        ans += abs(team1[i]-team2[i]);
    }
    cout << ans;
    return 0;
}
