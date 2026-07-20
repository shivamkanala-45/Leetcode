class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& v, int k) {
        int m=v.size();
        int n=v[0].size();
        int a=k/n,b=k%n;
        a=a%m;
        vector<vector<int>>ans(m,vector<int> (n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans[a][b]=v[i][j];
                b++;
                if(b==n)
                {
                    b=0;
                    a=(a+1)%m;
                }
            }
        }
        return ans; 
    }
};