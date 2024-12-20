#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n+1][n+1],num[n*n+1],c=0;
    int zero_pos_at;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            cin >> arr[i][j];
            if(arr[i][j] != 0) num[c++] = arr[i][j];
            else zero_pos_at = i;
        }
    }
    // for(int i=0;i<c;++i) cout << num[i] << ' ';
    // cout << '\n';
    int inversion_count = 0;
    for(int i=0;i<c;++i)
    {
        for(int j=i+1;j<c;++j)
        {
            if(num[i] > num[j]) inversion_count++;
        }
    }
    if(n%2 == 1 && inversion_count%2 == 0) cout << "YES";
    else if(n%2==0)
    {
        if(inversion_count%2 == 1 && zero_pos_at%2 == 0) cout << "YES";
        else if(inversion_count%2 == 0 && zero_pos_at%2 == 1) cout << "YES";
        else cout << "NO";
    }
    else cout << "NO";
    // cout << '\n';
    // cout << "amount of rows = " << ((n%2==0) ? "even" : "odd"); cout << '\n';
    // cout << "inversion count = " << ((inversion_count%2==0)?"even":"odd") << '\n';
    // cout << "zero is on = " << ((zero_pos_at%2==0) ? "even\n": "odd\n");
    return 0;
}