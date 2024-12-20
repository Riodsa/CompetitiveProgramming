#include<iostream>
using namespace std;

int cnt = 0;

int main()
{
    int n;
    cin >> n;
    string tmp;
    getline(cin,tmp);
    while(n--)
    {
        string s;
        getline(cin,s);
        s += "   ";
        int len = s.size();
        int point = 0;
        bool correct = true;
        cnt = 0;
        for(int i=0;i<len;++i)
        {
            if(s[i] == ' ') continue;
            if(s[i] == 'R') point++;
            else if(s[i] == 'Y') point += 2;
            else if(s[i] == 'G') point += 3;
            else if(s[i] == 'N') point += 4;
            else if(s[i] == 'B') point += 5;
            else if(s[i] == 'P') point += 6;
            else if(s[i] == 'K') point += 7;
            if(i == 0 && s[i] != 'R') correct = false;
            if(s[i] == 'R')
            {
                if(i-2 >= 0 && s[i-2] == 'R') correct = false;
                if(cnt > 2) correct = false;
                cnt = 0;
            }
            else
            {
                if(i-2 >= 0 && s[i-2] == 'R') continue;
                else
                {
                    ++cnt;
                    //cout << s[i] << ' ' << cnt << '\n';
                    if(cnt == 1 && s[i] == 'Y') continue;
                    else if(cnt == 2 && s[i] == 'G') continue;
                    else if(cnt == 3 && s[i] == 'N') continue;
                    else if(cnt == 4 && s[i] == 'B') continue;
                    else if(cnt == 5 && s[i] == 'P') continue;
                    else if(cnt == 6 && s[i] == 'K') continue;
                    else if(cnt > 6) correct = false;
                    else correct = false;
                }
            }
        }
        if(correct) cout << point << '\n';
        else cout << "WRONG_INPUT\n";
    }
    return 0;
}