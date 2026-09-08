class Solution {
public:
    int f(int n)
    {
        int c=0;
        while(n)
        {
            c++;
            n=n/10;
        }
        return c;
    }
    int countCommas(int n) {
        int d=f(n);
        if(d<=3) return 0;
        return n-999;

    }
};