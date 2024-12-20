#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k;
    cin >> n >> k;
    deque<int> num;
    for(int i=1;i<=n;++i)
    {
        num.push_back(i);
    }
    while(!num.empty())
    {
        for(int i=0;i<k-1;++i)
        {
            num.push_back(num.front());
            num.pop_front();
        }
        cout << num.front() << " ";
        num.pop_front();
    }
    return 0;
}
