#include<bits/stdc++.h>
using namespace std;

set<vector<int>> ans;

void solve(int n,int k,int idx,int prev,vector<int> &vec,int conones,int maxconones)
{
    if(idx < n)
    {
        if(n-idx+1 < k-maxconones) return ;
        maxconones = max(maxconones,conones);
        vec[idx] = true;
        if(prev == 1) solve(n,k,idx+1,1,vec,conones+1,maxconones);
        else solve(n,k,idx+1,1,vec,1,maxconones);
        vec[idx] = false;
        solve(n,k,idx+1,0,vec,0,maxconones);
    }
    else if(idx == n)
    {
        maxconones = max(maxconones,conones);
        if(maxconones >= k) ans.insert(vec);
        return ;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k;
    cin >> n >> k;
    vector<int> vec(n);
    solve(n,k,0,-1,vec,0,0);
    for(vector<int> x : ans)
    {
        for(int a : x) cout << a;
        cout << '\n';
    }
    return 0;
}