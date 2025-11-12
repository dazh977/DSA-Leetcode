class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        const int n = graph.size();
        unordered_set<int> visited;
        vector<bool> color(n);
        for (int i = 0; i < n; i++) {
            if (visited.count(i)) continue;
            if (!bfs(i, color, visited, graph)) return false;
        }
        return true;
    }

    bool bfs(int node, vector<bool>& color, unordered_set<int>& visited, const vector<vector<int>>& graph) {
        queue<int> q;
        q.push(node);
        visited.insert(node);
        color[node] = true;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            int curColor = color[cur];
            for (int neighbor : graph[cur]) {
                
                // if (color[neighbor] != -1 && color[neighbor] == color[cur]) return false;
                if (visited.count(neighbor) && curColor == color[neighbor]) return false;
                if (visited.count(neighbor)) continue;
                if (curColor) color[neighbor] = false;
                else color[neighbor] = true;
                q.push(neighbor);
                
                visited.insert(neighbor);
            }
        }
        return true;
    }
};
