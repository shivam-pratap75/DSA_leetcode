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
    int widthOfBinaryTree(TreeNode* root) {
    
   int result=0;
   queue<pair<TreeNode* ,int>> que;
   que.push({root,0});
    while(!que.empty()){
        int left=que.front().second;
        int right=que.back().second;
        result=max(result,right-left+1);
        int n=que.size();
        while(n){
            TreeNode* temp = que.front().first;
            int idx = que.front().second;
            que.pop();

            if(temp->left){
                que.push({temp->left,2*idx+1});
            }
            

            if(temp->right){
                que.push({temp->right,2*idx+2});
            }

            n--;
        }

    }
     
        
       return result; 
    }
};