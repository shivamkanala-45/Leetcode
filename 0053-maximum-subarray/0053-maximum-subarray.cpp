class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int target = nums[0];
        int res = nums[0];

        if (n == 1) return res;

        for (int i=1;i<n;i++) {
            target = max(nums[i], target + nums[i]);
            res = max(res, target);
        }

        return res;
    }
};