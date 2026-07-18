class Solution {
public:
    int findGCD(vector<int>& v) {
        int mx=INT_MIN;
        int mn=INT_MAX;
        for(auto x:v)
        {
            mx=max(mx,x);
            mn=min(mn,x);
        }
        return __gcd(mx,mn);
    }
};