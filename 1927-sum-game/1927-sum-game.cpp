class Solution {
public:
    bool sumGame(string s) {
        int l = 0, ll = 0, r = 0, rr = 0;
        int n = s.length();
        for (int i = 0; i < n / 2; i++) {
            if (s[i] == '?')
                ll++;
            else
                l += (s[i] - '0');
        }
        for (int i = n / 2; i < n; i++) {
            if (s[i] == '?')
                rr++;
            else
                r += (s[i] - '0');
        }
        cout << l << " " << r << " " << ll << " " << rr;
        if (ll == rr && l == r)
            return false;
        if (l > r && ll > rr || r > l && rr > ll)
            return true;
        if (abs(l - r) % 9 == 0) {
            int k = abs(l - r) / 9;
            if (abs(ll - rr) == 2 * k)
                return false;
        }
        return true;
    }
};