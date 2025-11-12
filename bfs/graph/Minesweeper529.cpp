class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        const int m = board.size(), n = board[0].size();
        if (board[click[0]][click[1]] == 'M' || board[click[0]][click[1]] == 'X') {
            board[click[0]][click[1]] = 'X';
            return board;
        }
        queue<pair<int, int>> q;
        q.push({click[0], click[1]});
        while (!q.empty()) {
            const auto [r, c] = q.front();
            q.pop();
            if (!expand(r, c, board)) continue;
            //board[r][c] = 'B';
            for (const auto& dir : dirs) {
                int x = r + dir[0], y = c + dir[1];
                if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size()) continue;
                if (board[x][y] != 'E') continue;
                //board[x][y] = 'B';
                q.push({x, y});
            }
        }

        return board;
    }


    bool expand(int r, int c, vector<vector<char>>& board) {
        if (board[r][c] == 'B') return false;
        int count = 0;
        int x = r, y = c;
        for (const auto& dir : dirs) {
            x = r + dir[0], y = c + dir[1];
            if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size()) continue;
            if (board[x][y] == 'M') count++;
        }
        if (count > 0) {
            board[r][c] = count + '0';
            return false;
        } else {
            board[r][c] = 'B';
            return true;
        }
    }

    const vector<vector<int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

};
