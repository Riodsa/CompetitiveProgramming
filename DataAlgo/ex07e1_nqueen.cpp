#include<bits/stdc++.h>
using namespace std;

const int N = 13;
int n;
int res = 0;
int board[N][N];

bool isValid(int r,int c)
{
    for(int i=r-1;i>=0;--i) if(board[i][c]) return false; // same row
    for(int i=c-1;i>=0;--i) if(board[r][i]) return false; // same col
    for(int i=r-1,j=c-1;i>=0&&j>=0;i--,j--) if(board[i][j]) return false; // same diag from top left
    for(int i=r-1,j=c+1;i>=0&&j<n;i--,j++) if(board[i][j]) return false; // same diag from top right
    return true;
}

void place_nQueen(int row)
{
    if(row == n)
    {
        res++;
        return ;
    }
    for(int col=0;col<n;++col)
    {
        if(isValid(row,col))
        {
            board[row][col] = 1;
            place_nQueen(row+1);
        }
        board[row][col] = 0;
    }
    return ;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    place_nQueen(0);
    cout << res;
    return 0;
}