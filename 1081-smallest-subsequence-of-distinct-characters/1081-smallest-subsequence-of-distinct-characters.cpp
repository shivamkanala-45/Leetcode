class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> f(26), b(26);

        for(char c : s)
            f[c - 'a']++;

        string ans;

        for(char c : s) {
            f[c - 'a']--;

            if(b[c - 'a'])
                continue;

            while(!ans.empty() &&
                  ans.back() > c &&
                  f[ans.back() - 'a'] > 0) {

                b[ans.back() - 'a'] = 0;
                ans.pop_back();
            }

            ans.push_back(c);
            b[c - 'a'] = 1;
        }

        return ans;
    }
};