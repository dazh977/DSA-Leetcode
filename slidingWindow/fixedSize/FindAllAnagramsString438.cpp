vector<int> findAnagrams(string s, string p) {
        if (p.length() > s.length()) return {};
        vector<int> res;
        vector<int> freqP(26, 0);
        vector<int> freqS(26, 0);
        for (int i = 0; i < p.length(); i++) {
            freqP[p[i] - 'a']++;
            freqS[s[i] - 'a']++;
        }
        for (int i = 0; i <= s.length() - p.length(); i++) {
            if (isAnagram(freqP, freqS)) res.push_back(i);
            if (i != s.length() - p.length()) {
                freqS[s[i] - 'a']--;
                freqS[s[i + p.length()] - 'a']++;
            }
        }
        return res;
    }

    bool isAnagram(const vector<int>& freqS, const vector<int>& freqP) {
        for (int i = 0; i < 26; i++) {
            if (freqS[i] != freqP[i]) return false;
        }
        return true;
    }
