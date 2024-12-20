#include<bits/stdc++.h>
using namespace std;

void solve(int n,int k,int idx,vector<bool> &vec,int cntones)
{
    if(idx < n)
    {
        if(cntones < k)
        {
            vec[idx] = true;
            cntones++;
            solve(n,k,idx+1,vec,cntones);
            cntones--;
        }
        vec[idx] = false;
        solve(n,k,idx+1,vec,cntones);
    }
    else if(idx == n && cntones == k)
    {
        for(int i=0;i<n;++i) cout << vec[i];
        cout << '\n';
        return ;
    }
    else return ;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k;
    cin >> k >> n;
    vector<bool> vec(n);
    solve(n,k,0,vec,0);
    return 0;
}