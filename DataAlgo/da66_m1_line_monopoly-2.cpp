#include<bits/stdc++.h>
using namespace std;

const int N = 1e9+1;
bool arr[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    int ans = 0;
    while(n--)
    {
        int opr; cin >> opr;
        if(opr == 1)
        {
            int a,b;
            cin >> a >> b;
            bool isOverlap = false;
            int cnt_overlap = 0;
            for(int i=a-1;i<=b+1;++i)
            {
                // cout << arr[i] << ' ';
                if(arr[i])
                {
                    if(!isOverlap) cnt_overlap++;
                    isOverlap = true;
                }
                else
                {
                    isOverlap = false;
                    if(i != a-1 && i != b+1)arr[i] = true;
                }
            }
            // cout << '\n';
            if(cnt_overlap >= 2) ans -= cnt_overlap-1;
            else if(cnt_overlap == 0) ans++;
            // cout << "overlap: " << cnt_overlap << '\n';
        }
        else if(opr == 2)
        {
            cout << ans << '\n';
        }
    }
    return 0;
}