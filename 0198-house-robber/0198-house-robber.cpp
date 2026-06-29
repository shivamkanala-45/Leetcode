class Solution {
public:
    int rob(vector<int>& v) {
        int n=v.size();
        vector<int>dp(n+3);
        dp[n+2]=0;
        dp[n+1]=0;
        dp[n]=0;
        for(int i=n-1;i>=0;i--)
        dp[i]=max(dp[i+2],dp[i+3])+v[i];
        return max(dp[0],dp[1]);
    }
};