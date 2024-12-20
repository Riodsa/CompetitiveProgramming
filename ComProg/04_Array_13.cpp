#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n+1],cnt_top = 0;
    for(int i=1;i<=n;++i) cin >> arr[i];
    for(int i=2;i<=n-1;++i) if(arr[i] > arr[i-1] && arr[i] > arr[i+1]) ++cnt_top;
    cout << cnt_top;
    return 0;
}