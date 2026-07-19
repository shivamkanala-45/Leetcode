class Solution {
public:
    int findMin(vector<int>& v) {
        int n = v.size();
        int l = 0, h = n - 1;
        int ans = INT_MAX;

        while (l <= h) {
            int m = l + (h - l) / 2;

            if (v[l] <= v[m]) {
                ans = min(ans, v[l]);
                l = m + 1;
            }
            else {
                ans = min(ans, v[m]);
                h = m - 1;
            }
        }

        return ans;
    }
};