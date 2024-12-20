#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<ll,ll>
const int N = 5e5+1;
int n,m;
ll path[N];
vector<ll> qsP,qsM;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    qsP.resize(n+1);
    qsM.resize(n+1);
    for(int i=1;i<=n;++i)
    {
        cin >> path[i];
        qsP[i] = (path[i]>0?qsP[i-1]+path[i] : qsP[i-1]);
        qsM[i] = (path[i]<0?qsM[i-1]+abs(path[i]) : qsM[i-1]);
    }
//    cout << "Paid : " << '\n';
//    for(int i=1;i<=n;++i)
//    {
//        cout << qsM[i] << " ";
//    }
//    cout << '\n' << "Point : " << '\n';
//    for(int i=1;i<=n;++i)
//    {
//        cout << qsP[i] << " ";
//    }
//    cout << '\n';
    while(m--)
    {
        int x;
        ll h,mh;
        cin >> x >> h;
        if(x == 0) mh = h;
        else mh = h+qsM[x];
        auto idx = lower_bound(qsM.begin()+x,qsM.end(),mh);
        if(idx != qsM.begin()+x) --idx;
        else
        {
//            cout << "0" << '\n';
            continue;
        }
        int pos = idx-qsM.begin();
//        cout << "pos : " << pos << '\n';
        cout << qsP[pos]-qsP[x] << '\n';
    }
    return 0;
}
