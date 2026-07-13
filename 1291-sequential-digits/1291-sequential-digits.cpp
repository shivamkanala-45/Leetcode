class Solution {
public:
    vector<int> sequentialDigits(int ld, int hd) {
        string s = "123456789";
        vector<int> ans;

        for (int len = 1; len <= 9; len++) {
            int i = 0;
            while (i + len <= 9) {
                int num = stoi(s.substr(i, len));

                if (num >= ld && num <= hd)
                    ans.push_back(num);

                i++;
            }
        }

        return ans;
    }
};