class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans=0;
        int k = 0;
        for (int i=0;i<s.length();i++) {
            if (s[i] == '(')
                k++;
            else {
                k--;
                if(s[i-1]=='(')
                    ans+=1 << k;
            }
        }
        return ans;
    }
};