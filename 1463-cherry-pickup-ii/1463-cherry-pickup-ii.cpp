class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> next(cols, vector<int>(cols, 0));

        for (int i = rows - 1; i >= 0; i--) {
            vector<vector<int>> cur(cols, vector<int>(cols, 0));
            for (int j1 = 0; j1 < cols; j1++)
                for (int j2 = 0; j2 < cols; j2++) {
                    int cherries = grid[i][j1] + (j1 != j2 ? grid[i][j2] : 0);
                    int best = 0;
                    if (i < rows - 1) {
                        for (int dj1 = -1; dj1 <= 1; dj1++)
                            for (int dj2 = -1; dj2 <= 1; dj2++) {
                                int nj1 = j1 + dj1, nj2 = j2 + dj2;
                                if (nj1 >= 0 && nj1 < cols && nj2 >= 0 &&
                                    nj2 < cols)
                                    best = max(best, next[nj1][nj2]);
                            }
                    }
                    cur[j1][j2] = cherries + best;
                }
            next = cur;
        }
        return next[0][cols - 1];
    }
};