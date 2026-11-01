class Solution {
public:
    int minMoves(vector<int>& v) {
        int n=v.size();
        sort(v.rbegin(),v.rend());
        int ans=0;
        for(int i=1;i<n;i++)
        ans+=(v[i-1]-v[i])*i;
        return ans;
    }
};