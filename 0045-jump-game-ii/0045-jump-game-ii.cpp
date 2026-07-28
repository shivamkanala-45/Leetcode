class Solution {
public:
    int jump(vector<int>& v) {
        int n = v.size();
        vector<int> b(n,INT_MAX);
        b[0]=0;
        int y=v[0];
        for (int i = 1; i <= min(y,n-1); i++)
            b[i] = 1;
        if(b[n-1]==1) return 1;
        for (int i = 1; i < n; i++) {
            if (b[i]!=INT_MAX) {
                int j = 1;
                while (j + i < n && j<= v[i]) {
                    b[j + i] = min(b[j+i],1+b[i]);
                    j++;
                }
            }
        }
        return b[n-1];
    }
};