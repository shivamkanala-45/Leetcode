class Solution {
public:
    vector<vector<int>> dp = vector<vector<int>>(21, vector<int>(21, -1));
    int f(int i,int j,vector<int>&v)
    {
        if(i==j) return dp[i][j] = v[i];
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=max(v[i]-f(i+1,j,v),v[j]-f(i,j-1,v));
    }
    bool predictTheWinner(vector<int>& v) {
        int n=v.size();
        if(f(0,n-1,v)<0) return false;
        return true;
    }
};