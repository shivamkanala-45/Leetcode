class Solution {
public:
    string removeOuterParentheses(string s) {
      string ans="";
      int c=0;
      for(int i=0;i<s.size();i++)
      {
        if(c==0 && s[i]=='(')
        {
            c++;
        }
        else if(c==1 && s[i]==')')
        {
            c--;
        }
        else 
        {
            if(s[i]=='(')
            {
                c++;
                ans+=s[i];
            }
            else
            {
                c--;
                ans+=s[i];
            }
        }
      } 
      return ans; 
    }
};