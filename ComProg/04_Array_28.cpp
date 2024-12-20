#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    string s;
    getline(cin,s);
    int char_count[27];
    for(int i=0;i<27;++i) char_count[i] = 0;
    int len = s.size();
    for(int i=0;i<len;++i)
    {
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            char c = tolower(s[i]);
            char_count[c-'a']++;
        }
    }
    for(int i=0;i<27;++i)
    {
        if(char_count[i] > 0)
        {
            char c = i+'a';
            cout << c << " -> " << char_count[i] << '\n';
        }
    }
    return 0;   
}