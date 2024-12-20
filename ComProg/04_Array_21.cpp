#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    int n;
    cin >> n;
    double arr[n+1];
    for(int i=1;i<=n;++i) cin >> arr[i];
    for(int i=1;i<=n;++i)
    {
        double sum = 0;
        // cout << arr[i] << ' ';
        for(int j=i;j>=1;--j)
        {
            // cout << sum << ' ';
            sum = 1/sum;
            if(j == i) sum = arr[j];
            else sum += (arr[j]);
        }
        cout << setprecision(10) << sum << '\n';
    }
    return 0;
}