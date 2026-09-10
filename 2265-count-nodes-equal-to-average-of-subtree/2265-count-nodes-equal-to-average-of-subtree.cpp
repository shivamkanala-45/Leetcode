/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    pair<int, int> f(TreeNode* r) {
        if (!r->left && !r->right) {
            ans++;
            return {r->val, 1};
        }
        pair<int,int> lt={0,0}, rt={0,0};
        if (r->left) {
            lt = f(r->left);
        }
        if (r->right) {
            rt = f(r->right);
        }
        int sum=r->val+rt.first+lt.first;
        int cnt=rt.second+lt.second+1;
        if(sum/cnt==r->val) ans++;
        return {sum,cnt};
    }
    int averageOfSubtree(TreeNode* r) {
        f(r);
        return ans;
    }
};