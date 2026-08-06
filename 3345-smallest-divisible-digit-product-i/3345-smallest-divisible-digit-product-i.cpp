class Solution {
public:
    int f(int n) {
        int x = 1;
        while (n) {
            x = x * (n % 10);
            n=n/10;
        }
        return x;
    }
    int smallestNumber(int n, int t) {
        for (int i = n; i <= n + 10; i++) {
            if (f(i) % t == 0)
                return i;
        }
        return 0;
    }
};