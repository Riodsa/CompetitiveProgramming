#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    unordered_map<string,int> mp;
    int n,k;
    cin >> n >> k;
    for(int i=0;i<n;++i)
    {
        string s;
        cin >> s;
        mp[s]++;
    }
    vector<int> score;
    for(auto a : mp)
    {
        score.push_back(a.second);
    }
    sort(score.begin(),score.end(),greater<>());
    int cnt = 0;
    int ans = 0;
    for(int x : score)
    {
        ans = x;
        cnt++;
        if(cnt == k) break;
    }
    cout << ans;
    return 0;
}