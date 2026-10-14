
class Solution {
public:
    string maxSumOfSquares(int n, int s) {
        string ans = "";

        while (s >= 9) {
            s -= 9;
            ans += '9';
        }

        if (s != 0)
            ans += (s + '0');

        while (ans.length() < n)
            ans += '0';
        if(ans.length()!=n) return "";
        return ans;
    }
};
