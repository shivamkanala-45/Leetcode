class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> v(26, 0);
        int n = s.length();
        for (auto x : s)
            v[x - 'a']++;
        string ans = "";
        char c;
        for (int i = 0; i <= 25; i++) {
            if (v[i] % 2)
                c = char(i + 'a');

            int k = v[i] / 2;
            v[i]=k;
            while (k--)
                ans += char(i + 'a');
        }
        if (n % 2)
            ans += c;
        for (int i = 25; i >= 0; i--) {
            while (v[i]--)
                ans += char(i + 'a');
        }
        return ans;
    }
};