class Solution {
public:
    int maxScore(vector<int>& v, int k) {
        int sum=0;
        int n=v.size();
        int i=0,j=n-1;
        while(i<k)
            sum+=v[i++];
        int ans=sum;
        i--;
        while(i>=0)
        {
            sum=sum-v[i]+v[j];
            ans=max(ans,sum);
            i--;
            j--;
        }
        return ans;
    }
};