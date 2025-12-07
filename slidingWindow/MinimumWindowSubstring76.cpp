class Solution {
public:
    string minWindow(string s, string t) {
        if (t.length() > s.length()) return "";
        int left = 0;
        int start = -1, window_len = s.length() + 1, valid = 0;
        for (char ch : t) {
            need[ch]++;
        }
        for (int right = 0; right < s.length(); right++) {
            window[s[right]]++;
            if (need.count(s[right])) {
                if (window[s[right]] == need[s[right]]) {
                    valid++;
                }
            }
            while (valid == need.size()) {
                if (right - left + 1 < window_len) {
                    window_len = right - left +1;
                    start = left;
                }
                if (need.count(s[left]) && window[s[left]] == need[s[left]]) {
                        valid--;
                }
                window[s[left]]--;
                left++;
            }
        }
        return window_len == s.length() + 1 ? "" : s.substr(start, window_len);
    }

unordered_map<char, int> need;
unordered_map<char, int> window;

};
