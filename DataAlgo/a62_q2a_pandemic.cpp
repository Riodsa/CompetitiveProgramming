#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
int r, c, T;
const int N = 5e2 + 1;
char board[N][N];
pii idx[4] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
int ans = 0;

void print_board(char b[N][N])
{
    for (int i = 1; i <= r; ++i)
    {
        for (int j = 1; j <= c; ++j)
        {
            cout << b[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "----------\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> r >> c >> T;
    queue<pii> q;
    for (int i = 1; i <= r; ++i)
    {
        for (int j = 1; j <= c; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == '1')
            {
                q.push({i, j});
                ans++;
            }
        }
    }
    int day = 1;
    while (!q.empty() && day <= T)
    {
        queue<pii> tmp;
        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i)
            {
                int tx = x + idx[i].first;
                int ty = y + idx[i].second;
                if (tx < 0 || tx > r)
                    continue;
                if (ty < 0 || ty > c)
                    continue;
                if (board[tx][ty] == '0')
                {
                    ans++;
                    board[tx][ty] = '1';
                    tmp.push({tx, ty});
                }
            }
        }
        swap(tmp, q);
        // cout << "q.size(): " << q.size() << '\n';
        // print_board(board);
        day++;
    }
    cout << ans;
    return 0;
}