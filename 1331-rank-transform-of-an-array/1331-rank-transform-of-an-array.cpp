class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& v) {
        vector<int>x(v);
        sort(v.begin(),v.end());
        unordered_map<int,int>m;
        int r=1;
        for(int i=0;i<v.size();i++)
        {
            if(!m[v[i]]) m[v[i]]=r++;
        }
        for(int i=0;i<v.size();i++)
            x[i]=m[x[i]];
        return x;
    }
};