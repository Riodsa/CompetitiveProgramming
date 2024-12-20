#include<iostream>
#include<set>
#include<vector>
using namespace std;

set<vector<int>> ss;
int main()
{
    string s;
    getline(cin,s);
    vector<int> arr;
    arr.resize(36);
    for(int i='a';i<='z';++i) arr[i-'a'] = 0;
    for(int i='0';i<='9';++i) arr[i-'0'+25] = 0;
    int len = s.size();
    for(int i=0;i<len;++i)
    {
        if(s[i] == ' ') continue;
        else
        {
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
            {
                s[i] = tolower(s[i]);
                // cout << s[i] << " = " << s[i]-'a' << '\n';
                arr[s[i]-'a']++;
            }
            else if(s[i] >= '0' && s[i] <= '9')
            {
                // cout << s[i] << " = " << s[i]-'0'+25 << '\n';
                arr[s[i]-'0'+25]++;
            }
        }
    }
    // for(int i=0;i<36;++i) cout << i << " : " << arr[i] << '\n';
    ss.insert(arr);
    getline(cin,s);
    arr.clear();
    arr.resize(36);
    for(int i='a';i<='z';++i) arr[i-'a'] = 0;
    for(int i='0';i<='9';++i) arr[i-'0'+25] = 0;
    len = s.size();
    for(int i=0;i<len;++i)
    {
        if(s[i] == ' ') continue;
        else
        {
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
            {
                s[i] = tolower(s[i]);
                // cout << s[i] << " = " << s[i]-'a' << '\n';
                arr[s[i]-'a']++;
            }
            else if(s[i] >= '0' && s[i] <= '9')
            {
                // cout << s[i] << " = " << s[i]-'0'+25 << '\n';
                arr[s[i]-'0'+25]++;
            }
        }
    }
    // for(int i=0;i<36;++i) cout << i << " : " << arr[i] << '\n';
    ss.insert(arr);
    if(ss.size() == 1) cout << "YES";
    else cout << "NO";
    return 0;
}