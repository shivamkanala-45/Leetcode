class Solution {
public:
    bool canJump(vector<int>& v) {
        int n = v.size();
        vector<bool> b(n);
        int y=v[0];
        for (int i = 0; i <= min(y,n); i++)
            b[i] = true;
        if(b[n-1]) return true;
        for (int i = 1; i < n; i++) {
            if (b[i]) {
                int j = 1;
                while (j + i < n && j<= v[i]) {
                    b[j + i] = true;
                    j++;
                }
            }
        }
        return b[n-1];
    }
};