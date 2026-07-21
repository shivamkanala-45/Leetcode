class Solution {
public:
    int maxProfit(vector<int>& v) {
        int p = 0;

        for (int i = 1; i < v.size(); i++) {
            if (v[i] > v[i - 1]) {
                p += v[i] - v[i - 1];
            }
        }

        return p;
    }
};