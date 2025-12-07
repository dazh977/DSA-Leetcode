bool checkInclusion(string s1, string s2) {
        if (s2.length() < s1.length()) return false;
        vector<int> freq1(26), freq2(26);
        for (int i = 0; i < s1.length(); i++) {
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }
        for (int i = 0; i <= s2.length() - s1.length(); i++) {
            if (isPerm(freq1, freq2)) return true;
            if (i != s2.length() - s1.length()) {
                freq2[s2[i] - 'a']--;
                freq2[s2[i + s1.length()] - 'a']++;
            }
        }
        return false;
    }

    bool isPerm(const vector<int>& freq1, const vector<int>& freq2) {
        for (int i = 0; i < 26; i++) {
            if (freq1[i] != freq2[i]) return false;
        }
        return true;
    }
