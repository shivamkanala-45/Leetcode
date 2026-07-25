class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> dict(wordList.begin(), wordList.end());

        queue<pair<string,int>> q;
        q.push({beginWord, 1});

        while(!q.empty()) {

            auto [word, dist] = q.front();
            q.pop();

            if(word == endWord)
                return dist;

            for(int i = 0; i < word.size(); i++) {

                char original = word[i];

                for(char ch = 'a'; ch <= 'z'; ch++) {

                    word[i] = ch;

                    if(dict.count(word)) {
                        q.push({word, dist + 1});
                        dict.erase(word); 
                    }
                }

                word[i] = original;
            }
        }

        return 0;
    }
};