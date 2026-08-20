class Solution {
public:
    int minDistance(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        vector<int> next(n + 1), cur(n + 1);
        for (int j = 0; j <= n; j++)
            next[j] = n - j;

        for (int i = m - 1; i >= 0; i--) {
            cur[n] = m - i;
            for (int j = n - 1; j >= 0; j--) {
                if (s1[i] == s2[j])
                    cur[j] = next[j + 1];
                else
                    cur[j] = 1 + min({next[j + 1], next[j], cur[j + 1]});
            }
            next = cur;
        }
        return next[0];
    }
};