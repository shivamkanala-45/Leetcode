class Solution {
public:
    bool canPartition(vector<int>& v) {
        int k=0;
        for(auto x:v)
        k+=x;
        if(k%2!=0) return false;
        k=k/2;
        vector<bool>b(k+1,false);
        b[0]=true;
        for(auto x:v)
        {
            for(int target=k;target>=x;target--)
            b[target]=b[target]||b[target-x];
        }
        return b[k];
    }
};