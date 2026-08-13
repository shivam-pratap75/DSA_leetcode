/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {

    
    public int GoodNodes(TreeNode root) {
        

        return dfs(root,int.MinValue);
    }

    private int dfs(TreeNode node,int maxValue){

        if(node==null)return 0;

        int good=0;

        if(node.val>=maxValue){
            good=1;
            maxValue=node.val;
        }

        int left=dfs(node.left,maxValue);
        int right=dfs(node.right,maxValue);

        return good+left+right;



    }
}