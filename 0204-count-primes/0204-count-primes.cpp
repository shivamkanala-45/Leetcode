class Solution {
public:
    int countPrimes(int n) {
        int c = 0;
        vector<bool> v(n + 1);
        for (int i = 2; i < n; i++) {
            if (!v[i]) {
                c++;
                for (int j = i; j < n; j += i) {
                    v[j] = true;
                }
            }
        }
        return c;
    }
};