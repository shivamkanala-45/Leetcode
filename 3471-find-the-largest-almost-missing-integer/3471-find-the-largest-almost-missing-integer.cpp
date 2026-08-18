class Solution {
public:
    int largestInteger(vector<int>& v, int k) {
        unordered_map<int, int> mp;
        for (auto x : v)
            mp[x]++;
        if (k == 1) {
            int ans = -1;
            for (auto x : mp) {
                if (x.second == 1)
                    ans = max(ans, x.first);
            }
            return ans;
        } else if (k == v.size()) {
            int ans = -1;
            for (auto x : v) {
                ans = max(ans, x);
            }
            return ans;
        }
        int ans = -1;
        if (mp[v[0]] == 1)
            ans = max(ans, v[0]);
        if (mp[v[v.size() - 1]] == 1)
            ans = max(ans, v[v.size() - 1]);
        return ans;
    }
};