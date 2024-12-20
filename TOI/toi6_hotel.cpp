#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    int ans = 0;
    while(n > 0)
    {
        if(n >= 9) {n-=15;ans+=3000;}
        else if(n >= 4) {n-=5;ans+=1500;}
        else if(n == 3) {n-=3;ans+=1300;}
        else if(n >= 2) {n-=2;ans+=800;}
        else {n--;ans+=500;}
    }
    cout << ans;
    return 0;
}
