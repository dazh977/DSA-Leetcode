class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for (vector<int>& prerequisite:prerequisites) {
            int to = prerequisite[0], from = prerequisite[1];
            inDegree[to]++;
            adj[from].push_back(to);
        }
        queue<int> q;
        for (int i = 0; i < inDegree.size(); i++) {
            if (inDegree[i] == 0) q.push(i);
        }
        if (q.size() == 0) return false;
        int count = q.size();
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int neighbor : adj[node]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                    count++;
                }
            }
        }

        return count == numCourses;
    }
};
