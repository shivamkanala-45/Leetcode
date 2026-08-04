class Solution {
public:
    vector<int> findMissingElements(vector<int>& v) {
        unordered_map<int,bool>mp;
        int mn=INT_MAX;
        int mx=INT_MIN;
        for(int i=0;i<v.size();i++)
        {
            mn=min(mn,v[i]);
            mx=max(mx,v[i]);
            mp[v[i]]=true;
        }
        vector<int>ans;
        for(int x=mn;x<mx;x++)
        {
            if(!mp[x]) ans.push_back(x);
        }
        return ans;
    }
};