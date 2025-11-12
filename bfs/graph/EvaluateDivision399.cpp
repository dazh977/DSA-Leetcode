class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> res;
        unordered_map<string, vector<pair<string, double>>> adj;
        for (int i = 0; i < equations.size(); i++) {
            vector<string> equation = equations[i];
            adj[equation[0]].push_back({equation[1], values[i]});
            adj[equation[1]].push_back({equation[0], 1.0 / values[i]});
        }

        for (vector<string>& query : queries) {
            if (adj.count(query[0]) == 0 || adj.count(query[1]) == 0) {
                res.push_back(-1.0);
                continue;
            }
            res.push_back(bfs(query[0], query[1], adj));
        }
        

        return res;
    }

    double bfs(string src, const string& dst, const unordered_map<string, vector<pair<string, double>>>& adj) {
            if (src == dst) return 1.0;
            queue<pair<string, double>> q;
            unordered_set<string> visited;
            q.push({src, 1.0});
            visited.insert(src);
            double res = 1.0;
            
            while (!q.empty()) {
                auto [cur, num] = q.front();
                q.pop();
                // res *= num;
                if (cur == dst) return num;
                
                for (const auto& neighbor : adj.at(cur)) {
                    if (adj.count(neighbor.first) == 0) return -1.0;
                    if (visited.count(neighbor.first)) {
                        continue;
                    }
                    q.push({neighbor.first, num * neighbor.second});
                    // res *= neighbor.second;
                    visited.insert(neighbor.first);
                    
                }
            }
            return -1.0;
    }
};
