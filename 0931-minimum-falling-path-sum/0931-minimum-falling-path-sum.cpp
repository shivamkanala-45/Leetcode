class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& v) {
        int m=v.size();
        int n=v[0].size();
        vector<int>p(n);
        for(int i=0;i<n;i++) p[i]=v[m-1][i];
        for(int i=m-2;i>=0;i--)
        {
            vector<int>c(n);
            for(int j=0;j<n;j++)
            {
                c[j]=p[j];
                if(j-1>=0) c[j]=min(c[j],p[j-1]);
                if(j+1<n) c[j]=min(c[j],p[j+1]);
                c[j]+=v[i][j];
            }
            p=c;
        }
        int ans=INT_MAX;
        for(auto x:p)
        ans=min(ans,x);
        return ans;
    }
};