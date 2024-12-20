#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string card[n+1],tmp[n+1];
    for(int i=1;i<=n;++i) cin >> card[i];
    string cmd;
    getchar();
    getline(cin,cmd);
    int len = cmd.size();
    for(int i=0;i<len;++i)
    {
        for(int i=1;i<=n;++i) tmp[i] = "";
        if(cmd[i] == 'C')
        {
            // cout << "CUT\n";
            for(int i=1;i<=n/2;++i) swap(card[i],card[i+(n/2)]);
        }
        else if(cmd[i] == 'S')
        {
            // cout << "SWAP\n";
            int c = 1;
            for(int i=1;i<=n/2;++i)
            {
                tmp[c++] = card[i];
                tmp[c++] = card[i+(n/2)];
            }
            for(int i=1;i<=n;++i) card[i] = tmp[i];
        }
    }
    for(int i=1;i<=n;++i) cout << card[i] << ' ';
    return 0;
}