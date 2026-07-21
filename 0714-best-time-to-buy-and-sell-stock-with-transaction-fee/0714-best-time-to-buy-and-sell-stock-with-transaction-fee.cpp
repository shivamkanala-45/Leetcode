class Solution {
public:
    int f(int i,int b,vector<int>& v,vector<vector<int>>& dp,int x)
    {
        if(i>=v.size()) return 0;
        if(dp[i][b] != -1)
        return dp[i][b];
        if(b)
        return dp[i][b]=max(-v[i]+f(i+1,0,v,dp,x),f(i+1,1,v,dp,x));
        return dp[i][b]=max(v[i]+f(i+1,1,v,dp,x)-x,f(i+1,0,v,dp,x));
    }
    int maxProfit(vector<int>& v,int x) {
        int n=v.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return f(0,1,v,dp,x);
    }
};