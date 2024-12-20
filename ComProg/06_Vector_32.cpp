#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void print_vec(vector<vector<int>> vec)
{
    int len = vec.size();
    for(int i=0;i<len;++i)
    {
        cout << i << " : ";
        for(int a : vec[i]) cout << a << ' ';
        cout << '\n';
    }
    cout << '\n';
}

int main()
{
    vector<vector<int>> vec;
    string s;
    int l;
    cin >> s;
    if(s == "first")
    {
        int x;
        while(cin >> x)
        {
            if(x == -1) break;
            if(vec.empty())
            {
                vector<int> tmp;
                tmp.push_back(x);
                vec.push_back(tmp);
            }
            else
            {
                l = vec.size();
                for(int i=0;i<l;++i)
                {
                    int sum = 0;
                    for(int a : vec[i]) sum += a;
                    if(sum + x <= 100) 
                    {
                        vec[i].push_back(x);
                        break;
                    }
                    else
                    {
                        if(i == l-1)
                        {
                            vec.push_back({x});
                        }
                    }
                }
            }
        }
    }
    else if(s == "best")
    {
        // cout << "BEST\n";
        int x;
        int best_sum = 100,to_add = -1;
        while(cin >> x)
        {
            if(x == -1) break;
            if(vec.empty()) vec.push_back({x});
            else
            {
                best_sum = 100,to_add = -1;
                l = vec.size();
                for(int i=0;i<l;++i)
                {
                    int sum = 0;
                    int len = vec[i].size();
                    for(int j=0;j<len;++j) sum += vec[i][j];
                    // cout << "sum = " << sum << '\n';
                    if(sum + x <= 100)
                    {
                        sum += x;
                        if(best_sum > 100-sum)
                        {
                            best_sum = 100-sum;
                            to_add = i;
                        }
                    }
                }
                if(to_add != -1) vec[to_add].push_back(x);
                else vec.push_back({x});
            }
            // print_vec(vec);
        }
    }
    l = vec.size();
    vector<tuple<int,int,vector<int>,int>> sum;
    for(int i=0;i<l;++i)
    {
        int tmp = 0;
        for(int a : vec[i]) tmp -= a;
        sort(vec[i].begin(),vec[i].end());
        sum.push_back({tmp,vec[i].size(),vec[i],i});
    }
    sort(sum.begin(),sum.end());
    for(int i=0;i<l;++i)
    {
        int s,amount,idx;
        tie(s,amount,ignore,idx) = sum[i];
        // cout << s << ' ' << amount << ' ' << idx << '\n';
        for(int a : vec[idx]) cout << a << ' ';
        cout << '\n';
    }
    return 0;
}