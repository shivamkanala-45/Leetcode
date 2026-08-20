class Solution {
public:
    vector<int> resultArray(vector<int>& v) {
        int n = v.size();
        vector<int>a,b;
        a.push_back(v[0]);
        b.push_back(v[1]);
        for(int i=2;i<n;i++)
            {
                if(a.back()>b.back())
                    a.push_back(v[i]);
                else
                    b.push_back(v[i]);
            }
        for(auto x:b)
        a.push_back(x);
        return a;
    }
};