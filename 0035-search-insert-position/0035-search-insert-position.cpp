class Solution {
public:
    int searchInsert(vector<int>& a, int target) {
        int s=0;
        int e=a.size()-1;
        int m;
        while(s<=e)
        {
            m=s+(e-s)/2;
            if(a[m]==target)
            return m;
            else if(a[m]>target)
            e=m-1;
            else
            s=m+1;
        }
        // if(a[m]>target)
        // return m;
        // else
        // return m+1;
        return s;


    }
};