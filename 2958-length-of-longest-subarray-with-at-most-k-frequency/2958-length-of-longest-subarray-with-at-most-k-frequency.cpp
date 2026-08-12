class Solution {
public:
    int maxSubarrayLength(vector<int>& v, int k) {
        int i=0,j=0;
        int n=v.size();
        unordered_map<int,int>mp;
        int ans=0;
        while(i<n)
        {
            mp[v[i]]++;
            while(j<n && mp[v[i]]>k)
                mp[v[j++]]--;
            ans=max(ans,i-j+1);
            i++;
        }
        return ans;
    }
};