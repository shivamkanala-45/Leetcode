class Solution {
public:
    int f(int n)
    {
        int k=0;
        while(n)
        {
            k+=n%10;
            n=n/10;
        }
        return k;
    }
    int smallestIndex(vector<int>& v) {
        for(int i=0;i<v.size();i++)
        {
            if(f(v[i])==i) return i;
        }
        return -1;
    }
};