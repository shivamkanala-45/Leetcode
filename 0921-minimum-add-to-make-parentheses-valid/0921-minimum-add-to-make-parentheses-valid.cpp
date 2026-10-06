class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0;
        int c = 0;
        for (auto x : s) {
            if (x == '(') {
                if (c < 0) {
                    ans += (-c);
                    c = 0;
                }
                c++;
            } else {
                c--;
            }
        }
        return ans + abs(c);
    }
};