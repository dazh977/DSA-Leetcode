struct comp {
    bool operator () (const vector<int>& p1, const vector<int>& p2) {
        // return p2.second < p2.second;
        return p1[0] > p2[0];
    }
};
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // int res = 0;
        vector<vector<pair<int, int>>> adj(n);
        //unordered_set<int> seen;
        for (const auto& flight : flights) {
            int source = flight[0], dest = flight[1], price = flight[2];
            adj[source].push_back({dest, price});
        }
        priority_queue<vector<int>, vector<vector<int>>, comp> pq;
        // seen.insert(src);
        vector<vector<int>> distFromSrc(n, vector<int>(k + 2, INT_MAX));


        pq.push({0, src, 0});
        
        while (!pq.empty()) {
            vector<int> node = pq.top();
            pq.pop();
            // res += price;
            int curPrice = node[0], source = node[1], step = node[2];
            if (step > k + 1) continue;
            if (distFromSrc[source][step] != INT_MAX) continue;
            
            if (source == dst) return curPrice;
            // seen.insert(source);
            distFromSrc[source][step] = step;
            
            for (pair<int, int>& neighbor : adj[source]) {
                // if (seen.count(neighbor.first)) continue;
                pq.push({neighbor.second + curPrice, neighbor.first, step + 1});
            }
        }
        
        return -1;
    }
};
