class Solution {
public:
    string lexGreaterPermutation(string s, string t) {
        unordered_map<char,int> mp;

        for(char c:s)
            mp[c]++;

        string ans="";

        for(char c:t){
            if(mp[c]>0){
                mp[c]--;
                ans+=c;
            }
            else{
                for(char x=c+1;x<='z';x++){
                    if(mp[x]>0){
                        ans+=x;
                        mp[x]--;

                        for(char y='a';y<='z';y++)
                            ans+=string(mp[y],y);

                        return ans;
                    }
                }
                break;
            }
        }
        for(int i=(int)ans.size()-1;i>=0;i--){

            mp[ans[i]]++;
            for(char c=ans[i]+1;c<='z';c++){
                if(mp[c]>0){

                    ans=ans.substr(0,i);
                    ans+=c;
                    mp[c]--;

                    for(char x='a';x<='z';x++)
                        ans+=string(mp[x],x);

                    return ans;
                }
            }
        }

        return "";
    }
};