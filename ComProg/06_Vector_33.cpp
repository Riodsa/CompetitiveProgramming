#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct party
{
    double remainder;
    double ans;
    double ss;
    string name;
    bool operator<(const party &x)&{
        if(remainder != x.remainder) return remainder > x.remainder;
        return ans > x.ans;
    }
};

bool sort_party_list(const party &x,const party &y)
{
    if((int)x.ans != (int)y.ans) return x.ans > y.ans;
    return x.ss > y.ss;
}

int main()
{
    vector<party> vec;
    string s;
    double all_score = 0;
    while(cin >> s)
    {
        if(s == "END") break;
        double tmp; cin >> tmp;
        vec.push_back({0,0,tmp,s});
        all_score += tmp;
    }
    double ave_score = all_score/100;
    // cout << "ave_score = " << ave_score << '\n';
    int len = vec.size();
    int all_ans = 0;
    for(int i=0;i<len;++i)
    {
        vec[i].ans = vec[i].ss/ave_score;
        vec[i].remainder = vec[i].ans - (int)(vec[i].ans);
        all_ans += (int)(vec[i].ans);
    }
    sort(vec.begin(),vec.end());
    int cnt = 0;
    if(all_ans < 100)
    {
        while(all_ans != 100)
        {
            vec[cnt].ans++;
            ++all_ans;
            ++cnt;
            if(cnt > len) cnt = 0;
        }
    }
    // cout << "all_ans = " << all_ans << '\n';
    sort(vec.begin(),vec.end(),sort_party_list);
    for(int i=0;i<len;++i)
    {
        if((int)(vec[i].ans) != 0) cout << vec[i].name << ' ' << (int)vec[i].ans << ' ' << vec[i].ss << '\n';
    }
    return 0;
}