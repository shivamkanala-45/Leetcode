class Solution {
public:
    int minimumTotal(vector<vector<int>>& v) {
        vector<int>p;
        int n=v.size();
        p.push_back(v[0][0]);
        for(int i=1;i<n;i++)
        {
            vector<int>temp;
            temp.push_back(v[i][0]+p[0]);
            for(int j=1;j<i;j++)
            {
                temp.push_back(v[i][j]+min(p[j],p[j-1]));
            }
            temp.push_back(v[i][i]+p[i-1]);
            p=temp;
        }
        int m=p[0];
        for(auto x:p)
        m=min(x,m);
        return m;
    }
};