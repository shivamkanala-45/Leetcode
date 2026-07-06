class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& v) {
        sort(v.begin(),v.end());
        int n=v.size();
        int x=v[0][1];
        int c=0;
        int y=v[0][0];
        set<int>s;
        s.insert(v[0][0]);
        for(int i=1;i<n;i++)
        {
            
           if (v[i][0] == y)
            {
                x = max(v[i][1],x);
            }
            else if(v[i][0]<=x)
            {
                if(v[i][1]<=x)
                {}
                else
                {
                x=v[i][1];
                s.insert(v[i][0]);
                }
            }
            else
            {
                s.insert(v[i][0]);
                x=v[i][1];
            }
        }
        return s.size();
    }
};