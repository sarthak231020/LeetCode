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

    public void inOrder(TreeNode root,List<Integer> ans) 
    {
        if(root == null) 
            return;
        inOrder(root.left,ans);
        ans.add(root.val);
        inOrder(root.right,ans);
    }

    public void inOrderOptimal(TreeNode root,int[] k,int[] ans) 
    {
        if(root == null) 
            return;
        
        inOrderOptimal(root.left,k,ans);
        k[0] = k[0]-1;
        if(k[0] == 0)
        {
            ans[0] = root.val;
            return;
        }
        inOrderOptimal(root.right,k,ans);
    }

    public int kthSmallest(TreeNode root, int k) {
        // For Brut
        // List<Integer> ans = new ArrayList<>();
        // inOrder(root,ans);
        // return ans.get(k-1);

        int[] ans = new int[1];
        int[] kVal = new int[1];
        ans[0] = -1;
        kVal[0] = k;
        inOrderOptimal(root,kVal,ans);
        return ans[0];
    }
}