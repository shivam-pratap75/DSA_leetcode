/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void solve(TreeNode* p, TreeNode* q, bool &result) {
        if (!p && !q) return;             
        if (!p || !q) {                   
            result = false;
            return;
        }

        if (p->val != q->val) {           
            result = false;
            return;
        }

        
        if (result) solve(p->left, q->left, result);
        if (result) solve(p->right, q->right, result);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool result = true;
        solve(p, q, result);
        return result;
    }
};
