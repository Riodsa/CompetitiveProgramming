#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

char str[6] = {' ','B','I','N','G','O'};

int main()
{
    vector<int> vec[6];
    bool bingo[6][6];
    int sumr[6],sumc[6],sumd1 = 0,sumd2 = 0;
    string tmp;
    getline(cin,tmp);
    // cout << "tmp = " << tmp << '\n';
    for(int i=1;i<=5;++i)
    {
        sumr[i] = 0;
        sumc[i] = 0;
        for(int j=1;j<=5;++j)
        {
            bingo[i][j] = false;
            string s; cin >> s;
            if(s != "*") 
            {
                int x = stoi(s);
                vec[j].push_back(x);
                // cout << "vec[" << j << "] : "; for(int k=0;k<vec[j].size();++k) cout << vec[j][k] << ' ';
                // cout << '\n';
            }
            else vec[j].push_back(0);
        }
        // cout << '\n';
    }
    // for(int i=0;i<5;++i)
    // {
    //     for(int j=1;j<=5;++j) 
    //     {
    //         cout << vec[j][i] << ' ';
    //     }
    //     cout << '\n';
    // }
    sumr[3]++;
    sumc[3]++;
    sumd1++;
    sumd2++;
    int cnt = 1;
    string s;
    getchar();
    while(getline(cin,s))
    {
        string x = "";
        int len = s.size();
        for(int i=0;i<=len;++i)
        {
            if(s[i] == ' ' || i == len)
            {
                char r = x[0];
                int c = 0;
                if(r == 'B') c = 1;
                else if(r == 'I') c = 2;
                else if(r == 'N') c = 3;
                else if(r == 'G') c = 4;
                else if(r == 'O') c = 5;
                int l = x.size();
                int num = stoi(x.substr(1,max(0,l-1)));
                int idx = find(vec[c].begin(),vec[c].end(),num)-vec[c].begin();
                idx++;
                if((unsigned long)idx != vec[c].size()+1)
                {
                    // cout << "BINGO " << idx << ' ' << c << '\n';
                    if(!bingo[idx][c])
                    {
                        if(idx == c) sumd1++;
                        else if(6-idx == c) sumd2++;
                        sumr[idx]++;
                        sumc[c]++;
                    }
                    bingo[idx][c] = true;
                    if(sumr[idx] == 5 || sumc[c] == 5 || sumd1 == 5 || sumd2 == 5)
                    {
                        cout << cnt << '\n';
                        if(sumr[idx] == 5)
                        {
                            for(int i=1;i<=5;++i)
                            {
                                if(vec[i][idx-1] != 0) cout << str[i] << vec[i][idx-1];
                                else continue;
                                if(i != 5) cout << ", ";
                            }
                            cout << '\n';
                        }
                        if(sumc[c] == 5)
                        {
                            for(int i=0;i<5;++i)
                            {
                                if(vec[c][i] != 0) cout << str[c] << vec[c][i];
                                else continue;
                                if(i != 4) cout << ", ";
                            }
                            cout << '\n';
                        }
                        if(sumd1 == 5)
                        {
                            for(int i=0;i<5;++i)
                            {
                                for(int j=1;j<=5;++j)
                                {
                                    if(i == j-1)
                                    {
                                        if(vec[j][i] != 0) cout << str[j] << vec[j][i];
                                        else continue;
                                        if(i != 4 && j != 5) cout << ", ";
                                    }
                                }
                            }
                            cout << '\n';
                        }
                        if(sumd2 == 5)
                        {
                            for(int i=4;i>=0;--i)
                            {
                                for(int j=5;j>=1;--j)
                                {
                                    if(5-i == j)
                                    {
                                        if(vec[j][i] != 0) cout << str[j] << vec[j][i];
                                        else continue;
                                        if(i != 0 && j != 5) cout << ", ";
                                    }
                                }
                            }
                            cout << '\n';
                        }
                        // cout << "sumr = " << sumr[idx] << " sumc = " << sumc[c] << " sumd1 = " << sumd1 << " sumd2 = " << sumd2 << '\n';
                        return 0;
                    }
                    // cout << "sumr = " << sumr[idx] << " sumc = " << sumc[c] << " sumd1 = " << sumd1 << " sumd2 = " << sumd2 << '\n';
                }
                x = "";
                ++cnt;
                continue;
            }
            x += s[i];
        }
    }
    return 0;
}