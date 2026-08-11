class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<long long> dp(target + 1, 0);
        dp[0] = 1;

        for (int a = 1; a <= target; a++) {
            for (int c : nums) {
                if (c <= a) {
                    if (dp[a] <= INT_MAX - dp[a - c])
                        dp[a] += dp[a - c];
                }
            }
        }

        return (int)dp[target];
    }
};