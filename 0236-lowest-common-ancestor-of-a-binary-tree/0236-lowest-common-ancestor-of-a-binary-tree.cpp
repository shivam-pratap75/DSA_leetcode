/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

TreeNode* lca(TreeNode* root, int p,int q){
    if(root==NULL) return NULL; // this is base case 
    if(root->val==p || root->val==q) return root; // if we hit the target value return it 

    TreeNode* node1 = lca(root->left,p,q); // call for left 
    TreeNode* node2 = lca(root->right,p,q); // call for right

    if(node1!=NULL && node2 !=NULL) return root; // when both value are not null
     // because there is only one node for the values are not null (visualize it) 

    if(node2!=NULL){  // if node2 is not  null then return the node2 
        return node2;
        }else{
            return node1; // else return the another node 
        } 
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;
        return lca(root,p->val,q->val);

        
    }
};