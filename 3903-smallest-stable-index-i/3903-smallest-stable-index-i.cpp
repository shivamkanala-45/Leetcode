class Solution {
public:
    int firstStableIndex(vector<int>& v, int k) {
        int n = v.size();
        vector<int>mx(n),mn(n);
        mx[0]=v[0];
        for (int i = 1; i < n; i++) {
            mx[i] = max(v[i], mx[i-1]);
        }
        mn[n-1]=v[n-1];
        for(int i=n-2;i>=0;i--)
            {
                mn[i]=min(mn[i+1],v[i]);
            }
        int ans=-1;
        for(int i=0;i<n;i++)
            {
                if(mx[i]-mn[i] <= k)
                {
                    ans=i;
                    break;
                }
            }
        return ans;
    }
};