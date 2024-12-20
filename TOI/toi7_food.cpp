#include<bits/stdc++.h>
using namespace std;

const int N = 9;
vector<int> food;
bool vis[N];
int n,m;
unordered_map<int,bool> reject;

int main()
{
    cin >> n >> m;
    for(int i=1;i<=m;++i)
    {
        int x; cin >> x;
        reject[x] = true;
    }
    for(int i=1;i<=n;++i)
    {
        food.push_back(i);
    }
    do
    {
        if(!reject[food[0]])
        {
            for(int x : food)
            {
                cout << x << " ";
            }
            cout << '\n';
        }
    } while(next_permutation(food.begin(),food.end()));
    return 0;
}
