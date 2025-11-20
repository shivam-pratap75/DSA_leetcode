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
    int find_maxi(vector<int>&nums,int i,int j){
        int idx=i,maxi=nums[i];
        while(i<=j){
            if(maxi<nums[i]){
                idx=i;
                maxi=nums[i];
            }
            i++;

        }
        return idx;
        
    }

    TreeNode* solve(vector<int>& nums,int i,int j){
        if (i > j) {
            return nullptr;
        }

        int idx=find_maxi(nums,i,j);
         TreeNode* root = new TreeNode(nums[idx]);
        root->left=solve(nums,i,idx-1);
        
        root->right=solve(nums,idx+1,j);
        return root;
        
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n=nums.size();
        
        return solve(nums,0,n-1);
        
    }
};