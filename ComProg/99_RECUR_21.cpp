#include <iostream>
using namespace std;
const int R = 7, C = 7;

pair<int,int> idx[4] = {{-1,0},{0,1},{1,0},{0,-1}};

void floodfill(int x[][C], int r, int c, int e)
{
    for(int i=0;i<4;++i)
    {
        int xr = r+idx[i].first, xc = c+idx[i].second;
        if(xr >= 0 && xr < R && xc >= 0 && xc < C)
        {
            if(x[xr][xc] == 0)
            {
                x[xr][xc] = e;
                floodfill(x,xr,xc,e);
            }
        }
    }
}
int main()
{
    int x[][C] = {{0}, {0}, {0}, {0}, {0}, {0}, {0}};
    for (int r = 0; r < R; ++r)
        for (int c = 0; c < C; ++c)
            cin >> x[r][c];
    int row, col, e;
    cin >> row >> col >> e;
    floodfill(x, row, col, e);
    for (int r = 0; r < R; ++r)
    {
        for (int c = 0; c < C; ++c)
            cout << x[r][c] << ' ';
        cout << endl;
    }
}