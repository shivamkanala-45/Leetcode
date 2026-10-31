class Solution {
public:
    int uniquePaths(vector<vector<int>>& v) {
        int n = v[0].size();
        int m = v.size();
        int mod=1000000007;
        vector<vector<pair<int, int>>> dp(m, vector<pair<int, int>>(n, {0, 0}));
        pair<int, int> x = {1, 0};
        for (int i = 0; i < n; i++) {
            dp[0][i] = x;
            if (v[0][i] == 1)
                x = {0, 0};
            ;
        }
        x = {0, 1};
        for (int j = 0; j < m; j++) {
            dp[j][0] = x;
            if (v[j][0] == 1)
                x = {0, 0};
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (v[i - 1][j] == 0)
                    dp[i][j].second = (int)(((long long)(dp[i - 1][j].first + dp[i - 1][j].second))%mod);
                else
                    dp[i][j].second = dp[i - 1][j].first;
                if (v[i][j - 1] == 0)
                    dp[i][j].first = (int)(((long long)(dp[i][j - 1].first + dp[i][j - 1].second))%mod);
                else
                    dp[i][j].first = dp[i][j - 1].second;
            }
        }
        return (dp[m - 1][n - 1].first + dp[m - 1][n - 1].second)%mod;
    }
};