class Solution {
public:
    int minMoves2(vector<int>& v) {
        sort(v.begin(),v.end());
        int n=v.size();
        int x=v[(n-1)/2];
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=abs(v[i]-x);
        }
        return ans;
    }
};