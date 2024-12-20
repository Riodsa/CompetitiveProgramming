#include<bits/stdc++.h>
using namespace std;

vector<int> vec;
int len;
bool check(int l,int r,bool isRev)
{
    int range = r-l;
    if(range == 2)
    {
        if(!isRev) return (vec[l] == 0 && vec[l+1] == 1);
        else return (vec[l+1] == 0 && vec[l] == 1);
    }

    int mid = (l+r)/2;

    if(!isRev) return (check(l,mid,false)||check(l,mid,true))&&check(mid,r,false);
    else return (check(mid,r,false)||check(mid,r,true))&&check(l,mid,true);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k;
    cin >> n >> k;
    len = 1<<k;
    vec.resize(len);
    while(n--)
    {
        for(int i=0;i<len;++i) cin >> vec[i];
        cout << (check(0,len,false)?"yes\n":"no\n");
    }
    return 0;
}