class Solution {
public:
    bool lemonadeChange(vector<int>& v) {
        int n = v.size();
        int a = 0, b = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] == 5)
                a++;
            else if (v[i] == 10 && a) {
                a--;
                b++;
            } else {
                if (a > 0 && b > 0) {
                    a--;
                    b--;
                } else if (a >= 3) {
                    a -= 3;
                } else
                    return false;
            }
        }
        return true;
    }
};