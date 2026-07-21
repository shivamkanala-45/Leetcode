class Solution {
public:
    int f(int i,int b,int c,vector<int>& v,vector<vector<vector<int>>>& dp)
    {
        if(i==v.size()) return 0;
        if(c==0) return 0;
        if(dp[i][b][c] != -1)
        return dp[i][b][c];
        if(b)
        return dp[i][b][c]=max(-v[i]+f(i+1,0,c,v,dp),f(i+1,1,c,v,dp));
        return dp[i][b][c]=max(v[i]+f(i+1,1,c-1,v,dp),f(i+1,0,c,v,dp));
    }
    int maxProfit(vector<int>& v) {
        int n=v.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return f(0,1,2,v,dp);
    }
};