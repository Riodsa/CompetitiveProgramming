#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> vec(n);
    for(int i=0;i<n;++i) cin >> vec[i];
    for(int i=0;i<m;++i)
    {
        int k; cin >> k;
        int cnt = 0;
        for(int j=0;j<n;++j)
        {
            if(vec[j] == k) break;
            else if(vec[j] > k) cnt++;
        }
        cout << cnt << '\n';
    }
    return 0;
}