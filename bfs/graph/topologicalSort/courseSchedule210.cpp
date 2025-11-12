class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for (vector<int>& prerequisite:prerequisites) {
            int to = prerequisite[0], from = prerequisite[1];
            inDegree[to]++;
            adj[from].push_back(to);
        }
        queue<int> q;
        for (int i = 0; i < inDegree.size(); i++) {
            if (inDegree[i] == 0) {
                q.push(i);
                res.push_back(i);
            }
        }
        if (q.size() == 0) return {};

        int count = q.size();
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int neighbor : adj[node]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                    count++;
                    res.push_back(neighbor);
                }
            }
        }
        if (count == numCourses) return res;
        return {};
    }
};

/*
0->1<-2
 <- 
*/
