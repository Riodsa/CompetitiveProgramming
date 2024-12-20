#include<iostream>
#include<map>
using namespace std;

int main()
{
    map<string,string> t2k,k2t;
    int arr[9] = {3,3,3,3,3,4,3,4,0};
    int cnt = 0,c=0;
    char now = 'a';
    // cout << "c = " << c << '\n';
    while(arr[c] != 0)
    {
        string code = "";
        string character = "";
        character.push_back(now);
        for(int i=0;i<cnt+1;++i) code += ((c+2)+'0');
        // cout << "character = " << character << " --> " << code << '\n';
        t2k[character] = code;
        k2t[code] = character;
        ++cnt,++now;
        if(cnt == arr[c])
        {
            cnt = 0;
            c++;
        }
    }
    t2k[" "] = "0";
    k2t["0"] = " ";
    // for(char i='a';i<='z';++i)
    // {
    //     string tmp = "";
    //     tmp.push_back(i);
    //     cout << i << " : " << t2k[tmp] << '\n';
    // }
    string opr;
    while(cin >> opr)
    {
        string str;
        getline(cin,str);
        int len = str.size();
        cout << ">> ";
        if(opr == "T2K")
        {
            for(int i=1;i<len;++i)
            {
                if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || str[i] == ' ')
                {
                    string tmp = "";
                    tmp.push_back(tolower(str[i]));
                    cout << t2k[tmp] << ' ';
                }
            }
        }
        else if(opr == "K2T")
        {
            string tmp = "";
            for(int i=1;i<len;++i)
            {
                if(str[i] == ' ' || i == len-1)
                {
                    if(i == len-1) tmp.push_back(str[i]);
                    cout << k2t[tmp];
                    // cout << "tmp = " << tmp << ' ';
                    tmp = "";
                    if(str[i] == ' ')
                    {
                        tmp.push_back(str[i]);
                        cout << k2t[tmp];
                        tmp = "";
                    }
                    continue;
                }
                tmp.push_back(str[i]);
            }
        }
        cout << '\n';
    }
    return 0;
}