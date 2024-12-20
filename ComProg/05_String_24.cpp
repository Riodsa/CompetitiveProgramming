#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    string s;
    getline(cin,s);
    int len = s.size();
    string first = "",last = "";
    int midL = 0,midR = 0;
    for(int i=0;i<len;++i)
    {
        if(s[i] == ' ')
        {
            midL = i;
            break;
        }
        first += s[i];
    }
    for(int i=len-1;i>=0;--i)
    {
        if(s[i] == ' ')
        {
            midR = i;
            break;
        }
        last += s[i];
    }
    reverse(last.begin(),last.end());
    string first_edit = "", last_edit = "";
    int first_stop=0,last_stop=0;
    int len_first = first.size(), len_last = last.size();
    for(int i=0;i<len_first;++i)
    {
        if(first[i] == 'a' || first[i] == 'e' || first[i] == 'i' || first[i] == 'o' || first[i] == 'u')
        {
            first_stop = i;
            break;
        }
    }    
    for(int i=len_last-1;i>=0;--i)
    {
        if(last[i] == 'a' || last[i] == 'e' || last[i] == 'i' || last[i] == 'o' || last[i] == 'u')
        {
            last_stop = i;
            // break;
        }
    }
    // cout << first << ' ' << last << '\n';
    // cout << first.substr(0,first_stop) << ' ' << last.substr(0,last_stop) << '\n';
    first_edit = last.substr(0,last_stop) + first.substr(first_stop,len_first-first_stop+1);
    last_edit = first.substr(0,first_stop) + last.substr(last_stop,len_last-last_stop+1);
    cout << last_edit << ' ';
    for(int i=midL+1;i<midR;++i)
    {
        cout << s[i];
    }
    cout << ' ' << first_edit;
    return 0;
}