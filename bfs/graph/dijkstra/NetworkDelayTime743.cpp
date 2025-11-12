class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (vector<int>& time:times) {
            int source = time[0], dest = time[1], dist = time[2];
            adj[source].push_back({dest, dist});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<int> distance(n + 1, INT_MAX);
        distance[k] = 0;
        pq.push({0, k});

        int res = 0;
        while (!pq.empty()) {
            auto [hello, cur_node] = pq.top();
            pq.pop();
            int start = cur_node;
            //if (source_to_cur >= distance[start]) continue;
            for (auto [dest, weight] : adj[start]) {
                if (weight + distance[start] >= distance[dest]) continue;
                // pq.push({dist + distance[start], dest});
                pq.push({weight + distance[start], dest});
                distance[dest] = weight + distance[start];
            }
        }
        // for (int i = 0; i <=n; i++) {
        for (int i = 1; i <=n; i++) {
            if (distance[i] == INT_MAX) return -1;
            res = max(res, distance[i]);
        }
        return res;
    }
};
