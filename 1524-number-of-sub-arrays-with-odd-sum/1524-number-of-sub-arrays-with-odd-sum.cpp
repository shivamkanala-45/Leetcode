
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int ans = 0, sum = 0;
        int odd = 0, even = 1;

        for (int x : arr) {
            sum += x;

            if (sum % 2 == 0) {
                ans += odd;
                even++;
            } else {
                ans += even;
                odd++;
            }

            ans %= MOD;
        }

        return ans;
    }
};
