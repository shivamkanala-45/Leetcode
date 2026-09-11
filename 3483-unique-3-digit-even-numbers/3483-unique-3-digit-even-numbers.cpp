class Solution {
public:
    int totalNumbers(vector<int>& v) {
        unordered_map<int,int>mp;
        for (int x : v)
            mp[x]++;
        int ans = 0;
        for (int i = 0; i <= 9 ;i += 2) {
            int x = mp[i]--;
            if (x) {
                for (int j = 0; j <= 9; j++) {
                    int y = mp[j]--;
                    if (y) {
                        for (int k = 1; k <= 9; k++) {
                            if (mp[k])
                                ans++;
                        }
                    }
                    mp[j] = y;
                }
            }
            mp[i]=x;
        }
        return ans;
    }
};