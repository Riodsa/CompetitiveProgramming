#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    double matrix[n+1][m+1];
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            cin >> matrix[i][j];
        }
    }
    for(int i=2;i<=n-1;++i)
    {
        for(int j=2;j<=m-1;++j)
        {
            double sum = 0;
            sum += matrix[i-1][j-1] + matrix[i-1][j] + matrix[i-1][j+1]
                  +matrix[i][j-1] + matrix[i][j] + matrix[i][j+1]
                  +matrix[i+1][j-1] + matrix[i+1][j] + matrix[i+1][j+1];
            sum /= 9;
            cout << round(sum*100)/100 << ' ';
        }
        cout << '\n';
    }
    return 0;
}