class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        if (grid.size() == 1) return grid[0][0];
        const size_t m = grid.size();
        static vector<vector<int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<vector<bool>> seen(m, vector<bool>(m, false));
        int maxH = 0;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({grid[0][0], {0,0}});
        seen[0][0] = true;
        // while (pq.top().first != m - 1 && !pq.empty()) {
        // while (pq.top().second.first != m - 1 && pq.top().second.second != m - 1 && !pq.empty()) {
        while (!pq.empty()) {
            auto [curMax, pos] = pq.top();
            auto [i, j] = pos;
            pq.pop();
            // seen[i][j] = true; move it to when push
            if (i == m - 1 && j == m - 1) return curMax;
            for (const vector<int>& dir:dirs) {
                int x = i + dir[0];
                int y = j + dir[1];
                if (x >= 0 && y >= 0 && x < m && y < m && !seen[x][y]) {
                    seen[x][y] = true;
                    pq.push({max(curMax, grid[x][y]), {x, y}});
                }
            }
        }
        // return -pq.top().first;
        return -1;
    }
private:
    
};

/*
    hashset visited
    pq([h, (x, y)])
    maxH
    add (h, (0, 0)) to pq
    while (!target && !pq.empty()) {
        element = pq.pop()
        curMax = element.first
        for (dir:directions) {
            if (!visited(x, y) and inbound) {
                pq.push(max(curMax, grid[x][y]));
            }
        }
    }
    return pq.top.height;


    0, 1, 2, 3, 4
    15 23 22 21 5
    12 13 14 24 16
    11 17 18 19 20
    10 9, 8, 7, 6

*/
