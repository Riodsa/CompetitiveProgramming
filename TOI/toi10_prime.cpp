#include<bits/stdc++.h>
using namespace std;

const int X = 1e7+7;
const int N = 5e5+1;
int prime[N],si;
bitset<X> chk;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for(int i=2;i<X;++i)
    {
        if(chk[i]) continue;
        prime[++si] = i;
        if(si >= n) break;
        for(int j=i;j<X;j+=i) chk[j] = true;
    }
    cout << prime[n];
    return 0;
}
