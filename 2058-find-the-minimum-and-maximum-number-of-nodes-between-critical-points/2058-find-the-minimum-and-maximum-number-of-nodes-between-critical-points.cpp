/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* h) {
        ListNode* t = h;
        int p;
        vector<int>ans;
        if (t->val > t->next->val)
            p = 0;
        else if (t->val < t->next->val)
            p = 1;
        else
            p = -1;
        t = t->next;
        int i = 0;
        while (t->next != NULL) {
            i++;
            if (t->next->val > t->val) {
                if (p == 0)
                    ans.push_back(i);
                p = 1;
            } else if (t->next->val < t->val) {
                if (p == 1)
                    ans.push_back(i);
                p = 0;
            } else
                p = -1;
            t=t->next;
        }
        if(ans.size()<2) return {-1,-1};
        int mn=INT_MAX;
        for(auto x:ans) cout<<x<<" ";
        for(int i=1;i<ans.size();i++)
        {
            mn=min(mn,ans[i]-ans[i-1]);
        }
        return {mn,ans.back()-ans[0]};
    }
};