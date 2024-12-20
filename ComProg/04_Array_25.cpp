#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n+1],mx = -1;
    for(int i=1;i<=n;++i)
    {
        cin >> arr[i];
        if(mx < arr[i]) mx = arr[i];
    }
    bool block[mx+1][n+1];
    int blue = 0;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=mx;++j) block[j][i] = false;
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=mx;j>=mx-arr[i]+1;--j) block[j][i] = true;
    }
    for(int i=1;i<=mx;++i)
    {
        for(int j=1;j<=n;++j)
        {
            // if(block[i][j]) cout << "O";
            // else cout << "X";
            if(!block[i][j])
            {
                bool haveL = false,haveR = false;
                if(j > 1) for(int k=j-1;k>=1;--k) if(block[i][k]) haveL = true;
                if(j < n) for(int k=j+1;k<=n;++k) if(block[i][k]) haveR = true;
                if(haveL && haveR) ++blue;
            }
        }
        // cout << '\n';
    }
    cout << blue;
    return 0;
}