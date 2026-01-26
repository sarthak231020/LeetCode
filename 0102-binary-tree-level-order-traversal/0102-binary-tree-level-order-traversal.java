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
    public List<List<Integer>> levelOrder(TreeNode root) {
        
        List<List<Integer>> ans = new ArrayList<>();
        if(root == null) 
            return ans;
        Deque<TreeNode> q = new ArrayDeque<>();
        q.offer(root);

        while(!q.isEmpty()) 
        {
            List<Integer> tempAns = new ArrayList<>();
            int size = q.size();
            for(int i=0;i<size;i++) 
            {
                TreeNode currNode = q.peek();
                q.poll();
                tempAns.add(currNode.val);
                if(currNode.left != null) 
                    q.offer(currNode.left);
                if(currNode.right != null) 
                    q.offer(currNode.right);
            }
            ans.add(tempAns);
        }

        return ans;
    }
}