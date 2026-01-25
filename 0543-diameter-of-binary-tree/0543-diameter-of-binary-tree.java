/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    
    public int solve(TreeNode root,int[] maxi) 
    {
        if(root == null) 
            return 0;
        
        int lh = solve(root.left,maxi);
        int rh = solve(root.right,maxi);
        maxi[0] = Math.max(maxi[0],lh+rh);
        return 1 + Math.max(lh,rh);
    }

    public int diameterOfBinaryTree(TreeNode root) {
        int[] maxi = new int[1]; // to make it pass by reference in Java...
        solve(root,maxi);
        return maxi[0];
    }
}