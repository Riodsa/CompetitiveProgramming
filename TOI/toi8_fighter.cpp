#include<bits/stdc++.h>
using namespace std;

int pO,pE;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> pO;
    pE = pO;
    int n = 2*pO;
    int cbO=0,cbE=0;
    for(int i=1;i<=n;++i)
    {
        int atk;
        cin >> atk;
        if(atk%2 == 1)
        {
            cbE = 0;
            cbO++;
            if(cbO >= 3)
            {
                pE -= 3;
            }
            else pE -= 1;
            if(pE <= 0)
            {
                cout << "1" << '\n' << atk;
                return 0;
            }
        }
        else if(atk%2 == 0)
        {
            cbO = 0;
            cbE++;
            if(cbE >= 3)
            {
                pO -= 3;
            }
            else pO -= 1;
            if(pO <= 0)
            {
                cout << "0" << '\n' << atk;
                return 0;
            }
        }
    }
    return 0;
}
