class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        if (target == "0000") return 0;
        unordered_set<string> deadendSeen(deadends.begin(), deadends.end());
        if (deadendSeen.count(target) || deadendSeen.count("0000")) return -1;
        vector<int> nextTurn;
        vector<int> prevTurn;
        for (int i = 0; i < 10; i++) {
            if (i == 9) {
                nextTurn.push_back(0);
                continue;
            }
            nextTurn.push_back(i + 1);
        }
        for (int i = 0; i < 10; i++) {
            if (i == 0) {
                prevTurn.push_back(9);
                continue;
            }
            prevTurn.push_back(i - 1);
        }

        queue<string> q;
        q.push("0000");
        unordered_set<string> visited;
        visited.insert("0000");
        int level = 0;
        while (!q.empty()) {
            // string cur = q.front();
            const int n = q.size();
            // q.pop();
            for (int i = 0; i < n; i++) {
                string cur = q.front();
                q.pop();
                for (int pos = 0; pos < 4; pos++) {
                    string nextComb = cur;
                    int digit = cur[pos] - '0';
                    int nextDigit = nextTurn[digit];
                    nextComb[pos] = nextDigit + '0';
                    if (deadendSeen.count(nextComb) || visited.count(nextComb)) continue;
                    if (nextComb == target) return level + 1;
                    q.push(nextComb);
                    visited.insert(nextComb);
                }
                for (int pos = 0; pos < 4; pos++) {
                    string nextComb = cur;
                    int digit = cur[pos] - '0';
                    int prevDigit = prevTurn[digit];
                    nextComb[pos] = prevDigit + '0';
                    if (deadendSeen.count(nextComb) || visited.count(nextComb)) continue;
                    if (nextComb == target) return level + 1;
                    q.push(nextComb);
                    visited.insert(nextComb);
                }
            }
            level++;
        }
        

        return -1;
    }

};

/*unordered_map<string, unordered_set<string>> graph; // 10000 * 5 bytes
        string start = "0000";
        graph[start].insert("9999");
        graph["9999"].insert("0000");*/
