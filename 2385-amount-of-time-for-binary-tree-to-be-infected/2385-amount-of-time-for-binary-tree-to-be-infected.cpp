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
    int time(TreeNode* root, int leaf, int &dist, int &result) {
        if(root == NULL) return 0;
        
        if(root->val == leaf) {
            dist = 0;
            // Calculate height of left and right subtrees
            int left_height = time(root->left, leaf, dist, result);
            int right_height = time(root->right, leaf, dist, result);
            result = max(result, max(left_height, right_height));
            return 1;
        }
        
        int l_dist = -1;
        int r_dist = -1;
        
        int lh = time(root->left, leaf, l_dist, result);
        int rh = time(root->right, leaf, r_dist, result);
        
        if(l_dist != -1) {
            dist = l_dist + 1;
            result = max(result, dist + rh);
        } else if(r_dist != -1) {
            dist = r_dist + 1;
            result = max(result, dist + lh);
        }
        
        return max(lh, rh) + 1;
    }
    
    int amountOfTime(TreeNode* root, int start) {
        int dist = -1;
        int result = 0;  
        time(root, start, dist, result);
        return result;
    }
};