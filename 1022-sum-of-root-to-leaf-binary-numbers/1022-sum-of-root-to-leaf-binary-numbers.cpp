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
    void solve(TreeNode* root,vector<string>&temp,string str){
        if (!root) return;
        if(root->left==NULL && root->right==NULL){
            str+=to_string(root->val);
            temp.push_back(str);
            return;
        }

        str+=to_string(root->val);
        

        solve(root->left,temp,str);
        solve(root->right,temp,str);

    }

    int sumRootToLeaf(TreeNode* root) {

     

    vector<string> temp;
    solve(root,temp,"");
    int ans=0;

    for(int i=0;i<temp.size();i++){
        string s=temp[i];
        int n=s.length()-1;
        int k=0;
        int res=0;
        while(k<=n){
            if(s[k]=='1')res+=pow(2,n-k);
            k++;
        }
        ans+=res;
    }
     return ans;   
    }
};