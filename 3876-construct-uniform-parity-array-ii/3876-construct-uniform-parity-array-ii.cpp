class Solution {
public:
    bool uniformArray(vector<int>& v) {
        int n = v.size();
        int i = -1;
        int j = -1;
        int o = INT_MAX;
        int e = INT_MAX;
        for (int k = 0; k < n; k++) {
            if (v[k] % 2 == 1) {
                if (v[k] < o) {
                    o = v[k];
                    i = k;
                }
            } else {
                if (v[k] < e) {
                    e = v[k];
                    j = k;
                }
            }
        }
        cout<<i<<j;
        if(i ==-1 || j==-1) return 1;
        if(v[i]<v[j]) return 1;
        return 0;
    }
};