class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& a) {

        unordered_map<int, vector<int>> mp;

        for (auto x : a)
            mp[x[0]].push_back(x[1]);

        int ans = (n - mp.size()) * 2;

        for (auto &[row, v] : mp) {

            bool p = 0, q = 0, r = 0;

            if (find(v.begin(), v.end(), 2) == v.end() &&
                find(v.begin(), v.end(), 3) == v.end() &&
                find(v.begin(), v.end(), 4) == v.end() &&
                find(v.begin(), v.end(), 5) == v.end())
                p = 1;

            if (find(v.begin(), v.end(), 4) == v.end() &&
                find(v.begin(), v.end(), 5) == v.end() &&
                find(v.begin(), v.end(), 6) == v.end() &&
                find(v.begin(), v.end(), 7) == v.end())
                q = 1;

            if (find(v.begin(), v.end(), 6) == v.end() &&
                find(v.begin(), v.end(), 7) == v.end() &&
                find(v.begin(), v.end(), 8) == v.end() &&
                find(v.begin(), v.end(), 9) == v.end())
                r = 1;

            if (p && r)
                ans += 2;
            else if (p || q || r)
                ans++;
        }

        return ans;
    }
};