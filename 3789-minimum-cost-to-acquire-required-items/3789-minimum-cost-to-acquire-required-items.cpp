class Solution {
public:
    long long minimumCost(int c1, int c2, int c, int a, int b) {
        long long ans=0;
        if(c1+c2>=c)
        {
            ans+=(long long)min(a,b)*c;
            if(a>=b)
            {
                a=a-b;
                ans+=(long long)min(c1,c)*a;
            }
            else
            ans+=(long long)min(c2,c)*(b-a);
        }
        else
        ans+=(long long)a*c1+(long long)b*c2;
        return ans;
    }
};