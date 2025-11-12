class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if (x + y < target) return false;
        queue<pair<int, int>> q;
        unordered_set<int> seen;
        q.push({0, 0});
        seen.insert(0);
        while (!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();
            if (cur.first + cur.second == target) return true;
            // if (cur.first == target || cur.second == target) return true;
            vector<pair<int, int>> nextState;
            calcNext(cur, nextState, x, y);
            for (int i = 0; i < nextState.size(); i++) {
                // int hash = cur.first * (y + 1) + cur.second; wrong
                int hash = (nextState[i].first) * (y + 1) + (nextState[i].second); 
                if (seen.count(hash)) continue;
                q.push({nextState[i]});
                seen.insert(hash);
            }
        }
        return false;
    }

    void calcNext(const pair<int, int>& cur, vector<pair<int, int>>& next, const int x, const int y) {
        next.push_back({x, cur.second}); // fill jug1
        next.push_back({cur.first, y}); // fill jug2
        next.push_back({0, cur.second}); // empty jug1
        next.push_back({cur.first, 0}); // empty jug2
        next.push_back({cur.first - min(cur.first, y - cur.second), 
            cur.second + min(cur.first, y - cur.second)}); // from jug1 to jug2
        next.push_back({cur.first + min(x - cur.first, cur.second), 
            cur.second - min(x - cur.first, cur.second)}); // from jug2 to jug1
    }
};
