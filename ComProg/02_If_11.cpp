#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    string s;
    cin >> s;
    if(s == "01" || s == "02" || s == "20" || s == "21" || s == "22" || s == "23" || s == "24" || s == "25" || s == "26" || s == "27"
    || s == "28" || s == "29" || s == "30" || s == "31" || s == "32" || s == "33" || s == "34" || s == "35" || s == "36" || s == "37"
    || s == "38" || s == "39" || s == "40" || s == "51" || s == "53" || s == "55" || s == "58")
    cout << "OK";
    else cout << "Error";
    return 0;
}