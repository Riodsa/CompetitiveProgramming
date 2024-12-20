#include<bits/stdc++.h>
using namespace std;
int wh[4][10];
int len = 3;
void print_wh()
{
    for(int i=0;i<len;++i)
    {
        for(int j=1;j<=9;++j)
        {
            cout << wh[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    string pass;
    cin >> pass;
    int p[4];
    p[0] = pass[0]-'0';
    p[1] = 8;
    p[2] = pass[2]-'0';
    for(int j=0;j<len;++j)
    {
        wh[j][1] = pass[j]-'0';
        for(int i=2;i<=9;++i)
        {
            wh[j][i] = wh[j][i-1]+1;
            if(wh[j][i] == 10)
            {
                wh[j][i] = 1;
            }
        }
    }
//    print_wh();
    string txt;
    cin >> txt;
    int len2 = txt.length();
    for(int i=0;i<len2;++i)
    {
        int idx = txt[i]-'0';
        idx = wh[0][wh[1][wh[2][idx]]];
        for(int j=0;j<len;++j)
        {
            int tmp[10];
            for(int k=1;k<=9;++k)
            {
                int pos = (k+9-p[j])%9;
                if(pos == 0) pos = 9;
                tmp[pos] = wh[j][k];
            }
            for(int k=1;k<=9;++k)
            {
                wh[j][k] = tmp[k];
            }
        }
        cout << idx;
//        print_wh();
    }
    return 0;
}
