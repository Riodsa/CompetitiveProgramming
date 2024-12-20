#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    deque<int> encrypt1(9),encrypt2(9),encrypt3(9);
    string code,system;
    cin >> system;
    int e1=system[0]-'0', e2=system[1]-'0', e3=system[2]-'0';
    for (int i=0; i<9; i++){
        encrypt1[i] = e1;
        encrypt2[i] = e2;
        encrypt3[i] = e3;
        (e1==9)? e1=1 : e1++;
        (e2==9)? e2=1 : e2++;
        (e3==9)? e3=1 : e3++;
    }
    cin >> code;
    for(int x : encrypt1)
    {
        cout << x << " ";
    }cout << '\n';
    for(int x : encrypt2)
    {
        cout << x << " ";
    }cout << '\n';
    for(int x : encrypt3)
    {
        cout << x << " ";
    }cout << '\n';
    cout << '\n';
    for (int i=0; i<code.length(); i++){
        code[i] = encrypt1[code[i]-'0'-1]+'0';
        e1 = system[0]-'0';
        while(e1--){
            int temp = encrypt1.front();
            encrypt1.pop_front();
            encrypt1.push_back(temp);
        }
        code[i] = encrypt2[code[i]-'0'-1]+'0';
        int temp = encrypt2.back();
        encrypt2.pop_back();
        encrypt2.push_front(temp);
        code[i] = encrypt3[code[i]-'0'-1]+'0';
        e3 = system[2]-'0';
        while(e3--){
            int temp = encrypt3.front();
            encrypt3.pop_front();
            encrypt3.push_back(temp);
        }
        for(int x : encrypt1)
        {
            cout << x << " ";
        }cout << '\n';
        for(int x : encrypt2)
        {
            cout << x << " ";
        }cout << '\n';
        for(int x : encrypt3)
        {
            cout << x << " ";
        }cout << '\n';
        cout << '\n';
    }
    cout << code;
    return 0;
}
