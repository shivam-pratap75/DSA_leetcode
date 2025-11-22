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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int level = 0;
        vector<vector<int>> result;
        if(root == NULL) return result;
        
        deque<TreeNode*> dq;
        dq.push_back(root);
        
        while(!dq.empty()) {
            int levelSize = dq.size();
            vector<int> temp1;
            
            
            for(int i = 0; i < levelSize; i++) {
                if(level % 2 == 0) {
                    
                    TreeNode* temp = dq.front();
                    dq.pop_front();
                    temp1.push_back(temp->val);
                    
                    
                    if(temp->left) dq.push_back(temp->left);
                    if(temp->right) dq.push_back(temp->right);
                } else {
                   
                    TreeNode* temp = dq.back();
                    dq.pop_back();
                    temp1.push_back(temp->val);
                    
                    
                    if(temp->right) dq.push_front(temp->right);
                    if(temp->left) dq.push_front(temp->left);
                }
            }
            
            result.push_back(temp1);
            level++;
        }
        
        return result;
    }
};