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
int pre_idx=0;

TreeNode* solve(vector<int>&inorder,vector<int>&preorder,int left,int right){
    if(left>right) return NULL;
    TreeNode* root=new TreeNode(preorder[pre_idx++]);// create a new node
    int index; // find index of the root node to find the left and right subtree
     for(int i=0;i<inorder.size();i++){
            if(inorder[i]==root->val){
                index=i;
                break;
            }
        }

        root->left=solve(inorder,preorder,left,index-1);// call for left subtree
        root->right=solve(inorder,preorder,index+1,right);// call for right subtree
        return root;

}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
    return solve(inorder,preorder,0,n-1);
    }
};