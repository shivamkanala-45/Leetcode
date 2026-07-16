class Solution {
public:
    long long gcdSum(vector<int>& a) {
        int n=a.size();
        int mx=a[0];
        vector<int>v(n);
        v[0]=a[0];
        for(int i=1;i<n;i++)
            {
                if(a[i]>mx)
                    mx=a[i];
                v[i]=__gcd(a[i],mx);
            }
        long long ans=0;
        sort(v.begin(),v.end());
        for(int i=0;i<n/2;i++)
            {
                ans+=__gcd(v[i],v[n-1-i]);
            }
        return ans;
    }
};