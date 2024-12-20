    #include<bits/stdc++.h>
    using namespace std;

    int main()
    {
        ios_base::sync_with_stdio(0); cin.tie(0);
        string s;
        cin >> s;
        int len = s.size();
        char tmp = s[0];
        int cnt = 1;
        for(int i=1;i<len;++i)
        {
            if(s[i] != s[i-1])
            {
                cout << tmp << ' ' << cnt << ' ';
                tmp = s[i];
                cnt = 1;
            }
            else ++cnt;
        }
        cout << tmp << ' ' << cnt;
        return 0;
    }