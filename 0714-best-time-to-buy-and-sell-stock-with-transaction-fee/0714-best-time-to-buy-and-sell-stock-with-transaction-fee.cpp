class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        vector<int> ahead(2, 0), cur(2);

        for (int i = n - 1; i >= 0; i--) {
            cur[1] = max(-prices[i] + ahead[0],
                         ahead[1]);

            cur[0] = max(prices[i] - fee + ahead[1],
                         ahead[0]);

            ahead = cur;
        }

        return ahead[1];
    }
};