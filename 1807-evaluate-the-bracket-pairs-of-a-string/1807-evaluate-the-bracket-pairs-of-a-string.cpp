class Solution {
public:
    string evaluate(string s, vector<vector<string>>& v) {
        string ans = "";
        unordered_map<string, string> mp;
        for (auto x : v) {
            mp[x[0]] = x[1];
        }
        string t = "";
        bool f = 0;
        for (int i = 0; i < s.length(); i++) {

            if (s[i] == ')') {
                f = 0;
            } else if (s[i] == '(' || f) {
                f = 1;
                if (s[i] != '(')
                    t += s[i];
            }
            if (!f) {
                if (t.length()) {
                    if (mp.find(t) != mp.end())
                        ans += mp[t];
                    else
                        ans += '?';
                    t = "";
                }
                if(s[i]!=')')
                ans += s[i];
            }
        }
        return ans;
    }
};