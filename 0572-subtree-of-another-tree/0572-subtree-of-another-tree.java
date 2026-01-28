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

    public boolean isEqual(TreeNode root,TreeNode subRoot) 
    {
        if(root == null || subRoot == null) 
            return root == subRoot;

        if(root.val != subRoot.val) 
            return false;
        
        return isEqual(root.left,subRoot.left) && isEqual(root.right,subRoot.right);
    }

    public boolean solBfs(TreeNode root,TreeNode subRoot) 
    {
        Deque<TreeNode> q = new ArrayDeque<>();
        q.offer(root);
        while(!q.isEmpty()) 
        {
            TreeNode curr = q.poll();
            if(curr.val == subRoot.val) 
            {
                if(isEqual(curr,subRoot)) 
                    return true;
            }
            if(curr.left != null) 
                q.offer(curr.left);
            if(curr.right != null) 
                q.offer(curr.right);
        }
        return false;
    }

    public boolean solDfs(TreeNode root,TreeNode subRoot)
    {
        if(root == null || subRoot == null)
            return root == subRoot;
        if(isEqual(root,subRoot))
            return true;
        return solDfs(root.left,subRoot) || solDfs(root.right,subRoot);
    }

    public boolean isSubtree(TreeNode root, TreeNode subRoot) 
    {
        // return brutSol(root,subRoot);
        return solDfs(root,subRoot);
    }
}