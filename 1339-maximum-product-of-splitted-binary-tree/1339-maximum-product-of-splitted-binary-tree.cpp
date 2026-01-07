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
    const int MOD = 1e9 + 7;
    long long result = 0;
    long long totalSum = 0;
    
    long long computeSubtreeSum(TreeNode* root) {
        if (!root) return 0;
        
        long long leftSum = computeSubtreeSum(root->left);
        long long rightSum = computeSubtreeSum(root->right);
        long long subtreeSum = root->val + leftSum + rightSum;
        
        if (totalSum > 0) {
            long long otherPart = totalSum - subtreeSum;
            long long product = subtreeSum * otherPart;
            result = max(result, product);
        }
        
        return subtreeSum;
    }
    
    int maxProduct(TreeNode* root) {
        
        totalSum = computeSubtreeSum(root);
        result = 0;
        computeSubtreeSum(root);
        
        return result % MOD;
    }
};