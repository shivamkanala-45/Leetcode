class Solution {
public:
    int bit_width(int n) {
        if (n == 0)
            return 0;

        int bits = 0;
        while (n) {
            bits++;
            n >>= 1;
        }
        return bits;
    }
    int uniqueXorTriplets(vector<int>& v) {
        int n = v.size();
        if (n <= 2)
            return n;
        else
            return 1 << bit_width(n);
    }
};