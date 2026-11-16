class Solution {
public:
    string f(string s,int k)
    {
        string p="";
        int c=0;
        int sum=0;
        for(auto x:s)
        {
            c++;
            sum+=(x-'0');
            if(c==k)
            {
                c=0;
                p+=to_string(sum);
                sum=0;
            }
        }
        if(c!=0) p+=to_string(sum);
        return p;
    }
    string digitSum(string s, int k) {
        string t=s;
        while(t.length()>k) t=f(t,k);
        return t;
    }
};