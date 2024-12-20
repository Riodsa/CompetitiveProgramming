#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    string s; cin >> s;
    int n; cin >> n;
    int num = stoi(s.substr(4,3));
    num += n;
    int step=0,step2=0,step3=0;
    if(num >= 1e3)
    {
        step = num/1e3;
        num %= (int)1e3;
    }
    int x = s[0]-'0';
    char a = s[1],b = s[2];
    if(b + step > 'Z')
    {
        step2++;
        step -= 'Z'-b+1;
        b = 'A' + (step)%26;
        step2 += step/26;
        if(a + step2 >= 'Z')
        {
            step3++;
            step2 -= 'Z'-a+1;
            a = 'A' + (step2)%26;
            step3 += step2/26;
            x += step3;
        }
        else a += step2;
    }
    else b += step;
    // cout << "step1 = " << step << " step2 = " << step2 << " step3 = " << step3 << '\n';
    string new_plate = to_string(x) + a + b + '-' + string(3-to_string(num).size(),'0') + to_string(num);
    cout << new_plate;
    return 0;
}