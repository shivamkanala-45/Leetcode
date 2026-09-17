class Solution {
public:
    int minSumOfLengths(vector<int>& v, int t) {
        int n = v.size();
        vector<int> p(n + 1, 0);

        for (int i = 0; i < n; i++) {
            p[i + 1] = p[i] + v[i];
        }
        vector<int> b(n, INT_MAX);

        unordered_map<int, int> mp;
        mp[0] = 0;
        int ans = INT_MAX;
        int mn = INT_MAX;

        for (int i = 1; i <= n; i++) {
            if (i >= 2)
                b[i - 1] = b[i - 2];

            if (mp.find(p[i] - t) != mp.end()) {

                int j = mp[p[i] - t];
                int len = i - j;
                if (j > 0 && b[j - 1] != INT_MAX) {
                    ans = min(ans, b[j - 1] + len);
                }

                mn = min(mn, len);
            }
            mp[p[i]] = i;
            b[i - 1] = min(b[i - 1], mn);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};