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
    void solve(TreeNode* root) {
        if (root == NULL) return;
        
        TreeNode* temp1 = root->left;
        TreeNode* temp2 = root->right;
        
        root->left = NULL;
        root->right = temp1;
        
        solve(temp1);
        
        // Find the rightmost node to attach temp2
        TreeNode* current = root;
        while (current->right != NULL) {
            current = current->right;
        }
        current->right = temp2;
        
        solve(temp2);
    }
    
    void flatten(TreeNode* root) {
        solve(root);
    }
};