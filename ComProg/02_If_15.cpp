#include<iostream>
using namespace std;

int main()
{
    string phnm;
    cin >> phnm;
    int len = phnm.size();
    if(len == 10)
    {
        if(phnm[0] == '0' && (phnm[1] == '6' || phnm[1] == '8' || phnm[1] == '9')) cout << "Mobile number";
        else cout << "Not a mobile number";
    }
    else cout << "Not a mobile number";
    return 0;
}