#include<bits/stdc++.h>
using namespace std;

void perm(int n,vector<int>& vec,int idx,unordered_map<int,bool> &used,unordered_map<int,int> before)
{
    if(idx < n)
    {
        for(int i=0;i<n;++i)
        {
            if(!used[i] && used[before[i]])
            {
                used[i] = true;
                vec[idx] = i;
                perm(n,vec,idx+1,used,before);
                used[i] = false;
            }
        }
    }
    else
    {
        for(int i=0;i<n;++i) cout << vec[i] << ' ';
        cout << '\n';
        return ;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    unordered_map<int,bool> used;
    unordered_map<int,int> before;
    int n,k;
    cin >> n >> k;
    for(int i=0;i<n;++i) before[i] = -1;    
    used[-1] = true;
    while(k--)
    {
        int a,b;
        cin >> a >> b;
        before[b] = a;
    }
    vector<int> vec(n);
    perm(n,vec,0,used,before);
    return 0;
}