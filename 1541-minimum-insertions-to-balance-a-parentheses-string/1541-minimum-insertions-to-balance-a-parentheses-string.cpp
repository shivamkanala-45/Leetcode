class Solution {
public:
    int minInsertions(string s) {
        int c = 0, ans = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') c++;
            else {
                if (i + 1 < s.size() && s[i + 1] == ')') i++;
                else ans++;
                if (c > 0) c--;
                else ans++;
            }
        }

        return ans + c * 2;
    }
};