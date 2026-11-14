class Solution {
public:
    int minimumSumSubarray(vector<int>& v, int l, int r) {
        int n = v.size();
        int ans = INT_MAX;

        for (int j = 0; j < n; j++) {
            int x = 0;

            for (int i = j; i < n && i - j + 1 <= r; i++) {
                x += v[i];

                if (i - j + 1 >= l && x > 0) {
                    ans = min(ans, x);
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};