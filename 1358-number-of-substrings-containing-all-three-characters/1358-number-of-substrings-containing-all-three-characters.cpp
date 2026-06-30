class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int a = 0, b = 0, c = 0;
        int i = 0, j = 0;
        long long ans = 0;
        bool k=false;
        while (i < n && j<n) {
            if(!k)
            {
            if (s[i] == 'a')
                a++;
            if (s[i] == 'b')
                b++;
            if (s[i] == 'c')
                c++;
            }
            else
            {
                k=false;
            }
            if (a && b && c) {
                ans += (n - i);
                switch (s[j]) {
                case 'a':
                    a--;
                    break;
                case 'b':
                    b--;
                    break;
                    default: c--;
                    break;
                }
                j++;
                k=true;
                continue;
            }
            i++;
        }
        return ans;
    }
};