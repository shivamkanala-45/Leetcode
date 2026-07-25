class Solution {
public:
    void d(int n,vector<int>&v)
    {
        while(n)
        {
            v[n%10]++;
            n=n/10;
        }
    }
    int maxProduct(int n) {
        vector<int>v(10,0);
        d(n,v);
        int c=2;
        int ans=1;
        for(int i=9;i>=0;i--)
        {
            if(v[i]>0)
            {
            ans=ans*i;
            v[i]--;
            i++;
            c--;
            }
            if(c==0)
            break;
        }
        return ans;
    }
};