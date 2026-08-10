class Solution {
public:
    bool winnerSquareGame(int n) {
       vector<bool>v(n+1,0);
       for(int i=0;i<=n;i++)
       {
        for(int j=1;j*j<=i;j++)
        {
            if(!v[i-(j*j)])
            {
            v[i]=1;
            break;
            }
        }
       }
       return v[n]; 
    }
};