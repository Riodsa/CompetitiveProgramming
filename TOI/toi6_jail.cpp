#include<bits/stdc++.h>
using namespace std;

const int N = 1e7+1;
bool jail[N];
vector<int> order;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,inc;
    cin >> n >> inc;
    int arr[n+1];
    for(int i=1;i<=n;++i)
    {
        arr[i] = i;
        jail[i] = false;
    }
    int combo = 1;
    int cnt = 0;
    int i = 1;
    while(cnt != n)
    {
        while(jail[i])
        {
            ++i;
            if(i > n) i = 1;
        }
        while(combo != inc)
        {
            ++combo;
            ++i;
            if(i>n) i=1;
            while(jail[i])
            {
                ++i;
                if(i > n) i = 1;
            }
        }
        cout << i << " ";
        jail[i] = true;
        combo = 1;
        ++cnt;
        ++i;
        if(i>n) i=1;
    }
//    cout << '\n';
//    for(int i=1;i<=n;++i)
//    {
//        cout << jail[i] << " ";
//    }
    return 0;
}
