class Solution {
public:
    int minimumPushes(string s) {
        vector<int>v(26,0);
        for(auto x:s)
        v[x-'a']++;
        sort(v.begin(),v.end(),greater<int>());
        int ans=0;
        for(int i=0;i<8;i++)
        ans+=v[i];
        for(int i=8;i<16;i++)
        ans+=2*v[i];
        for(int i=16;i<24;i++)
        ans+=3*v[i];
        ans+=4*v[24];
        ans+=4*v[25];
        return ans;
    }
};