class Solution {
public:
    int minOperations(vector<int>& v, int x) {
        int s = 0;
        int n = v.size();
        for (auto y : v)
            s += y;
        s -= x;
        int i = 0, j = 0;
        int cs = v[0];
        int ans=-1;
        while (j < n) {
            if (cs == s) {
                ans = max(ans, j - i + 1);
                cs -= v[i++];
                j++;
                if(j!=n) cs+=v[j];
            } else if (cs < s) {
                j++;
                if(j!=n) cs+=v[j];
            } else {
                if (i == j) {
                    cs-=v[i++];
                    j++;
                    if(j!=n)
                    cs+=v[j];
                } else {
                    cs -= v[i++];
                }
            }
        }
        if(cs==s) ans=max(ans,j-i);
        while(i<n)
        {
            cs-=v[i++];
            if(cs==s) ans=max(ans,j-i);
        }
        if(ans==-1) return -1;
        return n-ans;
    }
};