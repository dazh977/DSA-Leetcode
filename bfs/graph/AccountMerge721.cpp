class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> adj;
        for (const auto& account : accounts) {
            for (int i = 1; i < account.size() - 1; i++) {
                adj[account[i]].push_back(account[i + 1]);
                adj[account[i + 1]].push_back(account[i]);
            }
        }
        unordered_set<string> visited;

        for (const auto& account : accounts) {
            if (visited.count(account[1])) continue;
            vector<string> temp;
            temp.push_back(account[0]);
            dfs(account[1], temp, visited, adj);
            sort(temp.begin() + 1, temp.end());
            res.push_back(temp);
        }

        return res;
    }

    void dfs(const string mail, vector<string>& temp, unordered_set<string>& visited, 
                unordered_map<string, vector<string>>& adj) {
        if (visited.count(mail)) return;
        temp.push_back(mail);
        visited.insert(mail);
        for (string neighbor : adj[mail]) {
            //if (visited.count(neighbor)) continue;
            dfs(neighbor, temp, visited, adj);
        }

    }
    
};
