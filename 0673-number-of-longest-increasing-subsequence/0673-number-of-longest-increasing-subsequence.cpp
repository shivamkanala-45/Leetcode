class Solution {
public:
    int findNumberOfLIS(vector<int>& a) {
        int n = a.size(), mx = 1, ans = 0;
        vector<int> len(n, 1), cnt(n, 1);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(a[j] < a[i]) {
                    if(len[j] + 1 > len[i])
                        len[i] = len[j] + 1, cnt[i] = cnt[j];
                    else if(len[j] + 1 == len[i])
                        cnt[i] += cnt[j];
                }
            }
        }

        for(int x : len) mx = max(mx, x);
        for(int i = 0; i < n; i++)
            if(len[i] == mx) ans += cnt[i];

        return ans;
    }
};