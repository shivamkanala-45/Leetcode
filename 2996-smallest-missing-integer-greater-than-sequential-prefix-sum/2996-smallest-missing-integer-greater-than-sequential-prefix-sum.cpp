class Solution {
public:
    int missingInteger(vector<int>& v) {
        vector<bool> present(51, false);

        for (int x : v)
            present[x] = true;

        int sum = v[0];

        for (int i = 1; i < v.size(); i++) {
            if (v[i] == v[i - 1] + 1)
                sum += v[i];
            else
                break;
        }

        while (sum <= 50 && present[sum])
            sum++;

        return sum;
    }
};