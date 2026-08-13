class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        vector<int> next(n + 1, 0), cur(n + 1, 0);

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (s1[i] == s2[j])
                    cur[j] = 1 + next[j + 1];
                else
                    cur[j] = max(next[j], cur[j + 1]);
            }
            next = cur;
        }
        return next[0];
    }
};