class Solution {
public:
    vector<vector<vector<int>>> dp;

    bool dfs(int i, int j, vector<vector<char>>& v, int k) {
        int n = v.size();
        int m = v[0].size();
        if (k < 0)
            return false;
        if (i == n - 1 && j == m - 1)
            return k == 0;
        if (dp[i][j][k] != -1)
            return dp[i][j][k];

        bool ans = false;
        if (i + 1 < n) {
            if (v[i + 1][j] == '(')
                ans = ans || dfs(i + 1, j, v, k + 1);
            else
                ans = ans || dfs(i + 1, j, v, k - 1);
        }
        if (j + 1 < m) {
            if (v[i][j + 1] == '(')
                ans = ans || dfs(i, j + 1, v, k + 1);
            else
                ans = ans || dfs(i, j + 1, v, k - 1);
        }

        return dp[i][j][k] = ans;
    }

    bool hasValidPath(vector<vector<char>>& v) {
        int n = v.size();
        int m = v[0].size();

        if (v[0][0] == ')')
            return false;

        dp.assign(n, vector<vector<int>>(m, vector<int>(n + m + 1, -1)));

        return dfs(0, 0, v, 1);
    }
};