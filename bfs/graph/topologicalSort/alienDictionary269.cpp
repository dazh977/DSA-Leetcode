string alienOrder(vector<string>& words) {
        string res;
        vector<vector<char>> graph(26);
        vector<int> inDegree(26);
        unordered_set<char> occur;
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].size(); j++) {
                occur.insert(words[i][j]);
            }
        }
        for (int i = 0; i < words.size() - 1; i++) {
            if (i != words.size() - 1) {
                if (words[i].length() > words[i + 1].length() 
                    && words[i].substr(0, words[i + 1].length()) == words[i + 1]) {
                        return "";
                    }
            }
            int iterLen = min(words[i].length(), words[i + 1].length());
            for (int j = 0; j < iterLen; j++) {
                //if (i == j) continue;
                if (words[i][j] != words[i + 1][j]) {
                    graph[words[i][j] - 'a'].push_back(words[i + 1][j]);
                    inDegree[words[i + 1][j] - 'a']++;
                    break;
                }
            }
        }

        queue<char> q;
        for (int i = 0; i < 26; i++) {
            if (inDegree[i] == 0 && occur.count(i + 'a')) {
                q.push(i + 'a');
                res.push_back(i + 'a');
            }
        }
        while (!q.empty()) {
            char cur = q.front();
            q.pop();
            
            for (char neighbor : graph[cur - 'a']) {
                // inDegree[neighbor]--;
                inDegree[neighbor - 'a']--;
                if (inDegree[neighbor - 'a'] == 0) {
                    q.push(neighbor);
                    res.push_back(neighbor);
                }
            }
        }
        for (int i = 0; i < 26; i++) {
            if (inDegree[i] != 0) return "";
        }
        return res;
    }
