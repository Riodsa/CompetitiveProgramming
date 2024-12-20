#include<bits/stdc++.h>
using namespace std;

#define ll long long
struct shop
{
    int a,b,c,x,y,z;
};
const int N = 21;
const int M = 11;
int need;
ll ans = 1e18;
bool vis[M];
int m;
shop mp[M];

void go(ll res,int x,int y,int z,int a,int b,int c)
{
//    cout << "a = " << a << " b = " << b << " c = " << c << '\n';
    if(a >= need && b >= need && c >= need)
    {
        ans = min(ans,res);
    }
    else if(res >= ans) return ;
    else
    {
        for(int i=1;i<=m;++i)
        {
            if(vis[i]) continue;
            else
            {
                vis[i] = true;
                ll nres = res + (x-mp[i].x)*(x-mp[i].x) + (y-mp[i].y)*(y-mp[i].y) + (z-mp[i].z)*(z-mp[i].z);
//                cout << "cost : " << nres << '\n';
                go(nres,mp[i].x,mp[i].y,mp[i].z,a+mp[i].a,b+mp[i].b,c+mp[i].c);
                vis[i] = false;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int xx,yy,zz;
    cin >> need;
    cin >> xx >> yy >> zz;
    cin >> m;
    for(int i=1;i<=m;++i)
    {
        cin >> mp[i].x >> mp[i].y >> mp[i].z >> mp[i].a >> mp[i].b >> mp[i].c;
    }
//    for(int i=1;i<=m;++i)
//    {
//        cout << mp[i].a << " " << mp[i].b << " " << mp[i].c << " " << mp[i].x << " " << mp[i].y << " " << mp[i].z << '\n';
//    }
    go(0,xx,yy,zz,0,0,0);
    cout << ans;
    return 0;
}
