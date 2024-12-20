#include<iostream>
#include<set>
using namespace std;

void print_set(set<int> s)
{
    if(s.size() != 0)
    {
        for(int a : s) cout << a << ' ';
        cout << '\n';
    }
    else cout << "empty set\n";
}

int main()
{
    set<int> u,inter,d;
    string s;
    int cnt = 0;
    while(getline(cin,s))
    {
        // if(s == "X") break;
        string tmp = "";
        int len = s.size();
        set<int> t;
        for(int i=0;i<len;++i)
        {
            int num;
            if(s[i] == ' ' || i == len-1)
            {
                if(i == len-1) tmp += s[i];
                num = stoi(tmp);
                tmp = "";
                u.insert(num);
                if(cnt == 0) 
                {
                    inter.insert(num);
                    d.insert(num);
                }
                else
                {
                    if(inter.find(num) != inter.end()) t.insert(num);
                    if(d.find(num) != d.end()) d.erase(d.find(num));
                }
                continue;
            }
            tmp += s[i];
        }
        if(cnt > 0)
        {
            inter.clear();
            for(int a : t) inter.insert(a);
        }
        // cout << "U: "; print_set(u);
        // cout << "I: "; print_set(inter);
        // cout << "D: "; print_set(d);
        ++cnt;
    }
    cout << "U: "; print_set(u);
    cout << "I: "; print_set(inter);
    cout << "D: "; print_set(d);
    return 0;
}