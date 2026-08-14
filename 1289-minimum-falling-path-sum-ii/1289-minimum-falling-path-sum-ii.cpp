class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& v) {
        int m = v.size();
        int n = v[0].size();
        vector<int> p(n);
        for (int i = 0; i < n; i++)
            p[i] = v[m - 1][i];
        for (int i = m - 2; i >= 0; i--) {
            vector<int> c(n);
            for (int j = 0; j < n; j++) {
                c[j] = INT_MAX;
                for (int k = 0; k < n; k++) {
                    if(k==j) continue;
                    c[j] = min(c[j], p[k]);
                }
                c[j] += v[i][j];
            }
            p = c;
        }
        int ans = INT_MAX;
        for (auto x : p)
            ans = min(ans, x);
        return ans;
    }
};