class Solution {
public:
    int sortPermutation(vector<int>& v) {
        int n = v.size();
        int ans = -1;
        for (int i = 0; i < n; i++) {

            if (v[i] != i) {
                if (ans == -1)
                    ans = v[i];
                ans &= v[i];
            }
        }
        if(ans==-1)
        ans=0;
        return ans;
    }
};