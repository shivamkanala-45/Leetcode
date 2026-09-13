class Solution {
public:
    int largestOverlap(vector<vector<int>>& v1, vector<vector<int>>& v2) {
        int n = v1.size();
        vector<pair<int, int>> o1, o2;

        for(int r = 0; r < n; r++){
            for(int c = 0; c < n; c++){
                if(v1[r][c] == 1)
                    o1.push_back({r, c});
                if(v2[r][c] == 1)
                    o2.push_back({r, c});
            }
        }

        unordered_map<int, int> mp;
        int ans = 0;

        for(auto [r1, c1] : o1){
            for(auto [r2, c2] : o2){
                int dr = r1 - r2;
                int dc = c1 - c2;
                int key = dr * 100 + dc;
                mp[key]++;
                ans = max(ans, mp[key]);
            }
        }

        return ans;
    }
};