class Solution {
public:
     int m, n;

        void dfs(vector<vector<int>>& v, int i, int j) {
        if (i < 0 || j < 0 || i >= m || j >= n)
            return;

        if (v[i][j] != 1)
            return;

        v[i][j] = 2;

        dfs(v, i + 1, j);
        dfs(v, i - 1, j);
        dfs(v, i, j + 1);
        dfs(v, i, j - 1);
    }

    int numEnclaves(vector<vector<int>>& v) {
        m = v.size();
        n = v[0].size();

        for (int i = 0; i < m; i++) {
            if (v[i][0] == 1)
                dfs(v, i, 0);

            if (v[i][n - 1] == 1)
                dfs(v, i, n - 1);
        }

        for (int j = 0; j < n; j++) {
            if (v[0][j] == 1)
                dfs(v, 0, j);

            if (v[m - 1][j] == 1)
                dfs(v, m - 1, j);
        }
        int c=0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (v[i][j] == 1)
                    c++;
            }
        }
        return c;
    }
};