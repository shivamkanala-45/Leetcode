class Solution {
public:
    bool dfs(int i, int j, int k, int m, int n,
             vector<vector<char>>& board, string& word) {
        
        if (k == word.length()) return true;
        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != word[k])
            return false;

        char temp = board[i][j];
        board[i][j] = '#';

        bool found =
            dfs(i+1, j, k+1, m, n, board, word) ||
            dfs(i-1, j, k+1, m, n, board, word) ||
            dfs(i, j+1, k+1, m, n, board, word) ||
            dfs(i, j-1, k+1, m, n, board, word);

        board[i][j] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(i, j, 0, m, n, board, word))
                        return true;
                }
            }
        }
        return false;
    }
};