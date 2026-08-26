class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {

        int n = s.size();

        // Store positions of all 1s
        vector<int> pos;

        for (int i = 0; i < n; i++) {
            if (s[i] == '1')
                pos.push_back(i);
        }

        // Not enough 1s
        if (pos.size() < k)
            return "";

        string ans = "";

        // Consider every group of k consecutive 1s
        for (int i = 0; i + k - 1 < pos.size(); i++) {

            int l = pos[i];
            int r = pos[i + k - 1];

            string cur = s.substr(l, r - l + 1);

            // Shorter substring
            if (ans.empty() || cur.size() < ans.size()) {
                ans = cur;
            }

            // Same length -> lexicographically smaller
            else if (cur.size() == ans.size() && cur < ans) {
                ans = cur;
            }
        }

        return ans;
    }
};