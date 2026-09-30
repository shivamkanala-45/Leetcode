class Solution {
public:
    vector<int> maxDepthAfterSplit(string s) {
        int n=s.length();
        int a=0,b=0,i=0;
        vector<int>ans(n);
        while(i<n)
        {
            if(s[i]=='(')
            {
                if(b>=a)
                {
                    a++;
                    ans[i]=0;
                }
                else
                {
                    b++;
                    ans[i]=1;
                }
            }
            else
            {
                if(b>a)
                {
                    b--;
                    ans[i]=1;
                }
                else
                {
                    a--;
                    ans[i]=0;
                }
            }
            i++;
        }
        return ans;
    }
};