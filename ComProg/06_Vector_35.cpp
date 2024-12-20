#include<iostream>
#include<vector>
using namespace std;

int stringtonumber(string s)
{
    if(s == "soon") return 0;
    else if(s == "neung") return 1;
    else if(s == "et") return 1;
    else if(s == "song") return 2;
    else if(s == "yi") return 2;
    else if(s == "sam") return 3;
    else if(s == "si") return 4;
    else if(s == "ha") return 5;
    else if(s == "hok") return 6;
    else if(s == "chet") return 7;
    else if(s == "paet") return 8;
    else if(s == "kao") return 9;
    return -1;
}

int stringtovalue(string s)
{
    if(s == "lan") return 1e6;
    else if(s == "saen") return 1e5;
    else if(s == "muen") return 1e4;
    else if(s == "phan") return 1e3;
    else if(s == "roi") return 1e2;
    else if(s == "sip") return 1e1;
    return -1;
}

int main()
{
    string s;
    while(getline(cin,s))
    {
        if(s == "q") return 0;
        vector<string> vec;
        string tmp = "";
        int len = s.size();
        for(int i=0;i<len;++i)
        {
            if(s[i] == ' ')
            {
                vec.push_back(tmp);
                tmp = "";
                continue;
            }
            else if(i == len-1)
            {
                tmp += s[i];
                vec.push_back(tmp);
            }
            tmp += s[i];
        }
        int num = 1;
        int ans = 0;
        int l = vec.size();
        for(int i=0;i<l;++i)
        {
            string c = vec[i];
            // cout << c << ' ';
            int number = stringtonumber(c);
            if(number != -1)
            {
                num = number;
                if(i == l-1)
                {
                    ans += num;
                    // cout << '\n';
                }
                continue;
            }
            int value = stringtovalue(c);
            if(value != -1)
            {
                ans += value*num;
                num = 1;
                // cout << '\n';
            }
        }
        cout << ans << '\n';
    }
    return 0;
}