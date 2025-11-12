class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();
        int res = 0;
        //vector<vector<bool>> visited(m, vector<int>(n, false));
        int fresh = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) fresh++;
                //if (grid[i][j] == 2) q.push({i, j});
            }
        }
        if (fresh == 0) return 0;
        
        bool flag = false;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    if (flag) continue;
                    flag = true;
                    res = bfs(i, j, fresh, q, grid);
                }
            }
        }

        return fresh == 0 ? res - 1 : -1;
    }

    int bfs(int i, int j, int& fresh, queue<pair<int, int>>& q, vector<vector<int>>& grid) {
        int minutes = 0;
        q.push({i, j});
        //grid[i][j] = 2;
        while (!q.empty()) {
            
            const int n = q.size();
            for (int i = 0; i < n; i++) {
                auto [row, col] = q.front();
                q.pop();
                for (vector<int>& dir : dirs) {
                    int nextR = row + dir[0];
                    int nextC = col + dir[1];
                    if (nextR < 0 || nextC < 0 || nextR >= grid.size() || nextC >= grid[0].size())
                        continue;
                    if (grid[nextR][nextC] != 1) continue;
                    q.push({nextR, nextC});
                    grid[nextR][nextC] = 2;
                    fresh--;
                }
            }
            
            minutes++;
        }
        return minutes;
    }

    vector<vector<int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
};
