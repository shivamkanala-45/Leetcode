class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;

        unordered_map<char,bool> mp;

        int n = s.length();
        int i = 1, j = 0;
        int ans = 1;

        mp[s[0]] = true;

        while (i < n) {
            if (mp[s[i]]) {
                mp[s[j]] = false;
                j++;
            } else {
                mp[s[i]] = true;
                i++;
                ans = max(ans, i - j);
            }
        }

        return ans;
    }
};