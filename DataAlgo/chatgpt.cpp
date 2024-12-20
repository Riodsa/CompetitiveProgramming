#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int countInfectedCells(vector<vector<int>>& grid, int R, int C, int T) {
    // Directions for moving in the grid (up, down, left, right)
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    // Queue for BFS: stores (row, col, day)
    queue<tuple<int, int, int>> q;

    // Initialize the queue with all infected cells
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (grid[i][j] == 1) { // Found an infected cell
                q.push({i, j, 0}); // Push its position and day 0
            }
        }
    }

    // Perform BFS to spread the infection
    while (!q.empty()) {
        auto [x, y, day] = q.front();
        q.pop();

        // Stop if we've exceeded T days
        if (day == T) break;

        // Spread infection to adjacent cells
        for (auto [dx, dy] : directions) {
            int nx = x + dx, ny = y + dy;

            // Check bounds and if the cell can be infected
            if (nx >= 0 && nx < R && ny >= 0 && ny < C && grid[nx][ny] == 0) {
                grid[nx][ny] = 1; // Mark as infected
                q.push({nx, ny, day + 1}); // Add to queue with incremented day
            }
        }
    }

    // Count the total number of infected cells
    int infectedCount = 0;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (grid[i][j] == 1) {
                ++infectedCount;
            }
        }
    }
    
    return infectedCount;
}

int main() {
    int R, C, T;
    cin >> R >> C >> T;

    vector<vector<int>> grid(R, vector<int>(C));
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> grid[i][j];
        }
    }

    cout << countInfectedCells(grid, R, C, T) << endl;
    return 0;
}
