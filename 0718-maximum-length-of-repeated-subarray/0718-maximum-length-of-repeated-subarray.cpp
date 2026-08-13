class Solution {
public:
    int findLength(vector<int>& a, vector<int>& b) {
        int n1=a.size();
        int n2=b.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        int best=0;
        for(int i=1;i<=n1;i++)
        {
            for(int j=1;j<=n2;j++)
            {
                if(a[i-1]==b[j-1]) dp[i][j]=1+dp[i-1][j-1];
                best=max(best,dp[i][j]);
            }
        }
        return best;
    }
};