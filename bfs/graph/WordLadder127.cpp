class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<int>> res;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.count(endWord) == 0) return 0;
        unordered_map<string, vector<string>> graph;
        //dict.insert(beginWord);
        for (string word : dict) {
            for (int i = 0; i < word.length(); i++) {
                string temp = word;
                temp[i] = '*';
                //graph[word].push_back(temp);
                graph[temp].push_back(word);
            }
        }
         
        return bfs(beginWord, endWord, graph);
    }

    int bfs(const string beginWord, const string endWord,
            const unordered_map<string, vector<string>>& graph) {
        queue<pair<string, int>> q;
        unordered_set<string> visited;
        q.push({beginWord, 1});
        visited.insert(beginWord);
        
        while (!q.empty()) {
            const auto [word, dist] = q.front();
            q.pop();
            if (word == endWord) return dist;
            for (int i = 0; i < word.length(); i++) {
                string temp = word;
                
                temp[i] = '*';
                if (graph.count(temp) == 0) continue;
                for (string neighbor : graph.at(temp)) {
                    if (visited.count(neighbor)) continue;
                    q.push({neighbor, dist + 1});
                    visited.insert(neighbor);
                }
                
            }
        }
        return 0;
    }
};
