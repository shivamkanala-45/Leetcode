class Solution {
public:
    bool checkString(string s) {
        int y=0;
        for(auto x:s)
        {
            if(x=='a' && y) return 0;
            if(x=='b') y=1;
        }
        return 1;
    }
};