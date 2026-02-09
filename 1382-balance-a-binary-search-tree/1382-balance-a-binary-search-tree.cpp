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

    void solve(TreeNode* root,vector<int>&arr){
        if (root == NULL) return;

          solve(root->left,arr);
        arr.push_back(root->val);
          solve(root->right,arr);
    }
    TreeNode* solve2(vector<int>&arr,int st,int end){

        if(st>end)return NULL;
        int mid=(st+end)/2;

        TreeNode* temp = new TreeNode(arr[mid]);

        temp->left=solve2(arr,st,mid-1);
        temp->right=solve2(arr,mid+1,end);
        return temp;
    }
    TreeNode* balanceBST(TreeNode* root) {

        vector<int> arr;
        solve(root,arr);
        return solve2(arr,0,arr.size()-1);
       
    }
};