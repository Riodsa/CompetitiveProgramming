#include<iostream>
using namespace std;

int main()
{
    bool digit_check[11];
    for(int i=0;i<=9;++i) digit_check[i] = false;
    string s;
    getline(cin,s);
    int len = s.size();
    for(int i=0;i<len;++i)
    {
        if(s[i] >= '0' && s[i] <= '9') digit_check[s[i]-'0'] = true;
    }
    int missing_digit[11],c = 0;
    int count_missing_digit = 0;
    for(int i=0;i<=9;++i) missing_digit[i] = -1;
    for(int i=0;i<=9;++i) if(!digit_check[i]) missing_digit[c++] = i;
    for(int i=0;i<=9;++i)
    {
        if(missing_digit[i] != -1) cout << missing_digit[i];
        else count_missing_digit++;
        if(missing_digit[i+1] != -1 && i != 9) cout << ",";
    }
    if(count_missing_digit == 10) cout << "None";
    return 0;
}