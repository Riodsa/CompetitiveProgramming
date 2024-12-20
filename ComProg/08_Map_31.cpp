#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

struct Student
{
    double score;
    string id;
    vector<string> cl;
    string selected_class;
};

bool sorted_by_score(const Student &x,const Student &y)
{
    return x.score > y.score;
}

bool sorted_by_id(const Student &x,const Student &y)
{
    return x.id < y.id;
}

int main()
{
    map<string,int> mp;
    map<string,int> now;
    int n; cin >> n;
    for(int i=0;i<n;++i)
    {
        string id;
        int amount;
        cin >> id >> amount;
        mp[id] = amount;
        now[id] = 0;
    }
    int m; cin >> m;
    vector<Student> vec;
    for(int i=0;i<m;++i)
    {
        Student a;
        string c;
        cin >> a.id >> a.score;
        int cnt_class = 4;
        while(cnt_class--) 
        {
            cin >> c; 
            a.cl.push_back(c);
        }
        vec.push_back(a); 
    }
    // cout << '\n';
    sort(vec.begin(),vec.end(),sorted_by_score);
    for(int i=0;i<m;++i)
    {
        for(string x : vec[i].cl)
        {
            if(now[x] != mp[x])
            {
                // cout << "ID : " << x << " selected " << x << '\n';
                vec[i].selected_class = x;
                now[x]++;
                break;
            }
        }
    }
    // cout << '\n';
    sort(vec.begin(),vec.end(),sorted_by_id);
    for(int i=0;i<m;++i) cout << vec[i].id << ' ' << vec[i].selected_class << '\n';
    return 0;
}