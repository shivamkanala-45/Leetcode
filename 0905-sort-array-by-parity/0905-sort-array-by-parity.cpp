class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& v) {
        vector<int>ans;
        for(auto x:v)
        {
            if(x%2==0)
            ans.push_back(x);
        }
        for(auto x:v)
        {
            if(x%2!=0)
            ans.push_back(x);
        }
        return ans;
    }
};