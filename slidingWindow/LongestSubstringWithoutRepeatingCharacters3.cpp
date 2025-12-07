int lengthOfLongestSubstring(string s) {
        if (s.length() <= 1) return s.length();
        unordered_map<char, int> freq;
        int l = 0, r = 0;
        int res = 0;
        while (r < s.length()) {
            freq[s[r]]++;
            while (freq[s[r]] > 1) {
                freq[s[l]]--;
                l++;
            }
            res = max(res, r - l + 1);
            r++;
            
        }
        return res;
    }
