#include<bits/stdc++.h>
using namespace std;

int n,k,len;
vector<int> vec,qs;

bool check(int l,int r)
{
    if(r-l < 2) return true;
    int mid = (l+r)/2;
    int cntleft = qs[mid]-qs[l],cntright = qs[r]-qs[mid];
    if(abs(cntleft-cntright) > 1) return false;
    return (check(l,mid)&&check(mid,r));
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    len = 1<<k;
    vec.resize(len);
    qs.resize(len);
    while(n--)
    {
        int cnt = 0;
        for(int i=0;i<len;++i)
        {
            cin >> vec[i];
            if(vec[i] == 1) cnt++;
            qs[i+1] = qs[i]+vec[i];
        }
        if(check(0,len)) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}