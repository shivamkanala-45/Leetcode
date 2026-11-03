class Solution {
public:
    int minMoves(vector<int>& v) {
        int x=0;
        int n=v.size();
        for(int i=0;i<n;i++)
        x=max(x,v[i]);
        int ans=0;
        for(int i=0;i<n;i++)
        ans+=(x-v[i]);
        return ans;
    }
};